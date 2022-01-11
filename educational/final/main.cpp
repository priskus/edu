#include <iostream>
#include <map>
#include <vector>

class Mine {
public:
    Mine(){
        std::cout << "generate\n";
    }

    virtual void act(){
        std::cout << "first\n";
    }

    ~Mine(){
        std::cout << "destruct\n";
    }
};

class SecondMine final: public Mine{  //запрещает наследование от класса
    void act() override final{        //запрещает переопределение метода в наследниках
        std::cout << "second\n";
    }
};

class ThirdMine : public SecondMine{  //будет ошибка
    void act() override{   //будет ошибка
        std::cout << "third\n";
    }
};

int main() {
    Mine * my = new Mine;
    delete my;
    std::cout << "done!";
    
    return 0;
}