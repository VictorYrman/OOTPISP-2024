#include "Express.h"
#include <iostream>

Express::Express(const int countPlaces, const int countCarriages, const int maxSpeed) : Train(countCarriages, maxSpeed), mcountPlaces(countPlaces) {
    this->Add();
}

void Express::SetCountPlaces(const int countPlaces) {
    mcountPlaces = countPlaces;
}
int Express::GetCountPlaces() const {
    return mcountPlaces;
}

void Express::Show() const {
    std::cout << "Count of places: " << this->GetCountPlaces() << std::endl;
    std::cout << "MaxSpeed: " << this->GetMaxSpeed() << std::endl;
    std::cout << "Express: " << this << std::endl;
}