#pragma once
#include "Geometry.h"
#ifndef CONEH
#define CONEH

class Cone :
    public Geometry
{
private:
    float radius = 0.00;
    float height = 0.00;

public:
    Cone() = default;
    Cone(const float _radius, const float _height);
    ~Cone() = default;

    void SetRadius(const float _radius);
    float GetRadius() const;
    void SetHeight(const float _height);
    float GetHeight() const;

    void CountVolume() override;
    void CountArea() override;
    void Print() const override;

    void operator=(const Cone right);
    bool operator==(const Cone right) const;
    bool operator!=(const Cone right) const;
};

#endif