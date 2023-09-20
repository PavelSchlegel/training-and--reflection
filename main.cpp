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
    using namespace boost::json;
    std::string _str {"string_string"};

    struct Mystruct {
        int _id = 1;
        std::string _str {"default"};
    };

    Mystruct A;
    // value V {{"id", A._id}, {"str", A._str}};
    // if (V.is_object()) {
    //     std::cout << V << std::endl;
    // }
    // value B = string(_str);
    // if (B.is_array()) {
    //     std::cout << B << std::endl;
    // }
    // std::cout << B << std::endl;

    object N {{"id", A._id}, {"str", A._str}};

    char buf[200];
    serializer R;
    R.reset(&N);
    do {
        R.read(buf);
    } while (! R.done());

    stream_parser p;
    error_code ec;
    p.reset();
    p.write( buf, ec );
    // if( ! ec )
    //     p.write( ", 3]", ec );
    if( ! ec )
        p.finish( ec );
    if( ec ) {
        std::cout << ec.what() << std::endl;
    }

    value jv = p.release();

    std::cout << jv << std::endl;

    return 0;
}