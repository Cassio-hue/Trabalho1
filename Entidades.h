#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "Dominios.h"

// #-----------------------------------------classe Usuario-----------------------------------------#


class Usuario {
    private:
        Nome nome;
        Email email;
        Senha senha;
        Idioma idioma;
        Data data;
        Descricao descricao;

    public:
        void setNome(const Nome&);
        Nome getNome() const;

        void setEmail(const Email&);
        Email getEmail() const;

        void setSenha(const Senha&);
        Senha getSenha() const;

        void setIdioma(const Idioma&);
        Idioma getIdioma() const;

        void setData(const Data&);
        Data getData() const;

        void setDescricao(const Descricao&);
        Descricao getDescricao() const;
};

inline void Usuario::setNome(const Nome& nome){
    this->nome = nome;
}

inline Nome Usuario::getNome() const {
    return nome;
}

inline void Usuario::setEmail(const Email& email){
    this->email = email;
}

inline Email Usuario::getEmail() const {
    return email;
}

inline void Usuario::setSenha(const Senha& senha){
    this->senha = senha;
}

inline Senha Usuario::getSenha() const {
    return senha;
}

inline void Usuario::setIdioma(const Idioma& idioma){
    this->idioma = idioma;
}

inline Idioma Usuario::getIdioma() const {
    return idioma;
}

inline void Usuario::setData(const Data& data){
    this->data = data;
}

inline Data Usuario::getData() const {
    return data;
}

inline void Usuario::setDescricao(const Descricao& descricao){
    this->descricao = descricao;
}

inline Descricao Usuario::getDescricao() const {
    return descricao;
}

#endif // ENTIDADES_H_INCLUDED