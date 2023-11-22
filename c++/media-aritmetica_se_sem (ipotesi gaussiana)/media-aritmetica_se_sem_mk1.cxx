#include <iostream>
using namespace std;

int main () {

    int numero_misure_while = 0;
    int numero_misure_fatte = 0;
    float somma_misure = 0.0; 
    float valore_misura = 0.0;
    float media_aritmetica = 0.0;
    
    cout << "Inserire il numero totale delle misure effettuate" << endl;
    cin >> numero_misure_fatte;
    cout << endl; 
    
    while (numero_misure_while < numero_misure_fatte) {
        
        cout << "Inserire il valore numerico della misura" << endl;
        cin >> valore_misura;
        cout << endl;
        
        somma_misure = somma_misure + valore_misura;

        cout << "Al momento la somma delle varie misure vale\t" << somma_misure << endl << endl;
        
        
        numero_misure_while = numero_misure_while + 1;

    }

// calcolo della media aritmetica    
    media_aritmetica = somma_misure / numero_misure_fatte;
    
//presentazione in stdout dei dati relativi alla media aritmetica    
    cout << "La media aritmetica delle " << numero_misure_fatte << " misure eseguite è" << endl << endl;
    cout << media_aritmetica << endl << endl;

    return 0;
}
