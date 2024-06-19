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

    auto size = static_cast<int>(q.size());
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
    std::vector new_vec_of_floats = { 1.0f, 2.0f, 4.0f, 3.3f };
    push_average_to_begin(new_vec_of_floats);
    delete_by_key(new_vec_of_floats, 1.0f);
    sub_min_from_vector(new_vec_of_floats);

    for (const auto& i : new_vec_of_floats)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    std::vector<MyMoney> new_vec_of_mymoney = { MyMoney(1.66), MyMoney(4.51), MyMoney(0.4), MyMoney(6.53) };

    push_average_to_begin(new_vec_of_mymoney);
    delete_by_key(new_vec_of_mymoney, MyMoney(6.53));
    sub_min_from_vector(new_vec_of_mymoney);

    for (const auto& i : new_vec_of_mymoney)
    {
        std::cout << i << " ";
    }

   
    std::cout << std::endl;

    List<double> new_list_of_double;
    new_list_of_double.push_back(1.9);
    new_list_of_double.push_back(1.333);
    new_list_of_double.push_back(2.53);
    new_list_of_double.push_back(0.4);
    new_list_of_double.push_back(5.42);

    new_list_of_double.findAverageAndAddToFront();
    new_list_of_double.findAndRemove(2.53);
    new_list_of_double.subtractMinFromAll();

    new_list_of_double.print();

    
    std::cout << std::endl;
    std::queue<MyMoney> new_piece_of_queue;

    new_piece_of_queue.push(MyMoney(1.66));
    new_piece_of_queue.push(MyMoney(4.51));
    new_piece_of_queue.push(MyMoney(0.4));
    new_piece_of_queue.push(MyMoney(6.53));

    q_push_average_to_begin(new_piece_of_queue);
    q_delete_by_key(new_piece_of_queue, MyMoney(6.53));
    q_sub_min_from_queue(new_piece_of_queue);

    while (!new_piece_of_queue.empty())
    {
        std::cout << new_piece_of_queue.front() << " ";
        new_piece_of_queue.pop();
    }

    std::cout << std::endl;

    QList<float> new_set_of_floats;
    new_set_of_floats.push_back(1.9f);
    new_set_of_floats.push_back(1.333f);
    new_set_of_floats.push_back(2.53f);
    new_set_of_floats.push_back(11.0f);
    new_set_of_floats.push_back(11.0f);

    new_set_of_floats.findAverageAndAddToFront();
    new_set_of_floats.findAndRemove(11.0f);
    new_set_of_floats.subtractMinFromAll();

    while (!new_set_of_floats.empty())
    {
        std::cout << new_set_of_floats.front() << " ";
        new_set_of_floats.pop_front();
    }
}