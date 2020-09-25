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
    std::vector<std::thread> threads;

    thread_safe::Queue<int> queue;
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

int main(int argc, char* argv[])
{
    for (int i = 0; i < 5; i++) {
        //executeThreads(i);
        executeThreadsSafe(i);
    }

    thread_safe::Queue<double> que;
    for (int i = 10; i > 0; i--) {
        que.push((double)i / 100.0);
    }
    while (que.size() > 0) {
        double val;
        que.pop(val);
        std::cout << val << ", " << que.size() << std::endl;
    }
    
    return 0;
}
