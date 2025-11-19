#include <iostream>
using namespace std;

int totalHadir = 0;

void ubahTotalHadir(int mhs){
	totalHadir += mhs;
}

void rasio(int totalPertemuan){
	cout << "Total kehadiran kelas: " << totalHadir << " dari " << totalPertemuan << endl;
}

void persen(int totalPertemuan){
	cout << "Persentase kehadiran: " << (double)totalHadir / totalPertemuan * 100 << "%" << endl;
}

void isi(int mhs[], int jmhs){
	for(int i = 0; i < jmhs; i++){
		cout << "Kehadiran mahasiswa ke-" << i+1 << ": ";
		cin >> mhs[i];
		ubahTotalHadir(mhs[i]);
	}
}
int main(){
	int jmhs, totalPertemuan;
	cout << "Masukkan jumlah mahasiswa: ";
	cin >> jmhs;
	cout << "Masukkan total pertemuan: ";
	cin >> totalPertemuan;
	totalPertemuan *= jmhs;
	int mhs[jmhs];
	isi(mhs, jmhs);
	rasio(totalPertemuan);
	persen(totalPertemuan);
}
