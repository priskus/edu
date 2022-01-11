#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <chrono>
#include <math.h>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int ms = 0;
bool ready = false;

void chronograph()
{
    auto s = std::chrono::high_resolution_clock::now();
    while(true) {
        ++ms;
        if(ms%1000 == 0 && ms!=0) { /*ready = true;*/ cv.notify_all(); /*ready = false;*/}
        s += std::chrono::milliseconds(1);
        
        std::this_thread::sleep_until(s);
        
    }
}

void print(){
    while(true)
    {
        std::unique_lock <std::mutex> lck(mtx);
        /*while(!ready)*/ cv.wait(lck);
        std::cout << ms <<" "<< std::this_thread::get_id()<<std::endl;
    }
}

int main ()
{
    std::thread threads[3];
    std::thread chronos = std::thread(chronograph);
    for(int i = 0; i < 3; ++i)
    {
        threads[i] = std::thread(print);
    }
    for (auto& th : threads) th.join();

    return 0;
}