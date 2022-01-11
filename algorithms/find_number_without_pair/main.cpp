#include <iostream>
#include <vector>
//В последовательности записаны целые числа. 
// Одно из чисел встречается ровно один раз, остальные — по два раза. 
// Найти число, которое встречается один раз.
int main(){

  std::vector<int> m = {1,2,3,1,4,2,5,6,3,7,8,4,9,5,6,7,8};
  auto it1 = m.begin();
  auto it2 = it1;
  int buf = m[0];
  for(++it1; it1 != m.end(); ++it1)
    {
        buf ^= *it1;
    }
  std::cout << buf;

}