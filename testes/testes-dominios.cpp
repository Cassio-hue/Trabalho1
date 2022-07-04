#include "catch.hpp"
#include "../Dominios.h"
#include <unordered_map>

using namespace std;

const string NOMES_VALIDOS[] = {
    "Artur Padovezi",
    "A B",
    "Enzo Zanetti",
    "Artur Zbcdefghijklmnopqrstuvw",
};


const string NOMES_INVALIDOS[] = {
    "ArtUr Padovezi",
    "Ab",
    "ArturPadovezi",
    "Artur  Padovezi",
    "Artur ",
    " Artur Padovezi",
    "Artur Padovezi ",
    "artur Padovezi",
    "Artur padovezi",
    "Artur pAdovezi",
    "Artur Padove_zi",
    "Artur Padove-zi",
    "Artur Padove.zi",
    "Artur Padove@zi",
    "Artur Padovezi Piratelli",
    "Artur de Sa",
    "Artur padovezi Piratelli",
    "Artur Padovezi piratelli",
    "Artur Zbcdefghijklmnopqrstuvwx",
    "Artur Zbcdefghijklmnopqrstuvwxyz",
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
    Nome nome{NOMES_VALIDOS[0]};
    SECTION("Método set"){
        SECTION("Valores validos"){
            
            for(const string &valor : NOMES_VALIDOS){
                UNSCOPED_INFO("O valor é " << valor);
                CHECK_NOTHROW(nome.setValor(valor));

                CHECK((nome.getValor() == valor));
            }

        }

        SECTION("Valores invalidos"){
            for(const string &valor : NOMES_INVALIDOS){
                UNSCOPED_INFO("O valor é " << valor);

                CHECK_THROWS_AS(nome.setValor(valor), invalid_argument);
                CHECK((nome.getValor() != valor));

            }
        }
    }
    SECTION("Construtor"){
        Nome* nomeptr;
        SECTION("Valores validos"){
            
            for(const string &valor : NOMES_VALIDOS){
                UNSCOPED_INFO("O valor é " << valor);
                nomeptr = 0;
                nomeptr = new Nome(valor);

                CHECK((nomeptr != 0));
                if(nomeptr != 0)
                    CHECK((nomeptr->getValor() == valor));
                
                delete nomeptr;
            }
        }

        SECTION("Valores invalidos"){

            for(const string &valor : NOMES_INVALIDOS){
                UNSCOPED_INFO("O valor é " << valor);
                nomeptr = 0;
                
                CHECK_THROWS_AS((nomeptr = new Nome(valor)), invalid_argument);
                
                delete nomeptr;
            }
        }
    }
}


TEST_CASE("Testando Domínio Nota", "[Nota]"){
    Nota nota{NOTAS_VALIDAS[0]};

    SECTION("Método set"){
        SECTION("Valores validos"){

            for(const string &valor : NOTAS_VALIDAS){
                UNSCOPED_INFO("O valor é " << valor);
                CHECK_NOTHROW(nota.setValor(valor));

                CHECK((nota.getValor() == valor));
            }

        }

        SECTION("Valores invalidos"){
            for(const string &valor : NOTAS_INVALIDAS){
                UNSCOPED_INFO("O valor é " << valor);

                CHECK_THROWS_AS(nota.setValor(valor), invalid_argument);
                CHECK((nota.getValor() != valor));
            }
        }
    }

    SECTION("Construtor"){
        Nota* notaptr;

        SECTION("Valores validos"){
            for(const string &valor : NOTAS_VALIDAS){
                UNSCOPED_INFO("O valor é " << valor);
                notaptr = 0;
                
                CHECK_NOTHROW(notaptr = new Nota(valor));
                
                CHECK((notaptr->getValor() == valor));
                
                delete notaptr;
            }
        }

        SECTION("Valores invalidos"){
            for(const string &valor : NOTAS_INVALIDAS){
                UNSCOPED_INFO("O valor é " << valor);
                notaptr = 0;
                
                CHECK_THROWS_AS(notaptr = new Nota(valor), invalid_argument);
                
                delete notaptr;
            }
        }
    }
}






