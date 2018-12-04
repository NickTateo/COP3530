#include "AdjMatrix.h"

AdjMatrix::AdjMatrix(int t_dimension)
{
    dimension = t_dimension;

    matrix = new double[dimension*dimension];

    for(int i = 0; i < dimension*dimension; i++)
    {
        matrix[i] = 0;
    }
}

AdjMatrix::~AdjMatrix()
{
    delete[] matrix;
}

int AdjMatrix::getDimension()
{
    return dimension;
}

//takes desired 2D index and returns corresponding element of the 1D array
double AdjMatrix::getElementValue(int t_row, int t_column)
{
    return matrix[(t_row*dimension)+t_column];
}

void AdjMatrix::updateElement(int t_from, int t_to, double new_value)
{
    matrix[(t_from*dimension)+t_to] = new_value;
}

//once the number of pages is determined, this is called to reduce the unused space in the matrix
void AdjMatrix::resizeMatrix(int t_new_dimension)
{
    double *temp = new double[t_new_dimension*t_new_dimension];

    for(int r = 0; r < t_new_dimension; r++)
    {
        for(int c = 0; c < t_new_dimension; c++)
        {
            temp[(r*t_new_dimension)+c] = matrix[(r*dimension)+c];
        }
    }

    delete[] matrix;
    matrix = temp;
    dimension = t_new_dimension;
}
