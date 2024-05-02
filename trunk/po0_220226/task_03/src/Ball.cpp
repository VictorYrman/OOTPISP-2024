#include "Ball.h"
#include <iostream>

Ball::Ball(const float _radius) : radius(_radius) {
	CountVolume();
	CountArea();
}

void Ball::SetRadius(const float _radius) {
	radius = _radius;
	this->CountVolume();
	this->CountArea();
}

float Ball::GetRadius() const {
	return radius;
}

void Ball::CountVolume() {
	SetVolume((4.0 / 3.0) * 3.14 * (pow(GetRadius(), 3)));
}

void Ball::CountArea() {
	SetArea(4.0 * 3.14 * (pow(GetRadius(), 2)));
}

void Ball::Print() const {
	std::cout << "Ball" << std::endl;
	std::cout << "Radius: " << radius << std::endl;
	Geometry::Print();
}

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