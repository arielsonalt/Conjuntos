#ifndef NUMERO_H
#define NUMERO_H
#include "../include/Elemento.h"
#include <iostream>
#include <string>


class Numero: public Elemento
{
    private:
        int numero;
    public:
        Numero();
        int getNumero();
        void setNumero(int);
};

#endif // NUMERO_H
