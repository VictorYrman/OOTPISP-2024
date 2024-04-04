# Лабораторная работа №1 #

## Классы и объекты в С++ ##

## Вариант 11 ##
 

## Цель работы ##
Получить практические навыки реализации классов на С++.


### Блоки с кодом реализации конструкторов и деструктора ###
```c++

Person::Person() 
{

	cout << "The object " << this << " was created using the default constructor!" << endl;
}

Person::Person(const std::string& name, const i{nt age, const int sex)
	: mname(name), mage(age), msex(sex)
{

	cout << "The object " << this << " was created using a constructor with parameters!" << endl;
}

```

### Фрагмент программы, показывающий использование указателя на объект и указателя на функцию ###

#### Указатель на объект ####

```c++

auto person4 = std::make_unique<Person>();
	person4->SetName(name);
	person4->SetAge(age);
	person4->SetSex(sex);
	person4->Print();

```

#### В переменной person4 содержится адрес объекта. Затем вызывается метод SetName, SetAge, SetSex, Print класса Person. Методы SetName, SetAge, SetSex устанавливают значения полей name, age, sex, а метод Print выводит на консоль значения полей. ####

#### Указатель на функцию ####

```c++

void(Person:: * print)() const;
destroy = &Person::Print;

Person person3;
(person3.*print)();

```

#### Адрес функции Destroy записывается в указатель на функцию. Затем объект person3 разыменовывает адрес функции Destroy и вызывает её. ####
