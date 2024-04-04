#ifndef PERSONH
#define PERSONH

#include <string>

class Person {
private:
	std::string mname = "";
	int mage = 0;
	int msex = 0;

public:
	Person();
	Person(const std::string& name, const int age, const int sex);
	Person(Person const& person) = delete;
	Person& operator = (const Person&) = delete;
	void SetName(const std::string& name);
	void SetAge(const int age);
	void SetSex(const int sex);
	std::string GetName() const;
	int GetAge() const;
	int GetSex() const;
	void Print() const;
};

#endif