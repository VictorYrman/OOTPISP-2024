#include "Container.h"
#include "ContainerUnit.h"
#include "Geometry.h"
#include "Cone.h"
#include "Ball.h"
#include "Pyramid.h"
#include <iostream>
#include <memory>

void Container::ShowAll() const {
	ContainerUnit* ptr = begin;
	for (int i = 0; i < _size; i++) {
		ptr->geometry->Print();
		std::cout << std::endl;
		ptr = ptr->next;
	}
}

void Container::Add(Geometry* _geometry) {
	auto _new = std::make_unique<ContainerUnit>(_geometry);

	if (begin == nullptr) {
		begin = _new.get();
	}

	_new->next = nullptr;

	if (last != nullptr) {
		last->next = _new.get();
	}
	last = _new.get();

	_new.release();
	_size++;
}

int Container::Size() const {
	return _size;
}

Geometry* Container::operator[](const int index) {
	try
	{
		if (index < 0 || index >= _size)
			throw std::string{ "Your index is out of range\nReturn empty element" };

		ContainerUnit* ptr = begin;

		for (int i = 0; i < index; i++) {
			ptr = ptr->next;
		}

		return ptr->geometry;
	}
	catch (const std::string& error_message)
	{
		std::cout << error_message << std::endl;
		return nullptr;
	}
}