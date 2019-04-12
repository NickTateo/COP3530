#include "OpenAddressingMap.h"

void OpenAddressingMap::addNode(int row, HashNode *newNode)
{
    int index = row;
    if(table[row] != nullptr)
    {
        while(table[index] != nullptr)
        {
            index = (index + 1) % tableSize;
        }
        collisions++;
    }

    table[index] = newNode;
    fillLevel++;
}

void OpenAddressingMap::keyMod(HashNode *theNode)
{
    OpenAddressingMap::addNode((theNode->getKey() % tableSize), theNode);
}

void OpenAddressingMap::midSquare(HashNode *theNode)
{
    long keySquare = (theNode->getKey())*(theNode->getKey());
    int bitNum = ceil(log2(KEYFACTOR*tableSize*KEYFACTOR*tableSize));
    int bitsNeeded = ceil(log2(tableSize));
    int extraBits = (bitNum - bitsNeeded) / 2;
    int keyBits = floor(keySquare / pow(2, extraBits));
    int msIndex = keyBits % tableSize;

    OpenAddressingMap::addNode(msIndex, theNode);
}
