#pragma once
#include <string>
#include <iostream>

class Error {
public:
    explicit Error(const std::string& message);
    virtual ~Error() = default;
    virtual void print() const;

private:
    std::string message; 
protected:
    const std::string& getMessage() const;
};
