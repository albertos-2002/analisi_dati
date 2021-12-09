#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main () {
    string nome_file_in = "";
	vector<double> misure_input;
    int numero_misure_while = 0;  
    int numero_misure_fatte = 0; 
    double somma_misure = 0;  
    double valore_misura = 0;  
    double media_aritmetica = 0; 
    long double parametro_n_meno_1_se = 0; 
	long double parametro_1_diviso_n_meno_1_se = 0;  
	double scarto_quadrato = 0; 
    double scarto_quadrato_2 = 0; 
	long double somma_scarti_quadrati = 0;
    double radicando_se = 0;
    long double se = 0;
    long double sem = 0;
    double radice_numero_misure_fatte = 0;
    string valore_misura_str = "";  
cout << "Inserire il nome del file che deve essere letto" << endl;
cin >> nome_file_in;
ifstream file_in;
ofstream file_out;
file_in.open (nome_file_in);
if (file_in.fail()){
	cout << "Errore nell'apertura del file di input" << endl;
}
		while (!file_in.eof()) {
			getline(file_in, valore_misura_str, ',');
			try {			
			valore_misura = stod(valore_misura_str);
			}			
			catch (invalid_argument) {
			break;
			}
			misure_input.push_back(valore_misura);		
			somma_misure = somma_misure + valore_misura;			
			numero_misure_while = numero_misure_while + 1;				
		}
	numero_misure_fatte = numero_misure_while;
	file_in.close ();
	file_in.clear ();   
    media_aritmetica = somma_misure / numero_misure_fatte;    
    cout << "La media aritmetica (stima di mu valore medio) delle " << numero_misure_fatte << " misure eseguite è" << endl << endl;
    cout << media_aritmetica << endl << endl;   
        parametro_n_meno_1_se = numero_misure_fatte - 1;
        parametro_1_diviso_n_meno_1_se = 1/parametro_n_meno_1_se;
        //cout << "il parametro 1 / (N-1) vale =  " << parametro_1_diviso_n_meno_1_se << endl;   		    
	for (auto iterator : misure_input){
               scarto_quadrato = iterator - media_aritmetica;
               scarto_quadrato_2 = pow(scarto_quadrato,2);                
            somma_scarti_quadrati = somma_scarti_quadrati + scarto_quadrato_2;
	}	
        radicando_se = parametro_1_diviso_n_meno_1_se * somma_scarti_quadrati;
        se = sqrt(radicando_se);
    cout << "SE =  " << se << endl << endl;
    radice_numero_misure_fatte = sqrt(numero_misure_fatte);    
    sem = se / radice_numero_misure_fatte;
    cout << "SEM = " << sem << endl;
file_out.open("se.txt");
    if (file_in.fail()) {
        cout << "Errore nell'apertura del file di input" << endl;
    }
    file_out << se;
    file_out.close();
    file_out.clear();
    file_out.open("sem.txt");
    if (file_in.fail()) {
        cout << "Errore nell'apertura del file di input" << endl;
    }
    file_out << sem;
    file_out.close();
    file_out.clear();
    return 0;
}
