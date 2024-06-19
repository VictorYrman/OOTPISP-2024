#pragma once

#include <iostream>

class MyMoney
{
public:
	MyMoney() = default;
	explicit MyMoney(double amount);
	MyMoney(const MyMoney &other) = default;
	~MyMoney() = default;

	MyMoney &operator=(const MyMoney &a) = default;
	bool operator==(const MyMoney &a) const;
	auto operator<=>(const MyMoney &a) const = default;

	friend MyMoney operator+(const MyMoney& a, const MyMoney& b)
	{
		MyMoney result;
		result.SetDollars(a.GetDollars() + b.GetDollars());
		result.SetCents(a.GetCents() + b.GetCents());
		return result;
	}

	friend MyMoney operator/(const MyMoney& a, double val)
	{
		MyMoney result;
		result.SetDollars(a.GetDollars() / static_cast<int64_t>(val));
		result.SetCents(static_cast<int32_t>(a.GetCents() / val));
		return result;
	}

	friend std::ostream &operator<<(std::ostream &out, const MyMoney &a)
	{
		out << a.GetDollars() << " dollars, " << a.GetCents() << " cents" << std::endl;
		return out;
	}

	friend std::istream &operator>>(std::istream &in, MyMoney &a)
	{
		std::cout << "Enter amount of dollars: ";
		in >> a.dollars_;
		std::cout << "Enter amount of cents: ";
		in >> a.cents_;
		return in;
	}

	inline int32_t GetCents() const { return cents_; }
	inline int64_t GetDollars() const { return dollars_; }

	inline void SetCents(int32_t cents) { cents_ = cents; }
	inline void SetDollars(int64_t dollars) { dollars_ = dollars; }

private:
	int64_t dollars_ = 0;
	int32_t cents_ = 0;
};