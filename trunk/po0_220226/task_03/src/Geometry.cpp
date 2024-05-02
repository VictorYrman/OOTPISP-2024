#include "Geometry.h"
#include <iostream>

Geometry::Geometry(const float _volume, const float _area) : volume(_volume), area(_area){}

void Geometry::SetVolume(const float _volume) {
	volume = _volume;
}

float Geometry::GetVolume() const {
	return volume;
}

void Geometry::SetArea(const float _area) {
	area = _area;
}

float Geometry::GetArea() const {
	return area;
}

void Geometry::CountVolume() {

}

void Geometry::CountArea() {

}

void Geometry::Print() const {
	std::cout << "Volume: " << volume << std::endl;
	std::cout << "Area: " << area << std::endl;
}

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