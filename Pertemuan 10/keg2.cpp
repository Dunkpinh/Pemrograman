#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;


int cari_biner(int data[], int s, int cari) {
	int a, b, t, langkah;
	bool ketemu;

	a = 0; b = s - 1;
	langkah = 0;
	ketemu = false;
	do {
		t = (a + b) / 2;
		if (data[t] == cari) {
			ketemu = true;
		} else {
			if (data[t] > cari) {
				b = t - 1;
			} else {
				a = t + 1;
			}
		}
		langkah++;
	} while ((a <= b) && !(ketemu));

	return ketemu ? langkah : -1 * langkah;
}

void array_merge(int data[], int first, int mid, int last) {
	int n1 = mid - first + 1;
	int n2 = last - mid;

	int tmp_left[n1], tmp_right[n2];

	for (int i = 0; i < n1; i++)
	tmp_left[i] = data[first + i];
	for (int i = 0; i < n2; i++)
	tmp_right[i] = data[mid + 1 + i];

	int i = 0;
	int j = 0;
	int k = first;
	while (i < n1 && j < n2) {
		if (tmp_left[i] <= tmp_right[j]) {
			data[k] = tmp_left[i];
			i++;
		} else {
			data[k] = tmp_right[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		data[k] = tmp_left[i];
		i++;
		k++;
	}

	while (j < n2) {
		data[k] = tmp_right[j];
		j++;
		k++;
	}
}

void merge_sort(int data[], int first, int last) {
	if (first < last) {
		// indeks tengah larik
		int mid = (first + last) / 2;

		// sublarik kiri
		merge_sort(data, first, mid);
		// sublarik kanan
		merge_sort(data, mid + 1, last);

		// gabung sublarik kiri dan kanan sambil diurutkan
		array_merge(data, first, mid, last);
	}
}

void randomArray(int data[], int size, int minValue, int maxValue){
	srand(time(0));
	for(int i = 0; i < size ; i++){
		data[i] = minValue + rand() % (maxValue - minValue + 1);
	}
}

void printArray(int data[], int size){
	for(int i = 0; i < size; i++){
		cout << setw(5) << data[i];
	}
	cout << endl << endl;
}

void isiArray(int data[], int size){
	for(int i = 0; i < size; i++){
		cout << "Masukkan cari ke-" << i+1 <<": ";
		cin >> data[i];
	}
}

void cari_biner_array(int data[], int s, int idxData[], int sidx, int cari[]){
	for(int i = 0; i < sidx; i++){
		idxData[i] = cari_biner(data, 1000, cari[i]);
	}
}

int main(){
	int data[1000];
	int cari[10];
	randomArray(data, 1000, 0, 1000);
	printArray(data, 1000);
	merge_sort(data, 0, 1000);
	printArray(data, 1000);
	isiArray(cari, 10);
	int idxData[10];
	cari_biner_array(data, 1000, idxData, 10, cari);
	printArray(idxData, 10);
}
