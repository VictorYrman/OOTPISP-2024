# ������������ ������ �3 #

## ������� ���������� �������� � �������� ��������� ���������� � C++ ##

## ������� 11 ##
 

## ���� ������ ##
�������� ������ ���������� �������� � ��������� ��������� ���������� � C++. 

### ��������� ���������� ###
```c++
 Geometry* Container::operator[](const int index) {
	try
	{
		if (index < 0 || index >= _size)
			throw "Your index is out of range\nReturn empty element";

		ContainerUnit* ptr = begin;

		for (int i = 0; i < index; i++) {
			ptr = ptr->next;
		}

		return ptr->geometry;
	}
	catch (const char* error_message)
	{
		std::cout << error_message << std::endl;
		Geometry geometry;
		return &geometry;
	}
}
```

### ���������� ���������� ������ Geometry ###

```c++
void Geometry::operator=(const Geometry right) {
	this->volume = right.volume;
	this->area = right.area;
}

bool Geometry::operator==(const Geometry right) const {
	if (this->volume == right.volume && this->area == right.area)
		return true;
	else 
		return false;
}

bool Geometry::operator!=(const Geometry right) const {
	return !(*this == right);
}
```

### ���������� ���������� ������ Pyramid ###

```c++
void Pyramid::operator=(const Pyramid right) {
	this->baseArea = right.baseArea;
	this->height = right.height;
	this->SetVolume(right.GetVolume());
	this->SetArea(right.GetArea());
}

bool Pyramid::operator==(const Pyramid right) const {
	if (this->baseArea == right.baseArea && this->height == right.height)
		return true;
	else
		return false;
}

bool Pyramid::operator!=(const Pyramid right) const {
	return !(*this == right);
}
```

### ���������� ���������� ������ Ball ###

```c++
void Ball::operator=(const Ball right) {
	this->radius = right.radius;
	this->SetVolume(right.GetVolume());
	this->SetArea(right.GetArea());
}

bool Ball::operator==(const Ball right) const {
	if (this->radius == right.radius)
		return true;
	else
		return false;
}

bool Ball::operator!=(const Ball right) const {
	return !(*this == right);
}
```

### ���������� ���������� ������ Cone ###

```c++
void Cone::operator=(const Cone right) {
	this->radius = right.radius;
	this->height = right.height;
	this->SetVolume(right.GetVolume());
	this->SetArea(right.GetArea());
}

bool Cone::operator==(const Cone right) const {
	if (this->radius == right.radius && this->height == right.height)
		return true;
	else
		return false;
}

bool Cone::operator!=(const Cone right) const {
	return !(*this == right);
}
```
