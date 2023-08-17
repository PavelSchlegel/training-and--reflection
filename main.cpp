#include <iostream>
#include <vector>
#include <thread>
#include <future>

void example(int A) {
    std::cout << A << std::endl;
}

int main()
{
    std::packaged_task<void(int)> T(example);
    T(5);
    return 0;
}