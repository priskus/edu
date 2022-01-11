#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


struct greaterThanZero{
    bool operator()(int x){
        return x > 0;
    }
};

struct myCompare{
    bool operator()(int a, int b) const{
        return abs(a) < abs(b);
    }
};

int main ()
{
    std::vector<int> v{-1, -2, 4, 0, 3};
    cout << *find_if(v.begin(), v.end(), greaterThanZero()) << endl;

    sort(v.begin(), v.end(), myCompare());
    for (int x: v){
        cout << x << ' ';
    }
    cout << endl;


    std::set<int, myCompare> s; //по умолчанию используется компаратор std::less<int> есть еще greater
    s.insert(0);
    s.insert(-1);
    s.insert(2);

    for (int x: s){
        cout << x << ' ';
    }

    return 0;
}