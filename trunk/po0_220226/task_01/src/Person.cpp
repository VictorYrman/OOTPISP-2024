#include "Person.h"
#include <iostream>


Person::Person() 
{
	std::cout << "The object " << this << " was created using the default constructor!" << std::endl;
}

Person::Person(const std::string& name, const int age, const int sex)
: mname(name), mage(age), msex(sex){

	std::cout << "The object " << this << " was created using a constructor with parameters!" << std::endl;
}

void Person::SetName(const std::string& name) {
	this->mname = name;
}

void Person::SetAge(const int age) {
	this->mage = age;
}

void Person::SetSex(const int sex) {
	this->msex = sex;
}

std::string Person::GetName() const {
	if (this->mname == "")
		return "Null Value";
	else
		return this->mname;
}

int Person::GetAge() const {
	if (this->mage == 0)
		return -1;
	else
		return this->mage;
}

int Person::GetSex() const {
	if (this->msex == 0)
		return -1;
	else
		return this->msex;
}

void Person::Print() const {
	std::cout << "Name: " << this->GetName() << std::endl;
	std::cout << "Age: " << this->GetAge() << std::endl;

	if (this->GetSex() == 1)
		std::cout << "Sex: Male" << std::endl;
	else if (this->GetSex() == 2)
		std::cout << "Sex: Female" << std::endl;
	else
		std::cout << "You aren't a person!" << std::endl;
}
