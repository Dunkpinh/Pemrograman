#include<iostream>
using namespace std;

// Fungsi faktorial iteratif
int faktorialIteratif(int n) {
	int hasil = 1;
	for (int i = 1; i <= n; i++) {
		hasil *= i;
	}
	return hasil;
}

// Fungsi faktorial rekursif (dari kegiatan 1)
int faktorialRekursif(int n) {
	if (n <= 1) return 1;
	return n * faktorialRekursif(n - 1);
}

int main() {
	int angka;
	cout << "Masukkan angka untuk faktorial: ";
	cin >> angka;
	cout << "Faktorial (Iteratif) dari " << angka << " adalah " <<	
	faktorialIteratif(angka) << endl;
	cout << "Faktorial (Rekursif) dari " << angka << " adalah " <<
	faktorialRekursif(angka) << endl;
	return 0;
}
