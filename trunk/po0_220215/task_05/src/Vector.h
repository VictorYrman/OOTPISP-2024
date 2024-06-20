#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <algorithm> // for std::max_element

template<typename T>
class Vector {
private:
    std::vector<T> data;

public:
    Vector() = default;
    ~Vector() = default;

    void fillContainer(const std::vector<T>& elements) {
        data = elements;
    }

    void findMaxAndAddToBeginning() {
        if (!data.empty()) {
            auto maxElement = std::ranges::max_element(data);
            if (maxElement != data.end()) {
                T maxValue = *maxElement;
                data.insert(data.begin(), maxValue);
            }
        }
    }

    void removeMinElement() {
        if (!data.empty()) {
            auto minIt = std::ranges::min_element(data);
            data.erase(minIt);
        }
    }

    void addAverageToElements() {
        if (!data.empty()) {
            T sum = T();
            for (const auto& elem : data) {
                sum += elem;
            }
            T average = sum / (int)data.size();

            for (auto& elem : data) {
                elem += average;
            }
        }
    }

    void show() const {
        std::cout << "Elements:\n";
        for (const auto& elem : data) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

#endif
