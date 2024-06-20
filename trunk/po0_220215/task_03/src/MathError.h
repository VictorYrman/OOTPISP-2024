#pragma once
#include "Error.h"

class MathError : public Error {
public:
    explicit MathError(const std::string& msg);
    bool operator==(const MathError& other) const;
};
