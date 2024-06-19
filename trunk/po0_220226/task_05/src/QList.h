#pragma once

#include <queue>
#include <iostream>
#include <stdexcept>

template <typename T>
class QList
{
private:
    std::queue<T> elements;

public:
    QList() = default;
    ~QList() = default;

    void push_back(const T &value);
    void push_front(const T &value);
    void pop_front();
    void clear();

    bool empty() const { return elements.empty(); }
    size_t getSize() const { return elements.size(); }
    T &front() { return elements.front(); }
    T &back() { return elements.back(); }

    void findAverageAndAddToFront();
    bool findAndRemove(const T &key);
    void subtractMinFromAll();
};

template <typename T>
void QList<T>::push_back(const T &value)
{
    elements.push(value);
}

template <typename T>
void QList<T>::push_front(const T &value)
{
    std::queue<T> tempQueue;
    tempQueue.push(value);

    while (!elements.empty())
    {
        tempQueue.push(elements.front());
        elements.pop();
    }

    elements = std::move(tempQueue);
}

template <typename T>
void QList<T>::pop_front()
{
    if (elements.empty())
    {
        return;
    }
    elements.pop();
}

template <typename T>
void QList<T>::clear()
{
    while (!elements.empty())
    {
        elements.pop();
    }
}

template <typename T>
void QList<T>::findAverageAndAddToFront()
{
    if (elements.empty())
    {
        return;
    }

    // Calculate average
    if (elements.empty())
        return;

    auto size = static_cast<int>(elements.size());
    T sum = T();
    std::queue<T> temp = elements;

    while (!temp.empty())
    {
        sum = sum + temp.front();
        temp.pop();
    }

    T average = sum / static_cast<float>(size);

    // Add average to front
    elements.push(average);
}

template <typename T>
bool QList<T>::findAndRemove(const T &key)
{
    std::queue<T> tempQueue;

    bool found = false;
    while (!elements.empty())
    {
        T front = elements.front();
        elements.pop();

        if (front == key)
        {
            found = true;
        }
        else
        {
            tempQueue.push(front);
        }
    }

    // Restore elements from temporary queue
    elements = std::move(tempQueue);

    return found;
}

template <typename T>
void QList<T>::subtractMinFromAll()
{
    if (elements.empty())
    {
        return;
    }

    T minElement = elements.front();
    std::queue<T> tempQueue;

    // Find minimum element
    while (!elements.empty())
    {
        T front = elements.front();
        elements.pop();

        if (front < minElement)
        {
            minElement = front;
        }

        tempQueue.push(front);
    }

    // Subtract minimum element from all elements
    while (!tempQueue.empty())
    {
        T front = tempQueue.front();
        tempQueue.pop();
        elements.push(front - minElement);
    }
}
