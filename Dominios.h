#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED


#include <stdexcept>
#include <ctype.h>
#include <string>
#include <regex>
#include <unordered_set>


using namespace std;


class Dominio {
    private:
        string valor;
        virtual void validar(string) = 0;
    public:
        void setValor(string);
        string getValor() const;
};

inline string Dominio::getValor() const {
    return valor;
}


class Nome : public Dominio {
    private:
        void validar(string);
};


class Nota : public Dominio {
    private:
        void validar(string valor);
};


class Idioma : public Dominio {
    private:
        void validar(string);
        static const int NUMERO_IDIOMAS = 11;
};


class Data : public Dominio {
    private:
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
    private:
        static const regex PADRAO_ACEITO;
        void validar(string);
};

#endif // DOMINIOS_H_INCLUDED
