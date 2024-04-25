#pragma once
#include "Train.h"
class Express :
    public Train
{
private:
    int mcountPlaces = 0;
public:
    Express() = default;
    Express(const int countPlaces, const int countCarriages, const int maxSpeed);
    virtual ~Express() = default;
    void Show() const override;
    void SetCountPlaces(const int countPlaces);
    int GetCountPlaces() const;
};

