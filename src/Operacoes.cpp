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
    //ctor

}

void Operacoes::uniao(Instancias i){

    vector <int> uniao;

    vector <Conjunto> conjuntos = i.getUniverso().getConjuntos();

    for(int i=0; i<conjuntos.size();i++){

            Conjunto c = conjuntos[i];
             vector <int> conjunto = c.getConjunto();
        for(int j=0;j<conjunto.size();j++){
            vector<int>::iterator it;
            int num = conjunto[j];
            it = find(uniao.begin(), uniao.end(),num);
            if(it == uniao.end()){
                uniao.push_back(conjunto[j]);
            }
        }
    }
    cout<<"          A uniao dos comjuntos e: {";

    for(int k=0; k<uniao.size();k++){
        if(k != 0 && k != uniao.size()){cout<<",";}
        cout<<uniao[k];
    }
    cout<<"}"<<endl;
    cout<<endl;

}
void Operacoes::intersecao(Instancias i){
    setlocale(LC_ALL,"portuguese");
    vector <int> intersecao;

    vector <Conjunto> conjuntos = i.getUniverso().getConjuntos();
    int total = conjuntos.size();
    int cont=0;
    int apoio=0;
    int numero;
    for(int i=0; i<conjuntos.size();i++){
            Conjunto c = conjuntos[i];
             vector <int> conjunto = c.getConjunto();

        for(int j=0;j<conjunto.size();j++){
                apoio=0;
                cont=0;
                numero = conjunto[j];
            for(int l=0; l < conjuntos.size();l++){
                Conjunto c2 = conjuntos[l];
                vector <int> conjunto2 = c2.getConjunto();
                    vector<int>::iterator it;
                    int num = conjunto[j];
                    it = find(conjunto2.begin(), conjunto2.end(),num);
                    vector<int>::iterator it2;
                    it2 = find(intersecao.begin(), intersecao.end(),num);
                    if(it != conjunto2.end() && it2 == intersecao.end()){
                        cont++;
                        apoio++;
                    }
            }
            if(apoio == total){
            intersecao.push_back(numero);
            }
        }

    }
    cout<<"                     A INTERSECAO DOS CONJUNTOS E: {";
    for(int k=0; k<intersecao.size();k++){
        if(k != 0 && k != intersecao.size()){cout<<",";}
        cout<<intersecao[k];

    }
    cout<<"}"<<endl;
    cout<<endl;

}
void Operacoes::produtoCartesiano(Instancias i){

    setlocale(LC_ALL,"portuguese");

    vector <Conjunto> apoio = i.getUniverso().getConjuntos();
    Conjunto conjunto = apoio[0];
    vector <int> vetorConjunto = conjunto.getConjunto();

    vector <Conjunto> apoio2 = i.getUniverso().getConjuntos();
    Conjunto conjunto2 = apoio2[1];
    vector <int> vetorConjunto2 = conjunto2.getConjunto();

    cout<<"O PRODUTO CARTESIANO ENTRE O PRIMEIRO E O SEGUNDO CONJUNTO E: ";
    for(int i =0 ; i<vetorConjunto.size();i++){

                cout<<endl;

        for(int j=0; j<vetorConjunto2.size();j++){
            cout<<" {"<<vetorConjunto[i]<<","<<vetorConjunto2[j]<<"}";
        }
    }
    cout<<endl;
}
bool Operacoes::pertence(vector <int> a, vector<int> b){
    setlocale(LC_ALL,"portuguese");
    int tamanhoVetorA = a.size();
    int tamanhoVetorB = b.size();

    int contador1=0;
    int contador2=0;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            if(a[i] == b[j]){
                contador1++;
            }
        }
    }

    if(b[1] == '-'){
      for(int j=0;j<a.size();j++){
            if(a[j] == b[0]){
                return 1;
            }
    }
    return 0;
    }

    if(contador1 == tamanhoVetorA ){
        return 1;
    }else{
        return 0;
    }

}
bool Operacoes::contidoPropriamente(vector <int> a, vector <int> b){
    setlocale(LC_ALL,"portuguese");

    if(pertence(a,b) && (b.size()!= a.size())){
        return 1;
    }else{
        return 0;
    }
}
void Operacoes::criarRelacao(vector<int>, vector<int>){

}
void Operacoes::menorQue(Instancias instancia){
    vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
    Conjunto conjunto = apoio[0];
    vector <int> vetorConjuntoA = conjunto.getConjunto();


    vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
    Conjunto conjunto2 = apoio2[1];
    vector <int> vetorConjuntoB = conjunto2.getConjunto();
    Relacao relacao;
    for(int i=0; i<vetorConjuntoA.size();i++){
        for(int j=0;j<vetorConjuntoB.size();j++){
            if(vetorConjuntoA[i] < vetorConjuntoB[j]){
                relacao.setDominio(vetorConjuntoA[i]);
                relacao.setImagem(vetorConjuntoB[j]);
            }
        }
    }

    vector <int> conjuntoD = relacao.getDominio();
    vector <int> conjuntoI = relacao.getImagem();
    cout<<"Conjunto Dommínio"<<endl;
    cout<<"A ={";
    vector <int> apoio3;
    for(int i=0;i< conjuntoD.size();i++){
            int cont=0;

        for(int j=0;j<apoio3.size();j++){
            if(conjuntoD[i] == apoio3[j]){
                cont++;
            }
        }
        if(cont==0){
            apoio3.push_back(conjuntoD[i]);
        }
    }
    for(int k=0;k < apoio3.size();k++){
        cout<<apoio3[k];
        if(k<apoio3.size()-1){cout<<",";}
    }
    cout<<"} "<<endl;


    cout<<"Conjunto Imagem"<<endl;
    cout<<"B ={";
    vector <int> apoio4;
    for(int i=0;i< conjuntoI.size();i++){
            int cont=0;

        for(int j=0;j<apoio4.size();j++){
            if(conjuntoI[i] == apoio4[j]){
                cont++;
            }
        }
        if(cont==0){
            apoio4.push_back(conjuntoI[i]);
        }
    }
    for(int k=0;k < apoio4.size();k++){
        cout<<apoio4[k];
        if(k<apoio4.size()-1){cout<<",";}
    }
    cout<<"} "<<endl;

    cout<<"R: {";
    for(int i=0;i< conjuntoD.size();i++){
        cout<<"<"<<conjuntoD[i]<<","<<conjuntoI[i]<<">";
        if(i != conjuntoD.size()-1){
            cout<<",";
        }
    }
    cout<<"}"<<endl;
}
void Operacoes::maiorQue(Instancias instancia){
    vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
    Conjunto conjunto = apoio[0];
    vector <int> vetorConjuntoA = conjunto.getConjunto();


    vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
    Conjunto conjunto2 = apoio2[1];
    vector <int> vetorConjuntoB = conjunto2.getConjunto();
    Relacao relacao;
    for(int i=0; i<vetorConjuntoB.size();i++){
        for(int j=0;j<vetorConjuntoA.size();j++){
            if(vetorConjuntoB[i] < vetorConjuntoA[j]){
                relacao.setDominio(vetorConjuntoB[i]);
                relacao.setImagem(vetorConjuntoA[j]);
            }
        }
    }
    vector <int> conjuntoD = relacao.getDominio();
    vector <int> conjuntoI = relacao.getImagem();
    cout<<"Conjunto Dommínio"<<endl;
    cout<<"A ={";
    vector <int> apoio3;
    for(int i=0;i< conjuntoD.size();i++){
            int cont=0;

        for(int j=0;j<apoio3.size();j++){
            if(conjuntoD[i] == apoio3[j]){
                cont++;
            }
        }
        if(cont==0){
            apoio3.push_back(conjuntoD[i]);
        }
    }
    for(int k=0;k < apoio3.size();k++){
        cout<<apoio3[k];
        if(k<apoio3.size()-1){cout<<",";}
    }
    cout<<"} "<<endl;


    cout<<"Conjunto Imagem"<<endl;
    cout<<"B ={";
    vector <int> apoio4;
    for(int i=0;i< conjuntoI.size();i++){
            int cont=0;

        for(int j=0;j<apoio4.size();j++){
            if(conjuntoI[i] == apoio4[j]){
                cont++;
            }
        }
        if(cont==0){
            apoio4.push_back(conjuntoI[i]);
        }
    }
    for(int k=0;k < apoio4.size();k++){
        cout<<apoio4[k];
        if(k<apoio4.size()-1){cout<<",";}
    }
    cout<<"} "<<endl;
   cout<<"R: {";
    for(int i=0;i< conjuntoD.size();i++){
        cout<<"<"<<conjuntoD[i]<<","<<conjuntoI[i]<<">";
        if(i != conjuntoD.size()-1){
            cout<<",";
        }
    }
    cout<<"}"<<endl;
}
void Operacoes::igualA(Instancias instancia){
    vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
    Conjunto conjunto = apoio[0];
    vector <int> vetorConjuntoA = conjunto.getConjunto();


    vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
    Conjunto conjunto2 = apoio2[1];
    vector <int> vetorConjuntoB = conjunto2.getConjunto();
    Relacao relacao;
    for(int i=0; i<vetorConjuntoA.size();i++){
        for(int j=0;j<vetorConjuntoB.size();j++){
            if(vetorConjuntoA[i] == vetorConjuntoB[j]){
                relacao.setDominio(vetorConjuntoA[i]);
                relacao.setImagem(vetorConjuntoB[j]);
            }
        }
    }

    vector <int> conjuntoD = relacao.getDominio();
    vector <int> conjuntoI = relacao.getImagem();
    cout<<"Conjunto Dommínio"<<endl;
    cout<<"A ={";
    vector <int> apoio3;
    for(int i=0;i< conjuntoD.size();i++){
            int cont=0;

        for(int j=0;j<apoio3.size();j++){
            if(conjuntoD[i] == apoio3[j]){
                cont++;
            }
        }
        if(cont==0){
            apoio3.push_back(conjuntoD[i]);
        }
    }
    for(int k=0;k < apoio3.size();k++){
        cout<<apoio3[k];
        if(k<apoio3.size()-1){cout<<",";}
    }
    cout<<"} "<<endl;


    cout<<"Conjunto Imagem"<<endl;
    cout<<"B ={";
    vector <int> apoio4;
    for(int i=0;i< conjuntoI.size();i++){
            int cont=0;

        for(int j=0;j<apoio4.size();j++){
            if(conjuntoI[i] == apoio4[j]){
                cont++;
            }
        }
        if(cont==0){
            apoio4.push_back(conjuntoI[i]);
        }
    }
    for(int k=0;k < apoio4.size();k++){
        cout<<apoio4[k];
        if(k<apoio4.size()-1){cout<<",";}
    }
    cout<<"} "<<endl;

    cout<<"R: {";
    for(int i=0;i< conjuntoD.size();i++){
        cout<<"<"<<conjuntoD[i]<<","<<conjuntoI[i]<<">";
        if(i != conjuntoD.size()-1){
            cout<<",";
        }
    }
    cout<<"}"<<endl;
}
void Operacoes::serOQuadradoDe(Instancias instancia){
    vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
    Conjunto conjunto = apoio[0];
    vector <int> vetorConjuntoA = conjunto.getConjunto();


    vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
    Conjunto conjunto2 = apoio2[1];
    vector <int> vetorConjuntoB = conjunto2.getConjunto();
    Relacao relacao;
    for(int i=0; i<vetorConjuntoA.size();i++){
        for(int j=0;j<vetorConjuntoB.size();j++){
            if(sqrt(vetorConjuntoA[i]) == vetorConjuntoB[j]){
                relacao.setDominio(vetorConjuntoA[i]);
                relacao.setImagem(vetorConjuntoB[j]);
            }
        }
    }
    vector <int> conjuntoD = relacao.getDominio();
    vector <int> conjuntoI = relacao.getImagem();
    cout<<"Conjunto Dommínio"<<endl;
    cout<<"A ={";
    vector <int> apoio3;
    for(int i=0;i< conjuntoD.size();i++){
            int cont=0;

        for(int j=0;j<apoio3.size();j++){
            if(conjuntoD[i] == apoio3[j]){
                cont++;
            }
        }
        if(cont==0){
            apoio3.push_back(conjuntoD[i]);
        }
    }
    for(int k=0;k < apoio3.size();k++){
        cout<<apoio3[k];
        if(k<apoio3.size()-1){cout<<",";}
    }
    cout<<"} "<<endl;


    cout<<"Conjunto Imagem"<<endl;
    cout<<"B ={";
    vector <int> apoio4;
    for(int i=0;i< conjuntoI.size();i++){
            int cont=0;

        for(int j=0;j<apoio4.size();j++){
            if(conjuntoI[i] == apoio4[j]){
                cont++;
            }
        }
        if(cont==0){
            apoio4.push_back(conjuntoI[i]);
        }
    }
    for(int k=0;k < apoio4.size();k++){
        cout<<apoio4[k];
        if(k<apoio4.size()-1){cout<<",";}
    }
    cout<<"} "<<endl;
   cout<<"R: {";
    for(int i=0;i< conjuntoD.size();i++){
        cout<<"<"<<conjuntoD[i]<<","<<conjuntoI[i]<<">";
        if(i != conjuntoD.size()-1){
            cout<<",";
        }
    }
    cout<<"}"<<endl;
}
void Operacoes::serRaizQuadradaDe(Instancias instancia){
    vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
    Conjunto conjunto = apoio[0];
    vector <int> vetorConjuntoA = conjunto.getConjunto();


    vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
    Conjunto conjunto2 = apoio2[1];
    vector <int> vetorConjuntoB = conjunto2.getConjunto();
    Relacao relacao;
    for(int i=0; i<vetorConjuntoA.size();i++){
        for(int j=0;j<vetorConjuntoB.size();j++){
            if(vetorConjuntoA[i] == sqrt(vetorConjuntoB[j])){
                relacao.setDominio(vetorConjuntoA[i]);
                relacao.setImagem(vetorConjuntoB[j]);
            }
        }
    }
    vector <int> conjuntoD = relacao.getDominio();
    vector <int> conjuntoI = relacao.getImagem();
    cout<<"Conjunto Dommínio"<<endl;
    cout<<"A ={";
    vector <int> apoio3;
    for(int i=0;i< conjuntoD.size();i++){
            int cont=0;

        for(int j=0;j<apoio3.size();j++){
            if(conjuntoD[i] == apoio3[j]){
                cont++;
            }
        }
        if(cont==0){
            apoio3.push_back(conjuntoD[i]);
        }
    }
    for(int k=0;k < apoio3.size();k++){
        cout<<apoio3[k];
        if(k<apoio3.size()-1){cout<<",";}
    }
    cout<<"} "<<endl;


    cout<<"Conjunto Imagem"<<endl;
    cout<<"B ={";
    vector <int> apoio4;
    for(int i=0;i< conjuntoI.size();i++){
            int cont=0;

        for(int j=0;j<apoio4.size();j++){
            if(conjuntoI[i] == apoio4[j]){
                cont++;
            }
        }
        if(cont==0){
            apoio4.push_back(conjuntoI[i]);
        }
    }
    for(int k=0;k < apoio4.size();k++){
        cout<<apoio4[k];
        if(k<apoio4.size()-1){cout<<",";}
    }
    cout<<"} "<<endl;
    cout<<"R: {";
    for(int i=0;i< conjuntoD.size();i++){
        cout<<"<"<<conjuntoD[i]<<","<<conjuntoI[i]<<">";
        if(i != conjuntoD.size()-1){
            cout<<",";
        }
    }
    cout<<"}"<<endl;
}
void Operacoes::relacaoDoUsuario(Instancias instancia){
    char sair;
    vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
    Conjunto conjunto = apoio[0];
    vector <int> vetorConjuntoA = conjunto.getConjunto();

    vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
    Conjunto conjunto2 = apoio2[1];
    vector <int> vetorConjuntoB = conjunto2.getConjunto();

    cout<<"Conjunto A"<<endl;
    for(int i=0;i<vetorConjuntoA.size();i++){
        cout<<"Posicão ["<<i<<"]"<<" = "<<vetorConjuntoA[i]<<endl;
    }
    cout<<"Conjunto B"<<endl;
    for(int j=0;j<vetorConjuntoB.size();j++){
        cout<<"Posicão ["<<j<<"]"<<" = "<<vetorConjuntoB[j]<<endl;
    }


    Relacao relacao;
 while(sair != 's'){
    int numA,numB;
    cout<<"Digite a posição do elemento pertencenta ao conjunto A: "<<endl;
    cout<<"Posição A: ";cin>>numA;
    cout<<"Digite a posição do elemento pertencenta ao conjunto B: "<<endl;
    cout<<"Posição B: ";cin>>numB;
    relacao.setDominio(vetorConjuntoA[numA]);
    relacao.setImagem(vetorConjuntoB[numB]);
    cout<<"sair? s/n"<<endl;
    cin>>sair;

 }


    vector <int> conjuntoD = relacao.getDominio();
    vector <int> conjuntoI = relacao.getImagem();
    cout<<"Conjunto Dommínio"<<endl;
    cout<<"A ={";
    vector <int> apoio3;
    for(int i=0;i< conjuntoD.size();i++){
            int cont=0;

        for(int j=0;j<apoio3.size();j++){
            if(conjuntoD[i] == apoio3[j]){
                cont++;
            }
        }
        if(cont==0){
            apoio3.push_back(conjuntoD[i]);
        }
    }
    for(int k=0;k < apoio3.size();k++){
        cout<<apoio3[k];
        if(k<apoio3.size()-1){cout<<",";}
    }
    cout<<"} "<<endl;


    cout<<"Conjunto Imagem"<<endl;
    cout<<"B ={";
    vector <int> apoio4;
    for(int i=0;i< conjuntoI.size();i++){
            int cont=0;

        for(int j=0;j<apoio4.size();j++){
            if(conjuntoI[i] == apoio4[j]){
                cont++;
            }
        }
        if(cont==0){
            apoio4.push_back(conjuntoI[i]);
        }
    }
    for(int k=0;k < apoio4.size();k++){
        cout<<apoio4[k];
        if(k<apoio4.size()-1){cout<<",";}
    }
    cout<<"} "<<endl;

    cout<<"R: {";
    for(int i=0;i< conjuntoD.size();i++){
        cout<<"<"<<conjuntoD[i]<<","<<conjuntoI[i]<<">";
        if(i != conjuntoD.size()-1){
            cout<<",";
        }
    }
    cout<<"}"<<endl;
}


