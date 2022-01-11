#include <future>
#include <thread>
#include <limits>
#include <iostream>

using namespace std;
int main()
{
    std::promise<int> prom;

std::future<int> future = prom.get_future();

    function<void(size_t)> call = [&prom](size_t value)
            {
        size_t i = std::numeric_limits<size_t>::max();
        while(i--)
        {
            if(i == value)
                prom.set_value(777);
        }
            };

    std::thread thread(call, std::numeric_limits<size_t>::max() - 500);
    thread.detach();
    int res = future.get();
    cout << res;
}