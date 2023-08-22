#include <iostream>
#include <vector>
#include <thread>
#include <future>

void example(int A) {
    std::cout << A << std::endl;
}

int main()
{
    std::vector<int> D;
    for (std::size_t i = 0; i < 5; ++i) {
        std::cout << D.emplace_back(i);
    }
    /*
    for (std::size_t i = 0; i < 5; ++i) {
        std::cout << D[i] << " ";
    }
    */
    return 0;
}