#include "mylib.hpp"

int return_one()
{
    return 1;
}

void arr_init(int* arr)
{
    for (int i = 0; i < 3; ++i) {
        arr[i] = i;
    }
}

ClassThatUsesDB::ClassThatUsesDB(DBConnnetion* connetion)
: _connection(connetion)
{

}

void ClassThatUsesDB::openConnection()
{
    if (_connection->open("USER_DB")) {
        return;
    }

    throw std::runtime_error ("Some erorr(connetion)");
}

void ClassThatUsesDB::useConnection()
{
    _connection->execQuery();
}

void ClassThatUsesDB::clousConnection()
{
    if (!_connection->clous()) {
        return;
    }

    throw std::runtime_error ("Some erorr(clous)");
}
