
# Лабораторная работ №4 #

## Шаблоны классов ##

## Вариант 12 ##

## Цель работы ##
Создание консольного приложения, состоящегоиз нескольких файлов в системе программирования Visual Studio. Реализация шаблона класса-контейнера.

### Перегрузка операций ввода/вывода в классе List ###

```c++
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
```

### Перегрузка операторов ввода/вывода в классе Pair ###

```c++
    friend std::istream& operator>>(std::istream& in, Pair& a)
    {
        std::cout << "Enter first number(int)" << std::endl;
        in >> a.firstNumber;
        std::cout << "Enter second number(double)" << std::endl;
        in >> a.secondNumber;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Pair& a)
    {
        out << a.GetFirstNumber() << ":" << a.GetSecondNumber() << std::endl;
        return out;
    }
```

### Перегрузка оператора + класса List для добавления константы ко всем элементам ###

```c++
    friend void operator+(const List<T>& list, const int num)
    {
        for (size_t i = 0; i < list.Size(); i++)
        {
            list.elements[i] += num;
        }
    }
```

### Перегрузка оператора () класса List для определения размера списка ###

```c++
int operator()() const
    {
        return static_cast<int>(Size());
    }
```

### Перегрузка оператора [] класса List для обращения к элементу по индексу ###

```c++
const T& operator[](const size_t index) const
    {
        return elements[index];
    }
```
