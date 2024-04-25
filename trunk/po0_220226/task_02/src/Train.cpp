#include "Train.h"
#include <iostream>

Train::Train(const int countCarriages, const int maxSpeed) : Transport_Vehicle(maxSpeed), mcountCarriages(countCarriages) {
    this->Add();
}

void Train::SetCountCarriages(const int countCarriage) {
    mcountCarriages = countCarriage;
}
int Train::GetCountCarriages() const {
    return mcountCarriages;
}

void Train::Show() const {
    std::cout << "Count of train carriages: " << this->GetCountCarriages() << std::endl;
    std::cout << "MaxSpeed: " << this->GetMaxSpeed() << std::endl;
    std::cout << "Train: " << this << std::endl;
}