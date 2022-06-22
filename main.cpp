#include <iostream>
#include "Nome.h"
#include "Nota.h"

using namespace std;

int main()
{
    Nome a;
    a.setNome("C4ssio Borges");
    cout << a.getNome() << endl;

    string nota;

    Nota b;
    cout << "Digite uma nota (0-10): ";
    cin >> nota;
    b.setNota(nota);
    cout << b.getNota() << endl;

    return 0;
}
