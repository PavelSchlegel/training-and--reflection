#ifndef INHERITANCE
#define INHERITANCE
#include <iostream>

class X {
    public:
        void i_am() {
            std::cout << "I am X" << std::endl;        
        }
};

class Y : public X {
    public:
    //при создании Y метод будет вызван у род.
    //если предостааили свой, то выполниться дочерний
        void i_am() {
            std::cout << "I am Y" << std::endl;
        }
};

#endif