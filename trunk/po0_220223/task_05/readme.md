
# Лабораторная работа №5 #

## Последовательные контейнеры библиотеки STL ##

## Вариант 8 ##
 

## Цель работы ##
Создание консольного приложения, состоящего из нескольких файлов в системе программирования Visual Studio. Использование последовательных контейнеров библиотеки STL в ОО программе.

### Задания для первой и второй задачи ###
```c++

template <typename T>
void insertElementAtPosition(std::deque<T> &deq, const T &value, size_t position)
{
    if (auto it = std::ranges::find(deq, value); it != deq.end() && position <= deq.size())
    {
        deq.insert(deq.begin() + position, *it);
    }
}

template <typename T>
void adjustElementsByDifference(std::deque<T> &deq)
{
    if (!deq.empty())
    {
        auto [minIt, maxIt] = std::ranges::minmax_element(deq);
        T difference = *maxIt - *minIt;

        std::ranges::for_each(deq, [difference](T &elem)
                              { elem -= difference; });
    }
}

template <typename T>
void insertElementAtPosition(std::queue<T> &q, const T &value, size_t position)
{
    std::vector<T> elements;
    while (!q.empty())
    {
        elements.push_back(q.front());
        q.pop();
    }

    if (auto it = std::ranges::find(elements, value); it != elements.end() && position <= elements.size())
    {
        elements.insert(elements.begin() + position, *it);
    }

    for (const auto &elem : elements)
    {
        q.push(elem);
    }
}

template <typename T>
void removeElement(std::queue<T> &q, const T &value)
{
    std::queue<T> tempQueue;
    while (!q.empty())
    {
        if (q.front() != value)
        {
            tempQueue.push(q.front());
        }
        q.pop();
    }
    q = std::move(tempQueue);
}

template <typename T>
void adjustElementsByDifference(std::queue<T> &q)
{
    if (!q.empty())
    {
        std::vector<T> elements;
        while (!q.empty())
        {
            elements.push_back(q.front());
            q.pop();
        }

        auto [minIt, maxIt] = std::ranges::minmax_element(elements);
        T difference = *maxIt - *minIt;

        for (auto &elem : elements)
        {
            elem -= difference;
        }

        for (const auto &elem : elements)
        {
            q.push(elem);
        }
    }
}

```

### Задания для третьей задачи ###

```c++

bool Figures::operator==(const Figures& right) const
{
    if (this->area == right.area && this->perimeter == right.perimeter)
        return true;
    else return false;
}
}
```

