#include <iostream> // For std::cout
#include <memory> // For std::weak_ptr, std::shared_ptr, std::make_shared
#include <vector>
#include <cstring>

template<typename T, typename U = int >
void f(T, U x = 3){
    std::cout << 1 << std::endl;
    std::cout << x << std::endl;
}

//  специализация присоединяется к шаблону, написанному выше.
//  специализация выбирается после того, как выбрана перегрузка т.е.
//  сначала выбирается template<typename T, typename U> или template<typename T>
//  а потом для выбранного шаблона, подбирается специализация.

//  и хоть для f(0,0) должна вызваться f(int, int), по факту эта специализация
//  относится к тому шаблону, что сверху от нее: template<typename T, typename U>
//  но в перегрузке функций побеждает template<typename T>
//  поэтому выведется 2

// но если закоментировать template<>, то мы получаем уже не просто специализацию 
// какой-то шаблонной ф-ции, которая описана ранее,
// а полноправную ф-цию, участвующую в перегрузке 
template<>
void f(int, int){
    std::cout << 3;
}

template<typename T>
void f(T,T){
    std::cout << 2;
}

int main(){
    f(0.5);
    return 0;
}