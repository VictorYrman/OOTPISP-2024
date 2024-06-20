#pragma once
#include "MathError.h"

class OverflowError : public MathError {
public:
    OverflowError();
    bool operator==(const OverflowError& other) const;
};
