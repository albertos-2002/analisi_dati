#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main (){

//variabili per il calcolo

long double massa_terra_parziale = 5972; // espressa in Kg
long double parziale1 = 10000000;
long double parziale2 = 10000000;
long double parziale3 = 10000000;

long double mtma = 0;
long double mtmb = 0;

long double raggio_terra = 6371000; // espresso in metri
long double raggio_terra_quadro = 0;
long double costante_cavendish_pl2 = 0;
long double parametro = 0;
long double g_importata_pl2 = 0;

long double massa_terra = 0;

ifstream file_in_g_pl2;
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

	return 0;
}
