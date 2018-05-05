#include "include/Conjunto.h"
#include "include/Elemento.h"
#include "include/Instancias.h"
#include "include/Universo.h"
#include "include/Numero.h"
#include "include/Operacoes.h"
#include "include/Relacao.h"
#include <exception>
#include <locale>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    setlocale(LC_ALL,"portuguese");


    int numero=0;
   while(numero !=13){

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
if(instancia.getUniverso().getConjuntos().size() == 2){


    cout<<"                             ***********************************************************"<<endl;
    cout<<"                             ***********************************************************"<<endl;
    cout<<"                             *                                                         *"<<endl;
    cout<<"                             *   1-> PERTENCE / N�O PERTENCE?                          *"<<endl;
    cout<<"                             *   2-> CONTIDO OU IGUAL / N�O CONTIDO OU IGUAL           *"<<endl;
    cout<<"                             *   3-> CONTIDO PROPRIAMENTE / N�O CONTIDO PROPRIAMENTE   *"<<endl;
    cout<<"                             *   4-> UNI�O                                             *"<<endl;
    cout<<"                             *   5-> INTERSE��O                                        *"<<endl;
    cout<<"                             *   6-> PRODUTO CARTESIANO                                *"<<endl;
    cout<<"                             *   7-> MENOR QUE                                         *"<<endl;
    cout<<"                             *   8-> MAIOR QUE                                         *"<<endl;
    cout<<"                             *   9-> IGUAL A                                           *"<<endl;
    cout<<"                             *   10-> SER QUADRADO DE                                  *"<<endl;
    cout<<"                             *   11-> SER RAIZ DE                                      *"<<endl;
    cout<<"                             *   12-> RELA��O DO USU�RIO                               *"<<endl;
    cout<<"                             *                                             13-> SAIR   *"<<endl;
    cout<<"                             ***********************************************************"<<endl;
    cout<<"                             ***********************************************************"<<endl;
    cout<<"                                                     OP��O: ";cin>>numero;
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
            cout<<"                             N�O PERTENCE! O elemento N�O pertence ao conjunto."<<endl;
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
            cout<<"                     O PRIMEIRO CONJUNTO � CONTIDO OU IGUAL AO SEGUNDO VETOR"<<endl;
        }else{
            cout<<"                     N�O CONTIDO OU IGUAL!"<<endl;
            cout<<"                     O PRIMEIRO CONJUNTO � N�O CONTIDO OU IGUAL AO SEGUNDO VETOR"<<endl;
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
            cout<<"                     N�O CONTIDO PROPRIAMENTE!"<<endl;
            cout<<"                     O PRIMEIRO VETOR N�O ESTA CONTIDO PROPRIAMENTE NO SEGUNDO CONJUNTO"<<endl;
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
        if(instancia.getUniverso().getConjuntos().size() == 2){
            vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
            Conjunto conjunto = apoio[0];
            vector <int> vetorConjuntoA = conjunto.getConjunto();
            vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
            Conjunto conjunto2 = apoio2[1];
            vector <int> vetorConjuntoB = conjunto2.getConjunto();
            Relacao relacao;
            relacao = Operacoes::menorQue(vetorConjuntoA,vetorConjuntoB);
            Operacoes::classificarRelacao(relacao,instancia);
        }

        system("pause");
        system("cls");
    }else if(numero == 8 && instancia.getUniverso().getConjuntos().size()>1){
        vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
        Conjunto conjunto = apoio[0];
        vector <int> vetorConjuntoA = conjunto.getConjunto();
        vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
        Conjunto conjunto2 = apoio2[1];
        vector <int> vetorConjuntoB = conjunto2.getConjunto();

        Operacoes::classificarRelacao(Operacoes::maiorQue(vetorConjuntoA,vetorConjuntoB),instancia);
        system("pause");
        system("cls");
    }else if(numero == 9 && instancia.getUniverso().getConjuntos().size()>1){

        vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
        Conjunto conjunto = apoio[0];
        vector <int> vetorConjuntoA = conjunto.getConjunto();
        vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
        Conjunto conjunto2 = apoio2[1];
        vector <int> vetorConjuntoB = conjunto2.getConjunto();

        Operacoes::classificarRelacao(Operacoes::igualA(vetorConjuntoA,vetorConjuntoB),instancia);

        system("pause");
        system("cls");
    }else if(numero == 10 && instancia.getUniverso().getConjuntos().size()>1){
        vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
        Conjunto conjunto = apoio[0];
        vector <int> vetorConjuntoA = conjunto.getConjunto();
        vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
        Conjunto conjunto2 = apoio2[1];
        vector <int> vetorConjuntoB = conjunto2.getConjunto();

        Operacoes::classificarRelacao(Operacoes::serOQuadradoDe(vetorConjuntoA,vetorConjuntoB),instancia);

        system("pause");
        system("cls");
    }else if(numero == 11 && instancia.getUniverso().getConjuntos().size()>1){

        vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
        Conjunto conjunto = apoio[0];
        vector <int> vetorConjuntoA = conjunto.getConjunto();
        vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
        Conjunto conjunto2 = apoio2[1];
        vector <int> vetorConjuntoB = conjunto2.getConjunto();

        Operacoes::classificarRelacao(Operacoes::serRaizQuadradaDe(vetorConjuntoA,vetorConjuntoB),instancia);

        system("pause");
        system("cls");
    }else if(numero == 12 && instancia.getUniverso().getConjuntos().size()>1){

        vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
        Conjunto conjunto = apoio[0];
        vector <int> vetorConjuntoA = conjunto.getConjunto();

        vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
        Conjunto conjunto2 = apoio2[1];
        vector <int> vetorConjuntoB = conjunto2.getConjunto();

        cout<<"Conjunto A"<<endl;
        for(unsigned int i=0;i<vetorConjuntoA.size();i++){
            cout<<"Posic�o ["<<i<<"]"<<" = "<<vetorConjuntoA[i]<<endl;
        }
        cout<<"Conjunto B"<<endl;
        for(unsigned int j=0;j<vetorConjuntoB.size();j++){
            cout<<"Posic�o ["<<j<<"]"<<" = "<<vetorConjuntoB[j]<<endl;
        }
        Operacoes::classificarRelacao(Operacoes::relacaoDoUsuario(vetorConjuntoA,vetorConjuntoB),instancia);
        system("pause");
        system("cls");

    }else if(numero == 13){
        cout<<"                                                     SAIR"<<endl;
        system("pause");
    }else if(numero>='a' && numero<='z' || numero>='A' && numero<='Z'){
       cout<<"                                              **!OP��O INV�LIDA!**"<<endl;
        system("pause");
        system("cls");


    }else{
         cout<<"                                              **!OP��O INV�LIDA!**"<<endl;
        system("pause");
        system("cls");
    }
}else if(instancia.getUniverso().getConjuntos().size() == 3){


    cout<<"                             ***********************************************************"<<endl;
    cout<<"                             ***********************************************************"<<endl;
    cout<<"                             *                                                         *"<<endl;
    cout<<"                             *   1-> MENOR QUE                                         *"<<endl;
    cout<<"                             *   2-> MAIOR QUE                                         *"<<endl;
    cout<<"                             *   3-> IGUAL A                                           *"<<endl;
    cout<<"                             *   4-> SER QUADRADO DE                                   *"<<endl;
    cout<<"                             *   5-> SER RAIZ DE                                       *"<<endl;
    cout<<"                             *   6-> RELA��O DO USU�RIO                                *"<<endl;
    cout<<"                             *                                             7-> SAIR    *"<<endl;
    cout<<"                             ***********************************************************"<<endl;
    cout<<"                             ***********************************************************"<<endl;
    cout<<""<<endl;

    Relacao relacaoAB,relacaoBC;
    cout<<"Escolha a rela��o para R:A->B"<<endl;
    cout<<"OP��O PARA A->B: ";cin>>numero;
    if(numero == 1){
        vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
        Conjunto conjunto = apoio[0];
        vector <int> vetorConjuntoA = conjunto.getConjunto();

        vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
        Conjunto conjunto2 = apoio2[1];
        vector <int> vetorConjuntoB = conjunto2.getConjunto();

        relacaoAB = Operacoes::menorQue(vetorConjuntoA,vetorConjuntoB);
        system("pause");
    }
    if(numero == 2){
        vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
        Conjunto conjunto = apoio[0];
        vector <int> vetorConjuntoA = conjunto.getConjunto();

        vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
        Conjunto conjunto2 = apoio2[1];
        vector <int> vetorConjuntoB = conjunto2.getConjunto();

        relacaoAB = Operacoes::maiorQue(vetorConjuntoA,vetorConjuntoB);
        system("pause");
    }
    if(numero == 3){
        vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
        Conjunto conjunto = apoio[0];
        vector <int> vetorConjuntoA = conjunto.getConjunto();

        vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
        Conjunto conjunto2 = apoio2[1];
        vector <int> vetorConjuntoB = conjunto2.getConjunto();

        relacaoAB = Operacoes::igualA(vetorConjuntoA,vetorConjuntoB);
        system("pause");
    }
    if(numero == 4){
        vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
        Conjunto conjunto = apoio[0];
        vector <int> vetorConjuntoA = conjunto.getConjunto();

        vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
        Conjunto conjunto2 = apoio2[1];
        vector <int> vetorConjuntoB = conjunto2.getConjunto();

        relacaoAB = Operacoes::serOQuadradoDe(vetorConjuntoA,vetorConjuntoB);
        system("pause");

    }
    if(numero == 5){
        vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
        Conjunto conjunto = apoio[0];
        vector <int> vetorConjuntoA = conjunto.getConjunto();

        vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
        Conjunto conjunto2 = apoio2[1];
        vector <int> vetorConjuntoB = conjunto2.getConjunto();

        relacaoAB = Operacoes::serRaizQuadradaDe(vetorConjuntoA,vetorConjuntoB);
        system("pause");
    }
    if(numero == 6){
        vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
        Conjunto conjunto = apoio[0];
        vector <int> vetorConjuntoA = conjunto.getConjunto();

        vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
        Conjunto conjunto2 = apoio2[1];
        vector <int> vetorConjuntoB = conjunto2.getConjunto();

        cout<<"Conjunto A"<<endl;
        for(unsigned int i=0;i<vetorConjuntoA.size();i++){
            cout<<"Posic�o ["<<i<<"]"<<" = "<<vetorConjuntoA[i]<<endl;
        }
        cout<<"Conjunto B"<<endl;
        for(unsigned int j=0;j<vetorConjuntoB.size();j++){
            cout<<"Posic�o ["<<j<<"]"<<" = "<<vetorConjuntoB[j]<<endl;
        }

        relacaoAB = Operacoes::relacaoDoUsuario(vetorConjuntoA,vetorConjuntoB);

        system("pause");
    }
        if(numero == 7){
        break;
        system("pause");

    }
     cout<<"Escolha a rela��o para S:B->C"<<endl;
    cout<<"OP��O PARA B->C: ";cin>>numero;
    if(numero == 1){
        vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
        Conjunto conjunto2 = apoio2[1];
        vector <int> vetorConjuntoB = conjunto2.getConjunto();

        vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
        Conjunto conjunto = apoio[2];
        vector <int> vetorConjuntoC = conjunto.getConjunto();

        relacaoBC = Operacoes::menorQue(vetorConjuntoB,vetorConjuntoC);
        system("pause");
    }
    if(numero == 2){

        vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
        Conjunto conjunto2 = apoio2[1];
        vector <int> vetorConjuntoB = conjunto2.getConjunto();

        vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
        Conjunto conjunto = apoio[2];
        vector <int> vetorConjuntoC = conjunto.getConjunto();

        relacaoBC = Operacoes::maiorQue(vetorConjuntoB,vetorConjuntoC);
        system("pause");
    }
    if(numero == 3){
        vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
        Conjunto conjunto2 = apoio2[1];
        vector <int> vetorConjuntoB = conjunto2.getConjunto();

        vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
        Conjunto conjunto = apoio[2];
        vector <int> vetorConjuntoC = conjunto.getConjunto();

        relacaoBC = Operacoes::igualA(vetorConjuntoB,vetorConjuntoC);
        system("pause");
    }
    if(numero == 4){
        vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
        Conjunto conjunto2 = apoio2[1];
        vector <int> vetorConjuntoB = conjunto2.getConjunto();

        vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
        Conjunto conjunto = apoio[2];
        vector <int> vetorConjuntoC = conjunto.getConjunto();

        relacaoBC = Operacoes::serOQuadradoDe(vetorConjuntoB,vetorConjuntoC);
        system("pause");
    }
    if(numero == 5){
        vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
        Conjunto conjunto2 = apoio2[1];
        vector <int> vetorConjuntoB = conjunto2.getConjunto();

        vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
        Conjunto conjunto = apoio[2];
        vector <int> vetorConjuntoC = conjunto.getConjunto();

       relacaoBC = Operacoes::serRaizQuadradaDe(vetorConjuntoB,vetorConjuntoC);
        system("pause");
    }
    if(numero == 6){
        vector <Conjunto> apoio2 = instancia.getUniverso().getConjuntos();
        Conjunto conjunto2 = apoio2[1];
        vector <int> vetorConjuntoB = conjunto2.getConjunto();

        vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
        Conjunto conjunto = apoio[2];
        vector <int> vetorConjuntoC = conjunto.getConjunto();

        cout<<"Conjunto B"<<endl;
        for(unsigned int i=0;i<vetorConjuntoB.size();i++){
            cout<<"Posic�o ["<<i<<"]"<<" = "<<vetorConjuntoB[i]<<endl;
        }
        cout<<"Conjunto C"<<endl;
        for(unsigned int j=0;j<vetorConjuntoC.size();j++){
            cout<<"Posic�o ["<<j<<"]"<<" = "<<vetorConjuntoC[j]<<endl;
        }

        relacaoBC = Operacoes::relacaoDoUsuario(vetorConjuntoB,vetorConjuntoC);
        system("pause");
    }
    if(numero == 7){
        break;
        system("pause");
    }
    Relacao relacaoSoR;
    relacaoSoR = Operacoes::relacaoSoR(relacaoAB,relacaoBC);

    Universo u;
    vector <Conjunto> apoio = instancia.getUniverso().getConjuntos();
    Conjunto conjunto1 = apoio[0];
    u.setConjuto(conjunto1);
    Conjunto conjunto2 = apoio[2];
    u.setConjuto(conjunto2);
    Instancias inst;
    inst.setUniverso(u);

    Operacoes::impressao(relacaoSoR);

    Operacoes::classificarRelacao(relacaoSoR,inst);
    system("pause");



}

}



}
