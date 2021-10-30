#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main (){

//variabili numeriche

    double pi_greco = M_PI;
    double lunghezza = 0;
    double periodo = 0;
    double periodo_2 = 0;
    double g_stima = 0;
    double parametro_pi = 0;
    double parametro_pi_2 = 0;
    double parametro_lt = 0;
    
    double periodo3 = 0;

//variabili tipo stringa
    string periodo_str = "";
    
//dichiarazione file in e out
    ifstream file_in;
    ofstream file_out;
    ofstream file_out_parametri;
    ofstream file_out_l;

//inserzione parametri per il calcolo

	cout << "Inserire la lunghezza l del pendolo in metri" << endl;
	cin >> lunghezza;
	cout << endl;
	
//apertura file in lettura	
	file_in.open ("media_aritmetica_pt.txt");
	
	//controllo apertura file
	if (file_in.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	getline (file_in, periodo_str);
	try {
	periodo3 = stod(periodo_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}

	file_in.close();

//esecuzione operazioni

	periodo = periodo3 / 3;

	periodo_2 = pow(periodo,2);
	parametro_pi = 2 * pi_greco;
	parametro_pi_2 = pow(parametro_pi,2);
	parametro_lt = lunghezza / periodo_2;
	g_stima = parametro_pi_2 * parametro_lt;
	
//output di controllo
	cout << "La stima di g è   " << g_stima << endl;

//output file

	file_out.open ("g_stima_pt.txt");
	
	//controllo apertura file
	if (file_in.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	file_out << g_stima;
	
	file_out.close ();	
	
//----------------------------------------------------------------------------------

	file_out_parametri.open ("g_stima_pt_parametri.txt");	
	
	//controllo apertura file
	if (file_in.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	file_out_parametri << "Quadrato del periodo" << endl;
	file_out_parametri << periodo_2 << endl << endl;
	file_out_parametri << "Parametro 2pi" << endl;
	file_out_parametri << parametro_pi << endl << endl;
	file_out_parametri << "Parametro 2pi quadrato" << endl;
	file_out_parametri << parametro_pi_2 << endl << endl;
	file_out_parametri << "Parametro lunghezza / periodo^2" << endl;
	file_out_parametri << parametro_lt << endl << endl;
	file_out_parametri << "Verifica di pi greco" << endl;
	file_out_parametri << pi_greco << endl << endl;
	
	file_out_parametri.close();
	
//---------------------------------------------------------------------------------	
	
	file_out_l.open ("lunghezza.txt");
	
	//controllo apertura file
	if (file_in.fail()){
	cout << "Errore nell'apertura del file" << endl;
	}
	
	file_out_l << lunghezza;
	
	file_out_l.close ();
	
//---------------------------------------------------------------------------------	


cout << "Non posso calcolare l'incertezza su g con il periodo triplo" << endl;

/*

AL MOMENTO NON CALCOLABILE CON QUESTO METORO


//---------------------------------------------------------------------------------------
//STIMA INCRTEZZA SU g
//---------------------------------------------------------------------------------------

    double incertezza_g = 0;
    //la variabile g è stata definita sopra nel codice come    g_stima
    
//--incertezza su l
    double incertezza_l = 0;
      //la variabile l è stata definita precedentemente nel codice come   lunghezza	
      
    double risoluzione_l = 0.001; //espressa in metri -> equivale ad 1 millimetro
    double risoluzione_diviso_2 = risoluzione_l / 2;
    double radice_quadrata_di6 = sqrt(6);
    		
	//calcolo incertezza di l
    	incertezza_l = risoluzione_diviso_2 / radice_quadrata_di6;
    		
//--incertezza periodo
    double incertezza_periodo = 0;
    // la variabilr periodo è stata definita precedentemente nel codice come     periodo
	
    //input dell'incertezza del periodio
    
    ifstream file_in_incertezza_periodo;
    string valore_incertezza_periodo_str = "";
	
    	file_in_incertezza_periodo.open ("sem_pt.txt");
    	
    		//controllo paertura file
		if (file_in_incertezza_periodo.fail()){
		cout << "Errore nell'apertura del file di output" << endl; 
		}

	getline (file_in_incertezza_periodo, valore_incertezza_periodo_str);
	
	try {
	incertezza_periodo = stod(valore_incertezza_periodo_str);
	}
	catch (invalid_argument){
	cout << "Errore lettura valore" << endl;
	}
	
//calcolo dell'incertezza di g

//--definizione delle variabili

	double parametro_l = 0;
	double parametro_l_quadro = 0;
	
	double sotto_parametro_t = 0;	
	double parametro_t = 0;
	double parametro_t_quadro = 0;
	
	double radicando_incertezza_g = 0;
	double radice_incertezza_g = 0;
	
	parametro_l = incertezza_l / lunghezza;
	parametro_l_quadro = pow(parametro_l,2);
	
	sotto_parametro_t = incertezza_periodo / periodo;
	parametro_t = 2 * sotto_parametro_t;
	parametro_t_quadro = pow(parametro_t,2);

	radicando_incertezza_g = parametro_l_quadro + parametro_t_quadro;
	radice_incertezza_g = sqrt (radicando_incertezza_g);
	
//--calcolo incertezza su g

	incertezza_g = g_stima * radice_incertezza_g;


//file di output

//--definizione variabili	
	ofstream file_out_incertezza_l;
	ofstream file_out_incertezza_g;
	ofstream file_out_incertezza_g_parametri;
//-----------------------------------------------------------------------------------------------------------	
	file_out_incertezza_l.open("incertezza_lunghezza.txt");
		
		//controllo paertura file
		if (file_out_incertezza_l.fail()){
		cout << "Errore nell'apertura del file di output" << endl; 
		}
		
		file_out_incertezza_l << incertezza_l;
		
	file_out_incertezza_l.close();		
//-----------------------------------------------------------------------------------------------------------	
	file_out_incertezza_g.open("incertezza_g_pt.txt");
		
		//controllo paertura file
		if (file_out_incertezza_g.fail()){
		cout << "Errore nell'apertura del file di output" << endl; 
		}
		
		file_out_incertezza_g << incertezza_g;
		
	file_out_incertezza_g.close();
//------------------------------------------------------------------------------------------------------------
	file_out_incertezza_g_parametri.open("g_incertezza_pt_parametri.txt");
		
		//controllo paertura file
		if (file_out_incertezza_g_parametri.fail()){
		cout << "Errore nell'apertura del file di output" << endl; 
		}
		
		file_out_incertezza_g_parametri << "LUNGHEZZA" << endl;
		file_out_incertezza_g_parametri << "rislozione di l" << endl;
		file_out_incertezza_g_parametri << risoluzione_l << endl;
		file_out_incertezza_g_parametri << "risoluzione diviso 2" << endl;
		file_out_incertezza_g_parametri << risoluzione_diviso_2 << endl;
		file_out_incertezza_g_parametri << "valore della radice quadrata di 6" << endl;
		file_out_incertezza_g_parametri << radice_quadrata_di6 << endl << endl;
		file_out_incertezza_g_parametri << "VERIFICA CORRETTA ACCUISIZIONE DELL'INCERTEZZA SUL PERIODO" << endl;
		file_out_incertezza_g_parametri << incertezza_periodo << endl << endl;
		file_out_incertezza_g_parametri << "PARAMETRI NEL CALCOLO DELL'INGERTEZZA DI g" << endl;
		file_out_incertezza_g_parametri << "parametro incertezza di l diviso l" << endl;
		file_out_incertezza_g_parametri << parametro_l << endl;
		file_out_incertezza_g_parametri << "quadrato del numero sopra" << endl;
		file_out_incertezza_g_parametri << parametro_l_quadro << endl;
		file_out_incertezza_g_parametri << "valore incertezza periodo diviso il periodo" << endl;
		file_out_incertezza_g_parametri << sotto_parametro_t << endl;
		file_out_incertezza_g_parametri << "il numero sopra moltiplicato per 2" << endl;
		file_out_incertezza_g_parametri << parametro_t << endl;
		file_out_incertezza_g_parametri << "il numero sopra al quadrato" << endl;
		file_out_incertezza_g_parametri << parametro_t_quadro << endl;
		file_out_incertezza_g_parametri << "valore del radicando" << endl;
		file_out_incertezza_g_parametri << radicando_incertezza_g << endl;
		file_out_incertezza_g_parametri << "valore della radice quadrata del radicando" << endl;
		file_out_incertezza_g_parametri << radice_incertezza_g << endl;
		
	file_out_incertezza_g_parametri.close();
//------------------------------------------------------------------------------------------------------------


---------*/
	
	return 0;
}
