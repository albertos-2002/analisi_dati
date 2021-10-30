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
long double costante_cavendish_ps = 0;
long double parametro = 0;
long double g_importata_ps = 0;

long double massa_terra = 0;

ifstream file_in_g_ps;
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

	return 0;
}
