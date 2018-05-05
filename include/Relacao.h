#ifndef RELACAO_H
#define RELACAO_H
#include <vector>

using namespace std;

class Relacao
{
private:
    vector <int> dominio;
    vector <int> imagem;

public:
    Relacao();
    vector <int> getDominio();
    void setDominio(int);
    vector <int> getImagem();
    void setImagem(int);


};

#endif // RELACAO_H
