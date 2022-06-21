#include <iostream>
#include "Nome.h"

using namespace std;

int main()
{
    Nome a;
    a.setNome("Cassio");
    string guardado = a.getNome();

    cout << guardado << endl;

    return 0;
}
