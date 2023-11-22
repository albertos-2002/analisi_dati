#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;
int main () {
long double errore_posteriori = 0;
vector <float> xi;
vector <float> yi;
float intercetta = 0;
float coefficiente_angolare = 0;
int numerosita_campione = 0;
ifstream file_in_yi;
string file_in_yi_str = "";
ifstream file_in_xi;
string file_in_xi_str = "";
ifstream file_in_intercetta;
string file_in_intercetta_str = "";
ifstream file_in_coefficiente_angolare;
string file_in_coefficiente_angolare_str = "";
string valore_miusra_str = "";
float valore_miusra = 0;
cout << "Inserire il nome del file da cui leggere xi" << endl;
cin >> file_in_xi_str;
cout << "Inserire il nome del file da cui leggere yi" << endl;
cin >> file_in_yi_str;
cout << "Inserire il nome del file per il coefficiente angolare (b) della retta interpolante" << endl;
cin >> file_in_coefficiente_angolare_str;
cout << "Inserire il nome del file per l'intercetta (a) della retta interpolante" << endl;
cin >> file_in_intercetta_str;
file_in_xi.open(file_in_xi_str);
    if (file_in_xi.fail()) {
      cout << "Errore nell'apertura del file relativo a xi" << endl;
      return 1;
    }
  while (!file_in_xi.eof()){
    getline (file_in_xi, valore_miusra_str, ',');
    valore_miusra = stod(valore_miusra_str);
    xi.push_back(valore_miusra);
  }
file_in_xi.close();
  valore_miusra_str = "";
  valore_miusra = 0;
file_in_yi.open(file_in_yi_str);
  if (file_in_yi.fail()) {
    cout << "Errore nel apertura del file relativo a yi" << endl;
    return 1;
  }
  while (!file_in_yi.eof()){
    getline (file_in_yi, valore_miusra_str, ',');
    valore_miusra = stod(valore_miusra_str);
    yi.push_back(valore_miusra);
  }
file_in_yi.close();
if (xi.size() != yi.size()){
  cout << "I vettori xi e yi non hanno la stessa dimensione" << endl;
  return 2;
}
numerosita_campione = xi.size();
  valore_miusra = 0;
  valore_miusra_str = "";
file_in_intercetta.open(file_in_intercetta_str);
  if (file_in_intercetta.fail()){
    cout << "Errore nell'apertura del file relativo alla pendenza (a) " << endl;
    return 1;
  }
  while (!file_in_intercetta.eof()){
    getline(file_in_intercetta, valore_miusra_str);
    valore_miusra = stod(valore_miusra_str);
  }
  intercetta = valore_miusra;
file_in_intercetta.close();
  valore_miusra = 0;
  valore_miusra_str = "";
file_in_coefficiente_angolare.open(file_in_coefficiente_angolare_str);
  if (file_in_coefficiente_angolare.fail()){
    cout << "Errore nell'apertura del file relativo al coerfficiente angolare (b)" << endl;
    return 1;
  }
  while (!file_in_coefficiente_angolare.eof()){
    getline(file_in_coefficiente_angolare, valore_miusra_str);
    valore_miusra = stod(valore_miusra_str);
  }
  coefficiente_angolare = valore_miusra;
file_in_coefficiente_angolare.close();
long double sommatoria = 0;
long double parametro_c = 0;
long double parametro_d = 0;
long double parametro_e = 0;
for (int i=0; i<numerosita_campione; ++i){
  parametro_c = (coefficiente_angolare * xi.at(i)) + intercetta;
  parametro_d = yi.at(i) - parametro_c;
  parametro_e = pow(parametro_d,2);
  sommatoria = sommatoria + parametro_e;
}
float parametro_f = 0;
float parametro_g = 0;
float parametro_h = 0;
parametro_f = numerosita_campione - 2;
parametro_g = 1 / parametro_f;
parametro_h = parametro_g * sommatoria;
errore_posteriori = sqrt(parametro_h);
cout << "Il valore dell'errore a posteriori" << endl;
cout << errore_posteriori << endl;
    /*
ofstream file_out;
string file_out_str;
cout << "Inserire il nome del file di output per l'errore a posteriori" << endl;
cin >> file_out_str;
file_out.open(file_out_str);
  if (file_out.fail()){
    cout << "Errore nell'apertura del file di output" << endl;
    return 1;
  }
  file_out << errore_posteriori;
file_out.close();
*/
return 0;

}
