#include "Empl.h"
#include <memory>
using namespace std;

Empl::Empl() // реализация конструктора без параметорв
{
	cout << "Вызван конструктор по умолчанию \t объект - " << this << endl;
}
Empl::Empl(const char *NAME, const int DIS, const int EXP)
	: name(std::make_unique<std::string>(NAME)), age(DIS), exp(EXP) // реализация конструктора с параметрами
{
	cout << "Вызов конструктора с параметрами\t объект - " << this << endl;
}


void Empl::setName(const char *NAME)
{
	this->name = std::make_unique<std::string>(NAME);
}

std::string Empl::getName() const
{
	return *name;
}

void Empl::setAge(const int AGE)
{
	this->age = AGE;
}

int Empl::getAge() const
{
	return age;
}

void Empl::setExp(const int EXP)
{
	this->exp = EXP;
}

int Empl::getExp() const
{
	return exp;
}

void Empl::setFull(const char *NAME, const int AGE, const int EXP)
{
	this->name = std::make_unique<std::string>(NAME);
	this->age = AGE;
	this->exp = EXP;
}

void Empl::printInfo() const
{
	cout << endl;
	cout << "Имя: " << *name << endl;
	cout << "Возраст " << this->age << endl;
	cout << "Стаж: " << this->exp << endl;
	cout << endl;
}
