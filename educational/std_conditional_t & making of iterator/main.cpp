#include <iostream>
#include <vector>
#include <list>
#include <iterator>

template <bool B, typename T, typename F>//общая версия
struct conditional {
    using type = F;
};

template <typename T, typename F>//частичная специал-ия
struct conditional<true, T, F>{
    using type = T;
};

template <bool B, typename T, typename F>//шаблонная переменная
using conditional_t = typename conditional<B, T, F>::type;

template <typename T>
class Vector {
    T* arr;
    size_t sz;

public:
    template<bool IsConst>
    class common_iterator {
        conditional_t<IsConst, const T*, T*> ptr;
    public:
        common_iterator(T *ptr): ptr(ptr) {}

        conditional_t<IsConst, const T&, T&> operator*() {
            return *ptr;
        }

        conditional_t<IsConst, const T*, T*> operator->(){
            return ptr;
        }

        common_iterator &operator++(){
            ++ptr;
            return *this;
        }
    };

    using iterator = common_iterator<true>;
    using const_iterator = common_iterator<false>;
    iterator begin() const{
        return common_iterator(arr);
    }
    iterator end() const{
        return common_iterator(arr + sz);
    }
};

int main(){
    std::conditional_t<true, int, double> x;
    x = 1;
    std::cout << typeid(x).name();


}