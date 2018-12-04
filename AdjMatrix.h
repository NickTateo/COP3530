#ifndef ADJMATRIX_H
#define ADJMATRIX_H

#include <vector>
#include <iostream>
#include <iomanip>

using std::vector;
using std::cin;
using std::cout;

class AdjMatrix
{
    public:
        AdjMatrix(int);
        virtual ~AdjMatrix();

        int getDimension();
        double getElementValue(int, int);
        void updateElement(int, int, double);   //changes value of adj matrix at index [from_page][to_page] to a passed double
        void resizeMatrix(int);
        //void printMatrix();                     //for debug only

    private:
        int dimension;
        double * matrix;
};

#endif // ADJMATRIX_H


