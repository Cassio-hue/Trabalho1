// #include <ncurses.h>
#include <strings.h>
#include "CntlApresentacao.h"

using namespace std;

void CntrApresentacaoControle::executar() {
    // Mensagens a serem apresentadas na tela inicial.
    char texto1[]="Selecione um dos servicos: ";
    char texto2[]="1 - Acessar sistema.";
    char texto3[]="2 - Cadastrar usuario.";
    char texto4[]="3 - Acessar dados de anfitriões disponíveis.";
    char texto5[]="4 - Encerrar execucao do sistema.";

    // Mensagens a serem apresentadas na tela de seleção de serviço.
    char texto6[]="Selecione um dos servicos: ";
    char texto7[]="1 - Selecionar servicos de pessoal.";
    char texto8[]="2 - Selecionar servicos relacionados a produtos financeiros.";
    char texto9[]="3 - Encerrar sessao.";

    char texto10[]="Falha na autenticacao. Digite algo para continuar.";

    int campo;
    bool apresentar = true;

    while(apresentar){

        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;

        campo = getch() - 48;

        switch(campo) {
            case 1: if(cntrApresentacaoAutenticacao->autenticar(&email)) {
                        bool apresentar = true;
                        while(apresentar) {

                            cout << texto6 << endl;
                            cout << texto7 << endl;
                            cout << texto8 << endl;
                            cout << texto9 << endl;

                            campo = getch() - 48;

                            switch(campo) {
                                case 1: cntrApresentacaoUsuario->executar(email);
                                break;
                                case 2: apresentar = false;
                                    break;
                            }
                        }
                    }
                    else {
                        cout << texto10 << endl;
                        getch();
                    }
                    break;
            case 2: cntrApresentacaoUsuario->cadastrar();
                    break;
            case 3: apresentar = false;
                    break;
        }
    }
    return;
}


bool CntrApresentacaoAutenticacao::autenticar(Email *email) {
    // Mensagens a serem apresentadas na tela de autenticação.
    char texto1[]="Digite o Email: ";
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
//          getch();
        }
    }
    return (cntr->autenticar(*email, senha));
}


void CntrApresentacaoUsuario::executar(Email email) {

}


void CntrApresentacaoUsuario::cadastrar() {

}
