#include "HashNode.h"

//template <class valType>
HashNode::HashNode(int newKey, int newValue)
{
    key = newKey;
    value = newValue;
    next = nullptr;
}

//template <class valType>
HashNode::~HashNode()
{
    //dtor
}

//template <class valType>
void HashNode::setNext(HashNode *newNext)
{
    next = newNext;
}

//template <class valType>
int HashNode::getKey()
{
    return key;
}

//template <class valType>
int HashNode::getValue()
{
    return value;
}

//template <class valType>
HashNode *HashNode::getNext()
{
    return next;
}
