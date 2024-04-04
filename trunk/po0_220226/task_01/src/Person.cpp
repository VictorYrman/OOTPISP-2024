#include "Person.h"
#include <iostream>

using namespace std;

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

void Person::SetName(string name) {
	this->name = name;
}

void Person::SetAge(int age) {
	this->age = age;
}

void Person::SetSex(int sex) {
	this->sex = sex;
}

string Person::GetName() {
	if (this->name == "")
		return "Null Value";
	else
		return this->name;
}

int Person::GetAge() {
	if (this->age == 0)
		return -1;
	else
		return this->age;
}

int Person::GetSex() {
	if (this->sex == 0)
		return -1;
	else
		return this->sex;
}

void Person::Destroy() {
	this->~Person();
}

void Person::Print() {
	cout << "Name: " << this->GetName() << endl;
	cout << "Age: " << this->GetAge() << endl;

	if (this->GetSex() == 1)
		cout << "Sex: Male" << endl;
	else if (this->GetSex() == 2)
		cout << "Sex: Female" << endl;
	else
		cout << "You aren't a person!" << endl;
}

Person::~Person()
{
	cout << "Destructor was called by " << this << endl;
}
