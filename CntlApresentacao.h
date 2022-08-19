#ifndef CONTROLADORASAPRESENTACAO_H_INCLUDED
#define CONTROLADORASAPRESENTACAO_H_INCLUDED

#include <conio.h>
#include <iostream>
#include <string.h>

#include "Dominios.h"
#include "Entidades.h"
#include "Interface.h"

#define CLR_SCR system("cls");

class CntrApresentacaoControle {
    private:
        Email email;
        IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
        IApresentacaoUsuario *cntrApresentacaoUsuario;
        IApresentacaoHospedagem *cntrApresentacaoHospedagem;
    public:
        void executar();
        void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao*);
        void setCntrApresentacaoUsuario(IApresentacaoUsuario*);
        void setCntrApresentacaoHospedagem(IApresentacaoHospedagem*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr) {
    cntrApresentacaoAutenticacao = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoUsuario(IApresentacaoUsuario *cntr) {
    cntrApresentacaoUsuario = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoHospedagem(IApresentacaoHospedagem *cntr) {
    cntrApresentacaoHospedagem = cntr;
}


// ================================================================================
class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao {
    private:
        IServicoAutenticacao *cntr;
    public:
        bool autenticar(Email*);
        void setCntrServicoAutenticacao(IServicoAutenticacao*);
};

inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao *cntr) {
    this->cntr = cntr;
}


// ================================================================================
class CntrApresentacaoUsuario:public IApresentacaoUsuario {
    private:
        IServicoUsuario *cntrServicoUsuario;
        IServicoHospedagem *cntrServicoHospedagem;
        void consultarDadosPessoais();
    public:
        void cadastrar();
        void executar(Email);
        void setCntrServicoUsuario(IServicoUsuario*);
        void setCntrServicoHospedagem(IServicoHospedagem*);
};

inline void CntrApresentacaoUsuario::setCntrServicoUsuario(IServicoUsuario *cntr) {
    cntrServicoUsuario = cntr;
}

inline void CntrApresentacaoUsuario::setCntrServicoHospedagem(IServicoHospedagem *cntr) {
    cntrServicoHospedagem = cntr;
}



// ================================================================================
class CntrApresentacaoHospedagem:public IApresentacaoHospedagem {
    private:
        IServicoHospedagem *cntr;
        void listarHospedagens();
        void acessarDadosHospedagem();
    
        void cadastrarHospedagem();
        void editarHospedagem();
        void descadastrarHospedagem();
        void cadastrarAvaliacao();
        void editarAvaliacao();
        void descadastrarAvaliacao();
    public:
        void executar();
        void executar(Email);
        void setCntrServicoHospedagem(IServicoHospedagem*);
};

inline void CntrApresentacaoHospedagem::setCntrServicoHospedagem(IServicoHospedagem *cntr) {
    this->cntr = cntr;
}

#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED
