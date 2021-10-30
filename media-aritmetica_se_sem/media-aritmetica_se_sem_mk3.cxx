#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
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

//variabili stringhe e per conversione da stringa a variabile
    string valore_misura_str = "";
    string valore_misura_str_2 = "";

//apertura del file di input
ifstream file_in; 	//"NOME_FILE:ESTENSIONE"
ofstream file_out; 	//"NOME_FILE.ESTENSIONE"

//apertura del file in lettura
file_in.open ("NOME_FILE.ESTENSIONE");

//controllo se il file è stato aperto correttamente
if (file_in.fail()){
	cout << "Errore nell'apertura del file di input" << endl;
}

//ciclo di lettura delle misure con relativa somma

		while (!file_in.eof()) {
		
			getline(file_in, valore_misura_str, ',');
	
			//ciclo per trovare gli errori e far andare avanti il ciclo
			try {
			//trasforma la stringa in una variabile numerica
			valore_misura = stod(valore_misura_str);
			}
			
			catch (invalid_argument) {
			break;
			}
			
			//cout di ocntrollo
			cout << "CONTROLLO   valore misura    " << valore_misura << endl;
			
			somma_misure = somma_misure + valore_misura;
			
			//cout di controllo
			cout << "CONTROLLO   valore somma    " << somma_misure << endl;
			
			//contatore
			numero_misure_while = numero_misure_while + 1;
			cout << "numero totale delle misure   " << numero_misure_while << endl;
				
		}
		
	//cambio nome di variabile
	numero_misure_fatte = numero_misure_while;

	//chiude il file aperto in lettura
	file_in.close ();
	//dovrebbe permettere di riutilizzare la stessa variabile per leggere altri file
	file_in.clear ();
    
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
    
    //apertura del file in lettura
	file_in.open ("NOME_FILE.ESTENSIONE");

    //controllo se il file è stato aperto correttamente
    if (file_in.fail()){
	cout << "Errore nell'apertura del file di input" << endl;
    }
    
    	while (!file_in.eof()) {
    
    		getline(file_in, valore_misura_str_2, ',');
    		
    		//ciclo per trovare gli errori e far andare avanti il ciclo
			try {
			//trasforma la stringa in una variabile numerica
			valore_misura_se = stod(valore_misura_str_2);
			}
			
			catch (invalid_argument) {
			break;
			}
			
			//cout di controllo
			cout << "valore misura:  " << valore_misura_se << endl;
    
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
            //cout di controllo
            cout << "numero del ciclo  " << numero_misure_while_se << endl;
    
    	}
    	
    	//chiude il file aperto in lettura
	file_in.close ();
	//dovrebbe permettere di riutilizzare la stessa variabile per leggere altri file
	file_in.clear ();
    
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

//scrittura su file di output per SE e SEM



file_out.open ("NOME_FILE.ESTENSIONE", ofstream::out | ios_base::ate);
	
	//controllo paertura file
	if (file_out.fail()){
	cout << "Errore nell'apertura del file di output" << endl; 
	}
	
	file_out << "Media aritmetica" << endl;
    	file_out << media_aritmetica << endl;
    	file_out << "(totale misure = " << numero_misure_fatte << ")" << endl << endl;
	file_out << "SE" << endl;
	file_out << se << endl;
	file_out << "( il parametro 1/(N-1) = " << parametro_se_1 << ")" << endl;
	file_out << "( somma scarti quadrati = " << somma_scarti_quadrati << ")" << endl;
	file_out << "( radicando se = " << radicando_se << ")" << endl << endl;
	
	file_out << "SEM" << endl;
	file_out << sem << endl;


file_out.close();
    
   

    return 0;
}
