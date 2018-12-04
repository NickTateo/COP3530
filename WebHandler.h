#ifndef WEBHANDLER_H
#define WEBHANDLER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "AdjMatrix.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;

class WebHandler
{
    public:
        WebHandler(int, int);
        virtual ~WebHandler();
        void matrixTimesVector(int);

    private:
        int num_pages;
        int power_iterations;
        vector<string> url_table;
        vector<double> page_ranks;
        AdjMatrix *web_matrix;

        int getUrlIndex(string);
        void readInput(int);
        void initializeMatrixValues();
        void printPageRanks();
};

#endif // WEB_H
