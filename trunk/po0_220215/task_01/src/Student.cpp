#include "Student.h"
#include <cstring>

STUDENT::STUDENT() {
	Set("Lesha", 1, false);
	std::cout << "A parameterless constructor is called on an object " << this << std::endl;
}
STUDENT::STUDENT(const char* n, int k, bool s) {
	Set(n, k, s);
	std::cout << "A constructor with parameters is called on an object " << this << std::endl;
}
STUDENT& STUDENT::operator=(const STUDENT& p) {
	if (this != &p) {
		std::strncpy(name, p.name, LNAME);
		SetKurs(p.kurs);
		SetSex(p.sex);
		std::cout << "The copy constructor is called on the object " << this << std::endl;
	}
	return *this;
}
void STUDENT::Set(const char* n, int k, bool s) {
	SetName(n);
	SetKurs(k);
	SetSex(s);
}
void STUDENT::SetName(const char* n) {
	strcpy(name, n);
	std::cout << "Changed name of thе object " << this << std::endl;
}
void STUDENT::SetKurs(int k) {
	this->kurs = k;
	std::cout << "Changed course of thе object " << this << std::endl;
}
void STUDENT::SetSex(bool s) {
	this->sex = s;
	std::cout << "Changed sex of thе object " << this << std::endl;
}
void STUDENT::Show() const {
	std::cout << "name: " << name << ", course: " << kurs << ", sex: " << sex << std::endl;
}
char* STUDENT::GetName(){
	return this->name;
}
int STUDENT::GetKurs() const{
	return this->kurs;
}
bool STUDENT::GetSex() const{
	return this->sex;
}
STUDENT::~STUDENT()
{
	std::cout << "\nDestructor called on object " << this << std::endl;
	std::cout << "Student " << this->name << " deleted" << std::endl;
}


