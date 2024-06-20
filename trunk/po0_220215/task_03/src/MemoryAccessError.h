#pragma once
#include "Error.h"

class MemoryAccessError : public Error {
public:
    explicit MemoryAccessError(const std::string& msg);
    bool operator==(const MemoryAccessError& other) const;
};
