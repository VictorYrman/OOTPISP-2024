#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

class Time {
private:
    int minutes;
    int seconds;

    void normalize() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
    }

public:
    Time(int m = 0, int s = 0) : minutes(m), seconds(s) {
        normalize();
    }

    void operator+=(const Time& other) {
        int totalSeconds = (minutes + other.minutes) * 60 + seconds + other.seconds;
        minutes = totalSeconds / 60;
        seconds = totalSeconds % 60;
    }

    friend Time operator/(Time t, int num) {
        int totalSeconds = t.minutes * 60 + t.seconds;
        if (num != 0) {
            totalSeconds /= num;
        }
        int newMinutes = totalSeconds / 60;
        int newSeconds = totalSeconds % 60;
        return Time(newMinutes, newSeconds);
    }

    auto operator<=>(const Time& other) const = default;

    friend std::istream& operator>>(std::istream& is, Time& time) {
        std::string input;
        is >> input;

        if (size_t pos = input.find(':'); pos != std::string::npos) {
            try {
                int m = std::stoi(input.substr(0, pos));
                int s = std::stoi(input.substr(pos + 1));
                time.minutes = m;
                time.seconds = s;
                time.normalize();
                return is;
            }
            catch (const std::invalid_argument&) {
                throw std::invalid_argument("Invalid time format or out-of-range seconds");
            }
        }

        std::istringstream ss(input);
        ss >> time.minutes >> time.seconds;
        time.normalize();
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Time& time) {
        if (time.minutes < 10) {
            os << '0';
        }
        os << time.minutes << ":";
        if (time.seconds < 10) {
            os << '0';
        }
        os << time.seconds;
        return os;
    }

    int getMinutes() const {
        return minutes;
    }

    int getSeconds() const {
        return seconds;
    }
};

#endif
