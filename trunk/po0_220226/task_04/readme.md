
# Лабораторная работ №4 #

## Шаблоны классов ##

## Вариант 11 ##

## Цель работы ##
Создание консольного приложения, состоящегоиз нескольких файлов в системе программирования Visual Studio. Реализация шаблона класса-контейнера.

### Перегрузка операций ввода/вывода в классе списка ###

```c++
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
```

### Перегрузка операторов ввода/вывода в классе деньги ###

```c++
std::ostream& operator<<(std::ostream& out, const Cash& a)
{
    out << a.GetRubles() << "," << a.GetCopecks() << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Cash& a)
{
    std::cout << "Enter amount of rubles" << std::endl;
    in >> a.rubles;
    std::cout << "Enter amount of copecks" << std::endl;
    in >> a.copecks;
    return in;
}
```

### Перегрузка оператора + для сложения элементов ###

```c++
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
```

### Перегрузка оператора () для определения размера списка ###

```c++
int operator()() const
    {
        return static_cast<int>(Size());
    }
```

### Перегрузка оператора [] для обращения к элементу по индексу ###

```c++
const T& operator[](const size_t index) const
    {
        return elements[index];
    }
```






