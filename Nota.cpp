#include "Nota.h"
#include <iostream>
#include <cctype>
#include <stdexcept>

using namespace std;

bool Nota::validarNota(string valor) {
    for (int i = 0; i < valor.length(); i++){
        if (isalpha(valor[i])) {
            return false;
        }
    }

    if (stoi(valor) < 0 | stoi(valor)> 10) {
        return false;
    }
    return true;
}


void Nota::setNota(string nota) {
    if (validarNota(nota)) {
        this -> nota = stoi(nota);
        return;
    }
    throw std::invalid_argument("Nota invalida");
}

int Nota::getNota() {
    return nota;
}
