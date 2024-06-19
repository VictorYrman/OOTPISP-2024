
# Лабораторная работа №5 #

## Последовательные контейнеры библиотеки STL ##

## Вариант 11 ##
 

## Цель работы ##
Создание консольного приложения, состоящего из нескольких файлов в системе  программирования Visual Studio. Использование последовательных контейнеров библиотеки STL в ОО  программе. 

### Задания для первой и второй, третьей задачи ###
```c++
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
```

### Задания для четвертой задачи ###

```c++
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
```






