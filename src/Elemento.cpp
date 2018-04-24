#include "../include/Elemento.h"
#include <iostream>
#include <string>
using namespace std;

Elemento::Elemento()
{
    //ctor
}
void Elemento::setNome(string a){
    nome = a;
}
string Elemento::getNome(){
    return nome;
}


