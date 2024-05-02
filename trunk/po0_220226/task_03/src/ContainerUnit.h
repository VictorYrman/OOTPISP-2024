#pragma once
#include "Geometry.h"
#ifndef CONTAINERUNITH
#define CONTAINERUNITH

class ContainerUnit
{
public:
	ContainerUnit(Geometry* _geometry) : geometry(_geometry), next(nullptr) {}
	ContainerUnit* next;
	Geometry* geometry;
};

#endif