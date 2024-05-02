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
    Pyramid(const Pyramid& old) = delete;
    ~Pyramid() override = default;

    void SetBaseArea(const float _baseArea);
    float GetBaseArea() const;
    void SetHeight(const float _height);
    float GetHeight() const;

    void CountVolume() override;
    void CountArea() override;
    void Print() const override;

    bool operator==(const Pyramid& right) const;
};

#endif