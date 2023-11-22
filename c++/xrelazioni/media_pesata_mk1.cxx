#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

int main () {

  long double media_pesata = 0;
  long double incertezza_media_pesata = 0;

  //definizione vettori serie di dati
  vector <float> xi;
  vector <float> sxi;

  //definizione variabili per fstream
  ifstream file_in_xi;
  ifstream file_in_sxi;

  //definizione variabili string per io file
  string file_in_xi_str = "";
  string file_in_sxi_str = "";


  //cin file lettura dati
  cout << "Inserire il nome del file da cui leggere xi (valori medi)" << endl;
  cin >> file_in_xi_str;
  cout << "Inserire il nome del file da cui leggere Sxi (incertezze valori medi)" << endl;
  cin >> file_in_sxi_str;

  //lettura da file
  file_in_xi.open(file_in_xi_str);
  //controllo apertura del file
  if (file_in_xi.fail()){
  cout << "Errore nell'apertura del file relativo a xi" << endl;
  return 1;
  }

  string valore_misura_str = "";
  float valore_misura = 0;

  while (!file_in_xi.eof()){
    getline(file_in_xi, valore_misura_str, ',');
    valore_misura = stod(valore_misura_str);
    xi.push_back(valore_misura);
  }

  file_in_xi.close();


  file_in_sxi.open(file_in_sxi_str);
  //controllo apertura del file
  if (file_in_sxi.fail()) {
  cout << "Errore nell'apertura del file relativo a Sxi" << endl;
  return 1;
  }

  valore_misura_str = "";
  valore_misura = 0;

  while (!file_in_sxi.eof()){
    getline(file_in_sxi, valore_misura_str, ',');
    valore_misura = stod(valore_misura_str);
    sxi.push_back(valore_misura);
  }

  file_in_sxi.close();


  //controllo che i vettori possiedano la stessa dimensione
  if (xi.size() != sxi.size()){
    cout << "Dimensione xi diversa da Sxi" << endl;
    return 2;
  }

  int numerosita_campione = 0;
  numerosita_campione = xi.size();


long double sum_xi_diviso_sxi_pow2 = 0;
long double sum_1_diviso_sxi_pow2 = 0;

//costruzione sommatorie e calcolo media pesata e sua incertezza
long double parametro_a = 0;
long double parametro_b = 0;
for (int i=0; i<numerosita_campione; ++i){
  parametro_a = pow(sxi.at(i),2);
  parametro_b = xi.at(i) / parametro_a;
  sum_xi_diviso_sxi_pow2 = sum_xi_diviso_sxi_pow2 + parametro_b;
 }

 long double parametro_c = 0;
 long double parametro_d = 0;
 for (int i=0; i<numerosita_campione; ++i){
   parametro_c = pow(sxi.at(i),2);
   parametro_d = 1 / parametro_c;
   sum_1_diviso_sxi_pow2 = sum_1_diviso_sxi_pow2 + parametro_d;
  }

media_pesata = sum_xi_diviso_sxi_pow2 / sum_1_diviso_sxi_pow2;

cout << "Il valore della media pesata" << endl;
cout << media_pesata << endl;

long double parametro_e = 0;
parametro_e = 1 / sum_1_diviso_sxi_pow2;
incertezza_media_pesata = sqrt(parametro_e);

cout << "Incerteza della media pesata vale" << endl;
cout << incertezza_media_pesata << endl;

//stampa su file di output
ofstream file_out_mp;
ofstream file_out_inc_mp;
string file_out_mp_str;
string file_out_inc_mp_str;

//cin file lettura dati
cout << "Inserire il nome del file da output per il valore della media pesata" << endl;
cin >> file_out_mp_str;
cout << "Inserire il nome del file di output per l'incertezza della media pesata" << endl;
cin >> file_out_inc_mp_str;

file_out_mp.open(file_out_mp_str);
//controllo apertura del file
if (file_out_mp.fail()) {
cout << "Errore nell'apertura del file relativo al file di output per la media pesata" << endl;
return 1;
}
file_out_mp << media_pesata;

file_in_sxi.close();

file_out_inc_mp.open(file_out_inc_mp_str);
//controllo apertura del file
if (file_out_inc_mp.fail()) {
cout << "Errore nell'apertura del file di output relativo all'incertezza sulla media pesata" << endl;
return 1;
}
file_out_inc_mp << incertezza_media_pesata;

file_in_sxi.close();


return 0;

}
