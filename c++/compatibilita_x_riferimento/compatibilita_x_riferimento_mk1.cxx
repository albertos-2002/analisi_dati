#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main (){

//variabili dei valori
long double valore_x = 0;
long double incertezza_x = 0;
long double riferimento = 0;
long double incertezza_riferimento = 0;

//stringhe nome file da leggere
string in_file_valore_x = "";
string in_file_incertezza_x = "";

//variabili per i calcoli
long double numeratore = 0;
long double numeratore_abs = 0;
long double incertezza_x_pow2 = 0;
long double incertezza_riferimento_pow2 = 0;
long double denominatore = 0;
long double denominatore_sqrt = 0;
long double compatibilita_x = 0;

//stringhe per input di file
string valore_str = "";
string incertezza_valore_str = "";

//definizione file fstream
ifstream file_in_valore;
ifstream file_in_incertezza_valore;
ofstream file_out_compatibilita;

//cin nome dei file
cout << "Iserire il nome del file contenente il valore x" << endl;
cin >> in_file_valore_x;
cout << "Inseire il nome del file contenente l'incertezza di x" << endl;
cin >> in_file_incertezza_x;

//cin dei valori di riferimento
cout << "Inserire il valore di riferimento" << endl;
cin >> riferimento;
cout << "Inserire il valore dell'incertezza del riferimento, inserire 0 se non presente" << endl;
cin >> incertezza_riferimento;


//import dati

	//apertura file in lettura	
	file_in_valore.open (in_file_valore_x);
	
	//controllo apertura file
	if (file_in_valore.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	getline (file_in_valore, valore_str);
	try {
	valore_x = stod(valore_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}

	file_in_valore.close();
	
	//apertura file in lettura	
	file_in_incertezza_valore.open (in_file_incertezza_x);
	
	//controllo apertura file
	if (file_in_incertezza_valore.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	getline (file_in_incertezza_valore, incertezza_valore_str);
	try {
	incertezza_x = stod(incertezza_valore_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}

	file_in_incertezza_valore.close();
	
//esecuzione calcoli

	numeratore = valore_x - riferimento;
	numeratore_abs = abs(numeratore);
	
	incertezza_x_pow2 = pow(incertezza_x,2);
	incertezza_riferimento_pow2 = pow(incertezza_riferimento,2);
	denominatore = incertezza_x_pow2 + incertezza_riferimento_pow2;
	denominatore_sqrt = sqrt(denominatore);	
	compatibilita_x = numeratore_abs / denominatore_sqrt;

//output file

	file_out_compatibilita.open ("compatibilita_x_riferimento.txt");
	
	//controllo apertura file
	if (file_out_compatibilita.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	file_out_compatibilita << compatibilita_x;
	
	file_out_compatibilita.close ();

cout << "Fattore di compatibilità =  " << compatibilita_x << endl;

	return 0;
}
