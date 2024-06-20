#pragma once
#include "MathError.h"

class DivisionByZeroError : public MathError {
public:
    DivisionByZeroError();
    bool operator==(const DivisionByZeroError& other) const;
};
