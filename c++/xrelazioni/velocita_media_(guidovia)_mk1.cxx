#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main () {

//variabili per estremo superiore ed estremo inferiore
float sup = 0;
float inf = 0;
//delta x
float delta_x = 0;
//vettori necessari al calcolo
vector <float> tempo_intervallo;
vector <float> velocita_media;

//lettura da file per il tempo intervallo
fstream file_in_tempi;
string file_in_str;
cout << "Inserire il nome del file da cui leggere i tampi dell'intervallo" << endl;
cin >> file_in_str;

file_in_tempi.open(file_in_str);

//controllo di apertura
if ( file_in_tempi.fail()){
  cout << "Errore nell'apertura del file" << endl;
  return 1;
}

string valore_str = "";
float valore_float = 0;
while (!file_in_tempi.eof()){
getline (file_in_tempi, valore_str, ',');
try{
  valore_float = stof(valore_str);
  }
catch (invalid_argument) {
  cout << "errore lettura valore" << endl;
  }
tempo_intervallo.push_back(valore_float);
}

file_in_tempi.close();

//cin degli estremi
cout << "Inserire il valore del traguardo superiore della guidovia in metri" << endl;
cin >> sup;
cout << "Inserire il valore del traguardo inferiore della guidovia in metri" << endl;
cin >> inf;

//calcolo delata x
delta_x = sup-inf;

float parametro_a = 0;
//calcolo velocità media
for (auto c : tempo_intervallo){
  parametro_a = delta_x / c;
  velocita_media.push_back(parametro_a);
}

//scrittura su file out
ofstream file_velocita_out;
string file_out_str = "";

cout << "Inserire il nome del file su cui stampare le velocità medie" << endl;
cin >> file_out_str;

file_velocita_out.open(file_out_str);

//controllo apertura corretta del file
if (file_velocita_out.fail()){
cout << "Errore nell'apertura del file di output" << endl;
}

int parametro_b = velocita_media.size() - 1;
for (int i=0; i<parametro_b; ++i) {
  file_velocita_out << velocita_media.at(i) << ",";
}
file_velocita_out << velocita_media.at(parametro_b);

file_velocita_out.close();

//cout di controllo di alcuni valori
cout << "dimensione del vettore velocità media" << endl;
cout << velocita_media.size() << endl;
cout << "dimensione vettore velocità media -1" << endl;
cout << parametro_b << endl;
cout << "print del vettore velocità media per intero" << endl;
for (auto c : velocita_media){
cout << c << endl;
}
//-------------------------------------------------------------------------------


  return 0;
}
