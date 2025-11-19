#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int* bacaData(const string& filename, int& n) {
    ifstream file(filename);
    vector<int> temp;
    int x;

    while (file >> x) {
        temp.push_back(x);
    }

    n = temp.size();
    int* arr = new int[n]; 
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    return arr;
}

int maksimumRekursif(int arr[], int n) {
    if (n == 1) return arr[0];
    int maxSubarray = maksimumRekursif(arr, n - 1);
    return (arr[n - 1] > maxSubarray) ? arr[n - 1] : maxSubarray;
}

int main() {
    int n;
    int* arr = bacaData("angka_input.txt", n);

    cout << "Nilai maksimum dalam array: " << maksimumRekursif(arr, n) << endl;
    return 0;
}