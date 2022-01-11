#include <iostream>
#include <memory>
#include <vector>
#include <cstring>

template<typename T>
void f(T){}

template<typename T>//неудачная попытка специализации ф-ции
void f<T*>(T){}

template<typename T>//специализация ф-ции заменятеся ее перегрузкой
void f(T*){}


int main(){

    return 0;
}