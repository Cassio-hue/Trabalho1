#ifndef NOME_H
#define NOME_H
#include <iostream>

using namespace std;

class Nome {
    private:
        string nome;
        bool validarNome(string valor);
    public:
        void setNome(string valor);
        string getNome();
};

#endif // NOME_H
