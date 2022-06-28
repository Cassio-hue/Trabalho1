#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>
#include <ctype.h>
#include <string>
#include <regex>
#include <unordered_set>

using namespace std;


class Dominio {
    // Matrícula: 211038208

    private:
        string valor;
        virtual void validar(string) = 0;
    public:
        void setValor(string);
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
};


class Nota : public Dominio {
    // Matricula: 211036141

    private:
        void validar(string valor);
};


class Idioma : public Dominio {
    // Matricula: 211036141

    private:
        void validar(string);
        static const int NUMERO_IDIOMAS = 11;
};


class Data : public Dominio {
    // Matricula: 211036141

    private:
        void validar(string);
};

class Codigo : public Dominio {
    // Matricula: 211026495

    private:
        static const int TAMANHO_CODIGO = 11;
        void validar(string);
};


class Cidade : public Dominio {
    // Matrícula: 211038208

    public:
        static const unordered_set<string> POSSIVEIS;
    private:
        void validar(string);
};


class Email : public Dominio {
    // Matrícula: 211038208

    private:
        static const regex PADRAO_ACEITO;
        void validar(string);
};

class Descricao : public Dominio {
        private:
        static const regex PADRAO_NAO_ACEITO;
        static const int MAXIMO_CARACTERES = 40;
        void validar(string);
};

#endif // DOMINIOS_H_INCLUDED
