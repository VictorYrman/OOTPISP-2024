#pragma once
#include "Geometry.h"
#ifndef CONTAINERUNITH
#define CONTAINERUNITH

class ContainerUnit
{
public:
	explicit ContainerUnit(Geometry* _geometry) : geometry(_geometry) {}
	Geometry* geometry;
	ContainerUnit* next = nullptr;
};

#endif