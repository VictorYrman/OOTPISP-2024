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
    explicit Ball(const float _radius);
    Ball(const Ball& old) = delete;
    ~Ball() override = default;

    void SetRadius(const float _radius);
    float GetRadius() const;
    void CountVolume() override;
    void CountArea() override;
    void Print() const override;

    bool operator==(const Ball& right) const;
};

#endif