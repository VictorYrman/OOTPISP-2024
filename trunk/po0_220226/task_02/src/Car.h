#pragma once
#include "Transport_Vehicle.h"
#ifndef CARH
#define CARH

class Car :
    public Transport_Vehicle
{
private:
    std::string mmark = "";
public:
    Car() = default;
    Car(const std::string& mark, const int maxSpeed);
    void Show() const override;
    void SetMark(const std::string& mark);
    std::string GetMark() const;
};

#endif