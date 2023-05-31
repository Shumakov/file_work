#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// Базовый класс Анализатор
class Analizator {

public:
    virtual void check(char c) = 0;

};

//  Анализатор букв
class AnalizatorGl : public Analizator {
public:

    void check(char c) override {
        char val[] = "AaEeYyUuIiOo";
        for (int i{}; i < sizeof(val); ++i)
            if (c == val[i]) {
                std::cout << c << std::endl;
            }
    }
};

//  Анализатор цифр
class AnalizatorDig : public Analizator {
public:

    void check(char c) override {
        char val[] = "1234567890";
        for (int i{}; i < sizeof(val); ++i)
            if (c == val[i]) {
                std::cout << c << std::endl;
            }
    }
};


// Контроллер
class Controller {
public:

    std::vector<Analizator*> analizators;

    void run(const char* c, int size) {

        for (int i{}; i < size; ++i)
            for (auto a : analizators)            
                a->check(c[i]);
    }
};

int main99() {

    Controller  c;
    c.analizators.push_back(new AnalizatorGl);
    c.analizators.push_back(new AnalizatorDig);
    c.run("asdfgh33jkl2", 13);

    return 0;
}


class MyException : public std::exception {

    int type{};

public:

    MyException(int type) : 
        std::exception("Ошибка нашей функции"), 
        type{ type }{}

    int getType() const { return type; }
};

double divs(int a, int b) {

    if (b == 0) {
        throw std::exception("0");
        //std::cout << "Деление на 0 невозможно" << std::endl;
        //return -1;
    }
    double res = (double)a / b;
    if (res > 100)
        throw std::exception("1");
     return res;
}

void func(int v) {
    if (v == 0)
        throw MyException (0);
    if (v == 10)
        throw MyException (1);
    if (v == 100)
        throw MyException(2);


}


// Исключения
int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");

    try {
        func(100);
    }
    catch (int err) {
        std::cout << "Value = 0" << std::endl;
    }
    catch (const char* err) {
        std::cout << err << std::endl;
    }
    catch (MyException& err) {
        std::cout << err.what() << " " << err.getType()  << std::endl;
    }
    catch (std::exception ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;


    try {
        std::cout << divs(1000, 1) << std::endl;
    }
    catch (std::exception ex) {
        if (ex.what()[0] == '0')
            std::cout << "Деление на 0 не возможно!" << std::endl;
        else if (ex.what()[0] == '1')
            std::cout << "Результат больше 100!" << std::endl;
    }
    

    /*
    * Обработка исключительной ситуации от файлового потока
    * 
    try {
        std::string path = "test_ofstreamss.txt";
        std::ifstream ifs;
        ifs.exceptions(std::ifstream::badbit | std::ifstream::failbit);
        std::cout << "Попытка открыть файл" << std::endl;
        ifs.open(path);
        std::cout << "Файл открыт" << std::endl;
        ifs.close();
    }
    catch (std::fstream::failure ex) {
        std::cout << ex.what() << std::endl;
        std::cout << ex.code() << std::endl;
    }

    
    catch (std::exception& ex) {
        
        std::cout << ex.what() << std::endl;
    }
    
    */

    std::cout << "Afret try" << std::endl;

    return 0;






    try {
        std::string path = "test_ofstream.txt";
        std::ifstream ifs;
        ifs.exceptions(std::ifstream::badbit | std::ifstream::failbit);
        std::cout << "Попытка открыть файл" << std::endl;
        ifs.open(path);
        std::cout << "Файл открыт" << std::endl;
    }
    catch (std::fstream::failure ex) {
        std::cout << ex.what() << std::endl;
        std::cout << ex.code() << std::endl;
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}



int value{ 99 };
namespace Space1{
    int value(10);

    void print() {
        std::cout << "Print from Space1" << std::endl;
    }
}

namespace Space2 {
    int value(890);
    void print() {
        std::cout << "Print from Space2" << std::endl;
    }
}

namespace Space1 {
    int number(10);

    namespace SubSpace1 {
        int value = 283;
        void print() {
            std::cout << "Print from SubSpace1" << std::endl;
        }
                
    }
}

namespace {

    int noname = 896;
}

int main888() {

    int value{ 100 };

    int a = ::value;

    std::cout << ::value << std::endl;
    std::cout << value << std::endl;
    std::cout << Space1::value << std::endl;
    std::cout << Space2::value << std::endl;
    std::cout << Space1::SubSpace1::value << std::endl;

    Space1::print();
    Space1::SubSpace1::print();
    Space2::print();

    std::cout << noname << std::endl;
    return 0;
}
