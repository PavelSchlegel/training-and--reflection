#ifndef TRHEADPOOL
#define TRHEADPOOL

#include "headers.hpp"
#include "blockedqueue.hpp"

#define T_SIZE 4

void func(std::size_t A, std::size_t B);
// using task_type = std::packaged_task<void()>;
using res_type = std::future<void>;
using task_type = std::function<void()>;
using func_ptr = void (*) (int*, int, int);

class Thread_Pool
{
public:
    Thread_Pool();
    void start();
    void stop();
    res_type push_task(func_ptr, int* ARR, int A, int B);
    // res_type push_task(func_ptr, std::size_t A, std::size_t B);
    void thread_func(std::size_t qindex);
private:
    std::size_t _thread_count;
    std::vector<std::thread> _threads;
    std::vector<BlockedQueue<task_type>> _thread_queues;
    std::size_t _index;
    // std::mutex _mutex;
    // std::queue<task_type> _task_queue;
    // std::condition_variable _event_holder;
    // bool _work;
};
#endif