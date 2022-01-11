#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

int main()
{
    std::list<int> v = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    auto i = remove_if(v.begin(),v.end(),[](int& i){return (i%2)==0;});
    v.erase(i, v.end());
    for(int& i : v) std::cout << i <<' ';
    return 0;
}