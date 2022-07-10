#include "Entidades.h"
#include <stdexcept>


Hospedagem::Hospedagem(string codigo, string cidade, string pais, string nota, string descricao):
    codigo(codigo),
    cidade(cidade),
    pais(pais),
    nota(nota),
    descricao(descricao)
  {}