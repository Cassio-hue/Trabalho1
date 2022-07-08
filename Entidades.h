#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "Dominios.h"

// Não pode usar struct


class Usuario {
    private:
        Senha senha;
    public:
};

class Hospedagem {
    private:
        Codigo codigo;
        Cidade cidade;
        Pais pais;
        Nota nota;
        Descricao descricao;

    public:
        void setCodigo(const Codigo&);
        Codigo getCodigo() const;

        void setCidade(const Cidade&);
        Cidade getCidade() const;

        void setPais(const Pais&);
        Pais getPais() const;

        void setNota(const Nota&);
        Nota getNota() const;

        void setDescricao(const Descricao&);
        Descricao getDescricao() const;
};

inline void Hospedagem::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

inline Codigo Hospedagem::getCodigo() const {
    return codigo;
}

inline void Hospedagem::setCidade(const Cidade& cidade){
    this->cidade = cidade;
}

inline Cidade Hospedagem::getCidade() const {
    return cidade;
}

inline void Hospedagem::setPais(const Pais& pais){
    this->pais = pais;
}

inline Pais Hospedagem::getPais() const {
    return pais;
}

inline void Hospedagem::setNota(const Nota& nota){
    this->nota = nota;
}

inline Nota Hospedagem::getNota() const {
    return nota;
}

inline void Hospedagem::setDescricao(const Descricao& descricao){
    this->descricao = descricao;
}

inline Descricao Hospedagem::getDescricao() const {
    return descricao;
}


#endif // ENTIDADES_H_INCLUDED
