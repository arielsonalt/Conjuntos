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
        static void menorQue(Instancias);
        static void maiorQue(Instancias);
        static void igualA(Instancias);
        static void serOQuadradoDe(Instancias);
        static void serRaizQuadradaDe(Instancias);
        static void relacaoDoUsuario(Instancias);
        static void classificarRelacao(Relacao, Instancias);
        static bool funcional(Relacao, Instancias);
        static bool injetora(Relacao, Instancias);
        static bool total(Relacao, Instancias);
        static bool sobrejetora(Relacao, Instancias);
        static void dominioImagemSoR(Relacao);

};

#endif // OPERACOES_H
