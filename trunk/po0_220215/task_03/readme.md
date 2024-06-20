# Лабораторная работа №3 #

## Правила перегрузки операций и принципы обработки исключений в C++ ##

## Вариант 1 ##

## Цель работы ##
Изучение правил перегрузки операций и принципов обработки исключений в C++.

### Описание проекта ###
В данной лабораторной работе реализована иерархия классов для различных типов ошибок, таких как ошибки доступа к памяти, математические ошибки, деление на ноль и переполнение. Также реализован класс для хранения коллекции ошибок с перегрузкой оператора `[]`. Для базового класса и его потомков перегружены операции `==`, `!=` и `=`.

### Структура проекта ###

- `Error.h` и `Error.cpp`: базовый класс для всех ошибок.
- `MemoryAccessError.h` и `MemoryAccessError.cpp`: класс для ошибок доступа к памяти.
- `MathError.h` и `MathError.cpp`: базовый класс для математических ошибок.
- `DivisionByZeroError.h` и `DivisionByZeroError.cpp`: класс для ошибок деления на ноль.
- `OverflowError.h` и `OverflowError.cpp`: класс для ошибок переполнения.
- `ErrorCollection.h` и `ErrorCollection.cpp`: класс для хранения коллекции ошибок.
- `main.cpp`: демонстрационная программа, показывающая работу с классами ошибок и коллекцией ошибок.

### Обработка исключения в Error* operator[](size_t index) ###
```c++
Error* ErrorCollection::operator[](size_t index) {
    if (index >= errors.size()) {
        throw std::out_of_range("Index out of range");
    }
    return errors[index];
}
```
### Перегрузка операторов класса MemoryAccessError ###
```c++
bool MemoryAccessError::operator==(const MemoryAccessError& other) const {
    return this->message == other.message;
}
```
### Перегрузка операторов класса MathError ###
```c++
bool MathError::operator==(const MathError& other) const {
    return this->message == other.message;
}

```
### Перегрузка операторов класса DivisionByZeroError ###
```c++
bool DivisionByZeroError::operator==(const DivisionByZeroError& other) const {
    return this->message == other.message;
}

```
### Перегрузка операторов класса OverflowError ###
```c++
bool OverflowError::operator==(const OverflowError& other) const {
    return this->message == other.message;
}

```

