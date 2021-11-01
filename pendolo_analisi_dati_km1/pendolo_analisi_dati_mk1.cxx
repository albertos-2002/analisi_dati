#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

int main () {

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
CALCOLO MEDIA SE SEM PER PERIODO SINGOLO
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

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
ifstream file_in; 		//"NOME_FILE:ESTENSIONE"
ofstream file_out_media; 	//"NOME_FILE.ESTENSIONE"
ofstream file_out_se;		//"NOME_FILE.ESTENSIONE"
ofstream file_out_sem;		//"NOME_FILE.ESTENSIONE"
ofstream file_out_parametri;	//"NOME_FILE.ESTENSIONE"


//apertura del file in lettura
file_in.open ("dati_input_ps.txt");

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
			exit (1);
			return 1;
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
	file_in.open ("dati_input_ps.txt");

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

//scrittura su file di output per SE e SEM e media

file_out_media.open ("media_aritmetica_ps.txt", ofstream::out | ios_base::ate);

	//controllo paertura file
	if (file_out_media.fail()){
	cout << "Errore nell'apertura del file di output" << endl; 
	}

	file_out_media << media_aritmetica << endl;

file_out_media.close();
//------------------------------------------------------------------------------------------------------------------------
file_out_se.open ("se_ps.txt", ofstream::out | ios_base::ate);

	//controllo paertura file
	if (file_out_se.fail()){
	cout << "Errore nell'apertura del file di output" << endl; 
	}

	file_out_se << se << endl;

file_out_se.close();
//------------------------------------------------------------------------------------------------------------------------
file_out_sem.open ("sem_ps.txt", ofstream::out | ios_base::ate);

	//controllo paertura file
	if (file_out_sem.fail()){
	cout << "Errore nell'apertura del file di output" << endl; 
	}

	file_out_sem << sem << endl;

file_out_sem.close();
//------------------------------------------------------------------------------------------------------------------------
file_out_parametri.open ("parametri_ps.txt", ofstream::out | ios_base::ate);

	//controllo paertura file
	if (file_out_parametri.fail()){
	cout << "Errore nell'apertura del file di output" << endl; 
	}
	
	file_out_parametri << "Media aritmetica" << endl;
	file_out_parametri << "(totale misure = " << numero_misure_fatte << ")" << endl << endl;
	file_out_parametri << "SE" << endl;
	file_out_parametri << "( il parametro 1/(N-1) = " << parametro_se_1 << ")" << endl;
	file_out_parametri << "( somma scarti quadrati = " << somma_scarti_quadrati << ")" << endl;
	file_out_parametri << "( radicando se = " << radicando_se << ")" << endl << endl;


file_out_parametri.close();
//-----------------------------------------------------------------------------------------------------------------------

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
CALCOLO MEDIA SE SEM PER PERIODO TRIPLO
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

// variabili per la parte che calcola la somma e la media aritmetica
     numero_misure_while = 0;
     numero_misure_fatte = 0;
     somma_misure = 0; 
     valore_misura = 0;
     media_aritmetica = 0;
    
// variabili per la parte che calcola SE e SEM
     parametro_se_1 = 0;
     parametro_se_1_1 = 0; //non conosco che ordine delle operazione segue 
     numero_misure_while_se = 0;
     valore_misura_se = 0;
     scarto_quadrato = 0;
     scarto_quadrato_2 = 0; // variabile per ordine delle operazioni
     somma_scarti_quadrati = 0;
     radicando_se = 0; // variabile per ordine delle operazioni
     se = 0;
     sem = 0;
     radice_numero_misure_fatte = 0;

//variabili stringhe e per conversione da stringa a variabile
     valore_misura_str = "";
     valore_misura_str_2 = "";
  
//apertura del file di input
/*ifstream file_in; 		//"NOME_FILE:ESTENSIONE"
ofstream file_out_media; 	//"NOME_FILE.ESTENSIONE"
ofstream file_out_se;		//"NOME_FILE.ESTENSIONE"
ofstream file_out_sem;		//"NOME_FILE.ESTENSIONE"
ofstream file_out_parametri;*/	//"NOME_FILE.ESTENSIONE"


//apertura del file in lettura
file_in.open ("dati_input_pt.txt");

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
			exit (1);
			return 1;
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
	file_in.open ("dati_input_pt.txt");

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

//scrittura su file di output per SE e SEM e media

file_out_media.open ("media_aritmetica_pt.txt", ofstream::out | ios_base::ate);

	//controllo paertura file
	if (file_out_media.fail()){
	cout << "Errore nell'apertura del file di output" << endl; 
	}

	file_out_media << media_aritmetica << endl;

file_out_media.close();
//------------------------------------------------------------------------------------------------------------------------
file_out_se.open ("se_pt.txt", ofstream::out | ios_base::ate);

	//controllo paertura file
	if (file_out_se.fail()){
	cout << "Errore nell'apertura del file di output" << endl; 
	}

	file_out_se << se << endl;

file_out_se.close();
//------------------------------------------------------------------------------------------------------------------------
file_out_sem.open ("sem_pt.txt", ofstream::out | ios_base::ate);

	//controllo paertura file
	if (file_out_sem.fail()){
	cout << "Errore nell'apertura del file di output" << endl; 
	}

	file_out_sem << sem << endl;

file_out_sem.close();
//------------------------------------------------------------------------------------------------------------------------
file_out_parametri.open ("parametri_pt.txt", ofstream::out | ios_base::ate);

	//controllo paertura file
	if (file_out_parametri.fail()){
	cout << "Errore nell'apertura del file di output" << endl; 
	}
	
	file_out_parametri << "Media aritmetica" << endl;
	file_out_parametri << "(totale misure = " << numero_misure_fatte << ")" << endl << endl;
	file_out_parametri << "SE" << endl;
	file_out_parametri << "( il parametro 1/(N-1) = " << parametro_se_1 << ")" << endl;
	file_out_parametri << "( somma scarti quadrati = " << somma_scarti_quadrati << ")" << endl;
	file_out_parametri << "( radicando se = " << radicando_se << ")" << endl << endl;


file_out_parametri.close();
//-----------------------------------------------------------------------------------------------------------------------

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
CALCOLO MEDIA SE SEM PER PERIODO SINGOLO LUNGHEZZA MEZZA
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

// variabili per la parte che calcola la somma e la media aritmetica
     numero_misure_while = 0;
     numero_misure_fatte = 0;
     somma_misure = 0; 
     valore_misura = 0;
     media_aritmetica = 0;
    
// variabili per la parte che calcola SE e SEM
     parametro_se_1 = 0;
     parametro_se_1_1 = 0; //non conosco che ordine delle operazione segue 
     numero_misure_while_se = 0;
     valore_misura_se = 0;
     scarto_quadrato = 0;
     scarto_quadrato_2 = 0; // variabile per ordine delle operazioni
     somma_scarti_quadrati = 0;
     radicando_se = 0; // variabile per ordine delle operazioni
     se = 0;
     sem = 0;
     radice_numero_misure_fatte = 0;

//variabili stringhe e per conversione da stringa a variabile
     valore_misura_str = "";
     valore_misura_str_2 = "";

//apertura del file di input
/*ifstream file_in; 		//"NOME_FILE:ESTENSIONE"
ofstream file_out_media; 	//"NOME_FILE.ESTENSIONE"
ofstream file_out_se;		//"NOME_FILE.ESTENSIONE"
ofstream file_out_sem;		//"NOME_FILE.ESTENSIONE"
ofstream file_out_parametri;*/	//"NOME_FILE.ESTENSIONE"


//apertura del file in lettura
file_in.open ("dati_input_pl2.txt");

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
			exit (1);
			return 1;
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
	file_in.open ("dati_input_pl2.txt");

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

//scrittura su file di output per SE e SEM e media

file_out_media.open ("media_aritmetica_pl2.txt", ofstream::out | ios_base::ate);

	//controllo paertura file
	if (file_out_media.fail()){
	cout << "Errore nell'apertura del file di output" << endl; 
	}

	file_out_media << media_aritmetica << endl;

file_out_media.close();
//------------------------------------------------------------------------------------------------------------------------
file_out_se.open ("se_pl2.txt", ofstream::out | ios_base::ate);

	//controllo paertura file
	if (file_out_se.fail()){
	cout << "Errore nell'apertura del file di output" << endl; 
	}

	file_out_se << se << endl;

file_out_se.close();
//------------------------------------------------------------------------------------------------------------------------
file_out_sem.open ("sem_pl2.txt", ofstream::out | ios_base::ate);

	//controllo paertura file
	if (file_out_sem.fail()){
	cout << "Errore nell'apertura del file di output" << endl; 
	}

	file_out_sem << sem << endl;

file_out_sem.close();
//------------------------------------------------------------------------------------------------------------------------
file_out_parametri.open ("parametri_pl2.txt", ofstream::out | ios_base::ate);

	//controllo paertura file
	if (file_out_parametri.fail()){
	cout << "Errore nell'apertura del file di output" << endl; 
	}
	
	file_out_parametri << "Media aritmetica" << endl;
	file_out_parametri << "(totale misure = " << numero_misure_fatte << ")" << endl << endl;
	file_out_parametri << "SE" << endl;
	file_out_parametri << "( il parametro 1/(N-1) = " << parametro_se_1 << ")" << endl;
	file_out_parametri << "( somma scarti quadrati = " << somma_scarti_quadrati << ")" << endl;
	file_out_parametri << "( radicando se = " << radicando_se << ")" << endl << endl;


file_out_parametri.close();
//-----------------------------------------------------------------------------------------------------------------------


/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
CONFRONTO 3 SIGMA PERIODO SINGOLO
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//variabili

double sigma = 0;
double sigma_3 = 0;
double valore_in_lettura = 0;
double ciclo_while_in_lettura = 0;

ifstream file_in_sigma;
ifstream file_in_misure_ps;
ofstream file_out_confronto_3_sigma;

string sigma_str = "";
string valore_in_lettura_str = "";

//inserimento del valore sigma

	file_in_sigma.open ("se_ps.txt");

	//controllo se il file è stato aperto correttamente
	if (file_in_sigma.fail()){
	cout << "Errore nell'apertura del file di input" << endl;
	}

	getline(file_in_sigma, sigma_str);
	
	//ciclo per trovare gli errori e far andare avanti il ciclo
	try {
	//trasforma la stringa in una variabile numerica
	sigma = stod(sigma_str);
	}
	catch (invalid_argument){
	cout << "Errore nella lettura" << endl;
	}

//calcolo di 3 sigma

	sigma_3 = 3 * sigma;
	
//cout controllo

	cout << "3sigma   " << sigma_3 << endl;
	
//confronto misure con tre sigma

	//apertura del file in lettura
	file_in_misure_ps.open ("dati_input_ps.txt");

	//controllo se il file è stato aperto correttamente
	if (file_in_misure_ps.fail()){
	cout << "Errore nell'apertura del file di input" << endl;
	}

	file_out_confronto_3_sigma.open ("confronto_3_sigma_ps.txt");

	//ciclo di lettura delle misure 

		while (!file_in_misure_ps.eof()) {
		
			getline(file_in_misure_ps, valore_in_lettura_str, ',');
	
			//ciclo per trovare gli errori e far andare avanti il ciclo
			try {
			//trasforma la stringa in una variabile numerica
			valore_in_lettura = stod(valore_in_lettura_str);
			
			//cout di controllo
			cout << "valore della misura in lettura   " << valore_in_lettura << endl;
			   }		
			catch (invalid_argument) {
			cout << "Impossibile leggere la misura" << endl;
			   }
			  
			ciclo_while_in_lettura = ciclo_while_in_lettura + 1;  
			  
			if (valore_in_lettura > sigma_3){
			
			  file_out_confronto_3_sigma << ciclo_while_in_lettura << "\t" << valore_in_lettura << endl;
			}	
		}	

	file_out_confronto_3_sigma.close();
	
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
CONFRONTO 3 SIGMA PERIODO TRIPLO
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/	
	
//variabili

 sigma = 0;
 sigma_3 = 0;
 valore_in_lettura = 0;
 ciclo_while_in_lettura = 0;

//ifstream file_in_sigma;
ifstream file_in_misure_pt;
//ofstream file_out_confronto_3_sigma;

 sigma_str = "";
 valore_in_lettura_str = "";

//inserimento del valore sigma

	file_in_sigma.open ("se_pt.txt");

	//controllo se il file è stato aperto correttamente
	if (file_in_sigma.fail()){
	cout << "Errore nell'apertura del file di input" << endl;
	}

	getline(file_in_sigma, sigma_str);
	
	//ciclo per trovare gli errori e far andare avanti il ciclo
	try {
	//trasforma la stringa in una variabile numerica
	sigma = stod(sigma_str);
	}
	catch (invalid_argument){
	cout << "Errore nella lettura" << endl;
	}

//calcolo di 3 sigma

	sigma_3 = 3 * sigma;
	
//cout controllo

	cout << "3sigma   " << sigma_3 << endl;
	
//confronto misure con tre sigma

	//apertura del file in lettura
	file_in_misure_pt.open ("dati_input_pt.txt");

	//controllo se il file è stato aperto correttamente
	if (file_in_misure_pt.fail()){
	cout << "Errore nell'apertura del file di input" << endl;
	}

	file_out_confronto_3_sigma.open ("confronto_3_sigma_pt.txt");

	//ciclo di lettura delle misure 

		while (!file_in_misure_pt.eof()) {
		
			getline(file_in_misure_pt, valore_in_lettura_str, ',');
	
			//ciclo per trovare gli errori e far andare avanti il ciclo
			try {
			//trasforma la stringa in una variabile numerica
			valore_in_lettura = stod(valore_in_lettura_str);
			
			//cout di controllo
			cout << "valore della misura in lettura   " << valore_in_lettura << endl;
			   }		
			catch (invalid_argument) {
			cout << "Impossibile leggere la misura" << endl;
			   }
			  
			ciclo_while_in_lettura = ciclo_while_in_lettura + 1;  
			  
			if (valore_in_lettura > sigma_3){
			
			  file_out_confronto_3_sigma << ciclo_while_in_lettura << "\t" << valore_in_lettura << endl;
			}	
		}	

	file_out_confronto_3_sigma.close();	
	
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
CONFRONTO 3 SIGMA PERIODO SINGOLO LUNGHEZZA MEZZA
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/	
	
//variabili

 sigma = 0;
 sigma_3 = 0;
 valore_in_lettura = 0;
 ciclo_while_in_lettura = 0;

//ifstream file_in_sigma;
ifstream file_in_misure_pl2;
//ofstream file_out_confronto_3_sigma;

 sigma_str = "";
 valore_in_lettura_str = "";

//inserimento del valore sigma

	file_in_sigma.open ("se_pl2.txt");

	//controllo se il file è stato aperto correttamente
	if (file_in_sigma.fail()){
	cout << "Errore nell'apertura del file di input" << endl;
	}

	getline(file_in_sigma, sigma_str);
	
	//ciclo per trovare gli errori e far andare avanti il ciclo
	try {
	//trasforma la stringa in una variabile numerica
	sigma = stod(sigma_str);
	}
	catch (invalid_argument){
	cout << "Errore nella lettura" << endl;
	}

//calcolo di 3 sigma

	sigma_3 = 3 * sigma;
	
//cout controllo

	cout << "3sigma   " << sigma_3 << endl;
	
//confronto misure con tre sigma

	//apertura del file in lettura
	file_in_misure_pl2.open ("dati_input_pl2.txt");

	//controllo se il file è stato aperto correttamente
	if (file_in_misure_pl2.fail()){
	cout << "Errore nell'apertura del file di input" << endl;
	}

	file_out_confronto_3_sigma.open ("confronto_3_sigma_pl2.txt");

	//ciclo di lettura delle misure 

		while (!file_in_misure_pl2.eof()) {
		
			getline(file_in_misure_pl2, valore_in_lettura_str, ',');
	
			//ciclo per trovare gli errori e far andare avanti il ciclo
			try {
			//trasforma la stringa in una variabile numerica
			valore_in_lettura = stod(valore_in_lettura_str);
			
			//cout di controllo
			cout << "valore della misura in lettura   " << valore_in_lettura << endl;
			   }		
			catch (invalid_argument) {
			cout << "Impossibile leggere la misura" << endl;
			   }
			  
			ciclo_while_in_lettura = ciclo_while_in_lettura + 1;  
			  
			if (valore_in_lettura > sigma_3){
			
			  file_out_confronto_3_sigma << ciclo_while_in_lettura << "\t" << valore_in_lettura << endl;
			}	
		}	

	file_out_confronto_3_sigma.close();
	
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
STIMA g PERIODO SINGOLO 
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/		

//variabili numeriche

    double pi_greco = M_PI;
    double lunghezza = 0;
    double periodo = 0;
    double periodo_2 = 0;
    double g_stima = 0;
    double parametro_pi = 0;
    double parametro_pi_2 = 0;
    double parametro_lt = 0;

//variabili tipo stringa
    string periodo_str = "";
    
//dichiarazione file in e out
    ifstream file_in_g_ps;
    ofstream file_out;
    //ofstream file_out_parametri;
    ofstream file_out_l;

//inserzione parametri per il calcolo

	cout << "Inserire la lunghezza l del pendolo in metri" << endl;
	cin >> lunghezza;
	cout << endl;
	
//apertura file in lettura	
	file_in_g_ps.open ("media_aritmetica_ps.txt");
	
	//controllo apertura file
	if (file_in_g_ps.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	getline (file_in_g_ps, periodo_str);
	try {
	periodo = stod(periodo_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}

	file_in_g_ps.close();

//esecuzione operazioni

	periodo_2 = pow(periodo,2);
	parametro_pi = 2 * pi_greco;
	parametro_pi_2 = pow(parametro_pi,2);
	parametro_lt = lunghezza / periodo_2;
	g_stima = parametro_pi_2 * parametro_lt;
	
//output di controllo
	cout << "La stima di g è   " << g_stima << endl;

//output file

	file_out.open ("g_stima_ps.txt");
	
	//controllo apertura file
	if (file_out.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	file_out << g_stima;
	
	file_out.close ();	
	
//----------------------------------------------------------------------------------

	file_out_parametri.open ("g_stima_ps_parametri.txt");	
	
	//controllo apertura file
	if (file_out_parametri.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	file_out_parametri << "Quadrato del periodo" << endl;
	file_out_parametri << periodo_2 << endl << endl;
	file_out_parametri << "Parametro 2pi" << endl;
	file_out_parametri << parametro_pi << endl << endl;
	file_out_parametri << "Parametro 2pi quadrato" << endl;
	file_out_parametri << parametro_pi_2 << endl << endl;
	file_out_parametri << "Parametro lunghezza / periodo^2" << endl;
	file_out_parametri << parametro_lt << endl << endl;
	file_out_parametri << "Verifica di pi greco" << endl;
	file_out_parametri << pi_greco << endl << endl;
	
	file_out_parametri.close();
	
//---------------------------------------------------------------------------------	
	
	file_out_l.open ("lunghezza.txt");
	
	//controllo apertura file
	if (file_out_l.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	file_out_l << lunghezza;
	
	file_out_l.close ();
	
//---------------------------------------------------------------------------------	

/*
---------------------------------------------------------------------------------------
STIMA INCRTEZZA SU g
---------------------------------------------------------------------------------------
*/
    double incertezza_g = 0;
    //la variabile g è stata definita sopra nel codice come    g_stima
    
//--incertezza su l
    double incertezza_l = 0;
      //la variabile l è stata definita precedentemente nel codice come   lunghezza	
      
    double risoluzione_l = 0.001; //espressa in metri -> equivale ad 1 millimetro
    double risoluzione_diviso_2 = risoluzione_l / 2;
    double radice_quadrata_di6 = sqrt(6);
    		
	//calcolo incertezza di l
    	incertezza_l = risoluzione_diviso_2 / radice_quadrata_di6;
    		
//--incertezza periodo
    double incertezza_periodo = 0;
    // la variabilr periodo è stata definita precedentemente nel codice come     periodo
	
    //input dell'incertezza del periodio
    
    ifstream file_in_incertezza_periodo;
    string valore_incertezza_periodo_str = "";
	
    	file_in_incertezza_periodo.open ("sem_ps.txt");
    	
    		//controllo paertura file
		if (file_in_incertezza_periodo.fail()){
		cout << "Errore nell'apertura del file di output" << endl; 
		}

	getline (file_in_incertezza_periodo, valore_incertezza_periodo_str);
	
	try {
	incertezza_periodo = stod(valore_incertezza_periodo_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}
	
//calcolo dell'incertezza di g

//--definizione delle variabili

	double parametro_l = 0;
	double parametro_l_quadro = 0;
	
	double sotto_parametro_t = 0;	
	double parametro_t = 0;
	double parametro_t_quadro = 0;
	
	double radicando_incertezza_g = 0;
	double radice_incertezza_g = 0;
	
	parametro_l = incertezza_l / lunghezza;
	parametro_l_quadro = pow(parametro_l,2);
	
	sotto_parametro_t = incertezza_periodo / periodo;
	parametro_t = 2 * sotto_parametro_t;
	parametro_t_quadro = pow(parametro_t,2);

	radicando_incertezza_g = parametro_l_quadro + parametro_t_quadro;
	radice_incertezza_g = sqrt (radicando_incertezza_g);
	
//--calcolo incertezza su g

	incertezza_g = g_stima * radice_incertezza_g;


//file di output

//--definizione variabili	
	ofstream file_out_incertezza_l;
	ofstream file_out_incertezza_g;
	ofstream file_out_incertezza_g_parametri;
//-----------------------------------------------------------------------------------------------------------	
	file_out_incertezza_l.open("incertezza_lunghezza.txt");
		
		//controllo paertura file
		if (file_out_incertezza_l.fail()){
		cout << "Errore nell'apertura del file di output" << endl; 
		}
		
		file_out_incertezza_l << incertezza_l;
		
	file_out_incertezza_l.close();		
//-----------------------------------------------------------------------------------------------------------	
	file_out_incertezza_g.open("incertezza_g_ps.txt");
		
		//controllo paertura file
		if (file_out_incertezza_g.fail()){
		cout << "Errore nell'apertura del file di output" << endl; 
		}
		
		file_out_incertezza_g << incertezza_g;
		
	file_out_incertezza_g.close();
//------------------------------------------------------------------------------------------------------------
	file_out_incertezza_g_parametri.open("g_incertezza_ps_parametri.txt");
		
		//controllo paertura file
		if (file_out_incertezza_g_parametri.fail()){
		cout << "Errore nell'apertura del file di output" << endl; 
		}
		
		file_out_incertezza_g_parametri << "LUNGHEZZA" << endl;
		file_out_incertezza_g_parametri << "rislozione di l" << endl;
		file_out_incertezza_g_parametri << risoluzione_l << endl;
		file_out_incertezza_g_parametri << "risoluzione diviso 2" << endl;
		file_out_incertezza_g_parametri << risoluzione_diviso_2 << endl;
		file_out_incertezza_g_parametri << "valore della radice quadrata di 6" << endl;
		file_out_incertezza_g_parametri << radice_quadrata_di6 << endl << endl;
		file_out_incertezza_g_parametri << "VERIFICA CORRETTA ACCUISIZIONE DELL'INCERTEZZA SUL PERIODO" << endl;
		file_out_incertezza_g_parametri << incertezza_periodo << endl << endl;
		file_out_incertezza_g_parametri << "PARAMETRI NEL CALCOLO DELL'INGERTEZZA DI g" << endl;
		file_out_incertezza_g_parametri << "parametro incertezza di l diviso l" << endl;
		file_out_incertezza_g_parametri << parametro_l << endl;
		file_out_incertezza_g_parametri << "quadrato del numero sopra" << endl;
		file_out_incertezza_g_parametri << parametro_l_quadro << endl;
		file_out_incertezza_g_parametri << "valore incertezza periodo diviso il periodo" << endl;
		file_out_incertezza_g_parametri << sotto_parametro_t << endl;
		file_out_incertezza_g_parametri << "il numero sopra moltiplicato per 2" << endl;
		file_out_incertezza_g_parametri << parametro_t << endl;
		file_out_incertezza_g_parametri << "il numero sopra al quadrato" << endl;
		file_out_incertezza_g_parametri << parametro_t_quadro << endl;
		file_out_incertezza_g_parametri << "valore del radicando" << endl;
		file_out_incertezza_g_parametri << radicando_incertezza_g << endl;
		file_out_incertezza_g_parametri << "valore della radice quadrata del radicando" << endl;
		file_out_incertezza_g_parametri << radice_incertezza_g << endl;
		
	file_out_incertezza_g_parametri.close();
//------------------------------------------------------------------------------------------------------------

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
STIMA g PERIODO TRIPLO 
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/	

//variabili numeriche

     pi_greco = M_PI;
     lunghezza = 0;
     periodo = 0;
     periodo_2 = 0;
     g_stima = 0;
     parametro_pi = 0;
     parametro_pi_2 = 0;
     parametro_lt = 0;
    
     double periodo_3 = 0;

//variabili tipo stringa
     periodo_str = "";
    
//dichiarazione file in e out
    ifstream file_in_g_pt;
/*    ofstream file_out;
    ofstream file_out_parametri;
    ofstream file_out_l;*/

//inserzione parametri per il calcolo

	cout << "Inserire la lunghezza l del pendolo in metri" << endl;
	cin >> lunghezza;
	cout << endl;
	
//apertura file in lettura	
	file_in_g_pt.open ("media_aritmetica_pt.txt");
	
	//controllo apertura file
	if (file_in_g_pt.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	getline (file_in_g_pt, periodo_str);
	try {
	periodo_3 = stod(periodo_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}

	file_in_g_pt.close();

//esecuzione operazioni

	periodo = periodo_3 / 3;

	periodo_2 = pow(periodo,2);
	parametro_pi = 2 * pi_greco;
	parametro_pi_2 = pow(parametro_pi,2);
	parametro_lt = lunghezza / periodo_2;
	g_stima = parametro_pi_2 * parametro_lt;
	
//output di controllo
	cout << "La stima di g è   " << g_stima << endl;

//output file

	file_out.open ("g_stima_pt.txt");
	
	//controllo apertura file
	if (file_out.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	file_out << g_stima;
	
	file_out.close ();	
	
//----------------------------------------------------------------------------------

	file_out_parametri.open ("g_stima_pt_parametri.txt");	
	
	//controllo apertura file
	if (file_out_parametri.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	file_out_parametri << "Quadrato del periodo" << endl;
	file_out_parametri << periodo_2 << endl << endl;
	file_out_parametri << "Parametro 2pi" << endl;
	file_out_parametri << parametro_pi << endl << endl;
	file_out_parametri << "Parametro 2pi quadrato" << endl;
	file_out_parametri << parametro_pi_2 << endl << endl;
	file_out_parametri << "Parametro lunghezza / periodo^2" << endl;
	file_out_parametri << parametro_lt << endl << endl;
	file_out_parametri << "Verifica di pi greco" << endl;
	file_out_parametri << pi_greco << endl << endl;
	
	file_out_parametri.close();
	
//---------------------------------------------------------------------------------	
	
	file_out_l.open ("lunghezza.txt");
	
	//controllo apertura file
	if (file_out_l.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	file_out_l << lunghezza;
	
	file_out_l.close ();
	
//---------------------------------------------------------------------------------	


cout << "Non posso calcolare l'incertezza su g con il periodo triplo" << endl;

/*

AL MOMENTO NON CALCOLABILE CON QUESTO METORO


//---------------------------------------------------------------------------------------
//STIMA INCRTEZZA SU g
//---------------------------------------------------------------------------------------

     incertezza_g = 0;
    //la variabile g è stata definita sopra nel codice come    g_stima
    
//--incertezza su l
    double incertezza_l = 0;
      //la variabile l è stata definita precedentemente nel codice come   lunghezza	
      
     risoluzione_l = 0.001; //espressa in metri -> equivale ad 1 millimetro
     risoluzione_diviso_2 = risoluzione_l / 2;
     radice_quadrata_di6 = sqrt(6);
    		
	//calcolo incertezza di l
    	incertezza_l = risoluzione_diviso_2 / radice_quadrata_di6;
    		
//--incertezza periodo
    double incertezza_periodo = 0;
    // la variabilr periodo è stata definita precedentemente nel codice come     periodo
	
    //input dell'incertezza del periodio
    
//    ifstream file_in_incertezza_periodo;
    string valore_incertezza_periodo_str = "";
	
    	file_in_incertezza_periodo.open ("sem_pt.txt");
    	
    		//controllo paertura file
		if (file_in_incertezza_periodo.fail()){
		cout << "Errore nell'apertura del file di output" << endl; 
		}

	getline (file_in_incertezza_periodo, valore_incertezza_periodo_str);
	
	try {
	incertezza_periodo = stod(valore_incertezza_periodo_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}
	
//calcolo dell'incertezza di g

//--definizione delle variabili

	double parametro_l = 0;
	double parametro_l_quadro = 0;
	
	double sotto_parametro_t = 0;	
	double parametro_t = 0;
	double parametro_t_quadro = 0;
	
	double radicando_incertezza_g = 0;
	double radice_incertezza_g = 0;
	
	parametro_l = incertezza_l / lunghezza;
	parametro_l_quadro = pow(parametro_l,2);
	
	sotto_parametro_t = incertezza_periodo / periodo;
	parametro_t = 2 * sotto_parametro_t;
	parametro_t_quadro = pow(parametro_t,2);

	radicando_incertezza_g = parametro_l_quadro + parametro_t_quadro;
	radice_incertezza_g = sqrt (radicando_incertezza_g);
	
//--calcolo incertezza su g

	incertezza_g = g_stima * radice_incertezza_g;


//file di output

//--definizione variabili	
	ofstream file_out_incertezza_l;
	ofstream file_out_incertezza_g;
	ofstream file_out_incertezza_g_parametri;
//-----------------------------------------------------------------------------------------------------------	
	file_out_incertezza_l.open("incertezza_lunghezza.txt");
		
		//controllo paertura file
		if (file_out_incertezza_l.fail()){
		cout << "Errore nell'apertura del file di output" << endl; 
		}
		
		file_out_incertezza_l << incertezza_l;
		
	file_out_incertezza_l.close();		
//-----------------------------------------------------------------------------------------------------------	
	file_out_incertezza_g.open("incertezza_g_pt.txt");
		
		//controllo paertura file
		if (file_out_incertezza_g.fail()){
		cout << "Errore nell'apertura del file di output" << endl; 
		}
		
		file_out_incertezza_g << incertezza_g;
		
	file_out_incertezza_g.close();
//------------------------------------------------------------------------------------------------------------
	file_out_incertezza_g_parametri.open("g_incertezza_pt_parametri.txt");
		
		//controllo paertura file
		if (file_out_incertezza_g_parametri.fail()){
		cout << "Errore nell'apertura del file di output" << endl; 
		}
		
		file_out_incertezza_g_parametri << "LUNGHEZZA" << endl;
		file_out_incertezza_g_parametri << "rislozione di l" << endl;
		file_out_incertezza_g_parametri << risoluzione_l << endl;
		file_out_incertezza_g_parametri << "risoluzione diviso 2" << endl;
		file_out_incertezza_g_parametri << risoluzione_diviso_2 << endl;
		file_out_incertezza_g_parametri << "valore della radice quadrata di 6" << endl;
		file_out_incertezza_g_parametri << radice_quadrata_di6 << endl << endl;
		file_out_incertezza_g_parametri << "VERIFICA CORRETTA ACCUISIZIONE DELL'INCERTEZZA SUL PERIODO" << endl;
		file_out_incertezza_g_parametri << incertezza_periodo << endl << endl;
		file_out_incertezza_g_parametri << "PARAMETRI NEL CALCOLO DELL'INGERTEZZA DI g" << endl;
		file_out_incertezza_g_parametri << "parametro incertezza di l diviso l" << endl;
		file_out_incertezza_g_parametri << parametro_l << endl;
		file_out_incertezza_g_parametri << "quadrato del numero sopra" << endl;
		file_out_incertezza_g_parametri << parametro_l_quadro << endl;
		file_out_incertezza_g_parametri << "valore incertezza periodo diviso il periodo" << endl;
		file_out_incertezza_g_parametri << sotto_parametro_t << endl;
		file_out_incertezza_g_parametri << "il numero sopra moltiplicato per 2" << endl;
		file_out_incertezza_g_parametri << parametro_t << endl;
		file_out_incertezza_g_parametri << "il numero sopra al quadrato" << endl;
		file_out_incertezza_g_parametri << parametro_t_quadro << endl;
		file_out_incertezza_g_parametri << "valore del radicando" << endl;
		file_out_incertezza_g_parametri << radicando_incertezza_g << endl;
		file_out_incertezza_g_parametri << "valore della radice quadrata del radicando" << endl;
		file_out_incertezza_g_parametri << radice_incertezza_g << endl;
		
	file_out_incertezza_g_parametri.close();
//------------------------------------------------------------------------------------------------------------

-------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
STIMA g PERIODO SINGOLO LUNGHEZZA MEZZA 
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/	
	
//variabili numeriche

     pi_greco = M_PI;
     lunghezza = 0;
     periodo = 0;
     periodo_2 = 0;
     g_stima = 0;
     parametro_pi = 0;
     parametro_pi_2 = 0;
     parametro_lt = 0;

//variabili tipo stringa
     periodo_str = "";
    
//dichiarazione file in e out
    ifstream file_in_g_pl2;
/*    ofstream file_out;
    ofstream file_out_parametri;
    ofstream file_out_l;*/

//inserzione parametri per il calcolo

	cout << "Inserire la lunghezza l/2 del pendolo in metri" << endl;
	cin >> lunghezza;
	cout << endl;
	
//apertura file in lettura	
	file_in_g_pl2.open ("media_aritmetica_pl2.txt");
	
	//controllo apertura file
	if (file_in_g_pl2.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	getline (file_in_g_pl2, periodo_str);
	try {
	periodo = stod(periodo_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}

	file_in_g_pl2.close();

//esecuzione operazioni

	periodo_2 = pow(periodo,2);
	parametro_pi = 2 * pi_greco;
	parametro_pi_2 = pow(parametro_pi,2);
	parametro_lt = lunghezza / periodo_2;
	g_stima = parametro_pi_2 * parametro_lt;
	
//output di controllo
	cout << "La stima di g è   " << g_stima << endl;

//output file

	file_out.open ("g_stima_pl2.txt");
	
	//controllo apertura file
	if (file_out.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	file_out << g_stima;
	
	file_out.close ();	
	
//----------------------------------------------------------------------------------

	file_out_parametri.open ("g_stima_pl2_parametri.txt");	
	
	//controllo apertura file
	if (file_out_parametri.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	file_out_parametri << "Quadrato del periodo" << endl;
	file_out_parametri << periodo_2 << endl << endl;
	file_out_parametri << "Parametro 2pi" << endl;
	file_out_parametri << parametro_pi << endl << endl;
	file_out_parametri << "Parametro 2pi quadrato" << endl;
	file_out_parametri << parametro_pi_2 << endl << endl;
	file_out_parametri << "Parametro lunghezza / periodo^2" << endl;
	file_out_parametri << parametro_lt << endl << endl;
	file_out_parametri << "Verifica di pi greco" << endl;
	file_out_parametri << pi_greco << endl << endl;
	
	file_out_parametri.close();
	
//---------------------------------------------------------------------------------	
	
	file_out_l.open ("lunghezza_pl2.txt");
	
	//controllo apertura file
	if (file_out_l.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	file_out_l << lunghezza;
	
	file_out_l.close ();
	
//---------------------------------------------------------------------------------	

/*
---------------------------------------------------------------------------------------
STIMA INCRTEZZA SU g
---------------------------------------------------------------------------------------
*/
     incertezza_g = 0;
    //la variabile g è stata definita sopra nel codice come    g_stima
    
//--incertezza su l
     incertezza_l = 0;
      //la variabile l è stata definita precedentemente nel codice come   lunghezza	
      
     risoluzione_l = 0.001; //espressa in metri -> equivale ad 1 millimetro
     risoluzione_diviso_2 = risoluzione_l / 2;
     radice_quadrata_di6 = sqrt(6);
    		
	//calcolo incertezza di l
    	incertezza_l = risoluzione_diviso_2 / radice_quadrata_di6;
    		
//--incertezza periodo
     incertezza_periodo = 0;
    // la variabilr periodo è stata definita precedentemente nel codice come     periodo
	
    //input dell'incertezza del periodio
    
 //   ifstream file_in_incertezza_periodo;
     valore_incertezza_periodo_str = "";
	
    	file_in_incertezza_periodo.open ("sem_pl2.txt");
    	
    		//controllo paertura file
		if (file_in_incertezza_periodo.fail()){
		cout << "Errore nell'apertura del file di output" << endl; 
		}

	getline (file_in_incertezza_periodo, valore_incertezza_periodo_str);
	
	try {
	incertezza_periodo = stod(valore_incertezza_periodo_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}
	
//calcolo dell'incertezza di g

//--definizione delle variabili

	 parametro_l = 0;
	 parametro_l_quadro = 0;
	
	 sotto_parametro_t = 0;	
	 parametro_t = 0;
	 parametro_t_quadro = 0;
	
	 radicando_incertezza_g = 0;
	 radice_incertezza_g = 0;
	
	parametro_l = incertezza_l / lunghezza;
	parametro_l_quadro = pow(parametro_l,2);
	
	sotto_parametro_t = incertezza_periodo / periodo;
	parametro_t = 2 * sotto_parametro_t;
	parametro_t_quadro = pow(parametro_t,2);

	radicando_incertezza_g = parametro_l_quadro + parametro_t_quadro;
	radice_incertezza_g = sqrt (radicando_incertezza_g);
	
//--calcolo incertezza su g

	incertezza_g = g_stima * radice_incertezza_g;


//file di output

//--definizione variabili	
/*	ofstream file_out_incertezza_l;
	ofstream file_out_incertezza_g;
	ofstream file_out_incertezza_g_parametri;*/
//-----------------------------------------------------------------------------------------------------------	
	file_out_incertezza_l.open("incertezza_lunghezza_pl2.txt");
		
		//controllo paertura file
		if (file_out_incertezza_l.fail()){
		cout << "Errore nell'apertura del file di output" << endl; 
		}
		
		file_out_incertezza_l << incertezza_l;
		
	file_out_incertezza_l.close();		
//-----------------------------------------------------------------------------------------------------------	
	file_out_incertezza_g.open("incertezza_g_pl2.txt");
		
		//controllo paertura file
		if (file_out_incertezza_g.fail()){
		cout << "Errore nell'apertura del file di output" << endl; 
		}
		
		file_out_incertezza_g << incertezza_g;
		
	file_out_incertezza_g.close();
//------------------------------------------------------------------------------------------------------------
	file_out_incertezza_g_parametri.open("g_incertezza_pl2_parametri.txt");
		
		//controllo paertura file
		if (file_out_incertezza_g_parametri.fail()){
		cout << "Errore nell'apertura del file di output" << endl; 
		}
		
		file_out_incertezza_g_parametri << "LUNGHEZZA" << endl;
		file_out_incertezza_g_parametri << "rislozione di l" << endl;
		file_out_incertezza_g_parametri << risoluzione_l << endl;
		file_out_incertezza_g_parametri << "risoluzione diviso 2" << endl;
		file_out_incertezza_g_parametri << risoluzione_diviso_2 << endl;
		file_out_incertezza_g_parametri << "valore della radice quadrata di 6" << endl;
		file_out_incertezza_g_parametri << radice_quadrata_di6 << endl << endl;
		file_out_incertezza_g_parametri << "VERIFICA CORRETTA ACCUISIZIONE DELL'INCERTEZZA SUL PERIODO" << endl;
		file_out_incertezza_g_parametri << incertezza_periodo << endl << endl;
		file_out_incertezza_g_parametri << "PARAMETRI NEL CALCOLO DELL'INGERTEZZA DI g" << endl;
		file_out_incertezza_g_parametri << "parametro incertezza di l diviso l" << endl;
		file_out_incertezza_g_parametri << parametro_l << endl;
		file_out_incertezza_g_parametri << "quadrato del numero sopra" << endl;
		file_out_incertezza_g_parametri << parametro_l_quadro << endl;
		file_out_incertezza_g_parametri << "valore incertezza periodo diviso il periodo" << endl;
		file_out_incertezza_g_parametri << sotto_parametro_t << endl;
		file_out_incertezza_g_parametri << "il numero sopra moltiplicato per 2" << endl;
		file_out_incertezza_g_parametri << parametro_t << endl;
		file_out_incertezza_g_parametri << "il numero sopra al quadrato" << endl;
		file_out_incertezza_g_parametri << parametro_t_quadro << endl;
		file_out_incertezza_g_parametri << "valore del radicando" << endl;
		file_out_incertezza_g_parametri << radicando_incertezza_g << endl;
		file_out_incertezza_g_parametri << "valore della radice quadrata del radicando" << endl;
		file_out_incertezza_g_parametri << radice_incertezza_g << endl;
		
	file_out_incertezza_g_parametri.close();
//------------------------------------------------------------------------------------------------------------	

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
STIMA CAVENDISH PERIODO SINGOLO 
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//variabili per il calcolo

long double massa_terra_parziale = 5972; // espressa in Kg
long double parziale1 = 10000000;
long double parziale2 = 10000000;
long double parziale3 = 10000000;

long double mtma = 0;
long double mtmb = 0;

long double raggio_terra = 6371000; // espresso in metri
long double raggio_terra_quadro = 0;
long double costante_cavendish_ps = 0;
long double parametro = 0;
long double g_importata_ps = 0;

long double massa_terra = 0;

//ifstream file_in_g_ps;
ofstream file_out_cavendish_ps;

string g_ps_str = "";

//importo g

file_in_g_ps.open ("g_stima_ps.txt");
	
	//controllo apertura file
	if (file_in_g_ps.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	getline (file_in_g_ps, g_ps_str);
	try {
	g_importata_ps = stod(g_ps_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}

	file_in_g_ps.close();


//calcoli


//--------------------------------------------------------------
mtma = parziale1 * parziale2;
mtmb = mtma * parziale3;

massa_terra = massa_terra_parziale * mtmb;
//--------------------------------------------------------------

raggio_terra_quadro = pow(raggio_terra,2);
parametro = raggio_terra_quadro / massa_terra;

costante_cavendish_ps = g_importata_ps * parametro;

//output file

	file_out_cavendish_ps.open ("cavendish_ps.txt");
	
	//controllo apertura file
	if (file_out_cavendish_ps.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	file_out_cavendish_ps << costante_cavendish_ps;
	
	file_out_cavendish_ps.close ();

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
STIMA CAVENDISH PERIODO TRIPLO
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//variabili per il calcolo

 massa_terra_parziale = 5972; // espressa in Kg
 parziale1 = 10000000;
 parziale2 = 10000000;
 parziale3 = 10000000;

 mtma = 0;
 mtmb = 0;

 raggio_terra = 6371000; // espresso in metri
 raggio_terra_quadro = 0;
 long double costante_cavendish_pt = 0;
 parametro = 0;
 long double g_importata_pt = 0;
 massa_terra = 0;

//ifstream file_in_g_pt;
ofstream file_out_cavendish_pt;

string g_pt_str = "";

//importo g

file_in_g_pt.open ("g_stima_pt.txt");
	
	//controllo apertura file
	if (file_in_g_pt.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	getline (file_in_g_pt, g_pt_str);
	try {
	g_importata_pt = stod(g_pt_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}

	file_in_g_pt.close();


//calcoli


//--------------------------------------------------------------
mtma = parziale1 * parziale2;
mtmb = mtma * parziale3;

massa_terra = massa_terra_parziale * mtmb;
//--------------------------------------------------------------

raggio_terra_quadro = pow(raggio_terra,2);
parametro = raggio_terra_quadro / massa_terra;

costante_cavendish_pt = g_importata_pt * parametro;

//output file

	file_out_cavendish_pt.open ("cavendish_pt.txt");
	
	//controllo apertura file
	if (file_out_cavendish_pt.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	file_out_cavendish_pt << costante_cavendish_pt;
	
	file_out_cavendish_pt.close ();

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
STIMA CAVENDISH PERIODO SINGOLO LUNGHEZZA MEZZA 
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//variabili per il calcolo

 massa_terra_parziale = 5972; // espressa in Kg
 parziale1 = 10000000;
 parziale2 = 10000000;
 parziale3 = 10000000;

 mtma = 0;
 mtmb = 0;

 raggio_terra = 6371000; // espresso in metri
 raggio_terra_quadro = 0;
 long double costante_cavendish_pl2 = 0;
 parametro = 0;
 long double g_importata_pl2 = 0;

 massa_terra = 0;

//ifstream file_in_g_pl2;
ofstream file_out_cavendish_pl2;

string g_pl2_str = "";

//importo g

file_in_g_pl2.open ("g_stima_pl2.txt");
	
	//controllo apertura file
	if (file_in_g_pl2.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	getline (file_in_g_pl2, g_pl2_str);
	try {
	g_importata_pl2 = stod(g_pl2_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}

	file_in_g_pl2.close();


//calcoli


//--------------------------------------------------------------
mtma = parziale1 * parziale2;
mtmb = mtma * parziale3;

massa_terra = massa_terra_parziale * mtmb;
//--------------------------------------------------------------

raggio_terra_quadro = pow(raggio_terra,2);
parametro = raggio_terra_quadro / massa_terra;

costante_cavendish_pl2 = g_importata_pl2 * parametro;

//output file

	file_out_cavendish_pl2.open ("cavendish_pl2.txt");
	
	//controllo apertura file
	if (file_out_cavendish_pl2.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	file_out_cavendish_pl2 << costante_cavendish_pl2;
	
	file_out_cavendish_pl2.close ();
	
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
CONFRONTO CON RIFERIMENTO PERIODO SINGOLO  
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//definizione delle variabili per g

double valore_g_importato = 0;
 incertezza_g = 0;
double riferimento_g = 9.806;
double numeratore_g = 0;
double numeratore_g_assoluto = 0;
double compatibilita_g = 0;

string g_str = "";
string incertezza_g_str = "";

ifstream file_in_g;
ifstream file_in_incertezza_g;

ofstream file_out_compatibilita_g;

//import dati

	//apertura file in lettura	
	file_in_g.open ("g_stima_ps.txt");
	
	//controllo apertura file
	if (file_in_g.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	getline (file_in_g, g_str);
	try {
	valore_g_importato = stod(g_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}

	file_in_g.close();
	
	//---------------------------------------------------
	
	//apertura file in lettura	
	file_in_incertezza_g.open ("incertezza_g_ps.txt");
	
	//controllo apertura file
	if (file_in_incertezza_g.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	getline (file_in_incertezza_g, incertezza_g_str);
	try {
	incertezza_g = stod(incertezza_g_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}

	file_in_incertezza_g.close();
	
	//---------------------------------------------------
	
//esecuzione calcoli

	numeratore_g = valore_g_importato - riferimento_g;
	numeratore_g_assoluto = abs(numeratore_g);	
	compatibilita_g = numeratore_g_assoluto / incertezza_g;

//output file

	file_out_compatibilita_g.open ("confronto_g_riferimento_ps.txt");
	
	//controllo apertura file
	if (file_out_compatibilita_g.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	file_out_compatibilita_g << compatibilita_g;
	
	file_out_compatibilita_g.close ();

cout << "Compatibilità di g =  " << compatibilita_g << endl;

/*-------------------------------------------------------------------------------------------
SEZIONE CAVENDISH
-------------------------------------------------------------------------------------------*/

//definizione delle variabili per cavendish
double moltiplicatore_cavendish = 0;
double valore_cavendish_importato = 0;
double incertezza_cavendish = 0;
double riferimento_cavendish = 0;
double numeratore_c = 0;
double numeratore_c_assoluto = 0;
double compatibilita_c = 0;

string cavendish_str = "";
string incertezza_cavendish_str = "";

ifstream file_in_cavendish;
ifstream file_in_incertezza_cavendish;

ofstream file_out_compatibilita_cavendish;

//calcoletti per cavendish

moltiplicatore_cavendish = 1/100000000000;
riferimento_cavendish = 6.674 * moltiplicatore_cavendish;

//import dati

	//apertura file in lettura	
	file_in_cavendish.open("cavendish_ps.txt");
	
	//controllo apertura file
	if (file_in_cavendish.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	getline (file_in_cavendish, cavendish_str);
	try {
	valore_cavendish_importato = stod(cavendish_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}

	file_in_cavendish.close();
	
	//---------------------------------------------------
	
	//apertura file in lettura	
	file_in_incertezza_cavendish.open ("incertezza_cavendish_ps.txt");
	
	//controllo apertura file
	if (file_in_incertezza_cavendish.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	getline (file_in_incertezza_cavendish, incertezza_cavendish_str);
	try {
	incertezza_cavendish = stod(incertezza_cavendish_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}

	file_in_incertezza_cavendish.close();
	
	//---------------------------------------------------
	
//esecuzione calcoli

	numeratore_c = valore_cavendish_importato - riferimento_cavendish;
	numeratore_c_assoluto = abs(numeratore_c);	
	compatibilita_c = numeratore_c_assoluto / incertezza_cavendish;

//output file

	file_out_compatibilita_cavendish.open ("confronto_cavendish_riferimento_ps.txt");
	
	//controllo apertura file
	if (file_out_compatibilita_cavendish.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	file_out_compatibilita_cavendish << compatibilita_c;
	
	file_out_compatibilita_cavendish.close ();

cout << "Compatibilità di cavendish =  " << compatibilita_c << endl;

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
CONFRONTO CON RIFERIMENTO PERIODO SINGOLO TRIPLO
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//definizione delle variabili per g

 valore_g_importato = 0;
 incertezza_g = 0;
 riferimento_g = 9.806;
 numeratore_g = 0;
 numeratore_g_assoluto = 0;
 compatibilita_g = 0;

 g_str = "";
 incertezza_g_str = "";

/*ifstream file_in_g;
ifstream file_in_incertezza_g;

ofstream file_out_compatibilita_g;*/

//import dati

	//apertura file in lettura	
	file_in_g.open ("g_stima_pt.txt");
	
	//controllo apertura file
	if (file_in_g.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	getline (file_in_g, g_str);
	try {
	valore_g_importato = stod(g_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}

	file_in_g.close();
	
	//---------------------------------------------------
	
	//apertura file in lettura	
	file_in_incertezza_g.open ("incertezza_g_pt.txt");
	
	//controllo apertura file
	if (file_in_incertezza_g.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	getline (file_in_incertezza_g, incertezza_g_str);
	try {
	incertezza_g = stod(incertezza_g_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}

	file_in_incertezza_g.close();
	
	//---------------------------------------------------
	
//esecuzione calcoli

	numeratore_g = valore_g_importato - riferimento_g;
	numeratore_g_assoluto = abs(numeratore_g);	
	compatibilita_g = numeratore_g_assoluto / incertezza_g;

//output file

	file_out_compatibilita_g.open ("confronto_g_riferimento_pt.txt");
	
	//controllo apertura file
	if (file_out_compatibilita_g.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	file_out_compatibilita_g << compatibilita_g;
	
	file_out_compatibilita_g.close ();

cout << "Compatibilità di g =  " << compatibilita_g << endl;

/*-------------------------------------------------------------------------------------------
SEZIONE CAVENDISH
-------------------------------------------------------------------------------------------*/

//definizione delle variabili per cavendish
 moltiplicatore_cavendish = 0;
 valore_cavendish_importato = 0;
 incertezza_cavendish = 0;
 riferimento_cavendish = 0;
 numeratore_c = 0;
 numeratore_c_assoluto = 0; 
 compatibilita_c = 0;

 cavendish_str = "";
 incertezza_cavendish_str = "";

/*ifstream file_in_cavendish;
ifstream file_in_incertezza_cavendish;

ofstream file_out_compatibilita_cavendish;*/

//calcoletti per cavendish

moltiplicatore_cavendish = 1/100000000000;
riferimento_cavendish = 6.674 * moltiplicatore_cavendish;

//import dati

	//apertura file in lettura	
	file_in_cavendish.open("cavendish_pt.txt");
	
	//controllo apertura file
	if (file_in_cavendish.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	getline (file_in_cavendish, cavendish_str);
	try {
	valore_cavendish_importato = stod(cavendish_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}

	file_in_cavendish.close();
	
	//---------------------------------------------------
	
	//apertura file in lettura	
	file_in_incertezza_cavendish.open ("incertezza_cavendish_pt.txt");
	
	//controllo apertura file
	if (file_in_incertezza_cavendish.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	getline (file_in_incertezza_cavendish, incertezza_cavendish_str);
	try {
	incertezza_cavendish = stod(incertezza_cavendish_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}

	file_in_incertezza_cavendish.close();
	
	//---------------------------------------------------
	
//esecuzione calcoli

	numeratore_c = valore_cavendish_importato - riferimento_cavendish;
	numeratore_c_assoluto = abs(numeratore_c);	
	compatibilita_c = numeratore_c_assoluto / incertezza_cavendish;

//output file

	file_out_compatibilita_cavendish.open ("confronto_cavendish_riferimento_pt.txt");
	
	//controllo apertura file
	if (file_out_compatibilita_cavendish.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	file_out_compatibilita_cavendish << compatibilita_c;
	
	file_out_compatibilita_cavendish.close ();

cout << "Compatibilità di cavendish =  " << compatibilita_c << endl;

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
CONFRONTO CON RIFERIMENTO PERIODO SINGOLO LUNGHEZZA MEZZA 
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//definizione delle variabili per g

 valore_g_importato = 0;
 incertezza_g = 0;
 riferimento_g = 9.806;
 numeratore_g = 0;
 numeratore_g_assoluto = 0;
 compatibilita_g = 0;

 g_str = "";
 incertezza_g_str = "";

/*ifstream file_in_g;
ifstream file_in_incertezza_g;

ofstream file_out_compatibilita_g;*/

//import dati

	//apertura file in lettura	
	file_in_g.open ("g_stima_pl2.txt");
	
	//controllo apertura file
	if (file_in_g.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	getline (file_in_g, g_str);
	try {
	valore_g_importato = stod(g_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}

	file_in_g.close();
	
	//---------------------------------------------------
	
	//apertura file in lettura	
	file_in_incertezza_g.open ("incertezza_g_pl2.txt");
	
	//controllo apertura file
	if (file_in_incertezza_g.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	getline (file_in_incertezza_g, incertezza_g_str);
	try {
	incertezza_g = stod(incertezza_g_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}

	file_in_incertezza_g.close();
	
	//---------------------------------------------------
	
//esecuzione calcoli

	numeratore_g = valore_g_importato - riferimento_g;
	numeratore_g_assoluto = abs(numeratore_g);	
	compatibilita_g = numeratore_g_assoluto / incertezza_g;

//output file

	file_out_compatibilita_g.open ("confronto_g_riferimento_pl2.txt");
	
	//controllo apertura file
	if (file_out_compatibilita_g.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	file_out_compatibilita_g << compatibilita_g;
	
	file_out_compatibilita_g.close ();

cout << "Compatibilità di g =  " << compatibilita_g << endl;

/*-------------------------------------------------------------------------------------------
SEZIONE CAVENDISH
-------------------------------------------------------------------------------------------*/

//definizione delle variabili per cavendish
 moltiplicatore_cavendish = 0;
 valore_cavendish_importato = 0;
 incertezza_cavendish = 0;
 riferimento_cavendish = 0;
 numeratore_c = 0;
 numeratore_c_assoluto = 0;
 compatibilita_c = 0;

 cavendish_str = "";
 incertezza_cavendish_str = "";

/*ifstream file_in_cavendish;
ifstream file_in_incertezza_cavendish;

ofstream file_out_compatibilita_cavendish;*/

//calcoletti per cavendish

moltiplicatore_cavendish = 1/100000000000;
riferimento_cavendish = 6.674 * moltiplicatore_cavendish;

//import dati

	//apertura file in lettura	
	file_in_cavendish.open("cavendish_pl2.txt");
	
	//controllo apertura file
	if (file_in_cavendish.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	getline (file_in_cavendish, cavendish_str);
	try {
	valore_cavendish_importato = stod(cavendish_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}

	file_in_cavendish.close();
	
	//---------------------------------------------------
	
	//apertura file in lettura	
	file_in_incertezza_cavendish.open ("incertezza_cavendish_pl2.txt");
	
	//controllo apertura file
	if (file_in_incertezza_cavendish.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	getline (file_in_incertezza_cavendish, incertezza_cavendish_str);
	try {
	incertezza_cavendish = stod(incertezza_cavendish_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}

	file_in_incertezza_cavendish.close();
	
	//---------------------------------------------------
	
//esecuzione calcoli

	numeratore_c = valore_cavendish_importato - riferimento_cavendish;
	numeratore_c_assoluto = abs(numeratore_c);	
	compatibilita_c = numeratore_c_assoluto / incertezza_cavendish;

//output file

	file_out_compatibilita_cavendish.open ("confronto_cavendish_riferimento_pl2.txt");
	
	//controllo apertura file
	if (file_out_compatibilita_cavendish.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	file_out_compatibilita_cavendish << compatibilita_c;
	
	file_out_compatibilita_cavendish.close ();

cout << "Compatibilità di cavendish =  " << compatibilita_c << endl;

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Alberto Stocco :)  
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

    return 0;
}
