#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

std::mutex mtx;

void drive(){
    if(mtx.try_lock())
    {
        std::cout << std::this_thread::get_id() <<" start in try\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << std::this_thread::get_id() <<" end in try\n";
        mtx.unlock();
    }
    else
    {
        std::cout << std::this_thread::get_id() <<" outside of try\n";
    }

    mtx.lock();//mtx один на всех и пока он заблокирован в try() одним потоком
    // - остальные ждут разблокировки
    std::cout << std::this_thread::get_id() <<" raw lock\n";
    mtx.unlock();
}

int main() {
    std::thread trains[3];
    for(auto & train : trains)
        train = std::thread (drive);
    for(auto & train : trains)
    train.join();
}