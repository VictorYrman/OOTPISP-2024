#pragma once
#include "Geometry.h"
#include "ContainerUnit.h"
#ifndef CONTAINERH
#define CONTAINERH

class Container
{
private:
	int _size = 0;
	ContainerUnit* begin;
	ContainerUnit* last;

public:
	Container() = default;
	~Container() = default;

	void ShowAll() const;
	void Add(Geometry* _geometry);
	int Size() const;
	
	Geometry* operator[](const int index);
};

#endif