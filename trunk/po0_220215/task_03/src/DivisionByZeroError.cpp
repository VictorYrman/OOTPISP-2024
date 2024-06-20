#include "DivisionByZeroError.h"

DivisionByZeroError::DivisionByZeroError()
    : MathError("Division by zero") {}

bool DivisionByZeroError::operator==(const DivisionByZeroError& other) const {
    return getMessage() == other.getMessage();
}
