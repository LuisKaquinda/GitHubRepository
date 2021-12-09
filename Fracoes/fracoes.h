#ifndef FRACOES_H_INCLUDED
#define FRACOES_H_INCLUDED
#include <clocale>

class Fracao {
    private:
        float numerador;
        float denominador;
    public:
        Fracao() {}

        Fracao(float numerador, float denominador) {
            this->numerador = numerador;
            this->denominador = denominador;
        }

        void setNumerador(float numerador) {
            this->numerador = numerador;
        }
        void setDenominador(float denominador) {
            this->denominador = denominador;
        }

        float getNumerador() {
            return this->numerador;
        }
        float getDenominador(){
            return this->denominador;
        }

        Fracao somaFracoes(Fracao f) {
            Fracao aux;
            if((this->denominador == 0)||(f.getDenominador() == 0)){
                aux.setNumerador(-1);
                aux.setDenominador(-1);
                return aux;
            } else if(this->denominador == f.getDenominador()){
                aux.setNumerador(getNumerador() + f.getNumerador());
                aux.setDenominador(f.getDenominador());
                return aux;
            } else {
                aux.setDenominador(getDenominador()*f.getDenominador());
                aux.setNumerador(getNumerador()*f.getDenominador() + f.getNumerador()*getDenominador());
                return aux;
            }
        }

        Fracao subtFracoes(Fracao f) {
            Fracao aux;
            if((this->denominador == 0)||(f.getDenominador() == 0)){
                aux.setNumerador(-1);
                aux.setDenominador(-1);
                return aux;
            } else if(this->denominador == f.getDenominador()){
                aux.setNumerador(getNumerador() - f.getNumerador());
                aux.setDenominador(f.getDenominador());
                return aux;
            } else {
                aux.setDenominador(getDenominador()*f.getDenominador());
                aux.setNumerador(getNumerador()*f.getDenominador() - f.getNumerador()*getDenominador());
                return aux;
            }
        }

        Fracao multFracoes(Fracao f) {
            Fracao aux;
            if((this->denominador == 0)||(f.getDenominador() == 0)){
                aux.setNumerador(-1);
                aux.setDenominador(-1);
                return aux;
            } else {
                aux.setNumerador(getNumerador()*f.getNumerador());
                aux.setDenominador(getDenominador()*f.getDenominador());
                return aux;
            }  
        }

        Fracao divFracoes(Fracao f) {
            Fracao aux;
            if((this->denominador == 0)||(f.getDenominador() == 0)){
                aux.setNumerador(-1);
                aux.setDenominador(-1);
                return aux;
            } else {
                aux.setNumerador(getNumerador()*f.getDenominador());
                aux.setDenominador(getDenominador()*f.getNumerador());
                return aux;
            } 
        }

        bool fracoesIguais(Fracao outraFracao) {
            return ((this->numerador == outraFracao.getNumerador()) && (this->denominador == outraFracao.getDenominador()));
        }
};

#endif // EMPRESA_H_INCLUDED