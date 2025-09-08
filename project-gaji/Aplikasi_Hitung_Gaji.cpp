#include <iostream>
#include <string>
using namespace std;

int main(){
	struct data_pekerja {
	string nama;
	int no_identitas;
	int jam_kerja[5];
	};
	data_pekerja pekerja;
	int total=0, gajiUtuh=0, gaji, lembur=0;
	int gaji_per_jam = 5000;
	cout<<"Angelina Putri Ariani 23.12.2907"<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"Masukkan nama Anda : "; cin>>pekerja.nama;
	cout<<"Masukkan Nomor Identitas : ";cin>>pekerja.no_identitas;
	cout<<"=============================="<<endl;
	cout<<"INPUT JAM KERJA (SENIN - JUMAT)"<<endl;
	cout<<"=============================="<<endl;
	for (int i=0;i<5;i++){
		cout<<"Jam kerja pada hari ke-"<<i+1<<" :"; cin>>pekerja.jam_kerja[i];
		total += pekerja.jam_kerja[i];
		if (pekerja.jam_kerja[i]>7){
			int JamKer = (pekerja.jam_kerja[i] - 7);
			lembur += JamKer * gaji_per_jam * 15;
			gajiUtuh += 7*gaji_per_jam;
		} else {
			gajiUtuh += pekerja.jam_kerja[i] * gaji_per_jam;
		}
	}
	cout<<"Total Jam Kerja Anda (Senin - Jumat) : "<<total<<endl;
	
	gaji = gajiUtuh + lembur;
	cout<<"Gaji yang didapatkan : "<<gaji;
}


