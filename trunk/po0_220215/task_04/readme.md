# Лабораторная работа №4 #

## Шаблоны классов ##

## Вариант 1 ##
 

## Цель работы ##
Создание консольного приложения, состоящего из нескольких файлов в системе  программирования Visual Studio. Реализация шаблона класса-контейнера. 

### Перегрузка оператора [] в классе Vector (доступ по индексу) ###
```c++
Time& operator[](size_t index) {
    return data[index];
}
```
### Перегрузка оператора () в классе Vector (определение размера вектора) ###
```c++
size_t operator()() const {
    return data.size();
}
```

### Перегрузка оператора + в классе Vector (прибавление константы) ###

```c++
void operator+(int value) {
    for (auto& elem : data) {
        elem += value;
    }
}
```

### Перегрузка оператора += в классе Time ###

```c++
Time& operator+=(int value) {
    int totalSeconds = minutes * 60 + seconds + value;
    minutes = totalSeconds / 60;
    seconds = totalSeconds % 60;
    return *this;
}

void operator+=(const Time& other) {
    int totalSeconds = (minutes + other.minutes) * 60 + seconds + other.seconds;
    minutes = totalSeconds / 60;
    seconds = totalSeconds % 60;
}
```

### Перегрузка операторов ввода/вывода в классе Time ###

```c++
friend std::istream& operator>>(std::istream& is, Time& time) {
    std::string input;
    is >> input;

    size_t pos = input.find(':');
    if (pos != std::string::npos) {
        try {
            int m = std::stoi(input.substr(0, pos));
            int s = std::stoi(input.substr(pos + 1));
            time.minutes = m;
            time.seconds = s;
            time.normalize();
            return is;
        }
        catch (const std::invalid_argument& e) {
        }
    }

    std::istringstream ss(input);
    ss >> time.minutes >> time.seconds;
    time.normalize();
    return is;
}

friend std::ostream& operator<<(std::ostream& os, const Time& time) {
    os << std::setw(2) << std::setfill('0') << time.minutes << ":"
        << std::setw(2) << std::setfill('0') << time.seconds;
    return os;
}
```
