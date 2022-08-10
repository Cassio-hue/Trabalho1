#ifndef CONTROLADORASAPRESENTACAO_H_INCLUDED
#define CONTROLADORASAPRESENTACAO_H_INCLUDED

//#include <conio.h>
#include <iostream>
#include <string.h>

#include "Dominios.h"
#include "Entidades.h"
#include "Interface.h"

#define CLR_SCR system("cls");


class CntrApresentacaoControle {
    private:
        IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
        IApresentacaoUsuario *cntrApresentacaoUsuario;
    public:
        void executar();
        void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao*);
        void setCntrApresentacaoUsuario(IApresentacaoUsuario*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr) {
    cntrApresentacaoAutenticacao = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoUsuario(IApresentacaoUsuario *cntr){
            cntrApresentacaoUsuario = cntr;
}


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

//----------------------------------------------------------------------------------------

class CntrApresentacaoUsuario:public IApresentacaoUsuario {
    private:
        IServicoUsuario *cntrServicoUsuario;
        void consultarDadosPessoais();
    public:
        void executar(Email);
        void cadastrar();
        void setCntrServicoUsuario(IServicoUsuario*);
};

inline void CntrApresentacaoUsuario::setCntrServicoUsuario(IServicoUsuario *cntr) {
    cntrServicoUsuario = cntr;
}

//--------------------------------------------------------------------------------------------


#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED
