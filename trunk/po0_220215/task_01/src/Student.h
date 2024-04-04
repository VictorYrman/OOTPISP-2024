#pragma once
#include <cstring>
#include <iostream>
const int LNAME = 100;
class STUDENT {
	char name[LNAME];//name
	int kurs;//course
	bool sex;//sex
public:
	STUDENT();
	STUDENT(const char* n, int k, bool s);
	STUDENT& operator=(const STUDENT& p);
	void Set(const char* n, int k, bool s);
	void SetName(const char* n);
	void SetKurs(int k);
	void SetSex(bool s);
	void Show() const;
	char* GetName();
	int GetKurs() const;
	bool GetSex() const;
	~STUDENT();
};
