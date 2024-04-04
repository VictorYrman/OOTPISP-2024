#include <iostream>
#include "Person.h"
#include <vector>
#include <Windows.h>

using namespace std;

int main()
{
	string name;
	cout << "Enter your name: ";
	cin >> name;

	int age;
	cout << "Enter your age: ";
	cin >> age;

	int sex;
	cout << "Enter your sex (1 - male, 2 - female): ";
	cin >> sex;

	Person person1(name, age, sex);
	person1.Print();

	void(Person:: * destroy)();
	destroy = &Person::Destroy;

	vector <Person*> persons;
	persons.push_back(&person1);

	Person person2(person1);
	persons.push_back(&person2);

	Person person3;
	persons.push_back(&person3);

	(person3.*destroy)();

	persons[1]->Print();

	Person* person4 = new Person();
	person4->SetName(name);
	person4->SetAge(age);
	person4->SetSex(sex);
	person4->Print();


	system("pause");
}

