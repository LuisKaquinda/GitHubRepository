#ifndef LISTA_F_H_INCLUDED
#define LISTA_F_H_INCLUDED
#include <clocale>
#include <iostream>
#include "fracoes.h"
#include "no_f.h"



using namespace std;

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

        Fracao mediaPonderada(){
            Fracao media;
            if(vazio()) {
                media.setNumerador(-1);
                media.setDenominador(-1);
                return media;
            } else {
                Fracao soma, qtd;
                No* atual = getCabeca();
                int t = tamanhoDaLista(), cont = 0;
                soma.setNumerador(0);
                soma.setDenominador(1);
                for(int i = 0; i < t; i++){
                    soma = atual->getDado().somaFracoes(soma);
                    atual = atual->getProximo();
                    cont++;
                }
                qtd.setNumerador(cont);
                qtd.setDenominador(1);
                media = soma.divFracoes(qtd);
                return media;
            }
        }

        void obterNumerador(int pos){
            Fracao retorna;
            if(vazio()) {
                banner();
            } else {
                int t = tamanhoDaLista();
                if((pos > t) || (pos < 0)) {
                    cout << "Posicao nao encontrada!"<< endl; 
                } else {
                    No* atual = getCabeca();
                    for(int i = 0; i < t; i++){
                        if((i+1) == pos){
                            retorna.setNumerador(atual->getDado().getNumerador());
                            retorna.setDenominador(atual->getDado().getDenominador());
                            break;
                        }
                        atual = atual->getProximo();
                    }
                    cout << retorna.getNumerador();
                }
            }
        }

        void obterDenominador(int pos){
            Fracao retorna;
            if(vazio()) {
                banner();
            } else {
                int t = tamanhoDaLista();
                if((pos > t) || (pos < 0)) {
                    cout << "Posicao nao encontrada!"<< endl; 
                } else {
                    No* atual = getCabeca();
                    for(int i = 0; i < t; i++){
                        if((i+1) == pos){
                            retorna.setNumerador(atual->getDado().getNumerador());
                            retorna.setDenominador(atual->getDado().getDenominador());
                            break;
                        }
                        atual = atual->getProximo();
                    }
                    cout << retorna.getDenominador();
                }
            }
        }

        Fracao oInverso(Fracao f){
            Fracao invertida;
            invertida.setDenominador(f.getNumerador());
            invertida.setNumerador(f.getDenominador());
            return invertida;
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
            std::cout << "Lista Vazia!" << std::endl;
        }

        void operacoesSobreALista(){
            cout << "\t\t LISTA DE FREÇÕES" << endl << endl;
            cout << "==================================================\n\n";
            char answer = 'y';
            int option = 0;
            
            do{
                cout << "Que operação pretende executar sobre as frações (?):\n\n";
                cout << "1. Criar uma lista de frações\n 2. Adicionar\n 3. Remover\n 4. Consultar\n 5. Operar Frações \n\n";
                switch (option)
                {
                case 1:
                    
                    break;
                
                default:
                    break;
                }

            }while (answer != 'n');
            
        }
};



#endif // EMPRESA_H_INCLUDED