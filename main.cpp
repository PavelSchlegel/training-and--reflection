#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <functional>

void example(int A) {
    std::cout << A << std::endl;
}

int main()
{
    std::shared_future<int> A = std::async(std::launch::async, [](){return 10;}).share();
    std::future<int> B = std::async(std::launch::async, [&A](){return A.get() + 1;});

    std::cout << "A:" << A.get() << std::endl;
    std::cout << "B:" << B.get() << std::endl;
    return 0;
}