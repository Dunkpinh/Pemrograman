#include <iostream>
using namespace std;

void ketLulus(int rerata){
	if(rerata >= 70){
		cout << "Status: LULUS";
	}else{
		cout << "Status: TIDAK LULUS";
	}
}

void input(int a[], int length){
	for(int i = 0; i < length; i++){
		cout << "Nilai ke-" << i+1 << ": ";
		cin >> a[i];
	}
}

double rerata(int nilai[], int length){
	int jumlah = 0;
	for(int i = 0; i < length; i++){
		jumlah += nilai[i];
	}
	return jumlah/length;
}
int main(){
	cout << "Masukkan jumlah nilai: ";
	int jdata;
	cin >> jdata;
	int dataNilai[jdata];
	input(dataNilai, jdata);
	double mean = rerata(dataNilai, jdata);
	cout << "Rata-rata: " << mean << endl;
	ketLulus(mean);
	return 0;
}
