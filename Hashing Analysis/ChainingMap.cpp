#include "ChainingMap.h"

void ChainingMap::addNode(int row, HashNode *newNode)
{
    if(table[row] != nullptr)
    {
        HashNode *temp = table[row];
        while(temp->getNext() != nullptr)
        {
            temp = temp->getNext();
        }
        temp->setNext(newNode);

        collisions++;
    }
    else
    {
        table[row] = newNode;
    }
    fillLevel++;
}

void ChainingMap::keyMod(HashNode *theNode)
{
    ChainingMap::addNode((theNode->getKey() % tableSize), theNode);
}

void ChainingMap::midSquare(HashNode *theNode)
{
    long keySquare = (theNode->getKey())*(theNode->getKey());
    int bitNum = ceil(log2(KEYFACTOR*tableSize*KEYFACTOR*tableSize));
    int bitsNeeded = ceil(log2(tableSize));
    int extraBits = (bitNum - bitsNeeded) / 2;
    int keyBits = floor(keySquare / pow(2, extraBits));
    int msIndex = keyBits % tableSize;

    ChainingMap::addNode(msIndex, theNode);
    //int msIndex = (int)floor(keySquare / log2(tableSize)) % tableSize;
    //int temp = ((int)(keySquare / pow(2, extraBits))) % tableSize;
}

