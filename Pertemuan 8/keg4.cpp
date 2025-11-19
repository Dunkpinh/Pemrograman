#include <iostream>
using namespace std;

int pangkat(int x, int y){
	if(y == 0) return 1;
	return x * pangkat(x, y-1);
}

int main(){
	int x, y;
	cout << "Basis: ";
	cin >> x;
	cout << "Eksponen: ";
	cin >> y;
	int n = pangkat(x, y);
	cout << x << "^" << y << " = " << n;	
}
