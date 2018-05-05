#include "../include/Numero.h"
#include "../include/Elemento.h"
#include <iostream>
#include <string>
#include <vector>

Numero::Numero()
{
    //ctor
}

int Numero::getNumero()
{
    return numero;
}
void Numero::setNumero(int a)
{
    numero = a;
}

