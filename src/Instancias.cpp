#include "../include/Instancias.h"
#include "../include/Universo.h"
#include "../include/Conjunto.h"
#include "../include/Elemento.h"
#include "../include/Numero.h"
#include <exception>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

namespace patch
{
template < typename T > std::string to_string( const T& n )
{
    std::ostringstream stm;
    stm << n;
    return stm.str();
}
}

Instancias::Instancias()
{
    lerTxt();
}

void Instancias::setUniverso(Universo u)
{

    universo = u;
}
Universo Instancias::getUniverso()
{
    return universo;
}

void Instancias::lerTxt()
{

    vector <string> lista;
    string linha1;

    ifstream arquivo;
    arquivo.open("DadosdeEntrada.txt");

    while (arquivo.good())
    {
        getline(arquivo, linha1);
        lista.push_back(linha1);
    }

    Universo universo;

    for(int k=0; k<lista.size(); k++)
    {
        string linha = lista[k];
        for(int i=0; i<linha.size(); i++)
        {
            if(linha[i]>='A' && linha[i]<='Z')
            {

                Conjunto conjunto;
                conjunto.setNome(patch::to_string(linha[i]));

                int j = i+1;
                while(j < linha.size())
                {
                    if(linha[j] == ',' || linha[j] == '{' && linha[j] != ' '||linha[j] == '-')
                    {
                        j++;
                        string carac;
                        if(linha[j-1] == '-')
                        {
                            j++;
                            while(linha[j] != ',')
                            {
                                carac += linha[j];
                                j++;
                            }
                            istringstream convert(carac);
                            int Result;
                            if ( !(convert >> Result) )
                            {
                                Result = 0;
                            }
                            conjunto.setConjunto(Result*(-1));
                            j--;
                        }
                        else
                        {
                            while(linha[j] != ','&&linha[j]!='}')
                            {
                                carac += linha[j];
                                j++;
                            }
                            istringstream convert(carac);
                            int Result;
                            if ( !(convert >> Result) )
                            {
                                Result = 0;
                            }
                            conjunto.setConjunto(Result);
                            j--;
                        }
                    }
                    j++;
                }
                universo.setConjuto(conjunto);
            }

            if(linha[i]>='a' && linha[i]<='z')
            {

                Numero numero;
                numero.setNome(patch::to_string(linha[i]));

                int j = i+1;
                string carac;
                while(linha[j]!= '\0')
                {

                    if( linha[j]!= ' ' && linha[j]!= '=')
                    {
                        if(linha[j] == '-')
                        {
                            j++;
                            while(linha[j]!= '\0')
                            {
                                carac += patch::to_string(linha[j]);
                                j++;
                            }
                            istringstream convert(carac);
                            int Result;
                            if ( !(convert >> Result) )
                            {
                                Result = 0;
                            }
                            numero.setNumero(Result*(-1));
                            break;
                        }
                        else
                        {
                            carac += patch::to_string(linha[j]);
                        }
                    }
                    istringstream convert(carac);
                    int Result;
                    if ( !(convert >> Result) )
                    {
                        Result = 0;
                    }
                    numero.setNumero(Result);
                    j++;
                }
                universo.setNumero(numero);
                i=j;
            }
        }
    }
    setUniverso(universo);
    arquivo.close();
}

