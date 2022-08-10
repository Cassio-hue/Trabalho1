#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "Dominios.h"
#include "Entidades.h"

class IServicoAutenticacao;
class IServicoUsuario;

class IApresentacaoAutenticacao {
    public:
        virtual bool autenticar(Email*) = 0;
        virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
        virtual ~IApresentacaoAutenticacao(){}
};


class IApresentacaoUsuario{
    public:
        virtual void executar(Email) = 0;
        virtual void cadastrar() = 0;
        virtual void setCntrServicoUsuario(IServicoUsuario*) = 0;
        virtual ~IApresentacaoUsuario(){}
};


class IServicoAutenticacao {
    public:
        virtual bool autenticar(Email, Senha) = 0;
        virtual ~IServicoAutenticacao(){}
};


class IServicoUsuario {
public:
        virtual bool cadastrarUsuario(Usuario) = 0;
        virtual ~IServicoUsuario(){}
};



#endif // INTERFACES_H_INCLUDED
