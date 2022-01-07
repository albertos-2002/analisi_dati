#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
int main () {
float coefficiente_correlazione_pearson = 0;
float coefficiente_correlazione_pearson_se = 0;
vector <float> xi;
vector <float> yi;
float x_medio = 0;
float y_medio = 0;
ifstream file_in_xi;
ifstream file_in_x_medio;
ifstream file_in_yi;
ifstream file_in_y_medio;
string file_in_xi_str = "";
string file_in_x_medio_str = "";
string file_in_yi_str = "";
string file_in_y_medio_str = "";
long double sum_xi_meno_x_moltiplicato_yi_meno_y = 0;
long double sum_xi_meno_x_pow2 = 0;
long double sum_yi_meno_y_pow2 = 0;
cout << "Inserire il nome del file da cui leggere xi" << endl;
cin >> file_in_xi_str;
cout << "Inserire il nome del file da cui leggere yi" << endl;
cin >> file_in_yi_str;
cout << "Inserire il nome del file da cui leggere x medio" << endl;
cin >> file_in_x_medio_str;
cout << "Inserire il nome del file da cui leggere y medio" << endl;
cin >> file_in_y_medio_str;
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
file_in_x_medio.open(file_in_x_medio_str);
if (file_in_x_medio.fail()) {
cout << "Errore nell'apertura del file relativo a x medio" << endl;
return 1;
}
valore_misura_str = "";
valore_misura = 0;
while (!file_in_x_medio.eof()){
  getline(file_in_x_medio, valore_misura_str);
  valore_misura = stod(valore_misura_str);
  x_medio = valore_misura;
}
file_in_x_medio.close();
file_in_yi.open(file_in_yi_str);
if (file_in_yi.fail()) {
cout << "Errore nell'apertura del file relativo a yi" << endl;
return 1;
}
valore_misura_str = "";
valore_misura = 0;
while (!file_in_yi.eof()){
  getline(file_in_yi, valore_misura_str, ',');
  valore_misura = stod(valore_misura_str);
  yi.push_back(valore_misura);
}
file_in_yi.close();
file_in_y_medio.open(file_in_y_medio_str);
if (file_in_y_medio.fail()) {
cout << "Errore nell'apertura del file relativo a y medio" << endl;
return 1;
}
valore_misura_str = "";
valore_misura = 0;
while (!file_in_y_medio.eof()){
  getline(file_in_y_medio, valore_misura_str);
  valore_misura = stod(valore_misura_str);
  y_medio = valore_misura;
}
file_in_y_medio.close();
if (xi.size() != yi.size()){
  cout << "Dimensione xi diversa da yi" << endl;
  return 2;
}
int numerosita_campione = 0;
numerosita_campione = xi.size();
long double parametro_a = 0;
long double parametro_b = 0;
long double parametro_c = 0;
for (int i=0; i<numerosita_campione; ++i){
  parametro_a = xi.at(i) - x_medio;
  parametro_b = yi.at(i) - y_medio;
  parametro_c = parametro_a*parametro_b;
  sum_xi_meno_x_moltiplicato_yi_meno_y = sum_xi_meno_x_moltiplicato_yi_meno_y + parametro_c;
}
long double parametro_d = 0;
long double parametro_e = 0;
for (int i=0; i<numerosita_campione; ++i) {
  parametro_d = xi.at(i) - x_medio;
  parametro_e = pow(parametro_d,2);
  sum_xi_meno_x_pow2 = sum_xi_meno_x_pow2 + parametro_e;
}
long double parametro_f = 0;
long double parametro_g = 0;
for (int i=0; i<numerosita_campione; ++i) {
  parametro_f = yi.at(i) - y_medio;
  parametro_g = pow(parametro_f,2);
  sum_yi_meno_y_pow2 = sum_yi_meno_y_pow2 + parametro_g;
}
long double parametro_h = 0;
long double parametro_i = 0;
parametro_h = sum_xi_meno_x_pow2*sum_yi_meno_y_pow2;
parametro_i = sqrt(parametro_h);
coefficiente_correlazione_pearson = sum_xi_meno_x_moltiplicato_yi_meno_y / parametro_i;
cout << "Il coefficiente di correlazione di Pearson vale;" << endl;
cout << coefficiente_correlazione_pearson << endl;
ofstream file_out;
string file_out_str = "";
cout << "Inserire il nome del file di output per il coefficiente di correlazione di Pearson" << endl;
cin >> file_out_str;
file_out.open(file_out_str);
file_out << coefficiente_correlazione_pearson;
file_out.close();
float parametro_j = 0;
float parametro_k = 0;
float parametro_l = 0;
parametro_j = pow(coefficiente_correlazione_pearson,2);
parametro_k = 1 - parametro_j;
parametro_l = numerosita_campione - 2;
coefficiente_correlazione_pearson_se = parametro_k / parametro_l;
cout << "L'incertezza sul coefficiente di correlazione di Pearson vale" << endl;
cout << coefficiente_correlazione_pearson_se << endl;
ofstream file_out_secp;
string file_out_secp_str;
cout << "Inserire il nome per il file di output per l'incertezza sul coefficiente di corelazione di Pearson" << endl;
cin >> file_out_secp_str;
file_out_secp.open(file_out_secp_str);
file_out_secp << coefficiente_correlazione_pearson_se;
file_out_secp.close();
return 0;
}