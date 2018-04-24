#include "include/Conjunto.h"
#include "include/Elemento.h"
#include "include/Instancias.h"
#include "include/Universo.h"
#include "include/Numero.h"
#include "include/Operacoes.h"
#include <exception>
#include <locale>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL,"portuguese");

   int numero=0;

   while(numero != 7){

    Instancias instancia;
   cout<<endl;
    cout<<"DADOS DE ENTRADA";
   vector <Conjunto> conjuntos = instancia.getUniverso().getConjuntos();
   vector <Numero> numeros = instancia.getUniverso().getNumeros();
    cout<<""<<endl;
   for(int i=0;i< conjuntos.size();i++){
        cout<<conjuntos[i].getNome()<<" ={";
        vector <int> elementoConjunto = conjuntos[i].getConjunto();
        for(int j=0; j< elementoConjunto.size();j++){
            cout<<elementoConjunto[j];
            if(j<elementoConjunto.size()-1){cout<<",";}
        }
        cout<<"} "<<endl;
   }
   for(int k=0;k< numeros.size();k++){
        cout<<numeros[k].getNome()<<" = "<<numeros[k].getNumero();
        cout<<endl;
   }



    cout<<"                             ***********************************************************"<<endl;
    cout<<"                             ***********************************************************"<<endl;
    cout<<"                             *                                                         *"<<endl;
    cout<<"                             *   1-> PERTENCE / NÃO PERTENCE?                          *"<<endl;
    cout<<"                             *   2-> CONTIDO OU IGUAL / NÃO CONTIDO OU IGUAL           *"<<endl;
    cout<<"                             *   3-> CONTIDO PROPRIAMENTE / NÃO CONTIDO PROPRIAMENTE   *"<<endl;
    cout<<"                             *   4-> UNIÃO                                             *"<<endl;
    cout<<"                             *   5-> INTERSEÇÃO                                        *"<<endl;
    cout<<"                             *   6-> PRODUTO CARTESIANO                                *"<<endl;
    cout<<"                             *   7-> MENOR QUE                                         *"<<endl;
    cout<<"                             *   8-> MAIOR QUE                                         *"<<endl;
    cout<<"                             *   9-> IGUAL A                                           *"<<endl;
    cout<<"                             *   10-> SER QUADRADO DE                                  *"<<endl;
    cout<<"                             *   11-> SER RAIZ DE                                      *"<<endl;
    cout<<"                             *   12-> RELAÇÃO DO USUÁRIO                               *"<<endl;
    cout<<"                             *                                             13-> SAIR   *"<<endl;
    cout<<"                             ***********************************************************"<<endl;
    cout<<"                             ***********************************************************"<<endl;
    cout<<"                                                     OPÇÃO: ";cin>>numero;
    cout<<""<<endl;


    if(numero == 1 && instancia.getUniverso().getNumeros().size()>0){
        vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
        Conjunto conjunto = apoio[0];
        vector <int> vetorConjunto = conjunto.getConjunto();

        vector <Numero> apoio2 = instancia.getUniverso().getNumeros();
        Numero numero = apoio2[0];
        vector <int> vetorNumero;
        vetorNumero.push_back(apoio2[0].getNumero());
        vetorNumero.push_back('-');


        if(Operacoes::pertence(vetorConjunto,vetorNumero)){
            cout<<"                             PERTENCE! O elemento pertence ao conjunto."<<endl;
        }else{
            cout<<"                             NÃO PERTENCE! O elemento NÃO pertence ao conjunto."<<endl;
        }


        system("pause");
        system("cls");
    }else if(numero == 2 && instancia.getUniverso().getConjuntos().size()>1){
        vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
        Conjunto conjunto = apoio[0];
        vector <int> vetorConjunto = conjunto.getConjunto();


        vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
        Conjunto conjunto2 = apoio2[1];
        vector <int> vetorConjunto2 = conjunto2.getConjunto();
        if(Operacoes::pertence(vetorConjunto, vetorConjunto2)){
            cout<<"                     CONTIDO OU IGUAL!"<<endl;
            cout<<"                     O PRIMEIRO CONJUNTO É CONTIDO OU IGUAL AO SEGUNDO VETOR"<<endl;
        }else{
            cout<<"                     NÃO CONTIDO OU IGUAL!"<<endl;
            cout<<"                     O PRIMEIRO CONJUNTO É NÃO CONTIDO OU IGUAL AO SEGUNDO VETOR"<<endl;
        }

        system("pause");
        system("cls");
    }else if(numero == 3 && instancia.getUniverso().getConjuntos().size()>1){
        vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
        Conjunto conjunto = apoio[0];
        vector <int> vetorConjunto = conjunto.getConjunto();

        vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
        Conjunto conjunto2 = apoio2[1];
        vector <int> vetorConjunto2 = conjunto2.getConjunto();
        if(Operacoes::contidoPropriamente(vetorConjunto, vetorConjunto2)){
            cout<<"                     CONTIDO PROPRIAMENTE! O PRIMEIRO VETOR ESTA CONTIDO PROPRIAMENTE"<<endl;
            cout<<"                     O PRIMEIRO VETOR ESTA CONTIDO PROPRIAMENTE"<<endl;
        }else{
            cout<<"                     NÃO CONTIDO PROPRIAMENTE!"<<endl;
            cout<<"                     O PRIMEIRO VETOR NÃO ESTA CONTIDO PROPRIAMENTE NO SEGUNDO CONJUNTO"<<endl;
        }
        system("pause");
        system("cls");
    }else if(numero == 4 && instancia.getUniverso().getConjuntos().size()>1){
        Operacoes::uniao(instancia);
        system("pause");
        system("cls");
    }else if(numero == 5 && instancia.getUniverso().getConjuntos().size()>1){
        Operacoes::intersecao(instancia);
        system("pause");
        system("cls");
    }else if(numero == 6 && instancia.getUniverso().getConjuntos().size()>1){
        Operacoes::produtoCartesiano(instancia);
        system("pause");
        system("cls");
    }else if(numero == 7 && instancia.getUniverso().getConjuntos().size()>1){
        Operacoes::menorQue(instancia);
        system("pause");
        system("cls");
    }else if(numero == 8 && instancia.getUniverso().getConjuntos().size()>1){
        Operacoes::maiorQue(instancia);
        system("pause");
        system("cls");
    }else if(numero == 9 && instancia.getUniverso().getConjuntos().size()>1){
        Operacoes::igualA(instancia);
        system("pause");
        system("cls");
    }else if(numero == 10 && instancia.getUniverso().getConjuntos().size()>1){
        Operacoes::serOQuadradoDe(instancia);
        system("pause");
        system("cls");
    }else if(numero == 11 && instancia.getUniverso().getConjuntos().size()>1){
        Operacoes::serRaizQuadradaDe(instancia);
        system("pause");
        system("cls");
    }else if(numero == 12 && instancia.getUniverso().getConjuntos().size()>1){
        Operacoes::relacaoDoUsuario(instancia);
        system("pause");
        system("cls");
    }else if(numero == 13){
        cout<<"                                                     SAIR"<<endl;
        system("pause");
    }else {
        cout<<"                                              **!OPÇÃO INVÁLIDA!**"<<endl;
        system("pause");
        system("cls");
    }



   }



}
