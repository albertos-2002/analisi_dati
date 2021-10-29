#include <iostream>
#include <cmath>
using namespace std;

int main () {
    
// variabili per la parte che calcola la somma e la media aritmetica
    int numero_misure_while = 0;
    int numero_misure_fatte = 0;
    double somma_misure = 0; 
    double valore_misura = 0;
    double media_aritmetica = 0;
    
// variabili per la parte che calcola SE e SEM
    long double parametro_se_1 = 0;
    long double parametro_se_1_1 = 0; //non conosco che ordine delle operazione segue 
    int numero_misure_while_se = 0;
    double valore_misura_se = 0;
    double scarto_quadrato = 0;
    double scarto_quadrato_2 = 0; // variabile per ordine delle operazioni
    long double somma_scarti_quadrati = 0;
    double radicando_se = 0; // variabile per ordine delle operazioni
    long double se = 0;
    long double sem = 0;
    double radice_numero_misure_fatte = 0;
    //int numeratore_parametro_se = 1; // nel calcolare 1/variabile da errore invece con variabile=1/qualcosa funge
    
//inserimento del numero totale delle misure che sono state effettuate
    cout << "Inserire il numero totale delle misure effettuate" << endl;
    cin >> numero_misure_fatte;
    cout << endl; 
    
//ciclo while che fa la somma di tutte le misure, equivale a fare una sommatoria
//cambiare lo standard input
    while (numero_misure_while < numero_misure_fatte) {
        
        cout << "Inserire il valore numerico della misura" << endl;
        cin >> valore_misura;
        //equazione che somma la somma delle misure al nuovo valore        
        somma_misure = somma_misure + valore_misura;

        cout << "Al momento la somma delle varie misure vale\t" << somma_misure << endl;
        //equazione che mi fa fermare il cilo while dopo 120 ripetizioni di somma
        numero_misure_while = numero_misure_while + 1;

    }
    
// calcolo della media aritmetica    
    media_aritmetica = somma_misure / numero_misure_fatte;
    
//presentazione in standard output dei dati relativi alla media aritmetica    
    cout << "La media aritmetica (stima di mu valore medio) delle " << numero_misure_fatte << " misure eseguite è" << endl << endl;
    cout << media_aritmetica << endl << endl;
    
//calcolo della deviazione standard campionaria o SE
    
    // calcolo del primo parametro pari a 1/(N-1)
        
        parametro_se_1_1 = numero_misure_fatte - 1;
        
        //cout di verifica valori
        cout << "il denominatore N-1 vale =  " << parametro_se_1_1 << endl;
        
        parametro_se_1 = 1/parametro_se_1_1;
        
        //cout di verifica valori
        cout << "il parametro 1 / (N-1) vale =  " << parametro_se_1 << endl;     
    
    // calcolo della somma degli scarti quadrati rispetto alla media
    
        while (numero_misure_while_se < numero_misure_fatte) {
        
            //cin per tutte le misure che verrà sostituito da una lettura da file
            cout << "Inserire nuovamente il valore di tutte le misure" << endl;
            cin >> valore_misura_se;
            
            //calcolo dello scarto quadrato
            scarto_quadrato = valore_misura_se - media_aritmetica;
            scarto_quadrato_2 = pow(scarto_quadrato,2);
            
            //cout controllo valori
            cout << "lo scarto NON quadrato vale =  " << scarto_quadrato << endl;
            cout << "lo scarto quadrato della misura inserita sopra vale =  "<< scarto_quadrato_2 << endl;
            
            //somma della somma degli scarti quadrati
            somma_scarti_quadrati = somma_scarti_quadrati + scarto_quadrato_2;
            
            //cout di verifica valori
            cout << "la somma degli scarti quadrati al momento è =  " << somma_scarti_quadrati << endl;
            
            //contatore del ciclo
            numero_misure_while_se = numero_misure_while_se + 1;
        
        }
    
    // calcolo finale di SE, ovvero la radice quadrata
        radicando_se = parametro_se_1 * somma_scarti_quadrati;
        
        //cout controllo valori
        cout << "il valore del radicando è =  " << radicando_se << endl;
        
        se = sqrt(radicando_se);
    
    cout << "SE =  " << se << endl << endl; 
    
//calcolo SEM
    radice_numero_misure_fatte = sqrt(numero_misure_fatte);
    
    //cout controllo valori
    cout << "la radice del numero di misure fatte (N) =  " << radice_numero_misure_fatte << endl;
    
    sem = se / radice_numero_misure_fatte;
    
cout << "SEM = " << sem << endl;
    
    return 0;
}
