#ifndef NOTA_H
#define NOTA_H
#include <iostream>

using namespace std;

class Nota {
    private:
        int nota;
        bool validarNota(string valor);
    public:
        void setNota(string valor);
        int getNota();

};

#endif // NOTA_H
