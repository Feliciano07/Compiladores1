#ifndef ARREGLOS_H
#define ARREGLOS_H
#include "Herramientas/objeto.h"

class Arreglos
{
public:
    Arreglos();
    int F,C,N;

    Objeto* array;

    int tipo_;

    Arreglos(int F);
    Arreglos(int F,int C);
    Arreglos(int F,int C,int N);

    QString setDato1(Objeto nuevo,int i,int tipo);
    QString setDato2(Objeto nuevo,int i,int j,int tipo);
    QString setDato3(Objeto nuevo,int i,int j,int k,int tipo);


    Objeto getDato1(int i);
    Objeto getDato2(int i,int j);
    Objeto getDato3(int i,int j,int k);
};

#endif // ARREGLOS_H
