#ifndef RELACAO_H
#define RELACAO_H
#include <vector>

using namespace std;

class Relacao
{
    private:
        vector <int> dominio;
        vector <int> imagem;
        vector <int> dominio2;
        vector <int> imagem2;
    public:
        Relacao();
        vector <int> getDominio();
        void setDominio(int);
        vector <int> getImagem();
        void setImagem(int);
        vector <int> getDominio2();
        void setDominio2(int);
        vector <int> getImagem2();
        void setImagem2(int);

};

#endif // RELACAO_H
