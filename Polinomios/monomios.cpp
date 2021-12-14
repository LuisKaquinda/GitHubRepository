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
    res = m.somaMonomios(m1);
    cout << res.getCoeficiente() << res.getVariavel() << "^" << res.getGrauDaVariavel();
    return 0;
}