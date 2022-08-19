#include <iostream>

#include "Dominios.h"
#include "Entidades.h"
#include "Interface.h"
#include "CntlApresentacao.h"

using namespace std;

int main() {

    // Declarar poteiros e instanciar controladoras.
    CntrApresentacaoControle *cntrApresentacaoControle;
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    IApresentacaoUsuario *cntrApresentacaoUsuario;
    IApresentacaoHospedagem *cntrApresentacaoHospedagem;

    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
    cntrApresentacaoUsuario = new CntrApresentacaoUsuario();
    cntrApresentacaoHospedagem = new CntrApresentacaoHospedagem();

    cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoControle->executar();

    return 0;
};

