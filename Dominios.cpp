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
    if (valor.length() > 2) {
        throw invalid_argument("A nota não pode conter mais de dois dígitos.");
    }

    for (int i = 0; i < valor.length(); i++){
        if (!isdigit(valor[i])){
            throw invalid_argument("A nota deve ser um número.");
        }
    }

    if (VALOR_MIN > stoi(valor) | stoi(valor)> VALOR_MAX){
        throw invalid_argument("A nota deve ser um valor entre " + to_string(VALOR_MIN) + " e " + to_string(VALOR_MAX));
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

    int barPosition = valor.find("/");
    string meses[12] = {"Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out", "Nov", "Dez"};
    string dia = "";
    int diaNum = 0;
    string mes = "";
    bool mesValido = false;

    if (valor.length() != TAMANHO_DATA | barPosition != 2){
        throw invalid_argument("Formato inadequado para data.");
    }

    // Verificacao do dia
    for (int i = 0; i < 2; i++){
        if (!isdigit(valor[i])){
            throw invalid_argument("Formato inadequado para data.");
        }
        dia += valor[i];
    }

    diaNum = stoi(dia);

    if (!(diaNum >= 1 && diaNum <= 31)){
            throw invalid_argument("Formato inadequado para data.");
    }

    // Verificacao do mes
    for (int i = 3; i < 6; i++){
        if (!isalpha(valor[i])){
            throw invalid_argument("Formato inadequado para data.");
        }
        mes += valor[i];
    }

    for (int i = 0; i < MESES_ANO; i++){
        if (mes == meses[i]){
            mesValido = true;
            break;
        }
    }
    if (!mesValido){
        throw invalid_argument("Formato inadequado para data.");
    }

    // Validacao dos dias dos meses
    if (mes == meses[1] && diaNum > 29){
        throw invalid_argument("Formato inadequado para data.");
    }
    else if (mes == meses[3] && diaNum == 31) {
        throw invalid_argument("Formato inadequado para data.");
    }
    else if (mes == meses[5] && diaNum == 31) {
        throw invalid_argument("Formato inadequado para data.");
    }
    else if (mes == meses[8] && diaNum == 31) {
        throw invalid_argument("Formato inadequado para data.");
    }
    else if (mes == meses[10] && diaNum == 31) {
        throw invalid_argument("Formato inadequado para data.");
    }
}