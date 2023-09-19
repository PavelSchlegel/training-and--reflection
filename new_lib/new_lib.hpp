#pragma once
#include <boost/json.hpp>
#include <iostream>

// void d();

// class Interface
// {
// public:
//     virtual void print() = 0;
//     void F()
//     {
//         std::cout << "F" << std::endl;
//     }
// };

// inline void Interface::print()
// {
//     std::cout << "Interface" << std::endl;
// }

// class A: public Interface
// {
// public:
//     void print() override
//     {
//         std::cout << "Child" << std::endl;
//         // Interface::print();
//     }

//     void d()
//     {
//         std::cout << "print: d" << std::endl;
//     }
// };
inline std::string get()
{
    std::string line;
    std::cout << "get" << '\n';
    std::getline(std::cin, line);
    return line;
}

inline void test_json()
{
    // boost::json::value json {
    //                         {"key", 2},
    //                         {"id", 4},
    //                         {"str", "string"}
    //                         };
    boost::json::object O {
                        {"id", 1},
                        {"key", "string"}
                        };
    auto it = O.find("id");
    std::cout << it->value() << std::endl;
    std::cout << O.find("key")->value() << std::endl;
}