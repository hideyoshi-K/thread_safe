#include <iostream>
#include <thread>
#include <thread_safe_queue.hpp>

void executeThreads(int threadNum)
{
    std::vector<std::thread> threads;

    std::queue<int> queue;
    auto add = [&]() {
        for (int i = 0; i < 1000; i++) {
            queue.push(i);
        }
    };

    std::cout << "thread num:" << threadNum << std::endl;
    for (int i = 0; i < threadNum; i++) {
        threads.push_back(std::thread(add));
    }
    for (auto& th : threads) {
        th.join();
    }
    std::cout << "queue size = " << queue.size() << std::endl;
}

void executeThreadsSafe(int threadNum)
{
    thread_safe::Queue<int> queue;
}

int main(int argc, char* argv[])
{
    for (int i = 0; i < 10; i++) {
        //executeThreads(i);
        executeThreadsSafe(i);
    }
    
    return 0;
}
