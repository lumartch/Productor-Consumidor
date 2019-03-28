#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <iostream>
#include <unistd.h>
#include <queue>
/* Librerías necesarias para el funcionamiento de kbhit */
#include <termios.h>
#include <cstdlib>
#include <cstdio>
#include <fcntl.h>

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
    int productor();
    int consumidor();
    int kbhit(void);
};

#endif // INTERFAZ_H
