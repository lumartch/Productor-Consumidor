#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <iostream>
#include <unistd.h>
#include <queue>

using namespace std;

class Interfaz {
public:
    Interfaz();
    virtual ~Interfaz();
    void pantallaPrincipal();
private:
    queue <int> cola;
    int prodCont;
    int conCont;
    void turnoAleatorio();
    void productor();
    void consumidor();
};

#endif // INTERFAZ_H
