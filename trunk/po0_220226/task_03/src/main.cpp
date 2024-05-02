#include <string>
#include "ContainerUnit.h"
#include "Container.h"
#include "Geometry.h"
#include "Cone.h"
#include "Ball.h"
#include "Pyramid.h"
#include <iostream>

int main()
{
	Container arr;

	Pyramid pyr1(25.0, 5.0);
	Pyramid pyr2(16.0, 4.0);

	if (pyr1 == pyr2) {
		std::cout << "Pyramides are same" << std::endl;
	}
	else {
		std::cout << "Pyramides are different" << std::endl;
	}

	arr.Add(&pyr1);
	arr.Add(&pyr2);

	Ball ball1(5.0);
	Ball ball2;

	if (ball1 == ball2)
	{
		std::cout << "Balls are same" << std::endl;
	}
	else
	{
		std::cout << "Balls are different" << std::endl;
	}

	ball2 = ball1;

	arr.Add(&ball1);
	arr.Add(&ball2);

	Cone cone1(10.0, 5.0);
	Cone cone2(5.0, 10.0);

	if (cone1 == cone2)
	{
		std::cout << "Cones are same" << std::endl;
	}
	else
	{
		std::cout << "Cones are different" << std::endl;
	}

	arr.Add(&cone1);
	arr.Add(&cone2);

	std::cout << "Amount of geometries: " << arr.Size() << std::endl;
	arr.ShowAll();

	arr[7]->GetArea();
}