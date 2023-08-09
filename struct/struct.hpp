#ifndef STRUCT
#define STRUCT
#include <iostream>
#include <string>
#include <fstream>

/* app — открывает файл в режиме добавления;

   ate — переходит в конец файла перед чтением/записью;

   binary — открывает файл в бинарном режиме (вместо текстового режима);

   in — открывает файл в режиме чтения (по умолчанию для ifstream);

   out — открывает файл в режиме записи (по умолчанию для ofstream);

   trunc — удаляет файл, если он уже существует.

Можно указать сразу несколько флагов путем использования побитового ИЛИ (|).

   ifstream по умолчанию работает в режиме ios::in;

   ofstream по умолчанию работает в режиме ios::out;

   fstream по умолчанию работает в режиме ios::in ИЛИ ios::out, что означает, что вы можете выполнять как чтение содержимого файла, так и запись данных в файл.*/
struct Struct {
    private:
        std::string s_str;
        const std::string s_file {"str.txt"};
    public:
        explicit Struct(int hull) {
            std::ifstream fs;
            fs.open(s_file);
            if (fs.is_open()) {
                std::getline(fs,s_str);
                fs.close();
            }
        }
        Struct(const std::string& str) {
            s_str = std::move(str);
        }

        ~Struct() {
            std::ofstream outf;
            outf.open(s_file);
            if (outf.is_open()) {
                outf << s_str;
                outf.close();
            }
            std::cout << s_str << std::endl;
            std::cout << "Struct was seved....by!" << std::endl;
        }
};
#endif