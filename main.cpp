#include <iostream>
#include <vector>
#include <thread>
#include <future>

void example(int A) {
    std::cout << A << std::endl;
}

int main()
{
    std::vector<void(*)(int A)> X(5, example);
    for (const auto rec : X) {
        rec(1);
    }

    std::vector<int> D(5, 4);
    for (std::cout << "exampple:"; auto rec : D) {
        std::cout << rec << std::endl;
    }
    return 0;
}