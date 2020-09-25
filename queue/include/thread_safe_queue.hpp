#include <mutex>
#include <queue>
#include <exception>

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
                throw std::runtime_error("empty queue");
            }

            val = m_queue.front();
            m_queue.pop();
        }

        bool empty()
        {
            std::lock_guard<std::mutex> lock(m_mtx);
            return m_queue.empty();
        }

        size_t size()
        {
            std::lock_guard<std::mutex> lock(m_mtx);
            return m_queue.size();
        }

    private:
        std::mutex    m_mtx;
        std::queue<T> m_queue;
    };
}
