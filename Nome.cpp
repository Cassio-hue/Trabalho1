#include "Nome.h"

bool validateNome(string valor){
    /*
    Nome e sobrenome
    Ate 30 caracteres
    Somente letras (A-Z|a-z) ou espaco em branco
    Nao pode ter espaco em branco em sequencia
    Primeiro caracter de prenome ou sobrenome deve ser em maiusculo

    bool = numeroCaracteres;
    bool = primeiraLetraNome;
    bool = primeiraLetraSobrenome;
    bool = sequenciaEspacobranco;

    return (numeroCaracteres && primeiraLetraNome && primeiraLetraSobrenome && sequenciaEspacobranco);
    */
   return 0;
}

bool Nome::setNome(string valor){
    if (validateNome(valor)){
        nome = valor;
        return true;
    }
    return false;
}

string Nome::getNome(){
    return nome;
}
