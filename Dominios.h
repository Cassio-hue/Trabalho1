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


class Nome : public Dominio {
    // Matricula: 211036141

    private:
        void validar(string);
    public:
        Nome(const string&);
};


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
