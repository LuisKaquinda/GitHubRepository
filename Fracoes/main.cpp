#include <iostream>

using namespace std;

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
                banner(aux);
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
                banner(aux);
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
                banner(aux);
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
                banner(aux);
                return aux;
            } else {
                aux.setNumerador(getNumerador()*f.getDenominador());
                aux.setDenominador(getDenominador()*f.getNumerador());
                return aux;
            } 
        }

        bool fracoesIguais(Fracao outraFracao) {
            return ((this->numerador == outraFracao.getNumerador()) && (this->denominador == outraFracao.getDenominador()));
            //return this == outraFracao;
        }

        void banner(Fracao f) {
            if((f.getNumerador() == -1) && (f.getDenominador() == -1))
                cout << "Impossivel Resolver!" << endl;
        }

        void imprimir_fracao() {
            cout << this->numerador << "/"  << this->denominador << endl;
        }

        void imprimir(Fracao f){
    
        }
};



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

class Lista {
    private:
        No* cabeca;
    public:
        Lista() {
            this->cabeca = NULL;
        }
        Lista(No* cabeca) {
            this->cabeca = cabeca;
        }

        No* getCabeca() {
            return cabeca;
        }

        No* setCabeca(No* novo) {
            this->cabeca = novo;
        }

        void imprimirLista() {
            if( vazio() ) {
                cout << "A Lista esta vazia!" << endl;
            } else {
                No* atual = getCabeca();
                cout << "Minha Lista de Frações: " << endl;
                while (atual != NULL)
                {
                    cout << atual->getDado().getNumerador() << "/" << atual->getDado().getDenominador() << endl;
                    atual = atual->getProximo();
                }
                cout << endl;
            }
        }

        void addInicio(Fracao dado_novo) {
            No* novo_no = new No(dado_novo);
            if(vazio()) {
                setCabeca(novo_no);
            } else {
                novo_no->setProximo(getCabeca());
                setCabeca(novo_no);
            }
        }
        void removerInicio() {
            if( vazio() ) {
                imprimirLista();
            } else {
                No* atual = getCabeca();
                setCabeca(atual->getProximo());
                getCabeca()->setAnterior(NULL);
                delete atual;
            }
        }

        void addFim(Fracao dado_novo) {
            No* novo_no = new No(dado_novo);
            if(vazio()) {
                setCabeca(novo_no);
            } else {
                No* atual = getCabeca();
                while(atual->getProximo() != NULL){
                    atual = atual->getProximo();
                }
                atual->setProximo(novo_no);
                novo_no->setAnterior(atual);
            }
        }

        void removerFim() {
            if( vazio() ) {
                imprimirLista();
            } else {
                No* atual = getCabeca();
                while(atual->getProximo() != NULL){
                    atual = atual->getProximo();
                }
                atual->getAnterior()->setProximo(NULL);
                delete atual;
            }
        }

        bool acharFracao(Fracao aProcurar) {
            bool achou = false;
            if(vazio()){
                return false;
            } else {
                No* atual = getCabeca();
                while(atual != NULL) {
                    if(atual->getDado().fracoesIguais(aProcurar))
                        achou = true;
                    atual = atual->getProximo();
                }
                return achou;
            }
        }

        Fracao maiorFracao(){
            Fracao maiorf;
            if(vazio()){
                maiorf.setNumerador(-1);
                maiorf.setDenominador(-1);
                return maiorf;
            } else {
                No* atual = getCabeca();
                int t = tamanhoDaLista();
                maiorf.setNumerador(atual->getDado().getNumerador());
                maiorf.setDenominador(atual->getDado().getDenominador());
                for(int i = 0; i < t - 1; i++) {
                    if(maiorf.getDenominador() == atual->getProximo()->getDado().getDenominador()) {
                        if(atual->getProximo()->getDado().getNumerador() > maiorf.getNumerador()) {
                            maiorf.setNumerador(atual->getProximo()->getDado().getNumerador());
                            maiorf.setDenominador(atual->getProximo()->getDado().getNumerador());
                        }
                    } else {
                        if((maiorf.getDenominador()*atual->getProximo()->getDado().getNumerador()) > (atual->getProximo()->getDado().getDenominador() * maiorf.getNumerador())){
                            maiorf.setNumerador(atual->getProximo()->getDado().getNumerador());
                            maiorf.setDenominador(atual->getProximo()->getDado().getDenominador());
                        }
                    }
                    atual = atual->getProximo();
                }
                return maiorf;
            }
        }

        Fracao menorFracao(){
            Fracao menorf;
            if(vazio()){
                menorf.setNumerador(-1);
                menorf.setDenominador(-1);
                return menorf;
            } else {
                No* atual = getCabeca();
                int t = tamanhoDaLista();

                menorf.setNumerador(atual->getDado().getNumerador());
                menorf.setDenominador(atual->getDado().getDenominador());
                for(int i = 0; i < t - 1; i++) {
                    if(menorf.getDenominador() == atual->getProximo()->getDado().getDenominador()) {
                        if(atual->getProximo()->getDado().getNumerador() < menorf.getNumerador()) {
                            menorf.setNumerador(atual->getProximo()->getDado().getNumerador());
                            menorf.setDenominador(atual->getProximo()->getDado().getNumerador());
                        }
                    } else {
                        if((menorf.getDenominador()*atual->getProximo()->getDado().getNumerador()) < (atual->getProximo()->getDado().getDenominador() * menorf.getNumerador())){
                            menorf.setNumerador(atual->getProximo()->getDado().getNumerador());
                            menorf.setDenominador(atual->getProximo()->getDado().getDenominador());
                        }
                    }
                    atual = atual->getProximo();
                }
                return menorf;
            }
        }

        
        bool vazio() {
            if(getCabeca() == NULL) {
                return true;
            } else {
                return false;
            }
        }

        int tamanhoDaLista() {
            if( vazio() ) {
                return 0;
            } else {
                No* atual = getCabeca();
                int cont = 0;
                while(atual != NULL) {
                    atual = atual->getProximo();
                    cont++;
                }
                return cont;
            }
        }

        
        void banner(){
            cout << "Lista vazia!" << endl;
        }
};

int main() {

    Lista l = Lista();
    Fracao f(1, 2);
    Fracao f1(2, 2);
    Fracao f2(4, 2);
    Fracao f3(7, 5);
    Fracao f4(7, 2);
    Fracao f5(7, 4);
    Fracao f6(0, 4);
    Fracao f7(1, 7);

    l.addInicio(f);
    l.addFim(f1);
    l.addInicio(f2);
    l.addFim(f3);
    l.addInicio(f4);
    l.addFim(f);
    l.addFim(f5);
    l.addInicio(f6);

    cout << l.acharFracao(f6) << endl;

    cout << l.tamanhoDaLista() << endl;
    l.imprimirLista();
    cout << l.maiorFracao().getNumerador() << "/" << l.maiorFracao().getDenominador() << endl;
    cout << l.menorFracao().getNumerador() << "/" << l.menorFracao().getDenominador() << endl;
  return 0;
}
