#include "Dominios.h"

#include <string>

using namespace std;

void Dominio::setValor(string valor){
    validar(valor);
    this->valor = valor;
}


void Nome::validar(string nome){
    int numEspacoBranco = 0;
    int numLetrasMaisculas = 0;
    int nomeTamanho = nome.length();
    bool espacoBranco = false;
    bool primeiraLetraNome = isupper(nome[0]);

    if (!primeiraLetraNome | nomeTamanho >= 31){
        throw invalid_argument("Formato inadequado para nome.");
    }

    for (int i=0; i < nomeTamanho; i++){
        if (isupper(nome[i])){
            numLetrasMaisculas += 1;
        }
        if (nome[i] == ' '){
            numEspacoBranco += 1;
        }
        if (isdigit(nome[i])){
            throw invalid_argument("Formato inadequado para nome.");
        }
        else if (nome[i] == ' ' && espacoBranco){
            throw invalid_argument("Formato inadequado para nome.");
        }
        else if (nome[i] == ' ') {
            espacoBranco = true;
        }
        else if (espacoBranco && islower(nome[i])){
            throw invalid_argument("Formato inadequado para nome.");
        }
        else{
            espacoBranco = false;
        }
    }

    if (numLetrasMaisculas != 2 | numEspacoBranco != 1) {
        throw invalid_argument("Formato inadequado para nome.");
    }
}
