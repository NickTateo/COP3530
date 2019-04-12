#ifndef HASHNODE_H
#define HASHNODE_H

#include <iostream>

//template <class valType>

class HashNode
{
    public:
        HashNode(int, int);
        ~HashNode();

        void setNext(HashNode *);
        int getKey();
        int getValue();
        HashNode *getNext();

    private:
        int key;
        int value;
        HashNode *next;
};

#endif // HASHNODE_H
