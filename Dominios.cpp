#include "Dominios.h"


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

    regex rule("^([0-9]|10)$");

    if (!regex_match(valor, rule)){
        throw invalid_argument("A nota deve ser um valor valido.");
    }
}


void Idioma::validar(string valor){
    string idiomas[NUMERO_IDIOMAS] = {"Arabe", "Bengali", "Chines", "Espanhol", "Frances", "Hindi", "Indonesio", "Ingles", "Mandarim", "Portugues", "Russo"};

    for (int i=0; i < NUMERO_IDIOMAS; i++){
        if (valor == idiomas[i]){
            return;
        }
    }
    throw invalid_argument("Idioma nao disponivel");
}

void Data::validar(string valor){

    regex rule("^(([0-2][0-9]|[3][01])[\/](Jan|Mar|Mai|Jul|Ago|Out|Dez))|([0-2][0-9]|[3][0])[\/](Abr|Jun|Set|Nov)|([0-2][0-9])[\/](Fev)$");

    if ((!regex_match(valor, rule))) {
        throw invalid_argument("Data invalida");
    }

}
