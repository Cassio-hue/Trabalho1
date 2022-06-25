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

    Data day;

    string data;

    cout << "Digite a data (DD/MES): ";
    cin >> data;
    day.setValor(data);
    cout << day.getValor() << endl;
    return 0;
}
