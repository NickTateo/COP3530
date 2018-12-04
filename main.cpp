#include <iostream>

#include "WebHandler.h"

using std::cin;
using std::cout;

int main()
{

    int lines = -1;
    int iterations = -1;

    cin >> lines;
    cin >> iterations;

    if(cin.good() && lines > 0 && iterations > 0)
    {
        WebHandler wh(lines, iterations);
    }
    else
    {
        cout << "Error: improper input\n";
    }

    return 0;
}
