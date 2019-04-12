#ifndef HASHMAP_H
#define HASHMAP_H

#define COLWIDTH 15
#define KEYFACTOR 3
#define MODVALUE 28980

#include "HashNode.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <random>
#include <string>
#include <bitset>

using std::cout;
using std::setw;
using std::left;

class HashMap
{
    public:
        //HashMap() {}; //delete?
        HashMap(int newSize) : tableSize(newSize)
        {
            table = new HashNode*[tableSize];

            for(int i = 0; i < tableSize; i++)
            {
                table[i] = nullptr;
            }

            srand(time(0));
        }

        ~HashMap();
        virtual void addNode(int, HashNode *) = 0;
        virtual void keyMod(HashNode *) = 0;
        virtual void midSquare(HashNode *) = 0;
        HashNode *generateNode();
        HashNode *generateNode(int);
        void printTable();
        void printLoadFactor();
        void printNumCollisions();

    protected:
        int tableSize;
        int collisions = 0;
        int fillLevel = 0;
        HashNode **table = nullptr;

    private:
};

#endif
