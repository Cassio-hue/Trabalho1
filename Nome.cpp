#include "Nome.h"
#include <cctype>
#include <stdexcept>

using namespace std;

bool Nome::validarNome(string nome){
    int numEspacoBranco = 0;
    int numLetrasMaisculas = 0;
    int nomeTamanho = nome.length();
    bool espacoBranco = false;
    bool primeiraLetraNome = isupper(nome[0]);

    if (!primeiraLetraNome | nomeTamanho >= 31){
        return false;
    }

    for (int i=0; i < nomeTamanho; i++){
        if (isupper(nome[i])){
            numLetrasMaisculas += 1;
        }
        if (nome[i] == ' '){
            numEspacoBranco += 1;
        }
        if (isdigit(nome[i])){
            return false;
        }
        else if (nome[i] == ' ' && espacoBranco){
            return false;
        }
        else if (nome[i] == ' ') {
            espacoBranco = true;
        }
        else if (espacoBranco && islower(nome[i])){
            return false;
        }
        else{
            espacoBranco = false;
        }
    }

    if (numLetrasMaisculas != 2 | numEspacoBranco != 1) {
        return false;
    }

   return true;
}

void Nome::setNome(string nome){
    if (validarNome(nome)){
        this -> nome = nome;
        return;
    }
    
    throw std::invalid_argument("Nome invalido");
}

string Nome::getNome(){
    return nome;
}
