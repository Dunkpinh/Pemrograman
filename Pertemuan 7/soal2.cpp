#include <iostream>
using namespace std;

void tukarPassByValue(int a, int b){
	int temp = a;
	a = b;
	b = temp;
}

void tukarPassByReference(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main(){
	int a, b;
	cout << "Masukkan bilangan pertama: ";
	cin >> a;
	cout << "Masukkan bilangan kedua: ";
	cin >> b;
	cout << endl;
	cout << "Sebelum ditukar: " << "a = " << a << ", b = " << b << endl;
	tukarPassByValue(a, b);
	cout << "Setelah ditukar by value: " << "a = " << a << ", b = " << b << endl;
	tukarPassByReference(a, b);
	cout << "Seletah ditukar by reference: " << "a = " << a << ", b = " << b << endl;
}
