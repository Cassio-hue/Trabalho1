#include <iostream>

#include "Dominios.h"

using namespace std;

int main()
{
    // Nome a;
    // a.setValor("Cassio Vinicius");
    // cout << a.getValor() << endl;

    // string nota;
    // Nota b;
    // cout << "Digite uma nota (0-10): ";
    // cin >> nota;
    // b.setValor(nota);
    // cout << b.getValor() << endl;

    // Idioma lingua;
    // string idio;
    // cout << "Digite seu idioma (sem acento): ";
    // cin >> idio;
    // lingua.setValor(idio);
    // cout << lingua.getValor() << endl;

    Email m;

    string email;

    cout << "Digite o email: ";
    cin >> email;
    m.setValor(email);
    cout << m.getValor() << endl;
    return 0;
}
