#include "Nome.h"
#include <stdexcept>

using namespace std;

bool Nome::validateNome(string nome){
    
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
   return true;
}

void Nome::setNome(string nome){
    if (validateNome(nome)){
        this -> nome = nome;
        return;
    }
    throw std::invalid_argument("");
}

string Nome::getNome(){
    return nome;
}
