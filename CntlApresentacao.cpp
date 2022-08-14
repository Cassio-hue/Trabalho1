// #include <ncurses.h>
#include <strings.h>
#include "CntlApresentacao.h"

using namespace std;

void CntrApresentacaoControle::executar() {

}


bool CntrApresentacaoAutenticacao::autenticar(Email *email) {
    // Mensagens a serem apresentadas na tela de autenticação.
    char texto1[]="Digite o Email  : ";
    char texto2[]="Digite a Senha: ";
    char texto3[]="Dado em formato incorreto. Digite algo.";

    // Campos de entrada.
    char campo1[80];
    char campo2[80];

    Senha senha(campo2);

    while(true) {

        cout << texto1 << " ";
        cin >> campo1;
        cout << texto2 << " ";
        cin >> campo2;

        try{
            email->setValor(string(campo1));
            senha.setValor(string(campo2));
            break;
        }
        catch(invalid_argument &exp) {

            cout << texto3 << endl;
//            getch();
        }
    }
    return (cntr->autenticar(*email, senha));
}


void CntrApresentacaoUsuario::executar(Email) {

}


void CntrApresentacaoUsuario::cadastrar() {

}
