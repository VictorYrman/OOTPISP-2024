#include "Money.h"

Coins::Coins(double a)
    : rubles(static_cast<long>(a)),
      kopeck(static_cast<int>((a - static_cast<double>(rubles)) * 100 + 0.5))
{
    // Здесь можно оставить тело конструктора пустым, если дополнительная логика не требуется
}

bool Coins::operator==(const Coins& a) const
{
    return (kopeck == a.kopeck && rubles == a.rubles);
}

Coins::Coins(long r, int k) : rubles(r), kopeck(k) {}
