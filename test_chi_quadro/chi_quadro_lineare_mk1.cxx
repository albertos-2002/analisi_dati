#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

//consideriamo le incertezze sulle x trascurabile
//incertezza sulle y gaussiana

int main () {

long double retta_a = 0;
long double retta_b = 0;
ifstream file_in_y;
string nome_file_in_y = "";
ifstream file_in_x;
string nome_file_in_x = "";
ifstream file_in_incertezze_y;
string nome_file_in_incertezze_y = "";
vector <long double> misure_y;
vector <long double> misure_x;
vector <long double> incertezze_y;
long double numerosita_campione = 0;
vector <long double> valori_riferimento;
vector <long double> chi_non_quadri;
vector <long double> chi_quadri;
long double chi_quadro_misurato = 0;

cout << "Ricordiamo la tipologia di equazione lineare" << endl;
cout << "y = a + bx" << endl;
cout << "Inserire valore di a (intercetta)" << endl;
cin >> retta_a;
cout << "Inserire valore di b (coefficiente angolare)" << endl;
cin >> retta_b;

//variabili di lettura su file
string stringa_in = "";
long double valore_in = 0;

//lettura delle y
  cout << "Inserire il nome del file per la lettura di y" << endl;
  cin >> nome_file_in_y;

  file_in_y.open(nome_file_in_y);

  if (file_in_y.fail()) {
    cout << "Errore nell'apertura del file delle y" << endl;
    return 1;
  }
  while (!file_in_y.eof()) {
	   getline(file_in_y, stringa_in, ',');
	   valore_in = stod(stringa_in);
	   misure_y.push_back(valore_in);
  }
  file_in_y.close();

//lettura degli x
  cout << "Inserire il nome del file per la lettura di x" << endl;
  cin >> nome_file_in_x;

//----
stringa_in = "";
valore_in = 0;
//---

  file_in_x.open(nome_file_in_x);

  if (file_in_x.fail()) {
    cout << "Errore nell'apertura del file delle x" << endl;
    return 1;
  }
  while (!file_in_x.eof()) {
	   getline(file_in_x, stringa_in, ',');
	   valore_in = stod(stringa_in);
	   misure_x.push_back(valore_in);
  }
  file_in_x.close();

//lettura delle incertezze sulle y
  cout << "Inserire il nome file per incertezze sulle y" << endl;
  cin >> nome_file_in_incertezze_y;

//---
stringa_in = "";
valore_in = 0;
//---

  file_in_incertezze_y.open(nome_file_in_incertezze_y);

  if (file_in_incertezze_y.fail()) {
    cout << "Errore nell'apertura del file delle incertezze sulle y" << endl;
    return 1;
  }
  while (!file_in_incertezze_y.eof()) {
	   getline(file_in_incertezze_y, stringa_in, ',');
	   valore_in = stod(stringa_in);
	   incertezze_y.push_back(valore_in);
  }
  file_in_incertezze_y.close();

//controllo lunghezza vettori
if (misure_y.size() != misure_x.size()) {
	cout << "La lunghezza dei vettori y e x non corrisponde" << endl;
	return 2;
}
if (misure_y.size() != incertezze_y.size()) {
	cout << "La lunghezza dei vettori y e incertezza y non corrisponde" << endl;
	return 2;
}

numerosita_campione = misure_y.size();

//calcolo dei valori di riferimento
long double parametro_e = 0;
long double parametro_f = 0;
for (int i = 0; i<numerosita_campione; ++i) {
	parametro_e = misure_x.at(i)*retta_b;
	parametro_f = parametro_e + retta_a;
	valori_riferimento.push_back(parametro_f);
}

//calcolo dei chi (non quadrati)
long double parametro_g = 0;
long double parametro_h = 0;
for (int i = 0; i<numerosita_campione; ++i) {
	parametro_g = misure_y.at(i) - valori_riferimento.at(i);
	parametro_h = parametro_g / incertezze_y.at(i);
	chi_non_quadri.push_back(parametro_h);
}

//calcolo dei chi quadrati
long double parametro_k = 0;
for (int i = 0; i<numerosita_campione; ++i){
	parametro_k = pow(chi_non_quadri.at(i),2);
	chi_quadri.push_back(parametro_k);
}

//calcolo chi quadro misurato
for (int i = 0; i<numerosita_campione; ++i) {
	chi_quadro_misurato = chi_quadro_misurato + chi_quadri.at(i);
}

//stampa su std output dei singoli chi quadri e di quello misurato
cout << "I singoli chi quadri valgono" << endl;
for (int i = 0; i<numerosita_campione; ++i) {
	cout << chi_quadri.at(i) << endl;
}
cout << "Il chi quadro misurato vale" << endl;
cout << chi_quadro_misurato << endl;

long double ndof = 0;
ndof = y.size()-2;
cout << "NDOF" << endl;
cout << ndof << endl;	
	
  return 0;
}
