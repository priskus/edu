#include <iostream>

void f(){
    std::cout << "f\n";
    throw 1;
    std::cout << "f end";
}

void g(){
    f();
    std::cout << "g";
}

int main(){
   try{
       g();
   }
   catch (...){
       std::cout << "caught\n";
   }

}