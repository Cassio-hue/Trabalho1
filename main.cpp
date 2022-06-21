#include <iostream>
#include "Nome.h"
#include "Nota.h"

using namespace std;

int main()
{
    // Nome a;
    // a.setNome("Cassio Vinicius");
    // cout << a.getNome() << endl;

    string nota;

    Nota a;
    cin >> nota;
    cout << nota << endl;
    a.setNota(nota);
    cout << a.getNota() << endl;

    return 0;
}
