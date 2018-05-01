#include "Relacao.h"
#include <vector>
#include <iostream>
#include <ostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

Relacao::Relacao()
{

}

vector<int> Relacao::getDominio()
{
    return dominio;
}

void Relacao::setDominio(int numero)
{
    dominio.push_back(numero);
}

vector <int> Relacao::getImagem()
{
    return imagem;
}

void Relacao::setImagem(int numero)
{
    imagem.push_back(numero);
}
vector Relacao::getDominio2()
{
    return dominio2;
}

void Relacao::setDominio2(int numero)
{
    dominio2.push_back(numero);
}

vector Relacao::getImagem2(int numero)
{
    return imagem2;
}

void Relacao::setImagem2(int)
{
    imagem2.push_back(numero);
}




