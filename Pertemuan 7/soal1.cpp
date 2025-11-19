#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

double ctf(double c){ // ctf : celcius to fahrenheit
	return c * 9 / 5 + 32;
}

double ctk(double c){ // ctk : celcius to kelvin
	return c + 273.15;
}

void inputc(double c[], int length){ // input celcius
	for(int i = 0; i < length; i++){
		cout << "Masukkan  data suhu ke-" << i+1 << "(celcius): ";
		cin >> c[i];
	}
}

void convertctf(double c[], double f[], int length){ // konversi c ke f, lalu diassign ke array f
	for(int i = 0; i < length; i++){
		f[i] = ctf(c[i]);
	}
}

void convertctk(double c[], double k[], int length){ // konversi c ke k, lalu diassign ke array k
	for(int i = 0; i < length; i++){
		k[i] = ctk(c[i]);
	}
	cout << endl;
}

void print(double c[], double f[], double k[], int length){ // print dengan format
	stringstream ss;
    ss << right << setw(15) << "Celcius" << setw(15) << "Fahrenheit" << setw(15) << "Kelvin";
    string sline = ss.str();
	int p = sline.size();
	cout << sline << endl;
	cout << string(p, '-') << endl;
	for(int i = 0; i < length; i++){
		cout << right << setw(15) << c[i] << setw(15) << f[i] << setw(15) << k[i] << endl;
	}
}

int main (){
	int j; // j : jumlah data
	cout << "Masukkan jumlah data suhu: ";
	cin >> j;
	double c[j];
	double f[j];
	double k[j];
	inputc(c, j);
	convertctf(c, f, j);
	convertctk(c, k, j);
	print(c, f, k, j);
}
