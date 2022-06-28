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
        static const regex PADRAO_ACEITO;
        void validar(string valor);
};


class Idioma : public Dominio {
    // Matricula: 211036141

    public:
        static const unordered_set<string> POSSIVEIS_VALORES;
    private:
        void validar(string);
};


class Data : public Dominio {
    // Matricula: 211036141

    private:
        static const regex PADRAO_ACEITO;
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
        static const unordered_set<string> POSSIVEIS_VALORES;
    private:
        void validar(string);
};


class Email : public Dominio {
    // Matrícula: 211038208

    private:
        static const regex PADRAO_ACEITO;
        void validar(string);
};


class Senha : public Dominio {
    // Matrícula: 211038208

    private:
        static const regex PADRAO_ACEITO;
        void validar(string);
};


#endif // DOMINIOS_H_INCLUDED
