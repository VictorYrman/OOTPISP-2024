#pragma once
#include "Geometry.h"
#ifndef PYRAMIDH
#define PYRAMIDH

class Pyramid :
    public Geometry
{
private:
    float baseArea = 0.00;
    float height = 0.00;

public:
    Pyramid() = default;
    Pyramid(const float _baseArea, const float _height);
    ~Pyramid() = default;

    void SetBaseArea(const float _baseArea);
    float GetBaseArea() const;
    void SetHeight(const float _height);
    float GetHeight() const;

    void CountVolume() override;
    void CountArea() override;
    void Print() const override;

    void operator=(const Pyramid right);
    bool operator==(const Pyramid right) const;
    bool operator!=(const Pyramid right) const;
};

#endif