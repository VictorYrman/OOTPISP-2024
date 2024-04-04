# ������������ ������ �1 #

## ������ � ������� � �++ ##

## ������� 6 ##
 

## ���� ������ ##
�������� ������������ ������ ���������� ������� �� �++.


### ����� � ����� ���������� ������������� � ����������� ###
```c++
Exam::Exam(const char *name, const int date, const int grade)
	: _studentName(std::make_unique<std::string>(name)), _date(date), _grade(grade)
{
	std::cout << "The constructor with parameters is called " << this << std::endl;
}

Exam::Exam()
{
	std::cout << "A constructor without parameters is called " << this << std::endl;
}

```

### �������� ���������, ������������ ������������� ��������� �� ������ � ��������� �� ������� ###

#### ��������� �� ������ ####

```c++
a->Print();
```

#### � ���������� � ���������� ����� �������. ����� ���������� ����� Print ������ Exam. ����� ������� � ������� ���� ������� �. ####

#### ��������� �� ������� ####

```c++
void (Exam::*pf)() const = &Exam::Print;

std::array<Exam, 3> firstGroup = {
    Exam("Victor", 1, 10),
    Exam("Vitaliy", 1, 10),
    Exam("Dima", 1, 10)};

for (int i = 0; i < 3; i++)
{
    (firstGroup[i].*pf)();
}
```

#### ����� ������� print ������������ � ��������� �� �������. ����� ������ ������� ������� �������������� ��������� � �������� ������� Print ####