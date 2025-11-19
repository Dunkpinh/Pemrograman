#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Fungsi untuk mencetak isi array
void printArray(int data[], int size) {
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) cout << ", ";
    }
    cout << endl;
}

// Fungsi untuk mengisi array secara manual
void isiArray(int data[], int size) {
    for (int i = 0; i < size; i++) {
        cin >> data[i];
    }
}

// Fungsi untuk mengisi array dengan angka acak
void randomArray(int data[], int size, int minValue, int maxValue) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        data[i] = minValue + rand() % (maxValue - minValue + 1);
    }
}

// Fungsi merge untuk menggabungkan dua bagian array
void merge(int data[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = data[left + i];
    for (int j = 0; j < n2; j++) R[j] = data[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            data[k++] = L[i++];
        } else {
            data[k++] = R[j++];
        }
    }

    while (i < n1) data[k++] = L[i++];
    while (j < n2) data[k++] = R[j++];

    delete[] L;
    delete[] R;
}

// Fungsi rekursif merge sort
void mergeSort(int data[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(data, left, mid);
        mergeSort(data, mid + 1, right);
        merge(data, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;

    int data[n];
    isiArray(data, n);
    cout << endl;

    mergeSort(data, 0, n - 1);
    printArray(data, n);
}