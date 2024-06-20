#ifndef SVECTOR_H
#define SVECTOR_H

#include <vector>
#include <algorithm> // for std::max_element

template<typename T>
class SVector {
private:
    std::stack<T> stack;
    std::stack<T> tempStack;

public:
    void Add(const T& element) {
        stack.push(element);
    }

    void findMaxAndAddToBeginning() {
        if (!stack.empty()) {
            T maxElement = stack.top();
            tempStack.push(maxElement);
            stack.pop();

            while (!stack.empty()) {
                T current = stack.top();
                stack.pop();
                tempStack.push(current);
                if (maxElement < current) {
                    maxElement = current;
                }
            }

            stack.push(maxElement);

            while (!tempStack.empty()) {
                stack.push(tempStack.top());
                tempStack.pop();
            }
        }
    }

    void removeMinElement() {
        if (!stack.empty()) {
            T min = stack.top();
            stack.pop();
            tempStack.push(min);

            while (!stack.empty()) {
                T current = stack.top();
                stack.pop();
                if (current < min) {
                    min = current;
                }
                tempStack.push(current);
            }

            while (!tempStack.empty()) {
                if (!(tempStack.top() == min)) {
                    stack.push(tempStack.top());
                }
                tempStack.pop();
            }
        }
    }
    
    void addAverageToElements() {
        if (!stack.empty()) {
            T sum = T();
            int count = 0;
            tempStack = stack;

            while (!tempStack.empty()) {
                sum += tempStack.top();
                tempStack.pop();
                ++count;
            }

            T average = sum / count;

            tempStack = stack;
            while (!stack.empty()) {
                stack.pop();
            }
            while (!tempStack.empty()) {
                T& elem = tempStack.top();
                elem += average;
                tempStack.pop();
                stack.push(elem);
            }
        }
    }

    void show() const {
        std::cout << "Elements:\n";
        std::stack<T> tempSt = stack;

        while (!tempSt.empty()) {
            std::cout << tempSt.top() << " ";
            tempSt.pop();
        }
        std::cout << std::endl;
    }
};

#endif
