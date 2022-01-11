#include <iostream>  
#include <vector>
#include <algorithm>
//int x = 7; для глобальных переменных [&x] не нужно писать
int main() {
int x = 7;
    std::vector<int> nums {1,2,3,4,5,6,7};


    [&x](std::vector<int> v){
        for(int i : v)
            std::cout << i+x <<' ';
    }(nums);//объявили и сразу вызвали
}