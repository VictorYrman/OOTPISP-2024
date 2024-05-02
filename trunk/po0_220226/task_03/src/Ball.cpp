#include "Ball.h"
#include <iostream>
#include <cmath>

Ball::Ball(const float _radius) : radius(_radius) {
	
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
	SetVolume(float((4.0 / 3.0) * std::numbers::pi * (pow(GetRadius(), 3))));
}

void Ball::CountArea() {
	SetArea(float(4.0 * std::numbers::pi * (pow(GetRadius(), 2))));
}

void Ball::Print() const {
	std::cout << "Ball" << std::endl;
	std::cout << "Radius: " << radius << std::endl;
	Geometry::Print();
}


bool Ball::operator==(const Ball& right) const {
	if (this->radius == right.radius)
		return true;
	else
		return false;
}