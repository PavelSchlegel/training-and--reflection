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
    std::function<void()> A;
    if (A) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "Not ok" << std::endl;
    }
    return 0;
}