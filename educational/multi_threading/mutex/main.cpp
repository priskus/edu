#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex
#include<time.h>

std::mutex mtx;           // mutex for critical section
std::mutex mtx1;
void print_block (int n, char c) {

    mtx.lock();
    for (int i=0; i<n; ++i)
    {
        std::cout << c;
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10));
    }
    std::cout << '\n';
    mtx.unlock();
}

void print_flock (int n, char c) {

    mtx1.lock();
    for (int i=0; i<n; ++i)
    {
        std::cout << c;
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10));
    }
    std::cout << '\n';
    mtx1.unlock();
}

int main ()
{
    std::thread th1 (print_block,50,'*');
    std::thread th2 (print_flock,50,'$');

    th1.join();
    th2.join();

    return 0;
}