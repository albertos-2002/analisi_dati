#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {

//variabili numeriche
double numero_sigma = 0;
double sigma = 0;
double sigma_x = 0;
double valore_in_lettura = 0;
double ciclo_while_in_lettura = 0;

//variabili lettura file
ifstream file_in_sigma; //done
ifstream file_in_misure;
ofstream file_out_confronto_x_sigma;

string in_sigma_str = "";
string in_misure_str = "";

//variabili stringhe
string sigma_str = "";
string valore_in_lettura_str = "";

//cin del moltiplicatore di sigma
cout << "Inserisci il numero per il range del confronto, es: 3 per 3sigma" << endl;
cin >> numero_sigma;

//cin del nome dei file
cout << "Inserire il nome del file contenente se" << endl;
cin >> in_sigma_str;
cout << endl;
cout << "Inserire" << endl;

//inserimento del valore sigma

	file_in_sigma.open (in_sigma_str);

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

	sigma_x = numero_sigma * sigma;	
	
//confronto misure con tre sigma

	//cin file di input
	cout << "Inserire il nome del file che contiene le misure da confrontare" << endl;
	cin >> in_misure_str;

	//apertura del file in lettura
	file_in_misure.open (in_misure_str);

	//controllo se il file è stato aperto correttamente
	if (file_in_misure.fail()){
	cout << "Errore nell'apertura del file di input" << endl;
	}

	file_out_confronto_x_sigma.open ("confronto_x_sigma.txt");

	//ciclo di lettura delle misure 

		while (!file_in_misure.eof()) {
		
			getline(file_in_misure, valore_in_lettura_str, ',');
	
			//ciclo per trovare gli errori e far andare avanti il ciclo
			try {
			//trasforma la stringa in una variabile numerica
			valore_in_lettura = stod(valore_in_lettura_str);
					
			   }		
			catch (invalid_argument) {
			cout << "Impossibile leggere la misura" << endl;
			   }
			  
			ciclo_while_in_lettura = ciclo_while_in_lettura + 1;  
			  
			if (valore_in_lettura > sigma_x){
			
			  file_out_confronto_x_sigma << ciclo_while_in_lettura << "\t" << valore_in_lettura << endl;
			}	
		}	

	file_out_confronto_x_sigma.close();

	return 0;
}
