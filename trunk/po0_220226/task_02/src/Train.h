#pragma once
#include "Transport_Vehicle.h"
#ifndef TRAINH
#define TRAINH

class Train :
    public Transport_Vehicle
{
private:
    int mcountCarriages = 0;
public:
    Train() = default;
    Train(const int countCarriages, const int maxSpeed);
    void Show() const override;
    void SetCountCarriages(const int countCarriages);
    int GetCountCarriages() const;
};

#endif
