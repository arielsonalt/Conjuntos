#ifndef CONJUNTO_H
#define CONJUNTO_H
#include "../include/Elemento.h"
#include <string>
#include <vector>

using namespace std;

class Conjunto: public Elemento
{
    private:
        vector <int> conjunto;
    public:
        Conjunto();
        vector <int> getConjunto();
        void setConjunto(int);
};

#endif // CONJUNTO_H
