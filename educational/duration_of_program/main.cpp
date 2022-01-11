#include <chrono>
#include <iostream>
#include <thread>

class Timer {
public:
    Timer() : start(std::chrono::high_resolution_clock::now()) {}
    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end - start;
        std::cout << "Duration " << duration.count() << " s\n";
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
};

int main() {
    Timer t;
    int i = 0;
    auto s = std::chrono::high_resolution_clock::now();
    while(i < 100) {
        ++i;
        s += std::chrono::milliseconds(1);
        std::this_thread::sleep_until(s);
    }
}
