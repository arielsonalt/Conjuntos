#ifndef UNIVERSO_H
#define UNIVERSO_H
#include "../include/Elemento.h"
#include "../include/Conjunto.h"
#include "../include/Numero.h"
#include <string>
#include <vector>
using namespace std;

class Universo
{
private:
    string nome = "Universo";
    vector <Conjunto> conjuntos;
    vector <Numero> numeros;
public:
    Universo();
    vector <Conjunto> getConjuntos();
    vector <Numero> getNumeros();
    void setConjuto(Conjunto);
    void setNumero(Numero);
    string getNome();

};

#endif // UNIVERSO_H
