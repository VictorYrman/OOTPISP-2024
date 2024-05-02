#include "Pyramid.h"
#include <iostream>
#include <cmath>

Pyramid::Pyramid(const float _baseArea, const float _height) : baseArea(_baseArea), height(_height) {
	
}

void Pyramid::SetBaseArea(const float _baseArea) {
	baseArea = _baseArea;
	this->CountVolume();
	this->CountArea();
}

float Pyramid::GetBaseArea() const {
	return baseArea;
}

void Pyramid::SetHeight(const float _height) {
	height = _height;
	this->CountVolume();
	this->CountArea();
}

float Pyramid::GetHeight() const {
	return height;
}

void Pyramid::CountVolume() {
	SetVolume(float((1.0 / 3.0) * GetBaseArea() * GetHeight()));
}

void Pyramid::CountArea() {
	SetArea(float(GetBaseArea() + (4.0 * (0.5 * (sqrt(GetBaseArea()))) * sqrt(GetHeight() * GetHeight() + (0.5 * (sqrt(GetBaseArea()))) * (0.5 * (sqrt(GetBaseArea())))))));
}

void Pyramid::Print() const {
	std::cout << "Pyramid" << std::endl;
	std::cout << "BaseArea: " << baseArea << std::endl;
	std::cout << "Height: " << height << std::endl;
	Geometry::Print();
}

bool Pyramid::operator==(const Pyramid& right) const {
	if (this->baseArea == right.baseArea && this->height == right.height)
		return true;
	else
		return false;
}