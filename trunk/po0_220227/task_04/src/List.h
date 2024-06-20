#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

template <typename T>
class List
{
public:
    List() = default;
    ~List() = default;

    void Add(const T& element)
    {
        elements.push_back(element);
    }

    void Remove(const T& element)
    {
        for (auto it = elements.begin(); it != elements.end(); ++it)
        {
            if (*it == element)
            {
                elements.erase(it);
                return;
            }
        }
    }

    bool Contains(const T& element) const
    {
        return std::ranges::any_of(elements, [&](const auto& e) {
            return e == element;
            });
    }

    size_t Size() const
    {
        return elements.size();
    }

    T& operator[](const size_t index)
    {
        return elements[index];
    }

    const T& operator[](const size_t index) const
    {
        return elements[index];
    }

    int operator()() const
    {
        return static_cast<int>(Size());
    }

    friend List<T> operator+(const List<T>& list, const int num)
    {
        List<T> res;

        for (size_t i = 0; i < list.Size(); i++)
        {
            res.Add(list.elements[i] + num);
        }

        return res;        
    }

    friend std::ostream& operator<<(std::ostream& out, const List<T>& a)
    {
        out << "{ ";
        for (const auto& e : a.elements)
        {
            out << e << " ";
        }
        out << "}";
        return out;
    }

    friend std::istream& operator>>(std::istream& in, List<T>& a)
    {
        for (int i = 0; i < a(); i++)
        {
            T temp;
            in >> temp;
            a.Add(temp);
        }
        return in;
    }

private:
    std::vector<T> elements;
};