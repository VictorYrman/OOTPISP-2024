#include <iostream>
#include <string>
#include <sstream>

class Money
{
public:
    Money() = default;
    explicit Money(const std::string &money);
    ~Money() = default;

    Money &operator=(const Money &a) = default;
    bool operator==(const Money &a) const;

    inline int getMinutrs() const { return minutes; };
    inline int getSeconds() const { return seconds; };

    inline void setPennny(const int min) { minutes = min; };
    inline void setRubl(const int sec) { seconds = sec; };

    friend std::ostream &operator<<(std::ostream &output, const Money &a)
    {
        output << a.getMinutrs() << ":" << a.getSeconds() << " ";
        return output;
    }

    friend std::istream &operator>>(std::istream &input, Money &a)
    {
        std::cout << "Dollars: ";
        input >> a.minutes;
        std::cout << "Euro: ";
        input >> a.seconds;
        return input;
    }

private:
    int minutes = 0;
    int seconds = 0;
};
