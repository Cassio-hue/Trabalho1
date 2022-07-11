#include "Entidades.h"
#include <stdexcept>


Hospedagem::Hospedagem(const Codigo& codigo, const Cidade& cidade, 
  const Pais& pais, const Nota& nota, const Descricao& descricao) : 
  codigo(codigo.getValor()), cidade(cidade.getValor()), pais(pais.getValor()), 
  nota(nota.getValor()), descricao(descricao.getValor()) {
}

Avaliacao::Avaliacao(const Codigo& codigo, const Nota& nota, const Descricao& descricao); : 
  codigo(codigo.getValor()), nota(nota.getValor()), descricao(descricao.getValor()) {

}