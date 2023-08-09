#ifndef STRUCT
#define STRUCT
#include <iostream>
#include <string>

struct Struct {
    private:
        std::string s_str;
    public:
        Struct(const std::string& str) {
            s_str = std::move(str);
        }

        ~Struct() {
            std::cout << s_str << " " 
            << "Struct was distruct....by!" << std::endl;
        }
};
#endif