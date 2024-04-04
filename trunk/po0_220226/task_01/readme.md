# ������������ ������ �1 #

## ������ � ������� � �++ ##

## ������� 11 ##
 

## ���� ������ ##
�������� ������������ ������ ���������� ������� �� �++.


### ����� � ����� ���������� ������������� � ����������� ###
```c++

Person::Person() {
	name = "";
	age = 0;
	sex = 0;

	cout << "The object " << this << " was created using the default constructor!" << endl;
}

Person::Person(string name, int age, int sex) {
	this->name = name;
	this->age = age;
	this->sex = sex;

	cout << "The object " << this << " was created using a constructor with parameters!" << endl;
}

Person::Person(Person const& person) {
	this->name = person.name;
	this->age = person.age;
	this->sex = person.sex;

	cout << "The object " << this << " was created using the copy constructor!" << endl;
}

Person::~Person()
{
	cout << "Destructor was called by " << this << endl;
}

```

### �������� ���������, ������������ ������������� ��������� �� ������ � ��������� �� ������� ###

#### ��������� �� ������ ####

```c++

Person* person4 = new Person();
	person4->SetName(name);
	person4->SetAge(age);
	person4->SetSex(sex);
	person4->Print();

```

#### � ���������� person4 ���������� ����� �������. ����� ���������� ����� SetName, SetAge, SetSex, Print ������ Person. ������ SetName, SetAge, SetSex ������������� �������� ����� name, age, sex, � ����� Print ������� �� ������� �������� �����. ####

#### ��������� �� ������� ####

```c++

void(Person:: * destroy)();
destroy = &Person::Destroy;

Person person3;
(person3.*destroy)();

```

#### ����� ������� Destroy ������������ � ��������� �� �������. ����� ������ person3 �������������� ����� ������� Destroy � �������� �. ####