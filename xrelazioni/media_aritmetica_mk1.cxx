#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main () {

//definizione variabili
vector <long double> xi;
long double media = 0;
ifstream file_in;
string file_in_str = "";
ofstream file_out;
string file_out_str = "";
string valore_misura_str = "";
long double valore_misura = 0;
long double sommatoria = 0;

cout << "Inserire il nome del file da cui leggere i dati" << endl;
cin >> file_in_str;

//lettura da file
file_in.open(file_in_str);
  //controllo apertura del file
  if (file_in.fail()){
    cout << "Errore nell'apertura del file in input" << endl;
    return 1;
  }

  while (!file_in.eof()){
    getline(file_in, valore_misura_str, ',');
    valore_misura = stod(valore_misura_str);
    xi.push_back(valore_misura);
  }
file_in.close();

for (auto c : xi){
  sommatoria = sommatoria + c;
}

media = sommatoria / xi.size();

cout << "Il valore medio delle misure" << endl;
cout << media << endl;

cout << "Inserire il nome del file di output" << endl;
cin >> file_out_str;

//scrittura su file
file_out.open(file_out_str);
file_out << media;
file_out.close();

return 0;
}
