#include <iostream>
#include <string>
#include "Transport_Vehicle.h"
#include "Car.h"
#include "Train.h"
#include "Express.h"

int main()
{
    Car car1("BMW", 200);
    Train train1(10, 90);
    Express express1(100, 10, 150);
    Transport_Vehicle transport1;

    train1.SetCountCarriages(15);
    express1.SetCountPlaces(120);
    transport1.SetMaxSpeed(180);
    transport1.Add();
   
    Transport_Vehicle::Print();

    return 0;
}
