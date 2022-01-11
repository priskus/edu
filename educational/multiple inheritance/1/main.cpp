#include <iostream>
using namespace std;
struct Mother{
    int a = 1;
};

struct Father{
    int a = 2;
};

struct Son : public 
Mother, public Father{
    int s = 3;
    int a = 22;
};

int main() {
    Son s;
    cout << s.a<< endl;
    cout << s.Father::a;//или просто s.a если у Son свое поле а
}