#include <iostream>

struct Granny{
    virtual void f(){
        std::cout << 1;
    }
};

struct Mother : public Granny{

};

struct Father : public Granny{

};

struct Son: public Mother, public Father{

};

int main() {
    Mother * pm = new Son();

    std::cout << dynamic_cast<Father*>(pm);//в runtime узнаем, что под pm на самомо деле объект Son
        //а Son можно преобразовать к Father - OK
    std::cout << static_cast<Father*>(pm);//на этапе компиляции про веряется,
    // можно ли скатовать Mother к Father - нет, поэтому ошибка
}