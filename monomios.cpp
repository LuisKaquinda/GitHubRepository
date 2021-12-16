#include <iostream>
#include "monomios.h"
#include "fracoes.h"

using namespace std;

int main(){
    Fracao f(1);
    Monomio m = Monomio(2, 'x', 2);
    Monomio m1(2, 'x', 2);
    Monomio m2(f, 'x', 2);
    Monomio res;

    cout << m2.getCoeficiente().getNumerador() << endl;

    m.setCoeficiente(2);
    m.setGrauDaVariavel(3);

    //cout << m.getCoeficiente().getNumerador() << endl;
    //cout << m.getGrauDaVariavel().getNumerador() << endl;
    if((m.getCoeficiente().getDenominador() == 1) && (m.getGrauDaVariavel().getDenominador() == 1)){
        cout << m.getCoeficiente().getNumerador() << m.getVariavel() << "^" << m.getGrauDaVariavel().getNumerador() << endl;
    } else if((m.getCoeficiente().getDenominador() != 1) && (m.getGrauDaVariavel().getDenominador() == 1)){
        cout << m.getCoeficiente().getNumerador() << "/" << m.getCoeficiente().getDenominador() << m.getVariavel() << "^" << m.getGrauDaVariavel().getNumerador() << endl;
    } else if((m.getCoeficiente().getDenominador() == 1) && (m.getGrauDaVariavel().getDenominador() != 1)){
        cout << m.getCoeficiente().getNumerador() << m.getVariavel() << "^" << m.getGrauDaVariavel().getNumerador() << "/" << m.getGrauDaVariavel().getDenominador() << endl;   
    } else {
        cout << m.getCoeficiente().getNumerador() << "/" << m.getCoeficiente().getDenominador() << m.getVariavel() << "^" << m.getGrauDaVariavel().getNumerador() << "/" << m.getGrauDaVariavel().getDenominador() << endl;   
    }
    return 0;
}