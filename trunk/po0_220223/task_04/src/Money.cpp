
#include "Money.h"

Money::Money(const std::string &timeVect)
{
    std::stringstream ss(timeVect);
    char delimiter;
    ss >> minutes >> delimiter >> seconds;
}

bool Money::operator==(const Money &a) const = default;
