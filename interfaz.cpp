#include "interfaz.h"

Interfaz::Interfaz() {
    prodCont = 0;
    conCont = 0;
    pantallaPrincipal();
}

Interfaz::~Interfaz() {
    //dtor
}

void Interfaz::pantallaPrincipal() {
    cout << "+-------------------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                                    Productor <->  Consumidor                                                  |" << endl;
    cout << "+-------------------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                   Turno:                      Productor Status:                   Consumidor Status:                          |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15| 16| 17| 18| 19| 20| 21| 22| 23| 24| 25| 26| 27| 28| 29| 30| 31|" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
    srand(time(nullptr));
    turnoAleatorio();
}

void Interfaz::turnoAleatorio() {
    while(true){
        cout << "\033[4;28H          " << endl;
        int turno = rand() % 21;
        if(turno % 2){
            cout << "\033[4;28HProductor" << endl;
            sleep(1);
            productor();
        }
        else{
            cout << "\033[4;28HConsumidor" << endl;
            sleep(1);
            consumidor();
        }
    }
}

void Interfaz::productor() {
    if(cola.size() == 32){
        cout << "\033[4;67H           " << endl;
        cout << "\033[4;67HLleno" << endl;
        return;
    }
    cout << "\033[4;67HProduciendo" << endl;
    cout << "\033[4;104H           " << endl;
    cout << "\033[4;104HEsperando" << endl;
    for(int i = 0; i < 4; i++, prodCont++){
        if(prodCont == 32){
            prodCont = 0;
        }
        cout << "\033[8;" << (prodCont*4) + 3 << "H*" << endl;
        cola.push(1);
        sleep(1);
    }
    cout << "\033[4;67H           " << endl;
    cout << "\033[4;67HEsperando" << endl;
    sleep(1);
}

void Interfaz::consumidor() {
    if(cola.empty()){
        cout << "\033[4;104H           " << endl;
        cout << "\033[4;104HVacio" << endl;
        return;
    }
    cout << "\033[4;104HConsumiendo" << endl;
    cout << "\033[4;67H           " << endl;
    cout << "\033[4;67HEsperando" << endl;
    for(int i = 0; i < 4; i++, conCont++){
        if(conCont == 32){
            conCont = 0;
        }
        cout << "\033[8;" << (conCont*4) + 3 << "H " << endl;
        cola.pop();
        sleep(1);
    }
    cout << "\033[4;104H           " << endl;
    cout << "\033[4;104HEsperando" << endl;
    sleep(1);
}
