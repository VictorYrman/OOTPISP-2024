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

Cash Cash::operator+(const Cash& other) const
{
    int64_t resultRubles = rubles + other.rubles;
    int32_t resultCopecks = copecks + other.copecks;
    if (resultCopecks >= 100)
    {
        resultRubles += resultCopecks / 100;
        resultCopecks = resultCopecks % 100;
    }
    return Cash(static_cast<double>(resultRubles) + static_cast<double>(resultCopecks) / 100.0);
}

friend std::ostream& operator<<(std::ostream& out, const Cash& a)
{
    out << a.GetRubles() << "," << a.GetCopecks() << std::endl;
    return out;
}

friend std::istream& operator>>(std::istream& in, Cash& a)
{
    std::cout << "Enter amount of rubles" << std::endl;
    in >> a.rubles;
    std::cout << "Enter amount of copecks" << std::endl;
    in >> a.copecks;
    return in;
}