#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main () {

    //file input nome
    string nome_file_in = "";
    
//stanziamento vettori
	vector<double> misure_input;

// variabili per la parte che calcola la somma e la media aritmetica
    int numero_misure_while = 0;  //contatore del ciclo while, ovvero il numero di misure fatte
    int numero_misure_fatte = 0; //equivale al valore di numero_misure_while a fine del ciclo (numero totale misure)
    double somma_misure = 0;  //contiene il valore che è la somma di tutti i valori in lettura è nel ciclo while corrispondente
    double valore_misura = 0;  //viene messo il valore preso da stod
    double media_aritmetica = 0; //valore della media aritmetica (somma misure/numero_misure_fatte)
    
// variabili per la parte che calcola SE e SEM
    long double parametro_n_meno_1_se = 0; //done
	long double parametro_1_diviso_n_meno_1_se = 0;  // done
	double scarto_quadrato = 0; //valore della differenza fra xiesimo e x medio //done
    double scarto_quadrato_2 = 0; // variabile scarto_quadrato elevata al quadrato //done
	long double somma_scarti_quadrati = 0; // mantiene la somma di tutti gli scarti quadrati
    double radicando_se = 0;
    long double se = 0;
    long double sem = 0;
    double radice_numero_misure_fatte = 0;

//variabili stringhe e per conversione da stringa a variabile
    string valore_misura_str = "";  //prende il valore da stod()

//cin nome file
    cout << "Inserire il nome del file che deve essere letto" << endl;
    cin >> nome_file_in;

//apertura del file di input
ifstream file_in;
ofstream file_out;

//apertura del file in lettura
file_in.open (nome_file_in);

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
			
			//inserimento valore nel vettore misure_input
			misure_input.push_back(valore_misura);			
			
			somma_misure = somma_misure + valore_misura;			
			
			//contatore
			numero_misure_while = numero_misure_while + 1;				
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
        parametro_n_meno_1_se = numero_misure_fatte - 1;
		
        parametro_1_diviso_n_meno_1_se = 1/parametro_n_meno_1_se;
        
        //cout di verifica valori
        cout << "il parametro 1 / (N-1) vale =  " << parametro_1_diviso_n_meno_1_se << endl;   		
    
    // calcolo della somma degli scarti quadrati rispetto alla media
    
    //ciclo range for
	for (auto iterator : misure_input){

    		//calcolo dello scarto quadrato
               scarto_quadrato = iterator - media_aritmetica;
               scarto_quadrato_2 = pow(scarto_quadrato,2);
            
            //somma della somma degli scarti quadrati
            somma_scarti_quadrati = somma_scarti_quadrati + scarto_quadrato_2;
	}
    
    // calcolo finale di SE, ovvero la radice quadrata
        radicando_se = parametro_1_diviso_n_meno_1_se * somma_scarti_quadrati;
        
        se = sqrt(radicando_se);
    
    cout << "SE =  " << se << endl << endl;
    
    //calcolo SEM
    radice_numero_misure_fatte = sqrt(numero_misure_fatte);
    
    sem = se / radice_numero_misure_fatte;
    
    cout << "SEM = " << sem << endl;


//scrittura su file di se

//apertura del file in scrittura
	file_out.open ("se.txt");

//controllo se il file è stato aperto correttamente
	if (file_in.fail()) {
		cout << "Errore nell'apertura del file di input" << endl;
	}

//scrivo su file di output
    file_out << se;

//chiude il file aperto in lettura
	file_out.close();
//dovrebbe permettere di riutilizzare la stessa variabile per leggere altri file
	file_out.clear();

//scrittura su file di sem   

//apertura del file in scrittura
    file_out.open ("sem.txt");

    //controllo se il file è stato aperto correttamente
    if (file_in.fail()) {
        cout << "Errore nell'apertura del file di input" << endl;
    }

    //scrivo su file di output
    file_out << sem;

    //chiude il file aperto in lettura
    file_out.close();
    //dovrebbe permettere di riutilizzare la stessa variabile per leggere altri file
    file_out.clear();
    return 0;
}
