
# Лабораторная работа №4 #

## Шаблоны классов ##

## Вариант 8 ##
 

## Цель работы ##
Создание консольного приложения, состоящего из нескольких файлов в системе программирования Visual Studio. Реализация шаблона класса-контейнера в C++

### Обработка исключения в Error *operator[](const int index) ###
```c++
 try
    {
        if (index < 0 || index >= _size)
            throw std::out_of_range("index out of range");

        auto ptr = std::move(head);
        for (int i = 0; i < index; i++)
        {
            ptr = std::move(ptr->next);
        }
        return ptr->date;
    }
  
```

### Перегрузка операторов класса Fires ###

```c++

bool Figures::operator==(const Figures& right) const
{
    if (this->area == right.area && this->perimeter == right.perimeter)
}
}
```

### Перегрузка операторов класса Epse ###

```c++
bool Ellipse::operator==(const Ellipse& right) const
{
    if (this->facet == right.facet)
     
}
```

### Перегрузка операторов класса Sare ###

```c++
bool Square::operator==(const Square& right) const
{
    if (this->facet == right.facet)

}
```

### Перегрузка операторов класса Teze ###

```c++
bool Trapeze::operator==(const Trapeze& right) const
{
    if (this->cargoCapacity == right.cargoCapacity)
       
}
```

