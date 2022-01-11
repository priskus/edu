#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
using namespace std;

int main() {

    std::future<int> future = std::async(std::launch::async,
    [](int a){
                int c = a;
                for(int i = 0; i < 10; ++i) { c ++; this_thread::sleep_for(chrono::seconds(1));}
                return c;
            },
            10
    );
  
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
}