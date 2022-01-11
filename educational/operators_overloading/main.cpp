#include <iostream>

class A{
    int x;
public:
    A(int x):x(x){}
    A() = default;
    const int getX() const{return x;}

     A operator-() const{   //без первого const можно будет записать a1+a2 = 3; что в корне неправильно
        A neg;
        neg.x = -(this->x);
        return neg;
    }

    A& operator++(int){
        A temp(*this);
        this->x++;
        return temp;
    }

    A& operator=(const A &rv){
        if(&rv == this) return *this;
        x = rv.x;
        return *this;
    }

    A& operator+=(const A &a){
        this->x+=a.x;
        return *this;
    }
    friend const A operator+(const A&, const A&);
    friend std::ostream& operator<< (std::ostream&, const A &);

    bool operator< (const A& a) const{
        if(this->x < a.x) return true;
        else  return false;
    }

    bool operator> (const A& a) const{
        return a < *this;
    }

    bool operator== (const A &a) const{
        return !(*this < a || *this > a);
    }

    bool operator!= (const A& a) const{
        return !(a==*this);
    }
};

std::ostream& operator<< (std::ostream& out, const A& rv) {
    out << rv.x;
    return out;
}

const A operator+(const A& x, const A& y){
     A sum = x;
    return sum += y;
}

int main()
{
    A a0(10);
//    A a10 = -a0;
a0 = -a0;
    A a1(1), a2(2), a3(3), a4(4);
    std::cout <<a0<<std::endl;
    std::cout <<std::boolalpha<< (a0 > a4);
    return 0;
}