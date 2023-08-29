#include "threadpool.hpp"

std::mutex g_cout_lock;

void func(std::size_t A, std::size_t B)
{   
    std::unique_lock<std::mutex> M(g_cout_lock);
    std::cout << "I am func!" << "arg:" << A << " " << B << std::endl;
    // std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
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
}

void Thread_Pool::stop()
{
    for(int i = 0; i < _thread_count; ++i) {
       task_type empty_task;
       _thread_queues[i].push(empty_task);
    }
    for(auto& t: _threads) {
       t.join();
    }
}

struct TaskChain
{
    std::shared_ptr<TaskChain> parent;
    std::promise<void> current;
    TaskChain(std::shared_ptr<TaskChain> parent) noexcept
    : parent(std::move(parent))
    {

    }
    ~TaskChain()
    {
        current.set_value();
    }
};

thread_local std::shared_ptr<TaskChain> current_task; 
res_type Thread_Pool::push_task(func_ptr F, int* ARR, int A, int B)
{
    int queue_to_push = _index++ % _thread_count;
    auto chain = std::make_shared<TaskChain>(current_task);
    task_type task (
        [=] {
            current_task = chain;
            F(ARR, A, B);
            current_task = nullptr;
        }
    );
    _thread_queues[queue_to_push].push(task);
    return chain->current.get_future();
}

void Thread_Pool::thread_func(std::size_t qindex)
{
    while(true) {
       task_type task_to_do;
       bool res;
       int i = 0;
       for(; i < _thread_count; ++i) {
            res = _thread_queues[(qindex + i) % _thread_count].fast_pop(task_to_do);
            if(res) {
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
}