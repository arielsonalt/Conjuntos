#include "../include/Operacoes.h"
#include "../include/Elemento.h"
#include "../include/Conjunto.h"
#include "../include/Numero.h"
#include "../include/Instancias.h"
#include "../include/Universo.h"
#include "../include/Relacao.h"
#include <locale>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
Operacoes::Operacoes()
{


}

void Operacoes::uniao(Instancias i)
{

    vector <int> uniao;

    vector <Conjunto> conjuntos = i.getUniverso().getConjuntos();

    for(unsigned int i=0; i<conjuntos.size(); i++)
    {

        Conjunto c = conjuntos[i];
        vector <int> conjunto = c.getConjunto();
        for(unsigned int j=0; j<conjunto.size(); j++)
        {
            vector<int>::iterator it;
            int num = conjunto[j];
            it = find(uniao.begin(), uniao.end(),num);
            if(it == uniao.end())
            {
                uniao.push_back(conjunto[j]);
            }
        }
    }
    cout<<"          A uniao dos comjuntos e: {";

    for(unsigned int k=0; k<uniao.size(); k++)
    {
        if(k != 0 && k != uniao.size())
        {
            cout<<",";
        }
        cout<<uniao[k];
    }
    cout<<"}"<<endl;
    cout<<endl;

}
void Operacoes::intersecao(Instancias i)
{
    setlocale(LC_ALL,"portuguese");
    vector <int> intersecao;

    vector <Conjunto> conjuntos = i.getUniverso().getConjuntos();
    int total = conjuntos.size();
    int cont=0;
    int apoio=0;
    int numero;
    for(unsigned int i=0; i<conjuntos.size(); i++)
    {
        Conjunto c = conjuntos[i];
        vector <int> conjunto = c.getConjunto();

        for(unsigned int j=0; j<conjunto.size(); j++)
        {
            apoio=0;
            cont=0;
            numero = conjunto[j];
            for(unsigned int l=0; l < conjuntos.size(); l++)
            {
                Conjunto c2 = conjuntos[l];
                vector <int> conjunto2 = c2.getConjunto();
                vector<int>::iterator it;
                int num = conjunto[j];
                it = find(conjunto2.begin(), conjunto2.end(),num);
                vector<int>::iterator it2;
                it2 = find(intersecao.begin(), intersecao.end(),num);
                if(it != conjunto2.end() && it2 == intersecao.end())
                {
                    cont++;
                    apoio++;
                }
            }
            if(apoio == total)
            {
                intersecao.push_back(numero);
            }
        }

    }
    cout<<"                     A INTERSECAO DOS CONJUNTOS E: {";
    for(unsigned int k=0; k<intersecao.size(); k++)
    {
        if(k != 0 && k != intersecao.size())
        {
            cout<<",";
        }
        cout<<intersecao[k];

    }
    cout<<"}"<<endl;
    cout<<endl;

}
void Operacoes::produtoCartesiano(Instancias i)
{

    setlocale(LC_ALL,"portuguese");

    vector <Conjunto> apoio = i.getUniverso().getConjuntos();
    Conjunto conjunto = apoio[0];
    vector <int> vetorConjunto = conjunto.getConjunto();

    vector <Conjunto> apoio2 = i.getUniverso().getConjuntos();
    Conjunto conjunto2 = apoio2[1];
    vector <int> vetorConjunto2 = conjunto2.getConjunto();

    cout<<"O PRODUTO CARTESIANO ENTRE O PRIMEIRO E O SEGUNDO CONJUNTO E: ";
    for(unsigned int i =0 ; i<vetorConjunto.size(); i++)
    {

        cout<<endl;

        for(unsigned int j=0; j<vetorConjunto2.size(); j++)
        {
            cout<<" {"<<vetorConjunto[i]<<","<<vetorConjunto2[j]<<"}";
        }
    }
    cout<<endl;
}
bool Operacoes::pertence(vector <int> a, vector<int> b)
{
    setlocale(LC_ALL,"portuguese");
    int tamanhoVetorA = a.size();
    int tamanhoVetorB = b.size();

    int contador1=0;
    int contador2=0;
    for(unsigned int i=0; i<a.size(); i++)
    {
        for(unsigned int j=0; j<b.size(); j++)
        {
            if(a[i] == b[j])
            {
                contador1++;
            }
        }
    }

    if(b[1] == '-')
    {
        for(unsigned int j=0; j<a.size(); j++)
        {
            if(a[j] == b[0])
            {
                return 1;
            }
        }
        return 0;
    }

    if(contador1 == tamanhoVetorA )
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
bool Operacoes::contidoPropriamente(vector <int> a, vector <int> b)
{
    setlocale(LC_ALL,"portuguese");

    if(pertence(a,b) && (b.size()!= a.size()))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void Operacoes::criarRelacao(vector<int>, vector<int>)
{

}
Relacao Operacoes::menorQue(vector <int> vetorConjuntoA, vector <int> vetorConjuntoB)
{
    Relacao relacao;
    //CRIANDO A RELAÇÃO MENOR QUE
    for(unsigned int i=0; i<vetorConjuntoA.size(); i++)
    {
        for(unsigned int j=0; j<vetorConjuntoB.size(); j++)
        {
            if(vetorConjuntoA[i] < vetorConjuntoB[j])
            {
                relacao.setDominio(vetorConjuntoA[i]);
                relacao.setImagem(vetorConjuntoB[j]);
            }
        }
    }

    return relacao;

}
Relacao Operacoes::maiorQue(vector <int> vetorConjuntoA, vector <int> vetorConjuntoB)
{

    Relacao relacao;
    for(unsigned int i=0; i<vetorConjuntoB.size(); i++)
    {
        for(unsigned int j=0; j<vetorConjuntoA.size(); j++)
        {
            if(vetorConjuntoB[i] < vetorConjuntoA[j])
            {
                relacao.setDominio(vetorConjuntoB[i]);
                relacao.setImagem(vetorConjuntoA[j]);
            }
        }
    }
    return relacao;
}
Relacao Operacoes::igualA(vector <int> vetorConjuntoA, vector <int> vetorConjuntoB)
{

    Relacao relacao;
    for(unsigned int i=0; i<vetorConjuntoA.size(); i++)
    {
        for(unsigned int j=0; j<vetorConjuntoB.size(); j++)
        {
            if(vetorConjuntoA[i] == vetorConjuntoB[j])
            {
                relacao.setDominio(vetorConjuntoA[i]);
                relacao.setImagem(vetorConjuntoB[j]);
            }
        }
    }

    return relacao;
}
Relacao Operacoes::serOQuadradoDe(vector <int> vetorConjuntoA, vector <int> vetorConjuntoB)
{
    Relacao relacao;
    for(unsigned int i=0; i<vetorConjuntoA.size(); i++)
    {
        for(unsigned int j=0; j<vetorConjuntoB.size(); j++)
        {
            if(sqrt(vetorConjuntoA[i]) == vetorConjuntoB[j])
            {
                relacao.setDominio(vetorConjuntoA[i]);
                relacao.setImagem(vetorConjuntoB[j]);
            }
        }
    }
    return relacao;
}
Relacao Operacoes::serRaizQuadradaDe(vector <int> vetorConjuntoA, vector <int> vetorConjuntoB)
{
    Relacao relacao;
    for(unsigned int i=0; i<vetorConjuntoA.size(); i++)
    {
        for(unsigned int j=0; j<vetorConjuntoB.size(); j++)
        {
            if(vetorConjuntoA[i] == sqrt(vetorConjuntoB[j]))
            {
                relacao.setDominio(vetorConjuntoA[i]);
                relacao.setImagem(vetorConjuntoB[j]);
            }
        }
    }
    return relacao;
}
Relacao Operacoes::relacaoDoUsuario(vector <int> vetorConjuntoA, vector <int> vetorConjuntoB)
{
    char sair;
    Relacao relacao;
    while(sair != 's')
    {
        int numA,numB;
        cout<<"Digite a posição do elemento pertencenta ao conjunto A: "<<endl;
        cout<<"Posição A: ";
        cin>>numA;
        cout<<"Digite a posição do elemento pertencenta ao conjunto B: "<<endl;
        cout<<"Posição B: ";
        cin>>numB;
        relacao.setDominio(vetorConjuntoA[numA]);
        relacao.setImagem(vetorConjuntoB[numB]);
        cout<<"sair? s/n"<<endl;
        cin>>sair;

    }
    return relacao;
}
void Operacoes::classificarRelacao(Relacao relacao, Instancias instancia )
{

    if(funcional(relacao,instancia))
    {
        cout<<"É funcional"<<endl;
    }
    else
    {
        cout<<"Não é funcional"<<endl;
    }
    if(injetora(relacao,instancia))
    {
        cout<<"É injetora"<<endl;
    }
    else
    {
        cout<<"Não é injetora"<<endl;
    }
    if(total(relacao,instancia))
    {
        cout<<"É total"<<endl;
    }
    else
    {
        cout<<"Não é Total"<<endl;
    }
    if(sobrejetora(relacao,instancia))
    {
        cout<<"É sobrejetora"<<endl;
    }
    else
    {
        cout<<"Não é sobrejetora"<<endl;
    }

    if(total(relacao,instancia) && injetora(relacao,instancia))
    {
        cout<<"É monorrelação"<<endl;
    }
    else
    {
        cout<<"Não é monorrelação"<<endl;
    }

    if(funcional(relacao,instancia) && sobrejetora(relacao,instancia))
    {
        cout<<"É epirrelação"<<endl;
    }
    else
    {
        cout<<"Não é epirrelação"<<endl;
    }
    if(funcional(relacao,instancia) &&
            sobrejetora(relacao,instancia) &&
            total(relacao,instancia) &&
            injetora(relacao,instancia))
    {
        cout<<"É isorrelação"<<endl;
    }
    else
    {
        cout<<"Não é isorrelação"<<endl;
    }

}
bool Operacoes::total(Relacao relacao,Instancias instancia)
{

        vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
        Conjunto conjunto = apoio[0];
        vector <int> vetorConjuntoA = conjunto.getConjunto();

        vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
        Conjunto conjunto2 = apoio2[1];
        vector <int> vetorConjuntoB = conjunto2.getConjunto();

        vector <int> conjuntoD = relacao.getDominio();
        vector <int> conjuntoI = relacao.getImagem();
        vector <int> elementosPercorridos;
        int cont;
       for(unsigned int i=0; i< conjuntoD.size(); i++)
        {
        cont=0;
        for(unsigned int j=0; j<elementosPercorridos.size(); j++)
        {
            if(conjuntoD[i] == elementosPercorridos[j])
            {
                cont++;
            }
        }
        if(cont==0)
        {
            elementosPercorridos.push_back(conjuntoD[i]);
        }
    }
    if(elementosPercorridos.size()>= vetorConjuntoB.size()){
        return 1;
    }else{
        return 0;
    }
}
bool Operacoes::sobrejetora(Relacao relacao,Instancias instancia)
{
    vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
    Conjunto conjunto = apoio[0];
    vector <int> vetorConjuntoA = conjunto.getConjunto();

    vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
    Conjunto conjunto2 = apoio2[1];
    vector <int> vetorConjuntoB = conjunto2.getConjunto();

    vector <int> conjuntoD = relacao.getDominio();
    vector <int> conjuntoI = relacao.getImagem();

    vector <int> elementosPercorridos;
        int cont;
       for(unsigned int i=0; i< conjuntoI.size(); i++)
        {
        cont=0;
        for(unsigned int j=0; j<elementosPercorridos.size(); j++)
        {
            if(conjuntoI[i] == elementosPercorridos[j])
            {
                cont++;
            }
        }
        if(cont==0)
        {
            elementosPercorridos.push_back(conjuntoI[i]);
        }
    }
    if(elementosPercorridos.size()>= vetorConjuntoA.size()){
        return 1;
    }else{
        return 0;
    }
}
bool Operacoes::injetora(Relacao relacao,Instancias instancia)
{
    vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
    Conjunto conjunto = apoio[0];
    vector <int> vetorConjuntoA = conjunto.getConjunto();


    vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
    Conjunto conjunto2 = apoio2[1];
    vector <int> vetorConjuntoB = conjunto2.getConjunto();
    vector <int> conjuntoD = relacao.getDominio();
    vector <int> conjuntoI = relacao.getImagem();
    vector <int> elementosPercorridos;
    int cont;
    for(unsigned int i=0; i< conjuntoI.size(); i++)
    {
        cont=0;
        for(unsigned int j=0; j<elementosPercorridos.size(); j++)
        {
            if(conjuntoI[i] == elementosPercorridos[j])
            {
                cont++;
            }
        }
        if(cont==0)
        {
            elementosPercorridos.push_back(conjuntoI[i]);
        }else{
            return 0;
        }
    }
 return 1;
}
bool Operacoes::funcional(Relacao relacao,Instancias instancia)
{
    vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
    Conjunto conjunto = apoio[0];
    vector <int> vetorConjuntoA = conjunto.getConjunto();


    vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
    Conjunto conjunto2 = apoio2[1];
    vector <int> vetorConjuntoB = conjunto2.getConjunto();
    vector <int> conjuntoD = relacao.getDominio();
    vector <int> conjuntoI = relacao.getImagem();
    vector <int> elementosPercorridos;
    int cont;
    for(unsigned int i=0; i< conjuntoD.size(); i++)
    {
        cont=0;
        for(unsigned int j=0; j<elementosPercorridos.size(); j++)
        {
            if(conjuntoD[i] == elementosPercorridos[j])
            {
                cont++;
            }
        }
        if(cont==0)
        {
            elementosPercorridos.push_back(conjuntoD[i]);
        }else{
            return 0;
        }
    }
   return 1;
}
Relacao Operacoes::relacaoSoR(Relacao relacaoAB, Relacao relacaoBC)
{
    Relacao relacaoSoR;

    vector <int> conjuntoAB = relacaoAB.getImagem();
    vector <int> conjuntoABdominio = relacaoAB.getDominio();
    vector <int> conjuntoBCimagem = relacaoBC.getImagem();
    for(int i=0;i<conjuntoAB.size();i++){
      cout<<conjuntoBCimagem[i]<<endl;
    }
    for(int i=0;i<conjuntoAB.size();i++){
        relacaoSoR.setDominio(conjuntoABdominio[i]);
        relacaoSoR.setImagem(conjuntoBCimagem[i]);
    }
    return relacaoSoR;
}
void Operacoes::impressao(Relacao relacao)
{
    vector <int> conjuntoD = relacao.getDominio();
    vector <int> conjuntoI = relacao.getImagem();
    cout<<"Conjunto Dommínio"<<endl;
    cout<<"D ={";
    vector <int> apoio3;
    for(unsigned int i=0; i< conjuntoD.size(); i++)
    {
        int cont=0;

        for(unsigned int j=0; j<apoio3.size(); j++)
        {
            if(conjuntoD[i] == apoio3[j])
            {
                cont++;
            }
        }
        if(cont==0)
        {
            apoio3.push_back(conjuntoD[i]);
        }
    }
    for(unsigned int k=0; k < apoio3.size(); k++)
    {
        cout<<apoio3[k];
        if(k<apoio3.size()-1)
        {
            cout<<",";
        }
    }
    cout<<"} "<<endl;


    cout<<"Conjunto Imagem"<<endl;
    cout<<"I ={";
    vector <int> apoio4;
    for(unsigned int i=0; i< conjuntoI.size(); i++)
    {
        int cont=0;

        for(unsigned int j=0; j<apoio4.size(); j++)
        {
            if(conjuntoI[i] == apoio4[j])
            {
                cont++;
            }
        }
        if(cont==0)
        {
            apoio4.push_back(conjuntoI[i]);
        }
    }
    for(unsigned int k=0; k < apoio4.size(); k++)
    {
        cout<<apoio4[k];
        if(k<apoio4.size()-1)
        {
            cout<<",";
        }
    }
    cout<<"} "<<endl;

    // IMPRESSÃO DOS PARES DA RELAÇÃO
    cout<<"R: {";
    for(unsigned int i=0; i< conjuntoD.size(); i++)
    {
        cout<<"<"<<conjuntoD[i]<<","<<conjuntoI[i]<<">";
        if(i != conjuntoD.size()-1)
        {
            cout<<",";
        }
    }
    cout<<"}"<<endl;
}
