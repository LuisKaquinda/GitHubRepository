#ifndef MONOMIOS_H_INCLUDED
#define MONOMIOS_H_INCLUDED
#include <clocale>
#include "fracoes.h"

using namespace std;

class Monomio
{
private:
    Fracao coeficiente;
    char variavel;
    Fracao grauDaVariavel;
public:
    Monomio();
    Monomio(char variavel);
    Monomio(float coeficiente, char variavel);
    Monomio(Fracao coeficiente, char variavel);
    Monomio(char variavel, int grau);
    Monomio(float coeficiente, char variavel, int grau);
    Monomio(Fracao coeficiente, char variavel, int grau);
    Fracao getCoeficiente();
    void setCoeficiente(float coeficiente);
    void setCoeficiente(Fracao coeficiente);
    void setCoeficienteFracionario(Fracao coeficiente);
    char getVariavel();
    void setVariavel(char variavel);
    Fracao getGrauDaVariavel();
    void setGrauDaVariavel(int grau);
    void setGrauDaVariavel(Fracao grau);
    Monomio somaMonomios(Monomio monomio);
    Monomio subtraiMonomios(Monomio monomio);
    Monomio multiplicaMonomios(Monomio monomio);
    Monomio divideMonomios(Monomio monomio);
    ~Monomio();
};

//Constructors

Monomio::Monomio() {}

Monomio::Monomio(char variavel, int grau) {
    this->coeficiente.setNumerador(1);
    this->variavel = variavel;
    this->grauDaVariavel.setNumerador(grau);
}
Monomio::Monomio(char variavel) {
    this->coeficiente.setNumerador(1);
    this->variavel = variavel;
    this->grauDaVariavel.setNumerador(1);
}
Monomio::Monomio(float coeficiente, char variavel) {
    this->coeficiente.setNumerador(coeficiente);
    this->variavel = variavel;
    this->grauDaVariavel = 1;
}
Monomio::Monomio(float coeficiente, char variavel, int grau) {
    this->coeficiente.setNumerador(coeficiente);
    this->variavel = variavel;
    this->grauDaVariavel.setNumerador(grau);
}
Monomio::Monomio(Fracao coeficiente, char variavel, int grau) {
    this->coeficiente = coeficiente;
    this->variavel = variavel;
    this->grauDaVariavel.setNumerador(grau);
}

Monomio::Monomio(Fracao coeficiente, char variavel) {
    this->coeficiente = coeficiente;
    this->variavel = variavel;
    this->grauDaVariavel.setNumerador(1);
}

// End Constructors

Monomio::~Monomio() {}

//Setters e Getters

//Get coeficiente
Fracao Monomio::getCoeficiente() {
    return coeficiente;
}

//Set coeficiente não fracionario
void Monomio::setCoeficiente(float coeficiente) {
    this->coeficiente.setNumerador(coeficiente);
}

//Set coeficiente fracionario
void Monomio::setCoeficiente(Fracao coeficiente) {
    this->coeficiente = coeficiente;
}

//Get Variável
char Monomio::getVariavel() {
    return this->variavel;
}

//Set variável
void Monomio::setVariavel(char variavel) {
    this->variavel = variavel;
}

Fracao Monomio::getGrauDaVariavel(){
    return this->grauDaVariavel;
}

void Monomio::setGrauDaVariavel(int grau){
    this->grauDaVariavel.setNumerador(grau);
}

void Monomio::setGrauDaVariavel(Fracao grau){
    this->grauDaVariavel = grau;
}

//End Setters e Getters

#endif // EMPRESA_H_INCLUDED