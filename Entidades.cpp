#include "Entidades.h"

template <typename T>
void Entidade<T>::setInfo(T info){
    this->info = info;
}


void Usuario::setInfo(user_info info, Senha senha){
    if(this->senha.getValor() == senha.getValor()){
        this->info = info;
    }
}

