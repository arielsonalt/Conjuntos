#include "../include/Universo.h"
#include "../include/Elemento.h"
#include "../include/Conjunto.h"
#include <vector>
using namespace std;

Universo::Universo()
{

}
string Universo::getNome()
{
    return nome;
}
vector <Conjunto> Universo::getConjuntos()
{
    if(conjuntos.size()>0)
    {
        return conjuntos;
    }
    else
    {
        vector <Conjunto> apoio;
        return apoio;
    }


}
vector <Numero> Universo::getNumeros()
{
    if(numeros.size()>0)
    {
        return numeros;
    }
    else
    {
        vector <Numero> apoio;
        return apoio;
    }
}
void Universo::setConjuto(Conjunto c)
{
    conjuntos.push_back(c);
}
void Universo::setNumero(Numero n)
{
    numeros.push_back(n);
}




