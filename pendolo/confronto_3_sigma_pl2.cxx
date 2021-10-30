#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {

//variabili

double sigma = 0;
double sigma_3 = 0;
double valore_in_lettura = 0;
double ciclo_while_in_lettura = 0;

ifstream file_in_sigma;
ifstream file_in_misure_pl2;
ofstream file_out_confronto_3_sigma;

string sigma_str = "";
string valore_in_lettura_str = "";

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

	return 0;
}
