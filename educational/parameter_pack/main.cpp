#include <iostream>
#include<time.h>

template <typename ...T>
auto add(T ...args) {
  return (... + args);
};

template <int I, int ...Rest>
struct Sum
{
  static const int value = I + Sum<Rest...>::value;
};

template <int I>
struct Sum<I>
{
  static const int value = I;
};


int main()
{
  auto z = Sum<1,2,3>::value;
  std::cout << z;
   std::cout << add(1.5,2.2,3,4)<<std::endl;
}