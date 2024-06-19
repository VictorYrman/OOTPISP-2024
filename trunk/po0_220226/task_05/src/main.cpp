#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

#include "MyMoney.h"
#include "List.h"
#include "QList.h"
#include <queue>

template <class T>
void push_average_to_begin(std::vector<T> &vec)
{
    auto average = std::accumulate(vec.begin(), vec.end(), T());
    average = average / static_cast<float>(vec.size());

    vec.insert(vec.begin(), average);
}

template <class T>
void delete_by_key(std::vector<T> &vec, const T &key)
{
    auto elem = std::ranges::find(vec, key);
    vec.erase(elem);
}

template <class T>
void sub_min_from_vector(std::vector<T> &vec)
{
    auto min = std::ranges::min_element(vec);
    std::ranges::for_each(vec, [min](auto &i)
                          { i = i + *min; });
}

template <class T>
void q_push_average_to_begin(std::queue<T> &q)
{
    // Calculate average
    if (q.empty())
        return;

    int size = q.size();
    T sum = T();
    std::queue<T> temp = q;

    while (!temp.empty())
    {
        sum = sum + temp.front();
        temp.pop();
    }

    T average = sum / static_cast<double>(size);

    // Push average to the beginning
    std::queue<T> result;
    result.push(average);

    // Push all original elements back after average
    while (!q.empty())
    {
        result.push(q.front());
        q.pop();
    }

    q = std::move(result);
}

template <class T>
void q_delete_by_key(std::queue<T> &q, const T &key)
{
    // Delete all occurrences of key
    std::queue<T> result;
    while (!q.empty())
    {
        if (q.front() != key)
        {
            result.push(q.front());
        }
        q.pop();
    }
    q = std::move(result);
}

template <class T>
void q_sub_min_from_queue(std::queue<T> &q)
{
    // Subtract minimum element from all elements
    if (q.empty())
        return;

    // Find the minimum element
    T min = q.front();
    std::queue<T> temp = q;
    while (!temp.empty())
    {
        if (temp.front() < min)
        {
            min = temp.front();
        }
        temp.pop();
    }

    // Subtract min from each element
    std::queue<T> result;
    while (!q.empty())
    {
        result.push(q.front() + min);
        q.pop();
    }

    q = std::move(result);
}

int main()
{
    // TASK 1 //
    // -----------------------------------------------//
    std::vector<float> vec_of_floats = {1.0f, 2.0f, 4.0f, 3.3f};

    push_average_to_begin(vec_of_floats);
    delete_by_key(vec_of_floats, 1.0f);
    sub_min_from_vector(vec_of_floats);

    for (const auto &i : vec_of_floats)
    {
        std::cout << i << " ";
    }

    // -----------------------------------------------//

    // TASK 2 //
    // -----------------------------------------------//
    std::cout << std::endl;

    std::vector<MyMoney> vec_of_mymoney = {MyMoney(1.66), MyMoney(4.51), MyMoney(0.4), MyMoney(6.53)};

    push_average_to_begin(vec_of_mymoney);
    delete_by_key(vec_of_mymoney, MyMoney(6.53));
    sub_min_from_vector(vec_of_mymoney);

    for (const auto &i : vec_of_mymoney)
    {
        std::cout << i << " ";
    }

    // -----------------------------------------------//

    // TASK 3 //
    // -----------------------------------------------//
    std::cout << std::endl;

    List<double> list_of_double;
    list_of_double.push_back(1.9);
    list_of_double.push_back(1.333);
    list_of_double.push_back(2.53);
    list_of_double.push_back(0.4);
    list_of_double.push_back(5.42);

    list_of_double.findAverageAndAddToFront();
    list_of_double.findAndRemove(2.53);
    list_of_double.subtractMinFromAll();

    list_of_double.print();

    // -----------------------------------------------//

    // TASK 4 //
    // -----------------------------------------------//
    std::cout << std::endl;
    std::queue<MyMoney> somePieceOfStack;

    somePieceOfStack.push(MyMoney(1.66));
    somePieceOfStack.push(MyMoney(4.51));
    somePieceOfStack.push(MyMoney(0.4));
    somePieceOfStack.push(MyMoney(6.53));

    q_push_average_to_begin(somePieceOfStack);
    q_delete_by_key(somePieceOfStack, MyMoney(6.53));
    q_sub_min_from_queue(somePieceOfStack);

    while (!somePieceOfStack.empty())
    {
        std::cout << somePieceOfStack.front() << " ";
        somePieceOfStack.pop();
    }

    // -----------------------------------------------//

    // TASK 5 //
    // -----------------------------------------------//
    std::cout << std::endl;

    QList<float> ssetOfFloats;
    ssetOfFloats.push_back(1.9f);
    ssetOfFloats.push_back(1.333f);
    ssetOfFloats.push_back(2.53f);
    ssetOfFloats.push_back(11.0f);
    ssetOfFloats.push_back(11.0f);

    ssetOfFloats.findAverageAndAddToFront();
    ssetOfFloats.findAndRemove(11.0f);
    ssetOfFloats.subtractMinFromAll();

    while (!ssetOfFloats.empty())
    {
        std::cout << ssetOfFloats.front() << " ";
        ssetOfFloats.pop_front();
    }
}