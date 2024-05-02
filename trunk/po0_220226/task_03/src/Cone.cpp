#include "Cone.h"
#include <iostream>
#include <cmath>

Cone::Cone(const float _radius, const float _height) : radius(_radius), height(_height) {
	
}

void Cone::SetRadius(const float _radius) {
	radius = _radius;
	CountVolume();
	CountArea();
}

float Cone::GetRadius() const {
	return radius;
}

void Cone::SetHeight(const float _height) {
	height = _height;
	CountVolume();
	CountArea();
}

float Cone::GetHeight() const {
	return height;
}

void Cone::CountVolume() {
	SetVolume(float((1.0 / 3.0) * std::numbers::pi * (pow(GetRadius(), 2)) * GetHeight()));
}

void Cone::CountArea() {
	SetArea(float(std::numbers::pi * GetRadius() * (GetRadius() + (sqrt((pow(GetRadius(), 2)) + (pow(GetHeight(), 2)))))));
}

void Cone::Print() const {
	std::cout << "Cone" << std::endl;
	std::cout << "Radius: " << radius << std::endl;
	std::cout << "Height: " << height << std::endl;
	Geometry::Print();
}

bool Cone::operator==(const Cone& right) const {
	if (this->radius == right.radius && this->height == right.height)
		return true;
	else
		return false;
}