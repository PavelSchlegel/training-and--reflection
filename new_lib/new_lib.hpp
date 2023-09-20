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

inline void test_two()
{
    boost::json::value json {
                            {"key", 2},
                            {"id", 4},
                            {"str", "string"}
                            };
    boost::json::serializer sr;
    sr.reset(&json);
    // do
    // {
        char buf[10];
        // std::cout << sr.read(buf) << std::endl;
        sr.read(buf);
        boost::json::value A = boost::json::parse(buf);
        for (std::size_t i = 0; i < 10; ++i) {
            std::cout << buf[i];
        }

    // } while (! sr.done());
}

inline void test_json()
{
    // using namespace boost::json;
    // boost::json::object O {
    //                     {"id", 1},
    //                     {"key", "string"}
    //                     };
    // boost::json::serializer sr;
    // sr.reset(&O);
    // // do {
        
    //     char buf[20];
    //     sr.read(buf);
    //     // boost::json::value A = boost::json::parse(buf);
    //     for (std::size_t i = 0; i < 20; ++i) {
    //         std::cout << buf[i];
    //     }
    // // } while ( ! sr.done());
    // stream_parser p;
    // error_code ec;
    // p.reset();
    // p.write(buf, 20, ec);
    // // if( ! ec )
    // //     p.write( ", 3]", ec );
    // if( ! ec )
    //     p.finish( ec );
    // if( ec )
    //     std::cout << ec.what() << std::endl;
    // value jv = p.release();
    //     std::cout << jv << std::endl;
}