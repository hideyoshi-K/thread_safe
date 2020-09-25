#include <mutex>
#include <queue>

namespace thread_safe
{
    template<class T>
    class Queue
    {
    public:
        Queue() {}
        ~Queue() {}

        void push(T val)
        {
            std::lock_guard<std::mutex> lock(m_mtx);
            m_queue.push(val);
        }

        void pop(T& val)
        {
            std::lock_guard<std::mutex> lock(m_mtx);
            if (m_queue.empty()) {
                throw std::exception("empty queue");
            }

            val = m_queue.front();
            m_queue.pop();
        }

    private:
        std::mutex    m_mtx;
        std::queue<T> m_queue;
    };
}
