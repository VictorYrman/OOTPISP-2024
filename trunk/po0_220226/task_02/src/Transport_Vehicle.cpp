#include "Transport_Vehicle.h"
#include <iostream>

Transport_Vehicle::Transport_Vehicle(const int maxSpeed) : mmaxSpeed(maxSpeed) {
    this->Add();
}

void Transport_Vehicle::Add() {
    if (begin == nullptr) {
        begin = this;
    }
    next = nullptr;
    if (last != nullptr) {
        last->SetNext(this);
    }
    last = this;
    last->SetNext(nullptr);
}

void Transport_Vehicle::SetNext(Transport_Vehicle* nextTransport) {
    next = nextTransport;
}

void Transport_Vehicle::SetMaxSpeed(const int maxSpeed) {
    mmaxSpeed = maxSpeed;
}
int Transport_Vehicle::GetMaxSpeed() const {
    return mmaxSpeed;
}

void Transport_Vehicle::Print() {
    Transport_Vehicle* ptr = begin;

    while (ptr != nullptr) {
        ptr->Show();
        ptr = ptr->next;
    }
}

void Transport_Vehicle::Show() const {
    std::cout << "MaxSpeed: " << mmaxSpeed << std::endl;
    std::cout << "Transport Vehicle: " << this << std::endl;
}

Transport_Vehicle* Transport_Vehicle::begin = nullptr;
Transport_Vehicle* Transport_Vehicle::last = nullptr;