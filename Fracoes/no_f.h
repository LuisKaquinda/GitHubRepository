#ifndef NO_F_H_INCLUDED
#define NO_F_H_INCLUDED

#include "fracoes.h"
#include <clocale>


class No {
    private:
        No* anterior;
        Fracao dado;
        No* proximo;
    public:

        No(Fracao dado) {
            this->anterior = NULL;
            this->dado = dado;
            this->proximo = NULL;
        }

    void setAnterior(No * anterior) {
        this->anterior = anterior;
    }

    Fracao setDado(Fracao dado) {
        this->dado = dado;
    }

    void setProximo(No * proximo) {
        this->proximo = proximo;
    }

    No* getAnterior() {
        return anterior;
    }

    Fracao getDado() {
        return dado;
    }

    No* getProximo() {
        return proximo;
    }
};

#endif // EMPRESA_H_INCLUDED