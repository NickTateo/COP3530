#ifndef CHAININGMAP_H
#define CHAININGMAP_H

#include "HashMap.h"

class ChainingMap : public HashMap
{
    public:
        ChainingMap(int newSize) : HashMap(newSize) {};

        void addNode(int, HashNode *);
        void keyMod(HashNode *);
        void midSquare(HashNode *);

    protected:

    private:
};

#endif // CHAININGMAP_H
