#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

int main () {
//variabili
long double modulo_young = 0;
long double diametro_filo = 0;
long double lunghezza_filo_riposo = 0;
long double costante_elastica = 0;
long double errore_modulo_young = 0;
long double err_lunghezza = 0;
long double err_cost_elastica = 0;
long double err_diametro = 0;
//variabili di conversione
long double lunghezza_mm = 0;
long double err_lunghezza_mm = 0;
long double diametro_filo_mm = 0;
long double err_diametro_percentuale = 0;
long double err_relat_diametro = 0;
//variabili lettura su file
ifstream file_in_k;
ifstream file_in_err_k;
string file_k_str = "";
string file_err_k_str = "";
//variabili stampa su file
ofstream file_my;
ofstream file_emy;
string file_my_str = "";
string file_emy_str = "";

//la k viene determinata dalla regressione lineare


//cin dei valori numerici
//lunghezza
cout << "Inserire la lunghezza del filo [mm]" << endl;
cin >> lunghezza_mm;
lunghezza_filo_riposo = lunghezza_mm / 1000;
cout << "Inserire errore sulla lunghezza [mm]" << endl;
cin >> err_lunghezza_mm;
err_lunghezza = err_lunghezza_mm / 1000;
//diametro
cout << "Inserire il diametro del filo [mm]" << endl;
cin >> diametro_filo_mm;
diametro_filo = diametro_filo_mm / 1000;
cout << "Inserie errore sul diametro del filo [%]" << endl;
cin >> err_diametro_percentuale;
err_relat_diametro = err_diametro_percentuale / 100;
err_diametro = err_relat_diametro * diametro_filo;

//switch casi inserimento costante elastica
string switch_case = "";
cout << "Inserimento valore costante elastica" << endl;
cout << "Inserire \"f\" per la lettura da file" << endl;
cout << "Inserire \"m\" per l'inserimento manuale" << endl;
cin >> switch_case;

if (switch_case=="m") {
	cout << "Inserire il valore della costante elastica [m/N]" << endl;
	cin >> costante_elastica;
	cout << "Inserire errore sulla costante elastica [m/N]" << endl;
	cin >> err_cost_elastica;
}

else if (switch_case=="f") {
	cout << "Inserire il nome del file da cui leggere il valore di K" << endl;
	cin >> file_k_str;
	cout << "Inserire il nome del file da cui leggere il valore dell'errore su K" << endl;
	cin >> file_err_k_str;

	file_in_k.open(file_k_str);
		//controllo apertura
		if (file_in_k.fail()) {
			cout << "Errore nell'apertura del file di lettura per k" << endl;
			return 2;
		}
		//lettura
		string val_str = "";
		long double val_num = 0;
		getline(file_in_k, val_str);
		val_num = stod(val_str);
		costante_elastica = val_num;
	file_in_k.close();

	file_in_err_k.open(file_err_k_str);
		//controllo apertura
		if (file_in_err_k.fail()) {
			cout << "Errore nell'apertura del file di lettura per errore su k" << endl;
			return 2;
		}
		//lettura
		val_str = "";
		val_num = 0;
		getline(file_in_err_k, val_str);
		val_num = stod(val_str);
		err_cost_elastica = val_num;
	file_in_err_k.close();
}

else {
	cout << "Errore di inserimento" << endl;
	return 3;
}

//calcolo valore di E (modulo di Young)
long double diametro_pow2 = pow(diametro_filo,2);
long double numeratore = 4*lunghezza_filo_riposo;
long double denominatore = M_PI*diametro_pow2*costante_elastica;

modulo_young = numeratore/denominatore;

//output
cout << "Il modulo di young vale:" << endl;
cout << modulo_young << endl;

//calcolo errore
long double errp1 = err_lunghezza/lunghezza_filo_riposo;
long double errp2 = err_cost_elastica/costante_elastica;
long double errp3 = err_diametro/diametro_filo;
long double errp1_pow2 = pow(errp1,2);
long double errp2_pow2 = pow(errp2,2);
long double errp3_pow2_4 = 4*pow(errp3,2);
long double radicando = errp1_pow2+errp2_pow2+errp3_pow2_4;
long double radice = sqrt(radicando);

errore_modulo_young = modulo_young*radice;

//output
cout << "L'errore sul modulo di young vale:" << endl;
cout << errore_modulo_young << endl;

//stampa su file
cout << "Inserire il nome del file per il modulo di young" << endl;
cin >> file_my_str;
cout << "Inserire il nome del file per l'errore sul modulo di young" << endl;
cin >> file_emy_str;

file_my.open(file_my_str);
	if (file_my.fail()) {
	cout << "Errore nell'apertura del file per la scrittura del modulo di young" << endl;
	return 1;
	}
	file_my << modulo_young;
file_my.close();

file_emy.open(file_emy_str);
	if (file_emy.fail()) {
	cout << "Errore nell'apertura del file per la srittura dell'errore sul modulo di young" << endl;
	return 1;
	}
	file_emy << errore_modulo_young;
file_emy.close();

  return 0;
}
