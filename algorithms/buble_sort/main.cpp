#include <iostream>
#include <ctime>

void sort(int *l, int *r)
{
    int lg = r - l;
    if(lg<=1)        return;

    bool flag = true;
    while(flag){
        flag = false;
        for(int *i = l; i < r; ++i)
        {
            if(*i > *(i+1)) {
                std::swap(*i, *(i + 1));
                flag = true;
            }
        }
        --r;
    }
}

int main() {
    srand (time(NULL));
    std::cout <<typeid(150).name();
    int m[10];
    for(int &n : m){
        n = rand()%11;
    }
    sort(m,m+10);
    for(int n : m) std::cout << n<<" ";
    }