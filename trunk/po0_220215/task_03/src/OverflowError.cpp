#include "OverflowError.h"

OverflowError::OverflowError()
    : MathError("Overflow error") {}

bool OverflowError::operator==(const OverflowError& other) const {
    return getMessage() == other.getMessage();
}
