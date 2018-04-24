#ifndef ELEMENTO_H
#define ELEMENTO_H
#include <string>
#include "../include/Elemento.h"
using namespace std;

class Elemento
{
    private:
        string nome;
    public:
        Elemento();
        string getNome();
        void setNome(string);
};

#endif // ELEMENTO_H
