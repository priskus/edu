#include <iostream> // For std::cout
#include <memory> // For std::weak_ptr, std::shared_ptr, std::make_shared
#include <vector>
#include <cstring>


//vector<> может быть параметризирован любым типом
//который указываем при создании объекта типа Container
template <typename T, template<typename> typename Container = std::vector>
struct Stack {
    Container<T> c;            
    Container<int> c1;
};

template <typename T, typename Container = std::vector<int>>
struct Stack1 {
    Container c;                          
                                    //Запись Container изначально подразумевает в себе vector<T>, может и std::vector<int>
                                    //то есть мы фиксируем тип Container, и тут он уже не шаблонный парамерт шаблона
                                    //но это значение по умолчанию, и мы можем указать любой тип Container
                                    //хоть vector<string>

    // Container<int> c1;              //ошибка, лишнее <int>
};

int main(){

    int x = 0;
//    array<int, x> a;
Stack1 <int, std::vector<std::string>> a;
    return 0;
}