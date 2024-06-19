#include "MyMoney.h"

MyMoney::MyMoney(double amount)
    : dollars_(static_cast<int64_t>(amount)),
      cents_(static_cast<int32_t>((amount - static_cast<int64_t>(amount)) * 100))
{
}

bool MyMoney::operator==(const MyMoney &a) const
{
    return (cents_ == a.cents_ && dollars_ == a.dollars_);
}

MyMoney MyMoney::operator+(const MyMoney &a) const
{
    MyMoney result;
    result.dollars_ = dollars_ + a.dollars_;
    result.cents_ = cents_ + a.cents_;

    if (result.cents_ >= 100)
    {
        result.dollars_ += result.cents_ / 100;
        result.cents_ %= 100;
    }

    return result;
}

MyMoney MyMoney::operator/(double val) const
{
    int64_t totalCents = (dollars_ * 100 + cents_) / val;
    MyMoney result;
    result.dollars_ = totalCents / 100;
    result.cents_ = totalCents % 100;
    return result;
}