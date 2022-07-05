#include "catch.hpp"
#include "../Dominios.h"
#include <unordered_map>

using namespace std;

const pair<string, string> NOMES_VALIDOS[] = {
    make_pair("Artur Padovezi", "comum"),
    make_pair("Enzo Zanetti", "comum"),
    make_pair("A B", "com numero minimo de caracteres"),
    make_pair("Artur Zbcdefghijklmnopqrstuvw", "com 30 caracteres (o limite)"),
};


const pair<string, string> NOMES_INVALIDOS[] = {
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


const string NOTAS_VALIDAS[] = {
    "0",
    "9",
    "10",
};

const string NOTAS_INVALIDAS[] = {
    "11",
    "-1"
};




TEST_CASE("Testando Domínio Nome", "[Nome]"){ 
    SECTION("Método set", "[set]"){
        Nome nome{NOMES_VALIDOS[0].first};
        
        SECTION("Valores validos", "[validos]"){
            
            for(const pair<string, string> &valor_e_info : NOMES_VALIDOS){
                const string &valor = valor_e_info.first, &info = valor_e_info.second;

                UNSCOPED_INFO("O valor é " << valor << "\n" << info);

                CHECK_NOTHROW(nome.setValor(valor));

                CHECK((nome.getValor() == valor));
            }

        }

        SECTION("Valores invalidos", "[invalidos]"){
            for(const pair<string, string> &valor_e_info : NOMES_INVALIDOS){
                const string& valor = valor_e_info.first, info = valor_e_info.second;

                UNSCOPED_INFO("O valor é " << valor << "\n" << info);

                CHECK_THROWS_AS(nome.setValor(valor), invalid_argument);
                CHECK((nome.getValor() != valor));

            }
        }
    }
    SECTION("Construtor", "[construtor]"){
        Nome* nomeptr;

        SECTION("Valores validos", "[validos]"){
            
            for(const pair<string, string> &valor_e_info : NOMES_VALIDOS){
                const string& valor = valor_e_info.first, info = valor_e_info.second;

                nomeptr = 0;
                nomeptr = new Nome(valor);
                
                UNSCOPED_INFO("O valor é " << valor << "\n" << info);

                CHECK((nomeptr != 0));
                if(nomeptr != 0)
                    CHECK((nomeptr->getValor() == valor));
                
                delete nomeptr;
            }
        }

        SECTION("Valores invalidos", "[invalidos]"){

            for(const pair<string, string> &valor_e_info : NOMES_INVALIDOS){
                const string& valor = valor_e_info.first, info = valor_e_info.second;
                
                nomeptr = 0;

                UNSCOPED_INFO("O valor é " << valor << "\n" << info);
                
                CHECK_THROWS_AS((nomeptr = new Nome(valor)), invalid_argument);
                
                delete nomeptr;
            }
        }
    }
}


TEST_CASE("Testando Domínio Nota", "[Nota]"){
    SECTION("Método set", "[set]"){
        Nota nota{NOTAS_VALIDAS[0]};

        SECTION("Valores validos", "[validos]"){
            for(const string &valor : NOTAS_VALIDAS){
                UNSCOPED_INFO("O valor é " << valor);

                CHECK_NOTHROW(nota.setValor(valor));
                CHECK((nota.getValor() == valor));
            }
        }

        SECTION("Valores invalidos", "[invalidos]"){
            for(const string &valor : NOTAS_INVALIDAS){
                UNSCOPED_INFO("O valor é " << valor);

                CHECK_THROWS_AS(nota.setValor(valor), invalid_argument);
                CHECK((nota.getValor() != valor));
            }
        }
    }
    SECTION("Construtor", "[construtor]"){
        Nota* notaptr;

        SECTION("Valores validos", "[validos]"){
            for(const string &valor : NOTAS_VALIDAS){
                notaptr = 0;
                
                UNSCOPED_INFO("O valor é " << valor);

                CHECK_NOTHROW(notaptr = new Nota(valor));
                CHECK((notaptr->getValor() == valor));
                
                delete notaptr;
            }
        }

        SECTION("Valores invalidos", "[invalidos]"){
            for(const string &valor : NOTAS_INVALIDAS){
                notaptr = 0;
                
                UNSCOPED_INFO("O valor é " << valor);

                CHECK_THROWS_AS(notaptr = new Nota(valor), invalid_argument);
                
                delete notaptr;
            }
        }
    }
}

