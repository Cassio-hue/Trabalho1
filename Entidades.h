#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "Dominios.h"

struct user_info
{
    Nome nome;
    Email email;
    Idioma idioma;
    Data aniversario;
    // Descricao descricao;
};

template <typename T>
class Entidade
{
    public:
        T getInfo() const;
        void setInfo(T);
    protected:
        T info;
    private:
};

template <typename T>
inline T Entidade<T>::getInfo() const {
    return info;
}

class Usuario : public Entidade<user_info> {
    private:
        Senha senha;
    public:
        void setInfo(user_info, Senha);
};

#endif // ENTIDADES_H_INCLUDED
