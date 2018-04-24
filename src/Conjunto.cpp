#include "../include/Conjunto.h"
#include "../include/Elemento.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

Conjunto::Conjunto()
{
    //ctor
}

vector <int> Conjunto::getConjunto(){
    return conjunto;
}

void Conjunto::setConjunto(int numero){
    conjunto.push_back(numero);
}



