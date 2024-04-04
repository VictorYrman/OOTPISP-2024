
# Лабораторная работа №1 #

## Классы и объекты в С++ ##

## Вариант 1 ##
 

## Цель работы ##
Получить практические навыки реализации классов на С++.


### Определение пользовательского класса ###
```c++
class STUDENT {
	char name[LNAME];//имя
	int kurs;//курс
	bool sex;//пол
public:
	STUDENT(); //конструктор без параметров
	STUDENT(char* n, int k, bool s); //конструктор с параметрами
	STUDENT(const STUDENT& p); //конструктор копирования
	void Set(char* n, int k, bool s); //функция для установки всех данных
	void SetName(char* n); //функция для установки имени
	void SetKurs(int k); //функция для установки курса
	void SetSex(bool s); //функция для установки пола
	void Show(); //функция для вывода данных
	char* GetName(); //функция для получения имени
	int GetKurs(); //функция для получения курса
	bool GetSex(); //функция для получения пола
	~STUDENT(); //деструктор
};
```

### Блоки с кодом реализации конструкторов и деструктора ###
```c++
STUDENT::STUDENT() {
	char n[6] = "Lesha";
	strcpy_s(name, 100, n);
	kurs = 1;
	sex = 0;
	std::cout << "A parameterless constructor is called on an object " << this << std::endl;
}
STUDENT::STUDENT(char* n, int k, bool s) {
	strcpy_s(name, 100, n);
	kurs = k;
	sex = s;
	std::cout << "A constructor with parameters is called on an object " << this << std::endl;
}
STUDENT::STUDENT(const STUDENT& p) {
	strcpy_s(name, 100, p.name);
	kurs = p.kurs;
	sex = p.sex;
	std::cout << "The copy constructor is called on the object " << this << std::endl;
}
STUDENT::~STUDENT()
{
	std::cout << "\nDestructor called on object " << this << std::endl;
	std::cout << "Student " << name << " deleted" << std::endl;
}

```

### Фрагмент программы, показывающий использование указателя на объект и указателя на функцию ###

#### Указатель на объект ####

```c++
void (STUDENT:: * fptr) (char*, int, bool);
fptr = &STUDENT::Set;

STUDENT first(name, 3, 0);
STUDENT* pStudent;
pStudent = &first;

pStudent->Show();
(pStudent->*fptr)(name2, 2, 1); 
```

#### Создаётся указатель fptr на функцию класса STUDENT с тремя параметрами char*, int и bool и указатель pStudent на экземпляр класса STUDENT. Им присваиваются адреса функции Set и экземпляра first соответственно. Далее для pStudent вызывается метод Show и затем этот же разыменовывает указатель fptr и вызывает функцию Set ####


