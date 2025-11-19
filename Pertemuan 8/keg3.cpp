#include <iostream>
using namespace std;

int fibbonaci(int n){
	if(n == 0 || n == 1) return n;
	return fibbonaci(n-1) + fibbonaci(n-2); 
}

int main(){
	int m;
	cout << "Angka: ";
	cin >> m;
	int n = fibbonaci(m);
	cout << "Fibbonaci: " << n;	
}
