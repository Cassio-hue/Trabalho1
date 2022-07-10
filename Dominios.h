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
/// - 0 é a menor nota possível e 10 a maior nota possível
class Nota : public Dominio {
    // Matricula: 211036141

    private:
        static const regex PADRAO_ACEITO;
        void validar(string valor);
    public:
        Nota(const string&);
};

/// \brief Domínio Idioma
///
/// É importante se alientar que não ocorre a validação da acentuação, logo caso esteja presente algum acento no valor passado, será lançada uma exceção!
///
/// Possui uma função validar. Se o idioma (tipo string) passado para a função for válido, o idioma é armazenada. Caso contrário, ocorre o lançamento de uma exceção.
class Idioma : public Dominio {
    // Matricula: 211036141

    private:
        void validar(string);
    public:
        Idioma(const string&);
        /// **Os idiomas presentes no array de POSSIVEIS_VALORES são aceitos pela função validar**
        static const unordered_set<string> POSSIVEIS_VALORES;

};

/// \brief Domínio Data
///
/// Possui uma função validar. Se a data (tipo string) passada para a função for válida, a data é armazenada. Caso contrário, ocorre o lançamento de uma exceção.
///
/// O formato da data considerado válido: **DIA/MES**
///
/// **Formato dos dias**:
/// Numeros entre 01 - 31, número menor que 10 deve ser acompanhado com um zero.
///
/// **Formato dos meses**:
/// - JAN
/// - FEV
/// - MAC
/// - ABR
/// - MAI
/// - JUN
/// - JUL
/// - AGO
/// - SET
/// - OUT
/// - NOV
/// - DEZ
///
/// A função validar não leva em consideração anos bissextos
///
/// **Observações**:
/// - O mês de FEV vai até o dia 29
/// - Os meses: ABR, JUN, SET, NOV vão até o dia 30
/// - Os meses: JAN, MAR, MAIO, JUL, AGO, OUT vão até o dia 31

class Data : public Dominio {
    // Matricula: 211036141

    private:
        static const regex PADRAO_ACEITO;
        void validar(string);
    public:
        Data(const string&);
};

/// Código indentificador pelo último digito (algoritmo de Luhn)
class Codigo : public Dominio {
    // Matricula: 211026495
    private:
/// @param TAMANHO_CODIGO único tamanho permitido para código     
        static const int TAMANHO_CODIGO = 11;
/// verifica se o inserido é valido
/// 
/// @throw invalid_argument código não é valido, por último dígito ou tamanho
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

/// Descricao de usuário, hospedagem ou avaliação
class Descricao : public Dominio {
        // Matricula: 211026495
        private:
/// @param PADRAO_NAO_ACEITO constante regex que garante que a string inserida não possui pontuação em sequência
            static const regex PADRAO_NAO_ACEITO;
            static const int MAXIMO_CARACTERES;
            void validar(string);

/// @throw invalid_argument quando a descrição possui mais de 40 caracteres ou pontuação em sequência
        public:
            Descricao(const string&);
};

/// Pais escolhido para hospedagem
class Pais : public Dominio {
    // Matricula: 211026495

    private:
/// @param POSSIVEIS objeto com únicos possíveis países que são aceitos na classe
    static const unordered_set<string> POSSIVEIS;

/// @throw invalid_argument país não está entre os aceitos
    void validar(string);

    public:
    Pais(const string&);
};

#endif // DOMINIOS_H_INCLUDED
