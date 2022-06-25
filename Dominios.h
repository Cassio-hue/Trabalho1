#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED
#include <stdexcept>
#include <ctype.h>
#include <string>
#include <regex>


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

class Codigo : public Dominio {
    private:
        static const int TAMANHO_CODIGO = 11;
        void validar(string);
};


#endif // DOMINIOS_H_INCLUDED
