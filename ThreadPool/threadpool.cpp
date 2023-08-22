#include "threadpool.hpp"
#include <iostream>

std::mutex g_cout_lock;

void func(std::size_t A, std::size_t B)
{   
    std::unique_lock<std::mutex> M(g_cout_lock);
    std::cout << "I am func!" << "arg:" << A << " " << B << std::endl;
    std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
}

void Thread_Pool::start()
{
    _work = true;
    for (std::size_t i = 0; i < T_SIZE; ++i) {
        _threads.push_back(std::thread(&Thread_Pool::thread_func, this));
    }
}

void Thread_Pool::stop()
{
    std::unique_lock<std::mutex> M(_mutex);
    _work = false;
    for (auto& rec : _threads) {
        if (rec.joinable()) {
            rec.join();
        }
    }
}

void Thread_Pool::push_task(func_ptr F, std::size_t A, std::size_t B)
{
    std::lock_guard<std::mutex> M(_mutex);
    task_type new_task([=](){F(A, B);});
    _task_queue.push(new_task);
    _event_holder.notify_one();
}

void Thread_Pool::thread_func()
{
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
}