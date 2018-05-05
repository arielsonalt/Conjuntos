#ifndef OPERACOES_H
#define OPERACOES_H
#include "../include/Instancias.h"
#include "../include/Relacao.h"


class Operacoes
{
public:
    Operacoes();
    static bool pertence(vector <int>, vector <int>);
    static bool contidoPropriamente(vector <int>, vector <int>);
    static void uniao(Instancias);
    static void intersecao(Instancias);
    static void produtoCartesiano(Instancias);
    static void criarRelacao(vector <int>, vector <int>);
    static Relacao menorQue(vector<int>, vector<int>);
    static void impressao(Relacao);
    static Relacao maiorQue(vector<int>, vector<int>);
    static Relacao igualA(vector<int>, vector<int>);
    static Relacao serOQuadradoDe(vector<int>, vector<int>);
    static Relacao serRaizQuadradaDe(vector<int>, vector<int>);
    static Relacao relacaoDoUsuario(vector<int>, vector<int>);
    static void classificarRelacao(Relacao, Instancias);
    static bool funcional(Relacao, Instancias);
    static bool injetora(Relacao, Instancias);
    static bool total(Relacao, Instancias);
    static bool sobrejetora(Relacao, Instancias);
    static Relacao relacaoSoR(Relacao,Relacao);
    static void impressaoSoR(Relacao);


};

#endif // OPERACOES_H
