#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

int main () {

//definizione delle variabili per g

double valore_g_importato = 0;
double incertezza_g = 0;
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

	return 0;
}
