#pragma once

#include <iostream>
#include <memory>
#include <vector>

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
        for (const auto& e : elements)
        {
            if (e == element)
            {
                return true;
            }
        }
        return false;
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

    List<T> operator+(const List<T>& other) const
    {
        List<T> result;
        size_t maxSize = std::max(this->Size(), other.Size());
        for (size_t i = 0; i < maxSize; i++)
        {
            if (i < this->Size() && i < other.Size())
            {
                result.Add(this->elements[i] + other.elements[i]);
            }
            else if (i < this->Size())
            {
                result.Add(this->elements[i] + static_cast<T>(0));
            }
            else
            {
                result.Add(other.elements[i]);
            }
        }
        return result;
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