#ifndef TEST_VALUES_H_DEFINED
#define TEST_VALUES_H_DEFINED

#include "../Dominios.h"
#include <string>

using namespace std;

template <class Dom> class ValoresEInfo{
    public:
        static const pair<string, string> VALORES_VALIDOS[];
        static const pair<string, string> VALORES_INVALIDOS[];
};


template<> const pair<string, string> 
ValoresEInfo< Nome >::VALORES_VALIDOS[] = {
    make_pair("Artur Padovezi", "comum"),
    make_pair("Enzo Zanetti", "comum"),
    make_pair("A B", "com numero minimo de caracteres"),
    make_pair("Artur Zbcdefghijklmnopqrstuvw", "com 30 caracteres (o limite)"),
};


template<> const pair<string, string>
ValoresEInfo<Nome>::VALORES_INVALIDOS[] = {
    make_pair("ArtUr Padovezi", "com maiuscula a mais"),
    make_pair("Ab", "sem sobrenome e sem espaço"),
    make_pair("ArturPadovezi", "sem espaco entre nome e sobrenome"),
    make_pair("Artur  Padovezi", "com dois espacos no meio"),
    make_pair("Artur ", "sem sobrenome"),
    make_pair(" Artur Padovezi", "com um espaco a mais antes"),
    make_pair("Artur Padovezi ", "com um espaco a mais depois"),
    make_pair("artur Padovezi", "nome sem maiuscula"),
    make_pair("Artur padovezi", "sobrenome sem maiuscula"),
    make_pair("Artur pAdovezi", "sobrenome começando com minuscula"),
    make_pair("Artur Padove_zi", "contendo caracter invalido"),
    make_pair("Artur Padove-zi", "contendo caracter invalido"),
    make_pair("Artur Padove.zi", "contendo caracter invalido"),
    make_pair("Artur Padove@zi", "contendo caracter invalido"),
    make_pair("Artur Zbcdefghijklmnopqrstuvwx", "contendo 31 caracteres (max=30)"),
    make_pair("Artur Zbcdefghijklmnopqrstuvwxz", "contendo 32 caracteres (max=30)"),
    make_pair("Artur Padovezi Piratelli", "contendo nome a mais"),
    make_pair("Artur de Sa", "contendo nome a mais, nome do meio so de minusculas"),
    make_pair("Artur Padovezi piratelli", "contendo nome a mais, nome final so de minusculas"),
};


template<> const pair<string, string> 
ValoresEInfo< Nota >::VALORES_VALIDOS[] = {
    make_pair("0", "limite inferior"),
    make_pair("9", "maximo com unico digito"),
    make_pair("10", "limite superior"),
};
    

template<> const pair<string, string> 
ValoresEInfo< Nota >::VALORES_INVALIDOS[] = {
    make_pair("11", "acima do limite superior (nota <= 10)"),
    make_pair("-1", "abaixo do limite inferior (nota <= 0)")
}; 


template<> const pair<string, string> 
ValoresEInfo< Data >::VALORES_VALIDOS[] = {
    make_pair("01/Jan", "primeiro dia do ano"),
    make_pair("29/Fev", ""),
    make_pair("31/Dez", "ultimo dia do ano"),
};


template<> const pair<string, string> 
ValoresEInfo< Data >::VALORES_INVALIDOS[] = {
    make_pair("00/Jan", ""), 
    make_pair("30/Fev", ""), 
    make_pair("32/Mar", ""), 
    make_pair("300/Jan", "")
};


template<> const pair<string, string> 
ValoresEInfo< Codigo >::VALORES_VALIDOS[] = {
    // faz aí, Enzo
    make_pair("faz ai, Enzo", "faz ai, Enzo"), 
};

template<> const pair<string, string> 
ValoresEInfo< Codigo >::VALORES_INVALIDOS[] = {
    make_pair("faz ai, Enzo", "faz ai, Enzo"), 
};


// Cidade
template<> const pair<string, string> 
ValoresEInfo< Cidade >::VALORES_VALIDOS[] = {
    make_pair("Antalya", "cidade valida"),
    make_pair("Bangkok", "cidade valida"),
    make_pair("Delhi", "cidade valida"),
    make_pair("Dubai", "cidade valida"),
    make_pair("Hong Kong", "cidade valida"),
    make_pair("Londres", "cidade valida"),
    make_pair("Macau", "cidade valida"),
    make_pair("Mumbai", "cidade valida"),
    make_pair("Paris", "cidade valida"),
    make_pair("Rio de Janeiro", "cidade valida"),
    make_pair("Sao Paulo", "cidade valida"),
    make_pair("Seul", "cidade valida"),
    make_pair("Istambul", "cidade valida"),
    make_pair("Kuala Lumpur", "cidade valida"),
    make_pair("Nova Iorque", "cidade valida"),
    make_pair("Osaka", "cidade valida"),
    make_pair("Phuket", "cidade valida"),
    make_pair("Shenzhen", "cidade valida"),
    make_pair("Toquio", "cidade valida"),
};

template<> const pair<string, string> 
ValoresEInfo< Cidade >::VALORES_INVALIDOS[] = {
    make_pair("Tóquio", "cidade valida, mas com um acento"),
    make_pair("Shenzhin", "cidade valida, mas com uma letra errada"),
    make_pair("Phekut", "cidade valida, mas com uma letra trocada"),
    make_pair("Osaka ", "cidade valida, mas com um espaco depois"),
    make_pair(" Osaka", "cidade valida, mas com um espaco antes"),
};

//  Email

// Senha

// Descricao

#endif // TEST_VALUES_H_DEFINED