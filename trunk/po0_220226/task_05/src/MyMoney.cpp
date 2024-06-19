#include "MyMoney.h"

MyMoney::MyMoney(double amount)
    : dollars_(static_cast<int64_t>(amount)),
      cents_(static_cast<int32_t>((amount - static_cast<int32_t>(amount)) * 100))
{
}

bool MyMoney::operator==(const MyMoney &a) const
{
    return (cents_ == a.cents_ && dollars_ == a.dollars_);
}
