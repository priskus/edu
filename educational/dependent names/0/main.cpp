#include <iostream>
#include <vector>

template <typename T>
struct S{
    using X = T;
};

int a = 0;

template <>
struct S<int>{
    static int X;
};

template <typename T>
void f(){
    typename S<T>::X * a;    //в зависимости от Т эта строка может быть либо declaration, либо expression
                    //по умолчанию компилятор считает, что S<T>::X - это имя переменной
                    //и тогда это expression умножения X на a
                    //чтобы он воспринимал это как тип, перед ним нужно написать слово typename
                    //и тогда это declaration указателя
                    //X - зависимое имя
 //компилятор должен до шаблонной подстановки уметь решать: это имя переменной или имени
 //потому что он должен распарсить синтаксис
 
}

int main() {

//    f<int>();   //скомпилируется без typename в f()
    f<double>();  //скомпилируется с typename в f()
}

