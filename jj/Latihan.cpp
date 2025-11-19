#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

struct Karyawan{
    string nama, nik, jabatan;
    int umur;
};

void print(vector<Karyawan>& k){
    for (int i = 0; i < k.size(); i++) {
        cout << "Karyawan " << i + 1 << endl;
        cout << "Nama: " << k[i].nama << endl;
        cout << "Umur: " << k[i].umur << endl;
        cout << "NIK: " << k[i].nik << endl;
        cout << "Jabatan: " << k[i].jabatan << endl;
        cout << endl;
    }
}
void tambah(vector<Karyawan>& k){
    cout << "Masukkan data karyawan baru: (nama) (umur) (nik) (jabatan)" << endl;
    Karyawan k_input;
	cin >> k_input.nama >> k_input.umur >> k_input.nik >> k_input.jabatan;
    k.push_back(k_input);
}

void edit(vector<Karyawan>& k){
    cout << "Masukkan nik karyawan yang ingin diedit: ";
    string nik_edit;
    cin >> nik_edit;
    int count = 0;
    while(count < k.size() && k.at(count).nik != nik_edit){
        count++;
    }

    if(count == k.size()) {
        cout << "Karyawan dengan NIK tersebut tidak ditemukan" << endl;
        return;
    }

    cout << "Masukkan data baru karyawan: (nama) (umur) (nik) (jabatan)" << endl;
    Karyawan k_input;
	cin >> k_input.nama >> k_input.umur >> k_input.nik >> k_input.jabatan;
    k.at(count) = k_input;
}

void hapus(vector<Karyawan>& k){
    cout << "Masukkan nik karyawan yang ingin dihapus: ";
    string nik_edit;
    cin >> nik_edit;
    int count = 0;
    while(count < k.size() && k.at(count).nik != nik_edit){
        count++;
    }

    if(count == k.size()) {
        cout << "Karyawan dengan NIK tersebut tidak ditemukan" << endl;
        return;
    }

    k.erase(k.begin() + count);
}

int main(){
    vector<Karyawan> k;
    Karyawan k_input;
	ifstream inputFile("karyawan.txt");
	if (!inputFile) {
        cerr << "Tidak dapat membuka file!" << endl;
        return 1;
	}
	string line;
	while (getline(inputFile, line)) {
        stringstream ss(line);
        ss >> k_input.nama >> k_input.umur >> k_input.nik >> k_input.jabatan;
        k.push_back(k_input);
	}
    inputFile.close();
    
    cout << endl;
    cout << "1. Menampilkan semua data karyawan" << endl << "2. Menambahkan karyawan baru" << endl << "3. Mengedit data karyawan berdasarkan NIK" << endl << "4. Menghapus karyawan berdasarkan NIK" << endl << "5. Selesai" << endl << endl;
	int n;
	do{
		cout << "Pilih: ";
		cin >> n;
		
		switch(n){
			case 1:print(k); break;
			case 2:tambah(k); break;
			case 3:edit(k); break;
			case 4:hapus(k); break;
			case 5:break;
            default:cout << "Pilih 1-5!" << endl; break;
		}
		cout << endl;
	}while(n != 5);
}