#include "Dominios.h"


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
        else if (isupper(nome[i])){
            numLetrasMaisculas += 1;
        }
        else if (nome[i] == ' '){
            numEspacoBranco += 1;
        }
        else if (nome[i] == ' '){
            espacoBranco = true;
        }
        else {
            espacoBranco = false;
        }
    }

    if (numLetrasMaisculas != 2 | numEspacoBranco != 1) {
        throw invalid_argument("Formato inadequado para nome.");
    }
}


void Nota::validar(string valor){
    if (valor.length() > 2) {
        throw invalid_argument("A nota não pode conter mais de dois dígitos.");
    }

    for (int i = 0; i < valor.length(); i++){
        if (!isdigit(valor[i])){
            throw invalid_argument("A nota deve ser um número.");
        }
    }

    if (stoi(valor) < VALOR_MIN | stoi(valor)> VALOR_MAX){
        throw invalid_argument("A nota deve ser um valor entre 0 e 10.");
        // formatar string pa fica bunitu
    }
}
