#pragma once

#include <iostream>

class Cash
{
public:
    Cash() = default;
    explicit Cash(const double money);
    Cash(const Cash& other) = default;
    ~Cash() = default;

    Cash& operator=(const Cash& a) = default;
    bool operator==(const Cash& a) const;
    Cash operator+(const Cash& other) const;

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

    inline int32_t GetCopecks() const { return copecks; };
    inline int64_t GetRubles() const { return rubles; };

    inline void SetCopecks(const int32_t p) { copecks = p; };
    inline void SetRubles(const int64_t r) { rubles = r; };

private:
    int64_t rubles = 0;
    int32_t copecks = 0;
};