#include <iostream>
using namespace std;
struct Mother{
    int m = 1;
};

struct Father{
    int f = 2;
};

struct Son : public Mother, public Father{
    int s = 3;
};

int main() {
    Son s;
    //при множественном наследовании адреса будут разные у &s и pf
    //потому что в памяти объект Son состоит из части Mother и Father
    //и если мы хотим трактовать Son как Father, то нам нужно сместить указатель
    //на объект, не на начало объекта Son, а на Father, находящегося в в Son
    cout << &s << '\n';                         //0x62fe04
    Mother *mp = &s;
    cout << mp << endl;                         //0x62fe04
    cout << static_cast<Son*>(mp) << endl;      //0x62fe04
    Father *fp = &s;
    cout << fp << endl;                         //0x62fe08
    cout << static_cast<Son*>(fp) << endl;      //0x62fe04
}