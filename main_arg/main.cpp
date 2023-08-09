#include <iostream>

int main(int argc, char *argv[]) {
    //argv[0] - путь,имя текущей программы
    std::cout << "Program:" << argv[0] << std::endl;
    if (argc > 1) {
        std::cout << "arg count:" << " " << argc << std::endl;
        for (int i = 0; i < argc; ++i) {
            std::cout << i << " " << argv[i] << '\n';
        }
        return 0;
    }
    //несмотря на то, что путь,имя передаются по дефолту
    std::cout << "No arguments!" << std::endl; 
    return 0;
}