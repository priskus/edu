#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>

int main() {

    std::future<int> future = std::async(std::launch::deferred,
    [](int a){
    int c = a;
    for(int i = 0; i < 3; ++i) { c ++; std::this_thread::sleep_for(std::chrono::seconds(1));}
    return c;
    },
    10
    );


    int res = future.get();
    std::cout << res;

}