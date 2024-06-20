#pragma once

#include <iostream>
#include <memory>
#include <vector>

template <typename T>
class Vvector
{
public:
    Vvector() = default;
    ~Vvector() = default;

    void addVect(const T &elmnt);
    int sizeVect() const;
    int operator()() const;
    T operator[](const int i) const;
    
    void printVect() const;

    int getСontent() const { return content; };

    
private:
    std::unique_ptr<std::vector<T>> vectorElmnt = std::make_unique<std::vector<T>>(2);
    int content = 2;
    int quantity = 0;
};

template <class T>
void Vvector<T>::addVect(const T &elmnt)
{
    if (quantity >= content)
    {
        auto newElements = std::make_unique<std::vector<T>>(content * 2);
        for (int i = 0; i < quantity; ++i)
        {
            (*newElements)[i] = (*vectorElmnt)[i];
        }

        vectorElmnt = std::move(newElements);
        content *= 2;
    }
    quantity++;
    (*vectorElmnt)[quantity] = elmnt;
}



    

template <class T>
int Vvector<T>::sizeVect() const
{
    return quantity;
}

template <class T>
int Vvector<T>::operator()() const
{
    return sizeVect();
};

template <class T>
T Vvector<T>::operator[](const int i) const
{
    return (*vectorElmnt)[i];
}

template <class T>
void Vvector<T>::printVect() const
{
    std::cout << "{ ";
    for (int i = 0; i < quantity; ++i)
    {
        std::cout << (*vectorElmnt)[i] << " ";
    }
    std::cout << "}" << std::endl;
}

