#pragma once
#include "Geometry.h"
#ifndef BALLH
#define BALLH

class Ball :
    public Geometry
{
private:
    float radius = 0.00;

public:
    Ball() = default;
    Ball(const float _radius);
    ~Ball() = default;

    void SetRadius(const float _radius);
    float GetRadius() const;
    void CountVolume() override;
    void CountArea() override;
    void Print() const override;

    void operator=(const Ball right);
    bool operator==(const Ball right) const;
    bool operator!=(const Ball right) const;
};

#endif