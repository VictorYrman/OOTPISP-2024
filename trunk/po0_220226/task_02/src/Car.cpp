#include "Car.h"
#include <iostream>

Car::Car(const std::string& mark, const int maxSpeed) : Transport_Vehicle(maxSpeed), mmark(mark) {
    this->Add();
}

void Car::SetMark(const std::string& mark) {
    mmark = mark;
}

std::string Car::GetMark() const {
    return mmark;
}

void Car::Show() const {
    std::cout << "Mark: " << this->GetMark() << std::endl;
    std::cout << "MaxSpeed: " << this->GetMaxSpeed() << std::endl;
    std::cout << "Car: " << this << std::endl;
}