#include <iostream>
#include "Pair.h"
#include "List.h"

int main()
{
    List<int> list;
    list.Add(123);
    list.Add(213);
    list.Add(1);

    List<int> list2;
    list2.Add(24);
    list2.Add(16);
    list2.Add(22);

    list = list + 1;

    std::cout << list << std::endl;

    std::cout << "Element at index 1 is " << list[1] << std::endl;
    std::cout << "Size of the list is " << list() << std::endl;

    List<Pair> Pairs;

    Pairs.Add(Pair(1, 2.11));
    Pairs.Add(Pair(4, 52.52));
    Pairs.Add(Pair(213, 14.0));
    Pairs.Add(Pair(15, 51.1));
    Pairs.Add(Pair(14, 10.2));

    std::cout << Pairs << std::endl;

    Pair pair1(100, 5.1);
    Pair pair2(12, 9.2);
    Pair pair3 = pair1 + pair2;

    std::cout << "Pair1: " << pair1 
        << "Pair2: " << pair2 
        << "Pair3: " << pair3 << std::endl;
}