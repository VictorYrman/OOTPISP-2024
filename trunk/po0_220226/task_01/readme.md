# Лабораторная работа №1 #

## Классы и объекты в С++ ##

## Вариант 11 ##
 

## Цель работы ##
Получить практические навыки реализации классов на С++.


### Блоки с кодом реализации конструкторов и деструктора ###
```c++

Person::Person() {
	name = "";
	age = 0;
	sex = 0;

	cout << "The object " << this << " was created using the default constructor!" << endl;
}

Person::Person(string name, int age, int sex) {
	this->name = name;
	this->age = age;
	this->sex = sex;

	cout << "The object " << this << " was created using a constructor with parameters!" << endl;
}

Person::Person(Person const& person) {
	this->name = person.name;
	this->age = person.age;
	this->sex = person.sex;

	cout << "The object " << this << " was created using the copy constructor!" << endl;
}

Person::~Person()
{
	cout << "Destructor was called by " << this << endl;
}

```

### Фрагмент программы, показывающий использование указателя на объект и указателя на функцию ###

#### Указатель на объект ####

```c++

Person* person4 = new Person();
	person4->SetName(name);
	person4->SetAge(age);
	person4->SetSex(sex);
	person4->Print();

```

#### В переменной person4 содержится адрес объекта. Затем вызывается метод SetName, SetAge, SetSex, Print класса Person. Методы SetName, SetAge, SetSex устанавливают значения полей name, age, sex, а метод Print выводит на консоль значения полей. ####

#### Указатель на функцию ####

```c++

void(Person:: * destroy)();
destroy = &Person::Destroy;

Person person3;
(person3.*destroy)();

```

#### Адрес функции Destroy записывается в указатель на функцию. Затем объект person3 разыменовывает адрес функции Destroy и вызывает её. ####
