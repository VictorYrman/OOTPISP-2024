#include <iostream>
#include "Cash.h"
#include "List.h"

int main()
{
    List<int> list;
    list.Add(1);
    list.Add(2);
    list.Add(2);
    list.Add(3);
    list.Add(3);

    List<int> list2;
    list2.Add(5);
    list2.Add(52);
    list2.Add(22);
    list2.Add(312);

    auto List3 = list + list2;
    std::cout << List3 << std::endl;

    std::cout << "Element at index 2 is " << list[2] << std::endl;
    std::cout << "Size of the list is " << list() << std::endl;

    List<Cash> cashList;

    cashList.Add(Cash(10.50));
    cashList.Add(Cash(3.28));
    cashList.Add(Cash(55.99));
    cashList.Add(Cash(1.1));
    cashList.Add(Cash(1.1));

    std::cout << cashList << std::endl;

    Cash cash1(10.25);
    Cash cash2(3.75);
    Cash cash3 = cash1 + cash2;
    std::cout << "Cash1: " << cash1 << "Cash2: " << cash2 << "Cash3: " << cash3 << std::endl;
}