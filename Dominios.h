#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED
#include <string>
#include <stdexcept>
#include <ctype.h>


using namespace std;


class Dominio
{
    public:
        void setValor(string);
        string getValor() const;

    private:
        string valor;
        virtual void validar(string) = 0;
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
        static const int VALOR_MAX = 10, VALOR_MIN = 0;
};


#endif // DOMINIOS_H_INCLUDED
