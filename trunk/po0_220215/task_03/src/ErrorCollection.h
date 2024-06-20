#pragma once
#include "Error.h"
#include <vector>
#include <stdexcept>

class ErrorCollection {
private:
    std::vector<Error*> errors;
public:
    void addError(Error* err);
    size_t size() const;
    Error* operator[](size_t index);
};
