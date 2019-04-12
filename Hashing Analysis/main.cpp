//#include <iostream>

#include "ChainingMap.h"
#include "OpenAddressingMap.h"

//using namespace std;

int main()
{
    OpenAddressingMap cmap(100);

    for(int i = 0; i < 100; i++)
    {
        cmap.midSquare(cmap.generateNode(i+1));
        cmap.printLoadFactor();
        cmap.printNumCollisions();
    }

    //cmap.printTable();

    return 0;
}
