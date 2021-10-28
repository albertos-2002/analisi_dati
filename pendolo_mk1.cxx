#include <iostream>
using namespace std;

int numero_misure_while = 0;
int munero_misure_fatte = 0;
double float somma_misure = 0; 
double float valore_misure = 0;
double float media_aritmetica = 0;

cout << "Inserire il numero totale delle misure effettuate" << endl;
cin >> numero_misure_fatte; 

int main () {
    
    while (numero_misure_while <= numero_misure_fatte) {
        
        cout << "Inserire il valore numerico della misura" << endl;
        cin >> valore_misura;
        
        somma_misure = somma_misure + valore_misura;

        cout << "Al momento la somma delle varie misure vale" << endl;
        
        numero_misure_while = numero_misure_while + 1;

    }
    
media_aritmetica = somma_misure / numero_misure_fatte;
cout << "La media aritmetica delle " << numero_misure_fatte << "misure eseguite è" << endl;
cout << media_aritmetica << endl;

    return 0;
}
