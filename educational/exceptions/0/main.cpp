#include <iostream>
#include <vector>

int main(){
    std::vector<int> v(10);
    try {
        throw std::out_of_range("asd");
    }
    catch (std::exception& ex) { //тут будет пойман out_of_range
        std::cout << 1; //выведется 1
        throw 1;    //а этот throw никем не будет обработан
        //и как следствие будет terminated called
    }
    catch (std::out_of_range& oor) {
        std::cout << 2;
    }
    catch (...) {
        std::cout << 3;
    }
}