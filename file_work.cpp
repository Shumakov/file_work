#include <iostream>
#include <string>
//#icclude <unistd.h>
#include <memory>
#include <fstream>
#include <filesystem>//после с++17
//#include <experimental/filesystem>


//#include <windows.h>

// std::ifstream - чтение файла
// std::ofstream - запись в файл
// std::fstream - универсальный класс для работы с файлом



// ofstream
int main1() {

    setlocale(LC_ALL, "Russian");


    std::string path = "test_ofstream.txt";
    std::ofstream o;
    o.open(path);
    if (o.is_open()) {
        int i = 6789;
        o << "Test message! " << i << "\n";
        o << 555;
        std::string message{ "\nМое сообщение для записи в файл" };
       o << message << std::endl;
       o.close();
    }
    else {
        std::cout << "Error open file " << path;
    }
    return 0;
}

// ifstream
int main2() {
    setlocale(LC_ALL, "Russian");


    std::string path = "test_ofstream.txt";
    std::ifstream ifs;
    ifs.open(path);
    if (ifs.is_open()) {

        /*
        // Чтение из файла до окончания файла
        // читаем посмвольно
        char c;
        while (!ifs.eof()){        
            ifs.get(c);
            std::cout << c << "  ";
        }*/
/*
    // Чтение из файла пока, функция чтения не вернет false
    // (поток закончился)
    // читаем посимвольно
    char c;
    while (ifs.get(c)){
        std::cout << c << "  ";
    }
    */

        /*
    // Читаем с помощью пергруженного оператора >>
    // Чтение из файла до окончания файла
    while (!ifs.eof()){
        std::string message;

        //std::cin >> message;

        ifs >> message;

        std::cout << message << std::endl;
    }*/

    // Читаем из файла построчно с помощью функции getline
    // Чтение из файла до окончания файла
        /*
    while (!ifs.eof()){
        std::string message;
        std::getline (ifs,message);
        std::cout << message <<"\n";
    }*/


    ifs.close();
    }
    else {
        std::cout << "Error open file " << path;
    }
    return 0;
}


int main3() {

    setlocale(LC_ALL, "Russian");

    //Для корректного ввода на русском языке в консоли
    // SetConsoleCP(1251)
    // SetConsoleCP(866)

    //std::ios::out запись
    //std::ios::in  чтение
    //std::ios::app добавление при записи
    //std::ios::binary работа с бинарным файлом

    std::fstream ifs ("test.txt", std::ios::out |std::ios::in | std::ios::app);
    
    if (ifs.is_open()) {
        ifs << "My first messagesdgfdfgdgfdfgdgf\n";
        ifs.close();
    }
    else {
        std::cout << " Error open file" << std::endl;
    }

    ifs.open("test.txt", std::fstream::in);
    if (ifs.is_open()) {
        while (!ifs.eof()) {
            std::string str;
            std::getline(ifs, str);
            std::cout << str << std::endl;
        }
        ifs.close();
    }
    return 0;

}

// Сохранение экземпляров обьекитов (Point) в файл
//  Класс Point 
class Point {
    int x;
    int y;
public:
    Point(int x = 0, int y = 0) :x{ x }, y{ y } {}

    // Оператор для раблоты с потоком вывода
    friend std::ostream& operator<< (std::ostream&, const Point&);

    // Оператор для раблоты с потоком ввода
    friend std::istream& operator>> (std::istream&, Point&);

};

std::ostream& operator<< (std::ostream& io, const Point& point) {
    io << point.x << " " << point.y;
    return io;
}

std::istream& operator>> (std::istream& io, Point& point) {
    io >> point.x >> point.y;
    return io;
}


// Запись в текстовый файл 
int main5() {
    setlocale(LC_ALL, "Russian");
    

    std::string path = "object.txt";
    Point point{ 10,20 };
      
    // Запись в файл
    std::fstream ifs(path, std::ios::out | std::ios::in | std::ios::app);
        if (!ifs.is_open()) {
        std::cout << "Error open file " << path;
        return 0;
    }
    ifs << point << '\n';
    ifs.close();

    // Чтения из файла
    ifs.open(path, std::fstream::out | std::fstream::in | std::fstream::app);
    if (!ifs.is_open()) {
        std::cout << "Error open file " << path;
        return 0;
    }
    Point p2;
    std::cout << p2 << std::endl;    
    ifs >> p2;
    ifs.close();
    std::cout << p2 << std::endl;

    
    return 0;
}

// Запись в бинарный файл
int main() {
    setlocale(LC_ALL, "Russian");
    

    std::string path = "object2.txt";
    Point point{ 10,20 };
    Point point1{ 40,50 };
    Point point2{ 60,70 };

    // Запись бинарного файла
    std::fstream ifs(path, std::fstream::out | std::fstream::in | std::fstream::app | std::fstream::binary);
    if (!ifs.is_open()) {
        std::cout << "Error open file " << path;
        return 0;
    }
    // Пишем в файл каждую точку  write(указатель на обьект приведенный к char,  размер нашего обьекта  )
    ifs.write((char*)&point, sizeof(Point));
    ifs.write((char*)&point1, sizeof(Point));
    ifs.write((char*)&point2, sizeof(Point));
    ifs.close();

    // чтение из файла
    ifs.open(path, std::fstream::out | std::fstream::in | std::fstream::app);
    if (!ifs.is_open()) {
        std::cout << "Error open file " << path;
        return 0;
    }
    while (true) {
        Point p;
        // read указатель на обьект приведенный к char,  размер нашего обьекта 
        ifs.read((char*)&p, sizeof(Point));
        if (ifs.eof())
            break;
        std::cout << p << std::endl;
    }
    ifs.close();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    
    ifs.open(path, std::fstream::out | std::fstream::in | std::fstream::app);
    ifs.seekg(sizeof(Point));
    Point p;
    ifs.read((char*)&p, sizeof(Point));
    std::cout << p << std::endl;
    
    return 0;
}
