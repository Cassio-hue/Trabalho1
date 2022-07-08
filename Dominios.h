#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>
#include <ctype.h>
#include <string>
#include <regex>
#include <unordered_set>


using namespace std;


/// Parente de todos os domínios.
class Dominio {
    // Matrícula: 211038208

    private:
        string valor;
        virtual void validar(string) = 0;
    public:
        Dominio(const string&);
        virtual ~Dominio(){};

/// @param valor uma string qualquer
///
/// chama uma função de validação e, caso a entrada seja válida, o valor é armazenado
        void setValor(const string&);

/// @return valor
        string getValor() const;
};

inline string Dominio::getValor() const {
    // Matrícula: 211038208

    return valor;
}


/// \brief Domínio Nome 
///
/// Possui uma função validar. Se o nome (tipo string) passado para a função for válido, o nome é armazenado. Caso contrário, ocorre o lançamento de uma exceção.
///
/// **Regras para o nome ser aceito**:
/// 1. Até 30 caracteres
/// 2. Formato: prenome sobrenome
/// 3. Não pode ter dois espaços em branco
/// 4. Não pode terminar ou começar com espaço em branco
/// 5. Somente letras
/// 6. As letras iniciais do prenome e sobrenome devem ser maiúsculas
///
/// **Exemplos de nomes válidos**:
/// - Cassio Vinicius
/// - Joaquim Silva
/// - Dom Quixote
/// - Princesa Jujuba

class Nome : public Dominio {
    // Matricula: 211036141

    private:
        void validar(string);
    public:
        Nome(const string&);
};


/// \brief Domínio Nota 
///
/// Possui uma função validar. Se a nota (tipo string) passada para a função for válida, a nota é armazenada. Caso contrário, ocorre o lançamento de uma exceção.
///
/// **Regras para a nota ser aceita**:
/// 1. Somente números
/// 2. A nota deve ser um número entre 0 e 10
/// - Sendo 0 a menor nota possível e 10 a maior nota possível
class Nota : public Dominio {
    // Matricula: 211036141

    private:
        static const regex PADRAO_ACEITO;
        void validar(string valor);
    public:
        Nota(const string&);
};


class Idioma : public Dominio {
    // Matricula: 211036141

    private:
        void validar(string);
    public:
        Idioma(const string&);
        static const unordered_set<string> POSSIVEIS_VALORES;

};


class Data : public Dominio {
    // Matricula: 211036141

    private:
        static const regex PADRAO_ACEITO;
        void validar(string);
    public:
        Data(const string&);
};

class Codigo : public Dominio {
    // Matricula: 211026495

    private:
        static const int TAMANHO_CODIGO = 11;
        void validar(string);
    public:
        Codigo(const string&);
};


class Cidade : public Dominio {
    // Matrícula: 211038208

    private:
        void validar(string);
    public:
        static const unordered_set<string> POSSIVEIS_VALORES;
        Cidade(const string&);

};


class Email : public Dominio {
    // Matrícula: 211038208
    
    private:
        static const regex PADRAO_ACEITO;
        void validar(string);
    public:
        Email(const string&);

};


class Senha : public Dominio {
    // Matrícula: 211038208

    private:
        static const regex PADRAO_ACEITO;
        void validar(string);
    public:
        Senha(const string&);

};


class Descricao : public Dominio {
        // Matricula: 211026495

        private:
            static const regex PADRAO_NAO_ACEITO;
            static const int MAXIMO_CARACTERES;
            void validar(string);
        public:
            Descricao(const string&);
};

#endif // DOMINIOS_H_INCLUDED
