#include "HashMap.h"

HashMap::~HashMap()
{
    for(int i = 0; i < tableSize; i++)
    {
        if(table[i] != nullptr)
        {
            if(table[i]->getNext() != nullptr)
            {
                if(table[i]->getNext()->getNext() != nullptr)
                {
                    HashNode *temp0 = table[i]->getNext()->getNext();

                    while(temp0->getNext() != nullptr)
                    {
                        temp0 = temp0->getNext();
                        delete table[i]->getNext()->getNext();
                        table[i]->getNext()->setNext(temp0);
                    }
                    delete table[i]->getNext()->getNext();
                }
                delete table[i]->getNext();
            }
            delete table[i];
            table[i] = nullptr;
        }
    }
}

HashNode *HashMap::generateNode()
{
    return new HashNode(rand() % (KEYFACTOR*tableSize), rand() % MODVALUE);
}

HashNode *HashMap::generateNode(int val)
{
    return new HashNode(rand() % (KEYFACTOR*tableSize), val);
}

void HashMap::printTable()
{
    cout << left << setw(COLWIDTH) << "ROW" << setw(COLWIDTH) << "KEY" << setw(COLWIDTH) << "VALUE" << setw(COLWIDTH) << "ADDRESS" << "\n";
    for(int i = 0; i < tableSize; i++)
    {
        if(table[i] != nullptr)
        {
            HashNode *temp = table[i];
            do
            {
                cout << left
                << setw(COLWIDTH) << i
                << setw(COLWIDTH) << temp->getKey()
                << setw(COLWIDTH) << temp->getValue()
                << setw(COLWIDTH) << temp << "\n";
                temp = temp->getNext();
            }while(temp != nullptr);
        }
        else
        {
            cout << left
            << setw(COLWIDTH) << i
            << setw(COLWIDTH) << "EMPTY"
            << setw(COLWIDTH) << "EMPTY"
            << setw(COLWIDTH) << table[i] << "\n";
        }
    }
    cout << "\n\n";
}

void HashMap::printLoadFactor()
{
    cout << ((double)fillLevel)/((double)tableSize) << ";";
}

void HashMap::printNumCollisions()
{
    cout << collisions << "\n";
}
