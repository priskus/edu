#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable
#include <future>
using namespace std;

int main() {

    packaged_task<int(int)> task(
            [](int a){
                int c = a;
                for(int i = 0; i < 10; ++i) { c ++; this_thread::sleep_for(chrono::seconds(1));}
                return c;
            }
            );

    std::future<int> future = task.get_future();

    thread t(move(task),10);
    while(true){
        if(future.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
        { cout << "done!\n";
            int res = future.get();
            cout << res;
            break;
        }
        else
        {
            cout << "not yet!\n";
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
    t.join();
}