#include "Cash.h"

Cash::Cash(const double money)
    : rubles(static_cast<int64_t>(money)),
    copecks(static_cast<int32_t>((money - static_cast<int32_t>(money)) * 100))
{
}

bool Cash::operator==(const Cash& a) const
{
    return (copecks == a.copecks && rubles == a.rubles);
}