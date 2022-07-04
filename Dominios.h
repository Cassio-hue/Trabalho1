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
        Dominio(string);
        virtual ~Dominio(){};

/// @param valor uma string qualquer
///
/// chama uma função de validação e, caso a entrada seja válida, o valor é armazenado
        void setValor(string);

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
        Nome(string);
};


class Nota : public Dominio {
    // Matricula: 211036141

    private:
        void validar(string valor);
    public:
        Nota(string);
};


class Idioma : public Dominio {
    // Matricula: 211036141

    private:
        void validar(string);
        static const int NUMERO_IDIOMAS = 11;
    public:
        Idioma(string);
};


class Data : public Dominio {
    // Matricula: 211036141

    private:
        void validar(string);
    public:
        Data(string);
};

class Codigo : public Dominio {
    // Matricula: 211026495

    private:
        static const int TAMANHO_CODIGO = 11;
        void validar(string);
    public:
        Codigo(string);
};


class Cidade : public Dominio {
    // Matrícula: 211038208

    public:
        static const unordered_set<string> POSSIVEIS;
        Cidade(string);
    private:
        void validar(string);
};


class Email : public Dominio {
    // Matrícula: 211038208
    public:
        Email(string);

    private:
        static const regex PADRAO_ACEITO;
        void validar(string);
};


class Senha : public Dominio {
    public:
        Senha(string);

    private:
        static const regex PADRAO_ACEITO;
        void validar(string);
};


#endif // DOMINIOS_H_INCLUDED
