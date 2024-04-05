#include <iostream>
#include "Person.h"
#include <vector>
#include <memory>

int main()
{
	std::string name;
	std::cout << "Enter your name: ";
	std::cin >> name;

	int age;
	std::cout << "Enter your age: ";
	std::cin >> age;

	int sex;
	std::cout << "Enter your sex (1 - male, 2 - female): ";
	std::cin >> sex;

	Person person1(name, age, sex);
	person1.Print();

	void(Person:: * print)() const;
	print = &Person::Print;

	std::vector <Person*> persons;
	persons.push_back(&person1);

	Person person3;
	persons.push_back(&person3);

	(person3.*print)();

	persons[1]->Print();

	auto person4 = std::make_unique<Person>();
	person4->SetName(name);
	person4->SetAge(age);
	person4->SetSex(sex);
	person4->Print();
}

