#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#include "Time.h"
#include "Vector.h"
#include "SVector.h"

using namespace std;

template <typename T>
void findMaxAndAddToBeginning(vector<T>& vec) {
    if (!vec.empty()) {
        auto maxIt = std::ranges::max_element(vec);
        if (maxIt != vec.end()) {
            vec.insert(vec.begin(), *maxIt);
        }
    }
}

template <typename T>
void removeMinElement(vector<T>& vec) {
    if (!vec.empty()) {
        auto minIt = std::ranges::min_element(vec);
        vec.erase(minIt);
    }
}

template <typename T>
void addAverageToElements(vector<T>& vec) {
    if (!vec.empty()) {
        T sum = T();
        for (const auto& elem : vec) {
            sum += elem;
        }
        T average = sum / (int)vec.size();

        for (auto& elem : vec) {
            elem += average;
        }
    }
}

template <typename T>
void show(vector<T>&vec) {
    cout << "Elements:\n";
    for (const auto& elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
}

template <typename T>
void findMaxAndAddToBeginning(stack<T>& s) {
    if (!s.empty()) {
        stack<T> temp;
        T maxElement = s.top();
        temp.push(maxElement);
        s.pop();

        while (!s.empty()) {
            T current = s.top();
            s.pop();
            temp.push(current);
            if (maxElement < current) {
                maxElement = current;
            }
        }

        s.push(maxElement);

        while (!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }
    }
}

template <typename T>
void removeMinElement(stack<T>& s) {
    if (!s.empty()) {
        stack<T> temp;
        T minElement = s.top();
        s.pop();
        temp.push(minElement);

        while (!s.empty()) {
            T current = s.top();
            s.pop();
            if (current < minElement) {
                minElement = current;
            }
            temp.push(current);
        }

        while (!temp.empty()) {
            if (!(temp.top() == minElement)) {
                s.push(temp.top());
            }
            temp.pop();
        }
    }
}

template <typename T>
void addAverageToElements(stack<T>& s) {
    if (!s.empty()) {
        stack<T> temp = s;
        T current;
        int count = 0;
        T sum = T();

        while (!temp.empty()) {
            current = temp.top();
            temp.pop();
            sum += current;
            count++;
        }

        T average = sum / count;

        temp = s;
        while (!s.empty()) {
            s.pop();
        }
        while (!temp.empty()) {
            current = temp.top();
            temp.pop();
            current += average;
            s.push(current);
        }
    }
}

template <typename T>
void show(stack<T>& s) {
    cout << "Elements:\n";
    stack<T> temp = s;

    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

int main() {
    cout << "Task 1\n";
    vector<double> d_vector = { 3.18, 2.482, 5.252, 1.337, 5.049 };
    findMaxAndAddToBeginning(d_vector);
    removeMinElement(d_vector);
    addAverageToElements(d_vector);
    show(d_vector);

    cout << "Task 2\n";
    vector<Time> t_vector = { Time(1, 20), Time(2, 40), Time(3, 10) };
    findMaxAndAddToBeginning(t_vector);
    removeMinElement(t_vector);
    addAverageToElements(t_vector);
    show(t_vector);

    cout << "Task 3\n";
    Vector<double> d2_vector;
    d2_vector.fillContainer({ 8.51, 54.953, 0.001, 847.09, 6.12 });
    d2_vector.findMaxAndAddToBeginning();
    d2_vector.removeMinElement();
    d2_vector.addAverageToElements();
    d2_vector.show();

    cout << "Task 4\n";
    stack<Time> t_stack;
    t_stack.push(Time(1, 20));
    t_stack.push(Time(2, 40));
    t_stack.push(Time(3, 12));
    t_stack.push(Time(5, 56));
    t_stack.push(Time(0, 56));
    findMaxAndAddToBeginning(t_stack);
    removeMinElement(t_stack);
    addAverageToElements(t_stack);
    show(t_stack);

    cout << "Task 5\n";
    SVector<Time> t_svector;
    t_svector.Add(Time(10, 15));
    t_svector.Add(Time(24, 48));
    t_svector.Add(Time(05, 53));
    t_svector.Add(Time(38, 01));
    t_svector.Add(Time(0, 52));
    t_svector.findMaxAndAddToBeginning();
    t_svector.removeMinElement();
    t_svector.addAverageToElements();
    t_svector.show();
}
