#include "Vvector.h"
#include <iostream>
#include "Money.h"

int main()
{
    Vvector<int> vect1;
    Vvector<int> vect2;

    
    std::cout << vect1[1] << std::endl;

    vect2.addVect(1);
    vect2.addVect(2);
    vect2.addVect(3);
    vect2.addVect(4);

   
    std::cout << vect2[2] << std::endl;
    std::cout << "size vector 1: " << vect1() << std::endl;


   

    Vvector<Money> timeVect;

    
    timeVect.addVect(Money("11:41"));
    timeVect.addVect(Money("51:51"));
    timeVect.addVect(Money("31:50"));
    timeVect.addVect(Money("11:11"));

    
    return 0;
}
