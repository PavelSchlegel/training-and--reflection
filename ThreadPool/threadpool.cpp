#include "threadpool.hpp"

std::mutex g_cout_lock;

void func(std::size_t A, std::size_t B)
{   
    std::unique_lock<std::mutex> M(g_cout_lock);
    std::cout << "I am func!" << "arg:" << A << " " << B << std::endl;
    std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
}

Thread_Pool::Thread_Pool()
: _thread_count(std::thread::hardware_concurrency() != 0? std::thread::hardware_concurrency():4)
, _thread_queues(_thread_count)
{

}

void Thread_Pool::start()
{
    for(std::size_t i = 0; i < _thread_count; ++i) {
       _threads.emplace_back(&Thread_Pool::thread_func, this, i);
    }
    /*
    _work = true;
    for (std::size_t i = 0; i < T_SIZE; ++i) {
        _threads.push_back(std::thread(&Thread_Pool::thread_func, this));
    }
    */
}

void Thread_Pool::stop()
{
    for(int i = 0; i < _thread_count; ++i) {
       // кладем задачу-пустышку в каждую очередь
       task_type empty_task;
       _thread_queues[i].push(empty_task);
    }
    for(auto& t: _threads) {
       t.join();
    }
    /*
    std::unique_lock<std::mutex> M(_mutex);
    _work = false;
    _event_holder.notify_all();
    for (auto& rec : _threads) {
        if (rec.joinable()) {
            rec.join();
        }
    }
    */
}

void Thread_Pool::push_task(func_ptr F, std::size_t A, std::size_t B)
{
    // вычисляем индекс очереди, куда положим задачу
    int queue_to_push = _index++ % _thread_count;
    // формируем функтор
    task_type task = [=]{F(A, B);};
    // кладем в очередь
    _thread_queues[queue_to_push].push(task);
    /*
    std::lock_guard<std::mutex> M(_mutex);
    task_type new_task([=](){F(A, B);});
    _task_queue.push(new_task);
    _event_holder.notify_one();
    */
}

void Thread_Pool::thread_func(std::size_t qindex)
{
    while(true) {
       task_type task_to_do;
       bool res;
       int i = 0;
       for(; i < _thread_count; ++i) {
           if(res = _thread_queues[(qindex + i) % _thread_count].fast_pop(task_to_do)) {
               break;
           }
       }

       if (!res) {
           _thread_queues[qindex].pop(task_to_do);
       } else if (!task_to_do) {
           _thread_queues[(qindex + i) % _thread_count].push(task_to_do);
       }
       if (!task_to_do) {
           return;
       }
       task_to_do();
   }
    /*
    while(true) {
        task_type task;
        {
            std::unique_lock<std::mutex> M(_mutex);
            if (_task_queue.empty() && !_work) {
                return;
            }
            if (_task_queue.empty()) {
                _event_holder.wait(M, [&](){return !_task_queue.empty() || !_work;});
            }
            if (!_task_queue.empty()) {
                task = _task_queue.front();
                _task_queue.pop();
            }
        }
        task();
    }
    */
}