#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main () {
double numero_sigma = 0;
double sigma = 0;
double sigma_x = 0;
double valore_in_lettura = 0;
double ciclo_while_in_lettura = 0;
ifstream file_in_sigma;
ifstream file_in_misure;
ofstream file_out_confronto_x_sigma;
string in_sigma_str = "";
string in_misure_str = "";
string sigma_str = "";
string valore_in_lettura_str = "";
cout << "Inserisci il numero per il range del confronto, es: 3 per 3sigma" << endl;
cin >> numero_sigma;
cout << "Inserire il nome del file contenente se" << endl;
cin >> in_sigma_str;
cout << endl;
cout << "Inserire" << endl;
	file_in_sigma.open (in_sigma_str);
	if (file_in_sigma.fail()){
	cout << "Errore nell'apertura del file di input" << endl;
	}
	getline(file_in_sigma, sigma_str);
	try {
	sigma = stod(sigma_str);
	}
	catch (invalid_argument){
	cout << "Errore nella lettura" << endl;
	}	
	sigma_x = numero_sigma * sigma;	
	cout << "Inserire il nome del file che contiene le misure da confrontare" << endl;
	cin >> in_misure_str;
	file_in_misure.open (in_misure_str);
	if (file_in_misure.fail()){
	cout << "Errore nell'apertura del file di input" << endl;
	}
	file_out_confronto_x_sigma.open ("confronto_x_sigma.txt");
		while (!file_in_misure.eof()) {
			getline(file_in_misure, valore_in_lettura_str, ',');			
			try {
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
