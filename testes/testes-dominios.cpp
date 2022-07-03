#include "catch.hpp"
#include "../Dominios.h"

using namespace std;

TEST_CASE("Testando Domínio Nome", "[Nome]"){
    Nome nome;
    SECTION("Valores validos"){
        string valores_validos[] = {
            "Artur Padovezi", 
            "A B",
            "Enzo Zanetti",
            "Artur Zbcdefghijklmnopqrstuvw",
            };

        for(string &valor : valores_validos){
            INFO("O valor é " << valor);
            CHECK_NOTHROW(nome.setValor(valor));
            
            CHECK(nome.getValor() == valor);
        }
        
    }

    SECTION("Valores invalidos"){
        string valor_inicial = "Artur Padovezi";
        string valores_invalidos[] = {
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
        };

        CHECK_NOTHROW(nome.setValor(valor_inicial));
        
        CHECK(nome.getValor() == valor_inicial);

        for(string &valor : valores_invalidos){
            UNSCOPED_INFO("O valor é " << valor);
            CHECK_THROWS_AS(nome.setValor(valor), invalid_argument);

            CHECK(nome.getValor() == valor_inicial);
        }
    }
}