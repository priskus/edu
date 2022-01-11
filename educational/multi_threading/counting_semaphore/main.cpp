#include <iostream>
#include <semaphore>
#include <thread>
#include <vector>

std::counting_semaphore<2> prepareSignal(2);  
//первые два потока вызывают acquire, уменьшая счетчик от 2 до 0
//третий когда вызывает acquire счетчик оказывается равен 0
//и он ждет пока счетчик станет больше нуля
//и только после этого продолжает выполнение функции

void f1() {
    prepareSignal.acquire();
    for(int i = 0; i < 10; ++i)
    {
        std::cout << "first thread." << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    prepareSignal.release();
}

void f2() {

    prepareSignal.acquire();
    for(int i = 0; i < 10; ++i)
    {
        std::cout << "second thread." << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    prepareSignal.release();

}

void f3() {

    prepareSignal.acquire();
    for(int i = 0; i < 10; ++i)
    {
        std::cout << "third thread." << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    prepareSignal.release();

}
int main() {

    std::cout << '\n';

    std::thread t1(f1);
    std::thread t2(f2);
    std::thread t3(f3);

    t1.join();
    t2.join();
    t3.join();
    std::cout << '\n';

}