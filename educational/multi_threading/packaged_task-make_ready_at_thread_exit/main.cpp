#include <future>
#include <iostream>
#include <chrono>
#include <thread>
#include <utility>

void worker(std::future<void>& output)
{
    int variable = 0;
    std::packaged_task<void(int&)> my_task ([](int &action) { action=777; } );
    auto future = my_task.get_future();

    my_task.make_ready_at_thread_exit(variable); // Calls the stored task, forwarding args as its arguments,
        // just like calling its operator()
        //если написать my_task(), то просто будет вызвана ф-ция, хранящаяся в packaged_task
        //то есть packaged_task просто обертка для callable element

        //в этом месте функция в packaged_task уже отработала, о чем говорит измененное значение variable:
    std::cout << "worker: variable = " << std::boolalpha << variable << std::endl;
    auto status = future.wait_for(std::chrono::seconds(0));
    //но в future результат появится только после завершения ф-ции worker
    if (status == std::future_status::timeout)  
        std::cout << "worker: future is not ready yet" << std::endl;
    output = std::move(future);
}

int main()
{
    std::future<void> result;
    std::thread{worker, std::ref(result)}.join();
    auto status = result.wait_for(std::chrono::seconds(0));
    if (status == std::future_status::ready)
        std::cout << "main: result is ready" << std::endl;
}