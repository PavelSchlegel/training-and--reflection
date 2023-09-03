#pragma once
#include <iostream>

int return_one();
void arr_init(int* arr);

class DBConnnetion 
{
public:
    virtual bool open(const std::string& db_name) = 0;
    virtual bool clous() = 0;
    virtual void execQuery() = 0;
};

class ClassThatUsesDB 
{
private:
    DBConnnetion* _connection = nullptr;
public:
    ClassThatUsesDB(DBConnnetion* connetion);
    void openConnection();
    void useConnection();
    void clousConnection();
};