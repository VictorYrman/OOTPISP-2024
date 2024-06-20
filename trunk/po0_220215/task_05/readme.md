
# Лабораторная работа №5 #

## Последовательные контейнеры библиотеки STL ##

## Вариант 1 ##
 

## Цель работы ##
Создание консольного приложения, состоящего из нескольких файлов в системе  программирования Visual Studio. Использование последовательных контейнеров библиотеки STL в ОО  программе 

### Задания для первой, второй и третьей задач ###
```c++
template <typename T>
void findMaxAndAddToBeginning(vector<T>& vec) {
    if (!vec.empty()) {
        auto maxIt = std::max_element(vec.begin(), vec.end());
        if (maxIt != vec.end()) {
            vec.insert(vec.begin(), *maxIt);
        }
    }
}

template <typename T>
void removeMinElement(vector<T>& vec) {
    if (!vec.empty()) {
        auto minIt = min_element(vec.begin(), vec.end());
        T minValue = *minIt;
        vec.erase(minIt);
    }
}

template <typename T>
void addAverageToElements(vector<T>& vec) {
    if (!vec.empty()) {
        T sum = T();
        for (const auto& elem : vec) {
            sum += elem;
        }
        T average = sum / vec.size();

        for (auto& elem : vec) {
            elem += average;
        }
    }
}
```

### Задания для четвертой и пятой задач ###

```c++
template <typename T>
void findMaxAndAddToBeginning(stack<T>& s) {
    if (!s.empty()) {
        stack<T> temp;
        T maxElement = s.top();
        temp.push(maxElement);
        s.pop();

        while (!s.empty()) {
            T current = s.top();
            s.pop();
            temp.push(current);
            if (maxElement < current) {
                maxElement = current;
            }
        }

        s.push(maxElement);

        while (!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }
    }
}

template <typename T>
void removeMinElement(stack<T>& s) {
    if (!s.empty()) {
        stack<T> temp;
        T minElement = s.top();
        s.pop();
        temp.push(minElement);

        while (!s.empty()) {
            T current = s.top();
            s.pop();
            if (current < minElement) {
                minElement = current;
            }
            temp.push(current);
        }

        while (!temp.empty()) {
            if (!(temp.top() == minElement)) {
                s.push(temp.top());
            }
            temp.pop();
        }
    }
}

template <typename T>
void addAverageToElements(stack<T>& s) {
    if (!s.empty()) {
        stack<T> temp = s;
        T current;
        int count = 0;
        T sum = T();

        while (!temp.empty()) {
            current = temp.top();
            temp.pop();
            sum += current;
            count++;
        }

        T average = sum / count;

        temp = s;
        while (!s.empty()) {
            s.pop();
        }
        while (!temp.empty()) {
            current = temp.top();
            temp.pop();
            current += (average);
            s.push(current);
        }
    }
}
```

