#include "catch.hpp"
#include "../Entidades.h"
#include <iostream>


TEST_CASE ("usuario tem construtor, set e get funcionando", "[entidades][usuario]") {
    
}


TEST_CASE ("hospedagem tem construtor, set e get funcionando", "[entidades][hospedagem]") {
    Hospedagem* hospedagem = 0;

    Codigo      codigo      ("12345678903");
    Cidade      cidade      ("Antalya");
    Pais        pais        ("Estados Unidos");
    Nota        nota        ("10");
    Descricao   descricao   ("Ava! Meus amigos? t;do: que-sabes, naoo.");


    Codigo      codigo2      ("12345678903");
    Cidade      cidade2      ("Bangkok");
    Pais        pais2        ("Brasil");
    Nota        nota2        ("0");
    Descricao   descricao2   ("");

    SECTION("construtor funciona", "[construtor]") {
        REQUIRE_NOTHROW( hospedagem = new Hospedagem(codigo, cidade, pais, nota, descricao) );

        CHECK(hospedagem->getCodigo().getValor()    == codigo.getValor()   );
        CHECK(hospedagem->getCidade().getValor()    == cidade.getValor()   );
        CHECK(hospedagem->getPais().getValor()      == pais.getValor()     );
        CHECK(hospedagem->getNota().getValor()      == nota.getValor()     );
        CHECK(hospedagem->getDescricao().getValor() == descricao.getValor());

        SECTION("metodo set funciona", "[set]") {
            REQUIRE_NOTHROW(hospedagem->setCodigo   (   codigo2     ));
            REQUIRE_NOTHROW(hospedagem->setCidade   (   cidade2     ));
            REQUIRE_NOTHROW(hospedagem->setPais     (   pais2       ));
            REQUIRE_NOTHROW(hospedagem->setNota     (   nota2       ));
            REQUIRE_NOTHROW(hospedagem->setDescricao(   descricao2  ));


            CHECK(hospedagem->getCodigo().getValor()    == codigo2.getValor()   );
            CHECK(hospedagem->getCidade().getValor()    == cidade2.getValor()   );
            CHECK(hospedagem->getPais().getValor()      == pais2.getValor()     );
            CHECK(hospedagem->getNota().getValor()      == nota2.getValor()     );
            CHECK(hospedagem->getDescricao().getValor() == descricao2.getValor());
        }
    }

    delete hospedagem;
}


TEST_CASE ("avaliacao tem construtor, set e get funcionando", "[entidades][avaliacao]") {
    Avaliacao* avaliacao = 0;

    Codigo      codigo      ("12345678903");
    Nota        nota        ("10");
    Descricao   descricao   ("Ava! Meus amigos? t;do: que-sabes, naoo.");


    Codigo      codigo2      ("12345678903");
    Nota        nota2        ("0");
    Descricao   descricao2   ("");

    SECTION("construtor funciona", "[construtor]") {
        REQUIRE_NOTHROW( avaliacao = new Avaliacao(codigo, nota, descricao) );

        CHECK(avaliacao->getCodigo().getValor()    == codigo.getValor()   );
        CHECK(avaliacao->getNota().getValor()      == nota.getValor()     );
        CHECK(avaliacao->getDescricao().getValor() == descricao.getValor());

        SECTION("metodo set funciona", "[set]") {
            REQUIRE_NOTHROW(avaliacao->setCodigo   (   codigo2     ));
            REQUIRE_NOTHROW(avaliacao->setNota     (   nota2       ));
            REQUIRE_NOTHROW(avaliacao->setDescricao(   descricao2  ));


            CHECK(avaliacao->getCodigo().getValor()    == codigo2.getValor()   );
            CHECK(avaliacao->getNota().getValor()      == nota2.getValor()     );
            CHECK(avaliacao->getDescricao().getValor() == descricao2.getValor());
        }
    }

    delete avaliacao;
}