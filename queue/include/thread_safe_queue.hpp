#include <iostream>
#include <queue>

namespace thread_safe
{
    template<class T>
    class Queue
    {
    public:
        Queue() {}
        ~Queue() {}

    private:
        std::queue<T> m_queue;
    };
}
