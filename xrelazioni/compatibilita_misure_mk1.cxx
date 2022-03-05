#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

int main () {

//variabili lettura da file
string a_str = "";
string inc_a_str = "";
string b_str = "";
string inc_b_str = "";
//---------------------------------------
ifstream file_a;
ifstream file_inc_a;
ifstream file_b;
ifstream file_inc_b;

//variabili salvataggio
string val_str = "";
long double a = 0;
long double inc_a = 0;
long double b = 0;
long double inc_b = 0;

//variabili calcolo compatibilita
long double numeratore_segno = 0;
long double radicando = 0;
long double inc_a_pow2 = 0;
long double inc_b_pow2 = 0;
long double numeratore = 0;
long double denominatore = 0;
long double compatibilita = 0;

//variabili stampa file
ofstream file_out;
string nome_file_out = "";


cout << "Inserire il nome del file per la misura A" << endl;
cin >> a_str;
cout << "Inserire il nome per il file sull'incertezza su A" << endl;
cin >> inc_a_str;
cout << "Inserire il nome del file per la misura B" << endl;
cin >> b_str;
cout << "Inserire il nome del file sull'incertezza su B" << endl;
cin >> inc_b_str;

//import valori
file_a.open(a_str);
if (file_a.fail()) {
    cout << "Errore nell'apertura del file di a" << endl;
    return 1;
}
getline(file_a, val_str);
a = stod(val_str);
file_a.close();
//-----------------------------------------------------------------
file_inc_a.open(inc_a_str);
if (file_inc_a.fail()) {
    cout << "Errore nell'apertura del file di inc a" << endl;
    return 1;
}
val_str = "";
getline(file_inc_a, val_str);
inc_a = stod(val_str);
file_inc_a.close();
//-----------------------------------------------------------------
file_b.open(b_str);
if (file_b.fail()) {
    cout << "Errore nell'apertura del file di b" << endl;
    return 1;
}
val_str = "";
getline(file_b, val_str);
b = stod(val_str);
file_b.close();
//-----------------------------------------------------------------
file_inc_b.open(inc_b_str);
if (file_inc_b.fail()) {
    cout << "Errore nell'apertura del file di inc b" << endl;
    return 1;
}
val_str = "";
getline(file_inc_b, val_str);
inc_b = stod(val_str);
file_inc_b.close();

//calcolo compatibilità
inc_a_pow2 = pow(inc_a,2);
inc_b_pow2 = pow(inc_b,2);
numeratore_segno = a-b;
radicando = inc_a_pow2+inc_b_pow2;
numeratore = abs(numeratore_segno);
denominatore = sqrt(radicando);

compatibilita = numeratore/denominatore;

cout << "Il coefficiente di compatibilità vale:" << endl;
cout << compatibilita << endl;

//stampa su file output
cout << "Inserire il nome del file su cui stampare il valore della copatibilita" << endl;
cin >> nome_file_out;

file_out.open(nome_file_out);
if (file_out.fail()) {
cout << "Errore nell'apertra del file di output" << endl;
	return 2;
}
file_out << compatibilita;
file_out.close();
    return 0;
}
