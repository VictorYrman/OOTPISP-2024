#pragma once

#include <memory>
#include <iostream>
#include <stdexcept>

template <typename T>
class List
{
private:
    struct Node
    {
        T data;
        std::unique_ptr<Node> next = nullptr;
        explicit Node(const T &value) : data(value) {}
    };

    std::unique_ptr<Node> head = nullptr;
    Node *tail = nullptr;
    size_t size = 0;

public:
    List() = default;
    ~List() = default;
    bool empty() const { return size == 0; }

    void push_back(const T &value)
    {
        std::unique_ptr<Node> newNode = std::make_unique<Node>(value);
        if (tail)
        {
            tail->next = std::move(newNode);
            tail = tail->next.get();
        }
        else
        {
            head = std::move(newNode);
            tail = head.get();
        }
        ++size;
    }

    void push_front(const T &value)
    {
        std::unique_ptr<Node> newNode = std::make_unique<Node>(value);
        if (head)
        {
            newNode->next = std::move(head);
        }
        head = std::move(newNode);
        if (!tail)
        {
            tail = head.get();
        }
        ++size;
    }

    void pop_front()
    {
        if (!head)
        {
            return;
        }
        head = std::move(head->next);
        if (!head)
        {
            tail = nullptr;
        }
        --size;
    }

    void clear()
    {
        while (!empty())
        {
            pop_front();
        }
    }

    T &front() const
    {
        if (!head)
        {
            return nullptr;
        }
        return head->data;
    }

    T &back() const
    {
        if (!tail)
        {
            return nullptr;
        }
        return tail->data;
    }

    void findAverageAndAddToFront()
    {
        if (empty())
        {
            return;
        }

        T sum = 0;
        Node *current = head.get();
        while (current)
        {
            sum += current->data;
            current = current->next.get();
        }

        T average = sum / static_cast<double>(size);
        push_front(average);
    }

    bool findAndRemove(const T &key)
    {
        Node *current = head.get();
        Node *prev = nullptr;

        while (current)
        {
            if (current->data == key)
            {
                if (prev)
                {
                    prev->next = std::move(current->next);
                }
                else
                {
                    head = std::move(current->next);
                }

                if (!head)
                {
                    tail = nullptr;
                }

                --size;
                return true;
            }

            prev = current;
            current = current->next.get();
        }

        return false;
    }

    void subtractMinFromAll()
    {
        if (empty())
        {
            return;
        }

        T minElement = head->data;
        Node *current = head->next.get();

        while (current)
        {
            if (current->data < minElement)
            {
                minElement = current->data;
            }
            current = current->next.get();
        }

        current = head.get();
        while (current)
        {
            current->data -= minElement;
            current = current->next.get();
        }
    }

    void print() const
    {
        Node *current = head.get();

        while (current)
        {
            std::cout << current->data << " ";
            current = current->next.get();
        }
    }
};
