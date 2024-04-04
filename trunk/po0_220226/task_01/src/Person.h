#ifndef PERSONH
#define PERSONH

#include <string>

using namespace std;

class Person {
private:
	string name;
	int age;
	int sex;

public:
	Person();
	Person(string name, int age, int sex);
	Person(Person const& person);
	~Person();
	void SetName(string name);
	void SetAge(int age);
	void SetSex(int sex);
	string GetName();
	int GetAge();
	int GetSex();
	void Print();
	void Destroy();
};

#endif