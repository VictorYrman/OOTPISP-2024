#include <iostream>
#include "Vector.h"
#include "Time.h"

int main() {
    Time currentTime;
    std::cout << "Enter current time (minutes seconds): ";
    std::cin >> currentTime;
    std::cout << "Current time: " << currentTime << std::endl;

    // Create a vector of Time objects with 3 elements initialized to current time
    Vector tVector1(5, currentTime);
    std::cout << "Enter values for time vector A (5 elements): ";
    std::cin >> tVector1;
    std::cout << "Time vector A: " << tVector1 << std::endl;

    // Create another vector of Time objects with 5 elements initialized to current time
    Vector tVector2(10, currentTime);
    std::cout << "Time vector B (size 10): " << tVector2 << std::endl;

    // Assign timeVector's values to timeVector2
    tVector2 = tVector1;
    std::cout << "Time vector B after assignment: " << tVector2 << std::endl;
    std::cout << "Value of time vector A at index 2: " << tVector1[2] << std::endl;
    std::cout << "Length of time vector A: " << tVector1() << std::endl;

    // Demonstrate adding 30 seconds to each element of timeVector
    tVector1 + 30;
    std::cout << "Adding 10 seconds to time vector A: " << tVector1 << std::endl;

    return 0;
}
