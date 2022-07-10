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
        string getNome() const;

        void setEmail(const Email&);
        string getEmail() const;

        void setSenha(const Senha&);
        string getSenha() const;

        void setIdioma(const Idioma&);
        string getIdioma() const;

        void setData(const Data&);
        string getData() const;

        void setDescricao(const Descricao&);
        string getDescricao() const;

        Usuario(string nome, string email, string senha, string idioma, string data, string descricao);
};


inline void Usuario::setNome(const Nome& nome){
    this->nome = nome;
}

inline string Usuario::getNome() const {
    return nome.getValor();
}

inline void Usuario::setEmail(const Email& email){
    this->email = email;
}

inline string Usuario::getEmail() const {
    return email.getValor();
}

inline void Usuario::setSenha(const Senha& senha){
    this->senha = senha;
}

inline string Usuario::getSenha() const {
    return senha.getValor();
}

inline void Usuario::setIdioma(const Idioma& idioma){
    this->idioma = idioma;
}

inline string Usuario::getIdioma() const {
    return idioma.getValor();
}

inline void Usuario::setData(const Data& data){
    this->data = data;
}

inline string Usuario::getData() const {
    return data.getValor();
}

inline void Usuario::setDescricao(const Descricao& descricao){
    this->descricao = descricao;
}

inline string Usuario::getDescricao() const {
    return descricao.getValor();
}


// #-----------------------------------------classe hospedagem-----------------------------------------#
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

        Hospedagem(string codigo, string cidade, string pais, string nota, string descricao);
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


// #-----------------------------------------classe Avaliacao-----------------------------------------#

class Avaliacao {
    private:
        Codigo codigo;
        Nota nota;
        Descricao descricao;

    public:
        void setCodigo(const Codigo&);
        Codigo getCodigo() const;

        void setNota(const Nota&);
        Nota getNota() const;

        void setDescricao(const Descricao&);
        Descricao getDescricao() const;
};

inline void Avaliacao::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

inline Codigo Avaliacao::getCodigo() const {
    return codigo;
}

inline void Avaliacao::setNota(const Nota& nota){
    this->nota = nota;
}

inline Nota Avaliacao::getNota() const {
    return nota;
}

inline void Avaliacao::setDescricao(const Descricao& descricao){
    this->descricao = descricao;
}

inline Descricao Avaliacao::getDescricao() const {
    return descricao;
}
// #---------------------------------------------------------------------------------------------------#

#endif // ENTIDADES_H_INCLUDED
