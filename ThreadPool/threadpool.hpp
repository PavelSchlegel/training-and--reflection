#ifndef TRHEADPOOL
#define TRHEADPOOL
#include <queue>
#include <future>
#include <condition_variable>
#include <vector>

#define T_SIZE 4

void func(std::size_t A, std::size_t B);
using task_type = std::function<void()>;
using func_ptr = void (*) (std::size_t, std::size_t);

class Thread_Pool
{
public:
    void start();
    void stop();
    void push_task(func_ptr, std::size_t A, std::size_t B);
    void thread_func();
private:
    std::vector<std::thread> _threads;
    std::mutex _mutex;
    std::queue<task_type> _task_queue;
    std::condition_variable _event_holder;
    bool _work;
};
#endif