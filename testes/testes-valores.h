#ifndef VALORES_PARA_TESTES
#define VALORES_PARA_TESTES

#include "../Dominios.h"
#include <string>

using namespace std;

template <class Dom> class ValoresEInfo{
    public:
        static const pair<string, string> VALORES_VALIDOS[];
        static const pair<string, string> VALORES_INVALIDOS[];
};

#endif