#include "../headers/read_write_file.hpp"

void who_are_you() {
    std::cout << "Hi, what is your name?" << std::endl;
    std::string name;
    std::string f_name = "name_data.txt";
    std::getline(std::cin, name);
    std::fstream fs;
    fs.open(f_name, std::fstream::out);
    if (fs.is_open()) {
        fs << name << '\n';
        fs.close();
        return;
    }
    std::cout << "File was not open!" << std::endl;
}

void by() {
    std::string name = "ERROR";
    std::string f_name = "name_data.txt";
    std::fstream fs;
    fs.open(f_name, std::fstream::in);
    if (fs.is_open()) {
        fs >> name;
        fs.close();
        std::cout << "See you later," << name << std::endl;
        return;
    }
    std::cout << "File was not open!" << std::endl;
}