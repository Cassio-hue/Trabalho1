#include <iostream>
#include "Dominios.h"

using namespace std;

int main()
{
    Nome a;
    a.setValor("Cassio Vini");
    cout << a.getValor() << endl;

    string nota;
    Nota b;
    cout << "Digite uma nota (0-10): ";
    cin >> nota;
    b.setValor(nota);
    cout << b.getValor() << endl;

    return 0;
}
