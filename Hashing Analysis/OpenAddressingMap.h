#ifndef OPENADDRESSINGMAP_H
#define OPENADDRESSINGMAP_H

#include "HashMap.h"

class OpenAddressingMap : public HashMap
{
    public:
        OpenAddressingMap(int newSize) : HashMap(newSize) {};

        void addNode(int, HashNode *);
        void keyMod(HashNode *);
        void midSquare(HashNode *);

    protected:

    private:
};

#endif // OPENADDRESSINGMAP_H
