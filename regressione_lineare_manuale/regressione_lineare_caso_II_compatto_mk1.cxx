#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
int main () {
vector <long double> syi;
vector <long double> yi;
vector <long double> xi;
vector <long double> syi_pow2;
vector <long double> xi_pow2;
vector <long double> xiyi;
string nome_file_in_incertezze_ordinate = "";
ifstream file_in_incertezze;
string misura_incertezza_ordinata_str = "";
long double valore_incertezza = 0;
string nome_file_in_misure_ordinate = "";
ifstream file_in_misure_ordinate;
string misura_ordinata_str = "";
long double valore_misura_ordinata = 0;
string nome_file_in_misure_ascisse = "";
ifstream file_in_misure_ascisse;
string misura_ascisse_str = "";
long double valore_misura_ascisse = 0;
long double misura_ascissa_quadrata = 0;
long double misura_incertezza_ordinata_quadrata = 0;
long double misura_ascissa_moltiplicata_ordinata = 0;
long double sum_1_diviso_syi_pow2 = 0;
long double sum_xi_pow2_diviso_syi_pow2 = 0;
long double sum_xi_diviso_syi = 0;
long double sum_yi_diviso_syi_pow2 = 0;
long double sum_xi_diviso_syi_pow2 = 0;
long double sum_xiyi_diviso_syi_pow2 = 0;
long double pow2_sum_xi_diviso_syi_pow2 = 0;
long double delta = 0;
long double delta_diviso_1 = 0;
long double a = 0;
long double incertezza_a = 0;
long double b = 0;
long double incertezza_b = 0;
ofstream file_out_a;
ofstream file_out_incertezza_a;
ofstream file_out_b;
ofstream file_out_incertezza_b;
string nome_file_a_str = "";
string nome_file_a_incertezza_str = "";
string nome_file_b_str = "";
string nome_file_b_incertezza_str = "";
cout << "Inserire il nome del file da cui leggere le incertezze sulle ordinate" << endl;
cin >> nome_file_in_incertezze_ordinate;
file_in_incertezze.open(nome_file_in_incertezze_ordinate);
if (file_in_incertezze.fail()){
  cout << "Errore nell'apertura del file relativo alle incertezze sulle ordinate" << endl;
  return(1);
}
while (!file_in_incertezze.eof()){
  getline(file_in_incertezze, misura_incertezza_ordinata_str, ',');
  try {
    valore_incertezza = stod(misura_incertezza_ordinata_str);
  }
  catch(invalid_argument){
    cout << "errore lettura valore" << endl;
//    break;
  }
  syi.push_back(valore_incertezza);
}
file_in_incertezze.close();
cout << "Inserire il nome del file da cui leggere le misure sulle ordinate" << endl;
cin >> nome_file_in_misure_ordinate;
file_in_misure_ordinate.open(nome_file_in_misure_ordinate);
if (file_in_misure_ordinate.fail()){
  cout << "Errore nell'apertura del file relativo alle misure sulle ordinate" << endl;
  return(1);
}
while (!file_in_misure_ordinate.eof()){
  getline(file_in_misure_ordinate, misura_ordinata_str, ',');
  try {
    valore_misura_ordinata = stod(misura_ordinata_str);
  }
  catch(invalid_argument){
    break;
  }
  yi.push_back(valore_misura_ordinata);
}
file_in_misure_ordinate.close();
cout << "Inserire il nome del file da cui leggere le misure sulle ascisse" << endl;
cin >> nome_file_in_misure_ascisse;
file_in_misure_ascisse.open(nome_file_in_misure_ascisse);
if (file_in_misure_ascisse.fail()){
  cout << "Errore nell'apertura del file relativo alle misure sulle ascisse" << endl;
  return(1);
}
while (!file_in_misure_ascisse.eof()){
  getline(file_in_misure_ascisse, misura_ascisse_str, ',');
  try {
    valore_misura_ascisse = stod(misura_ascisse_str);
  }
  catch(invalid_argument){
    break;
  }
  xi.push_back(valore_misura_ascisse);
}
file_in_misure_ascisse.close();
if (syi.size() != yi.size()) {
  cout << "Errore" << endl;
  cout << "Dimensioni dei vettori incertezze ordinate e misure ordinate non corrispondono" << endl;
  return 2;
}
if (yi.size() != xi.size()) {
  cout << "Errore" << endl;
  cout << "Dimensioni dei vettori misure ordinate e misure ascisse non corrispondono" << endl;
  return 2;
}
for (auto c : xi){
  misura_ascissa_quadrata = pow(c,2);
  xi_pow2.push_back(misura_ascissa_quadrata);
}
for (auto c : syi){
  misura_incertezza_ordinata_quadrata = pow(c,2);
  syi_pow2.push_back(misura_incertezza_ordinata_quadrata);
}
for (int i=0; i<xi.size(); ++i){
  misura_ascissa_moltiplicata_ordinata = xi.at(i)*yi.at(i);
  xiyi.push_back(misura_ascissa_moltiplicata_ordinata);
}
long double parametro_b = 0;
for (int i=0; i < xi.size(); ++i){
  parametro_b = xi_pow2.at(i)/syi_pow2.at(i);
  sum_xi_pow2_diviso_syi_pow2 = sum_xi_pow2_diviso_syi_pow2 + parametro_b;
}
long double parametro_d = 0;
for (int i=0; i < xi.size(); ++i){
  parametro_d = yi.at(i)/syi_pow2.at(i);
  sum_yi_diviso_syi_pow2 = sum_yi_diviso_syi_pow2 + parametro_d;
}
long double parametro_e = 0;
for (int i=0; i < xi.size(); ++i){
  parametro_e = xi.at(i)/syi_pow2.at(i);
  sum_xi_diviso_syi_pow2 = sum_xi_diviso_syi_pow2 + parametro_e;
}
long double parametro_f = 0;
for (int i=0; i < xi.size(); ++i){
  parametro_f = xiyi.at(i)/syi_pow2.at(i);
  sum_xiyi_diviso_syi_pow2 = sum_xiyi_diviso_syi_pow2 + parametro_f;
}
long double parametro_r = 0;
long double parametro_s = 0;
for (auto c : syi){
  parametro_s = pow(c,2);
  parametro_r = 1/parametro_s;
  sum_1_diviso_syi_pow2 = sum_1_diviso_syi_pow2 + parametro_r;
}
long double parametro_g = 0;
pow2_sum_xi_diviso_syi_pow2 = pow(sum_xi_diviso_syi_pow2,2);
parametro_g = sum_1_diviso_syi_pow2 * sum_xi_pow2_diviso_syi_pow2;
delta = parametro_g - pow2_sum_xi_diviso_syi_pow2;
delta_diviso_1 = 1/delta;
long double parametro_h = 0;
long double parametro_i = 0;
long double parametro_j = 0;
long double parametro_k = 0;
parametro_h = sum_xi_pow2_diviso_syi_pow2 * sum_yi_diviso_syi_pow2;
parametro_i = sum_xi_diviso_syi_pow2 * sum_xiyi_diviso_syi_pow2;
parametro_j = parametro_h - parametro_i;
a = delta_diviso_1 * parametro_j;
parametro_k = delta_diviso_1 * sum_xi_pow2_diviso_syi_pow2;
incertezza_a = sqrt(parametro_k);
long double parametro_l = 0;
long double parametro_m = 0;
long double parametro_n = 0;
long double parametro_o = 0;
parametro_l = sum_1_diviso_syi_pow2 * sum_xiyi_diviso_syi_pow2;
parametro_m = sum_xi_diviso_syi_pow2 * sum_yi_diviso_syi_pow2;
parametro_n = parametro_l - parametro_m;
b = delta_diviso_1 * parametro_n;
parametro_o = delta_diviso_1 * sum_1_diviso_syi_pow2;
incertezza_b = sqrt(parametro_o);
cout << endl;
cout << "Il parametro a (intercetta) della regressione lineare vale:" << endl;
cout << a << endl;
cout << "La sua incertezza vale:" << endl;
cout << incertezza_a << endl;
cout << "Il parametro b (coefficiente angolare) della regressione lineare vale:" << endl;
cout << b << endl;
cout << "La sua incertezza vale:" << endl;
cout << incertezza_b << endl;
cout << "Inserisci il nome per il file parametro a della regressione lineare" << endl;
cin >> nome_file_a_str;
cout << "Inserisci il nome per il file incertezza sul parametro a della regressione lineare" << endl;
cin >> nome_file_a_incertezza_str;
cout << "Inserisci il nome per il file parametro b della regressione lineare" << endl;
cin >> nome_file_b_str;
cout << "Inserisci il nome per il file incertezza b della regressione lineare" << endl;
cin >> nome_file_b_incertezza_str;
file_out_a.open(nome_file_a_str);
file_out_a << a;
file_out_a.close();
file_out_b.open(nome_file_b_str);
file_out_b << b;
file_out_b.close();
file_out_incertezza_a.open(nome_file_a_incertezza_str);
file_out_incertezza_a << incertezza_a;
file_out_incertezza_a.close();
file_out_incertezza_b.open(nome_file_b_incertezza_str);
file_out_incertezza_b << incertezza_b;
file_out_incertezza_b.close();
  return 0;
}
