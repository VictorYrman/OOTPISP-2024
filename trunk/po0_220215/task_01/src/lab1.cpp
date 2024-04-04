#include <iostream>
#include "Student.h"
using namespace std;

int main()
{
    void (STUDENT:: * fptr) (const char*, int, bool);
    fptr = &STUDENT::Set;

    STUDENT first("Sasha", 3, false);
    STUDENT* pStudent;
    pStudent = &first;
    first.Show();


    cout << endl;
    STUDENT second;
    second.Show();

    cout << endl;
    STUDENT third = first;
    third.Show();


    cout << endl;
    pStudent->Show();
    (pStudent->*fptr)("Masha", 2, true);
    pStudent->Show();

    cout << endl;
}
