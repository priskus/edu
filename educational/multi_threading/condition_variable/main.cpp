#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void print_id (int id) {
  std::unique_lock<std::mutex> lck(mtx);//блочит mtx
    std::cout << "thread " << id << " before wait\n";
  while (!ready) cv.wait(lck);  //поток останавливается тут и ждёт пока 
                                // в main потоке, в ф-ции go() вызовется cv.notify_all()
                                //в то же время тут mutex освобождается
                                //но потом после cv.notify_all() mutex снова блокируется, чтобы не было 
                                //одновременного доступа в критическую область
  // ...

  std::cout << "thread " << id << " after wait\n";
}

void go() {
    std::cout << "start in go\n";
  std::unique_lock<std::mutex> lck(mtx);
  ready = true;
    std::cout << "in go before notify\n";
    std::this_thread::sleep_for(std::chrono::seconds(4));
  cv.notify_all();  //разблокировка всех потоков, кто наткнулся на wait()
}

int main ()
{
  std::thread threads[10];
  // spawn 10 threads:
  for (int i=0; i<10; ++i)
    threads[i] = std::thread(print_id,i);

  std::cout << "10 threads ready to race...\n";
  go();                       // go!

  for (auto& th : threads) th.join();

  return 0;
}