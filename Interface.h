#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "Dominios.h"
#include "Entidades.h"

class IServicoAutenticacao;
class IServicoUsuario;
class IServicoHospedagem;

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


class IApresentacaoHospedagem {
    public:
        virtual void executar() = 0;
        virtual void executar(Email) = 0;
        virtual void setCntrServicoHospedagem(IServicoHospedagem*) = 0;
        virtual ~IApresentacaoHospedagem(){}
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


class IServicoHospedagem {
    public:
        virtual void listarHospedagens();
        virtual void acessarDadosHospedagem();
    
        virtual void cadastrarHospedagem();
        virtual void editarHospedagem();
        virtual void descadastrarHospedagem();
        virtual void cadastrarAvaliacao();
        virtual void editarAvaliacao();
        virtual void descadastrarAvaliacao();
    
        //virtual bool cadastrarConta(Conta) = 0;
        //virtual bool consultarConta(Conta*) = 0;
        //virtual bool cadastrarProdutoInvestimento(Produto) = 0;
        //virtual bool descadastrarProdutoInvestimento(Codigo) = 0;
        //virtual bool realizarAplicacao(Aplicacao) = 0;
        //virtual bool recuperarAplicacao(Aplicacao*) = 0;
        //virtual ~IServicoProdutosFinanceiros(){}
};

#endif // INTERFACES_H_INCLUDED
