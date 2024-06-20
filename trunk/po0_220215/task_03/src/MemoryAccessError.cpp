#include "MemoryAccessError.h"

MemoryAccessError::MemoryAccessError(const std::string& msg)
    : Error("Memory Access Error: " + msg) {}

bool MemoryAccessError::operator==(const MemoryAccessError& other) const {
    return getMessage() == other.getMessage();
}

