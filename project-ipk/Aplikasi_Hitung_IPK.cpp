#include<iostream>
#include <string>
using namespace std;

int main(){
	struct siswa{
		int nim;
		string nama;
		int sks[20];
		int matkul;
		float nilai;
		char nilaihuruf[10];	
	};
	siswa murid;
	float total_nilai =0;
	int total_sks=0;
	cout<<"Angelina Putri Ariani 23.12.2907"<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"Masukkan NIM (4 digit terakhir) : ";cin>>murid.nim;
	cout<<"Masukkan Nama : ";cin>>murid.nama;
	cout<<"Masukkan banyak mata kuliah : ";cin>>murid.matkul;
	for(int i=0;i<murid.matkul;i++){
		cout<<"Masukkan Jumlah SKS Mata Kuliah "<<i+1<<" : ";cin>>murid.sks[i];
		cout<<"Masukkan Nilai Mata Kuliah : ";cin>>murid.nilai;
		if (murid.nilai>=81&&murid.nilai<=100){
			murid.nilai=4;
			murid.nilaihuruf[i]='A';
		}else if(murid.nilai<81&&murid.nilai>=61){
			murid.nilai=3;
			murid.nilaihuruf[i]='B';
		}else if(murid.nilai<61&&murid.nilai>=41){
			murid.nilai=2;
			murid.nilaihuruf[i]='C';
		}else if(murid.nilai<41&&murid.nilai>=21){
			murid.nilai=1;
			murid.nilaihuruf[i]='D';
		}else {
			murid.nilai=0;
			murid.nilaihuruf[i]='E';
		}
		total_nilai+=murid.nilai * murid.sks[i];
		total_sks+= murid.sks[i];
	}
	float ipk = total_nilai / total_sks;
	cout<<"-------------------------------------"<<endl;
	cout<<"\tData Mahasiswa"<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"Nama : "<<murid.nama<<endl;;
	cout<<"NIM : "<<murid.nim<<endl;;
	cout<<"Jumlah Mata Kuliah : "<<murid.matkul<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"\tPerolehan Nilai Huruf"<<endl;
	cout<<"-------------------------------------"<<endl;
	for(int i=0;i<murid.matkul;i++){
		cout << "Mata Kuliah " << i + 1 << " (SKS: " << murid.sks[i]<< ") : " << murid.nilaihuruf[i] << endl;
	}
	cout<<"-------------------------------------"<<endl;
	cout<<"Indeks Prestasi Kumulatif : "<<ipk<<endl;
}
