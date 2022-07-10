#include "Entidades.h"
#include <stdexcept>

Usuario:: Usuario(string nome, string email, string senha, string idioma, string data, string descricao):
    nome(nome),
    email(email),
    senha(senha),
    idioma(idioma),
    data(data),
    descricao(descricao)
    {}

Hospedagem::Hospedagem(string codigo, string cidade, string pais, string nota, string descricao):
    codigo(codigo),
    cidade(cidade),
    pais(pais),
    nota(nota),
    descricao(descricao)
  {}
