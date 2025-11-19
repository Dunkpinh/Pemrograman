#include <iostream>
using namespace std;

// Quick Sort
void quick_sort(int data[], int first, int last) {
    int a = first, b = last;
    int pivot = data[(first + last) / 2]; 
    do {
        while (data[a] < pivot) a++;
        while (data[b] > pivot) b--;

        if (a <= b) {
            swap(data[a], data[b]);
            a++;
            b--;
        }
    } while (a < b);
    if (first < b) quick_sort(data, first, b);
    if (a < last) quick_sort(data, a, last);
}

double medianVal(int data[], int n){
	int medianIdx = n / 2;
    if (n % 2 == 1) {
        return data[medianIdx];
    } else {
        return (data[medianIdx - 1] + data[medianIdx]) / 2.0;
    }
}

void isiArray(int data[], int size) {
    for (int i = 0; i < size; i++) {
        cin >> data[i];
    }
}

void printArray(int data[], int size) {
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) cout << ", ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int data[n];
    isiArray(data, n);
    quick_sort(data, 0, n - 1);
    printArray(data, n);
    double median = medianVal(data, n);
    cout << median << endl;
}