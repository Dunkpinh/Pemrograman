#include <iostream>
using namespace std;

// Memisahkan bilangan ganjil ke depan array, mengembalikan indeks batas akhir ganjil
int pisahkanGanjil(int data[], int first, int last) {
    int i = first;
    for (int j = first; j < last; j++) {
        if (data[j] % 2 != 0) {
            swap(data[j], data[i]);
            i++;
        }
    }
    return i;
}

// Insertion sort menaik (ascending)
void insertionSortNaik(int data[], int low, int high) {
    for (int i = low + 1; i < high; i++) {
        int key = data[i];
        int j = i - 1;
        while (j >= low && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

// Insertion sort menurun (descending)
void insertionSortTurun(int data[], int low, int high) {
    for (int i = low + 1; i < high; i++) {
        int key = data[i];
        int j = i - 1;
        while (j >= low && data[j] < key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

// Mengisi array dengan input manual
void isiArray(int data[], int size) {
    for (int i = 0; i < size; i++) {
        cin >> data[i];
    }
}

// Menampilkan isi array dari indeks low ke high
void printArray(int data[], int low, int high) {
    for (int i = low; i < high; i++) {
        cout << data[i];
        if (i < high - 1) cout << ", ";
    }
}

int main() {
    int n;
    cin >> n;

    int data[n];
    isiArray(data, n);
    cout << endl;

    // Pisahkan ganjil dan genap, lalu urutkan masing-masing
    int batasGanjil = pisahkanGanjil(data, 0, n);
    insertionSortNaik(data, 0, batasGanjil);
    insertionSortTurun(data, batasGanjil, n);

    // Tampilkan hasil
    printArray(data, 0, batasGanjil);
    cout << " | ";
    printArray(data, batasGanjil, n);
}