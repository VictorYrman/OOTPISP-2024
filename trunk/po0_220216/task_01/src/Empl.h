#pragma once
#include <iostream>
#include <string>
#include <memory>
const int SIZE = 20;

class Empl
{
private:
	std::unique_ptr<std::string> name;
	int age;
	int exp;

public:
	Empl(); // конструктор по умолчанию

	Empl(const char *NAME, const int DIS, const int EXP); // конструктор с параметрами

	void setName(const char *NAME); // сеттер для поля name
	std::string getName() const;	// геттер для поля name

	void setAge(const int AGE); // сеттер для поля age
	int getAge() const;			// геттер для поля age

	void setExp(const int EXP); // сеттер для поля exp
	int getExp() const;			// геттер для поля exp

	void setFull(const char *NAME, const int AGE, const int EXP); // полный сеттер для всех полей

	void printInfo() const; // метод вывода всех полей данного объекта класса
};
