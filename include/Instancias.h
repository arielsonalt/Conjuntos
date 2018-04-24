#ifndef INSTANCIAS_H
#define INSTANCIAS_H
#include "../include/Universo.h"
using namespace std;

class Instancias
{
    private:
        Universo universo;
    public:
        Instancias();
        void lerTxt();
        void setUniverso(Universo);
        Universo getUniverso();
};

#endif // INSTANCIAS_H
