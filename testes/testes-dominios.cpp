#include "../Dominios.h"
#include <unordered_map>
#include "testes-valores.h"
#include "catch.hpp"

using namespace std;


TEMPLATE_TEST_CASE( "dominios tem construtor, set e get funcionando", "[dominios][template]",
            Nome , Nota, Data, Codigo, Cidade, Email, Senha, Descricao //, outros dominios. Acessiveis no teste por TestType
    ) {
    
 
    SECTION("Método set", "[set]"){
        TestType dominio{
            ValoresEInfo<TestType>::VALORES_VALIDOS[0].first
        };
 
        SECTION("Valores validos", "[validos]"){
 
            for(const pair<string, string> &valor_e_info : ValoresEInfo<TestType>::VALORES_VALIDOS){
                const string &valor = valor_e_info.first, &info = valor_e_info.second;
 
                SECTION(valor + '\n' + info){
                    CHECK_NOTHROW(dominio.setValor(valor));
 
                    CHECK((dominio.getValor() == valor));
                }
            }
 
        }
 
        SECTION("Valores invalidos", "[invalidos]"){
            for(const pair<string, string> &valor_e_info : ValoresEInfo<TestType>::VALORES_INVALIDOS){
                const string& valor = valor_e_info.first, info = valor_e_info.second;
 
                SECTION(valor + '\n' + info){
                    CHECK_THROWS_AS(dominio.setValor(valor), invalid_argument);
                    CHECK((dominio.getValor() != valor));
                }
            }
        }
    }
 
 
    SECTION("Construtor", "[construtor]"){
        TestType* dominioptr;
 
        SECTION("Valores validos", "[validos]"){
 
            for(const pair<string, string> &valor_e_info : ValoresEInfo<TestType>::VALORES_VALIDOS){
                const string& valor = valor_e_info.first, info = valor_e_info.second;
 
                SECTION(valor + '\n' + info){
 
                    dominioptr = 0;
 
                    CHECK_NOTHROW(dominioptr = new TestType(valor));
                    if(dominioptr != 0)
                        CHECK((dominioptr->getValor() == valor));
 
                    delete dominioptr;
                }
            }
        }
 
        SECTION("Valores invalidos", "[invalidos]"){
 
            for(const pair<string, string> &valor_e_info : ValoresEInfo<TestType>::VALORES_INVALIDOS){
                const string& valor = valor_e_info.first, info = valor_e_info.second;
 
                SECTION(valor + '\n' + info){
                    dominioptr = 0;
 
                    CHECK_THROWS_AS((dominioptr = new TestType(valor)), invalid_argument);
 
                    delete dominioptr;
                }
            }
        }
    }
}
