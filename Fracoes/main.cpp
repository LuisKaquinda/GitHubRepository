#include <iostream>
#include "fracoes.h"
#include "no_f.h"
#include "lista_f.h"
#include <clocale>

using namespace std;

int main(){
    setlocale(LC_ALL, "PORTUGUESE");
    cout << "\t\t LISTA DE FREÇÕES" << endl << endl;
    cout << "==================================================\n\n";
    char answer = 'y';
    int option = 0;
            
    do{
        cout << "Que operação pretende executar sobre as frações (?):\n\n";
        cout << "0. Criar uma lista de frações (1 [sim] | 0 [não]): ";
        cin >> option;
        if(option == 1){
            Lista l = Lista();
            l.imprimirLista();
            cout << "Lista Criada com sucesso!\n\n";
            system("cls");
            option = 0;
            cout << "\nOperações sobre a lista\n 1.Adicionar\n 2.Remover \n 3.Consultar \n 4. Outras Opções \n";
            cin >> option;
            switch (option)
            {
            case 1:
                Fracao f(-1, -1);
                int numero;
                cout << "Digite o numerador: ";
                cin >> numero;
                f.setNumerador(numero);
                cout << "Digite o denominador: ";
                cin >> numero;
                f.setDenominador(numero);
                l.addInicio(f);
                system("cls");
                l.imprimirLista();
                answer = 'n';
                break;
            
            default:
                break;
            }
        }
    }while (answer != 'n');
    
    return 0;
}