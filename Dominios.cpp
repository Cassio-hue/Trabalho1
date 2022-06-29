#include "Dominios.h"
#include <iostream>

using namespace std;


void Dominio::setValor(string valor){
    // Matrícula: 211038208

    validar(valor);
    this->valor = valor;
}


void Nome::validar(string nome){
    // Matricula: 211036141

    int numEspacoBranco = 0;
    int numLetrasMaisculas = 0;
    int nomeTamanho = nome.length();
    bool espacoBranco = false;
    bool primeiraLetraNome = isupper(nome[0]);

    if (!primeiraLetraNome || nomeTamanho >= 31){
        throw invalid_argument("Formato inadequado para nome.");
    }
    for (int i=0; i < nomeTamanho; ++i){
        cout << nome[i] << endl;
        if (!isalpha(nome[i]) && (nome[i] != ' ')){
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
            espacoBranco = false;
        }
        else if (nome[i] == ' '){
            numEspacoBranco += 1;
            espacoBranco = true;
        }
        else {
            espacoBranco = false;
        }
    }

    if (numLetrasMaisculas != 2 || numEspacoBranco != 1) {
        throw invalid_argument("Formato inadequado para nome.");
    }
}


void Nota::validar(string valor){
    // Matricula: 211036141


    if (!regex_match(valor, PADRAO_ACEITO)){
        throw invalid_argument("A nota deve ser um valor valido.");
    }
}


void Idioma::validar(string valor){
    // Matricula: 211036141

    if (POSSIVEIS_VALORES.find(valor) == POSSIVEIS_VALORES.end()){
        throw invalid_argument("Idioma indisponivel");
    }
}


void Data::validar(string valor){
    // Matricula: 211036141

    if ((!regex_match(valor, PADRAO_ACEITO))) {
        throw invalid_argument("Data invalida");
    }
}


void Codigo::validar(string valor) {
    // Matricula: 211026495

    if (!( valor.size() == TAMANHO_CODIGO )) {
        throw invalid_argument("Tamanho do codigo invalido.");
    }

    int soma = 0;
    bool ehpar = false;

    for (int i= TAMANHO_CODIGO-1; i>=0; i--) {
        int d = valor[i] - '0';

        if (ehpar) {
            d = d*2;
        }

        soma += d/10;
        soma += d%10;
        ehpar = !ehpar;
    }

    if (soma % 10 != 0) {
        throw invalid_argument("Ultimo digito incorreto.");
    }
}


void Cidade::validar(string valor){
    // Matrícula: 211038208

    if (POSSIVEIS_VALORES.find(valor) == POSSIVEIS_VALORES.end()){
        throw invalid_argument("Cidade Invalida");
    }
}


void Email::validar(string valor){
    // Matrícula: 211038208

    if ( !regex_match(valor, PADRAO_ACEITO) ) {
        throw invalid_argument("Email invalido");
    }
}


void Senha::validar(string valor){
    if ( !regex_match(valor, PADRAO_ACEITO) ){
        throw invalid_argument("Senha invalida");
    }
}
