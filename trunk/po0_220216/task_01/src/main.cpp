#include <iostream>
#include "Empl.h"
#include <array>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	Empl person1;
	Empl person2("Валерий", 61, 15);
	person2.printInfo();

	std::array<Empl, 3> group = {Empl("Макс", 22, 2), Empl("Игнат", 34, 7), Empl("Виктор", 81, 57)};

	group[0].setName("Олег");

	group[0].printInfo();

	Empl person4("Валерия", 44, 12);
	void (Empl::*pf)() const = &Empl::printInfo; // использования указателя на метод класса
	(person4.*pf)();
}
