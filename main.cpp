#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <functional>
#include "Qsort_Pool/threadpool.hpp"
// #include <mylib.hpp>
#include "new_lib/new_lib.hpp"
int get_int()
{
    return 1;
}

int main()
{
    // boost::json::object O;                      // пустой объект
    // // сария вызывов для вставки
    // O[get()] = get_int();                                // insert a int
    // O[ "pi" ] = 3.141;                          // insert a double
    // O[ "happy" ] = true;                        // insert a bool
    // O[ "name" ] = "Boost";                      // insert a string
    // std::cout << O << std::endl;
    /*Вместо того, чтобы создавать документ JSON с помощью серии вызовов функций, 
    можно создать его в одном операторе, используя список инициализаторов:*/

    // boost::json::value value = {
    //                             {"id", 2},
    //                             {"pi", 3.141},
    //                             {"happy", true},
    //                             {"name", "Boost"}
    //                             };
    // boost::json::object A = {{"id", 2}};
    // std::cout << value << std::endl;
    // // std::cout << A << std::endl;
    // boost::json::value C = boost::json::parse("[1, 2, 3]");
    // // std::cout << C << std::endl;
    // std::string serial = boost::json::serialize(value);
    // // std::cout << serial << std::endl;
    // boost::json::serializer sr;
    // sr.reset(&value);
    // do
    // {
    //     char buf[20];
    //     std::cout << sr.read(buf) << std::endl;

    // } while (! sr.done());
    // boost::json::value F = boost::json::parse(serial);
    // test_json();
    // std::cout << O << std::endl;
    test_json();
    return 0;
}