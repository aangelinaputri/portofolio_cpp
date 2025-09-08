#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>

using namespace std;

void daftarbuku()
{
	string *judulBuku = new string[10] {"Pergi", "Pulang", "Bulan", "Bintang", "Matahari", "Nebula", "Pulang Pergi", "Rindu", "Hujan", "Alvaska"};
    int *jumlahBuku = new int[10] {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int *bukuKeluar = new int[10] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    string *kode = new string[10] {"0001", "0002", "0003", "0004", "0005", "0006", "0007", "0008", "0009", "0010"};

    cout << "\n" << endl;
    cout << "\t\t\tDaftar Buku" << endl;
    cout << "\t\t\t___________\n" << endl;
    cout << "------------------------------------------------------------------\n";
    cout << " No  Kode Buku     Judul Buku    Jumlah Buku     Buku Keluar\n";
    cout << "------------------------------------------------------------------\n";

    for (int i = 0; i < 10; i++) 
	{
        cout << " " << i + 1 << "\t" << kode[i] << "\t   " << judulBuku[i] << "\t\t" << jumlahBuku[i] << "\t\t " << bukuKeluar[i] << "     \n";
    }
}

void Pinjam(string &npinjam, string &apinjam, string &rpinjam, char &jbuku, int &i, int &x) 
{
    cout << "\t\t\t\t Transaksi Peminjaman : \n";
    cout << "\t\t\t _______________________________________________\n\n";
    cout << "Masukkan nama \t: "; cin >> npinjam;
    cout << "Masukkan NIM \t: "; cin >> apinjam;
    cout << "Berapa banyak yang ingin dipinjam? Lebih dari satu (Y/T) : "; cin >> jbuku;

    string bpinjam[100];
    if (jbuku == 'Y' || jbuku == 'y') 
	{
        cout << "Masukkan jumlah buku : "; cin >> i;
        for (x = 0; x < i; x++) 
		{
            cout << "Judul buku yang dipinjam : "; cin >> bpinjam[x];
        }
    } 
	else if (jbuku == 'T' || jbuku == 't') 
	{
        cout << "Judul buku yang dipinjam : "; cin >> bpinjam[0];
        i = 1;
    }

    cout << "Peminjaman Berhasil!!" << endl;
    cout << "riwayat/selesai : "; cin >> rpinjam;
    cout << "========================================================================================================================" << endl;

    if (rpinjam == "riwayat") 
	{
        system("cls");
        cout << "\t\t\t Riwayat Peminjaman" << endl;
        cout << "\t\t\t __________________\n" << endl;
        cout << "------------------------------------------------------------------\n";
        cout << "No\t Nama Peminjam\t\t NIM\t Judul Buku\t   \n";
        cout << "------------------------------------------------------------------\n";
        for (int k = 0; k < i; k++) 
		{
            cout << k + 1 << "\t" << npinjam << "\t" << apinjam << "\t" << bpinjam[k] << endl;
        }
    } 
	else 
	{
        cout << "Silahkan kembalikan buku paling lambat satu minggu setelah dipinjam " << endl;
    }
}

void Kembalikan(string &npinjam, string &apinjam, string &kembali, string &rpinjam, char &jbuku, int &i, int &x) 
{
    cout << "\t\t\t\t Transaksi Pengembalian : \n";
    cout << "\t\t\t\t____________________\n" << endl;
    cout << "Masukkan nama\t : "; cin >> npinjam;
    cout << "Masukkan NIM\t : "; cin >> apinjam;
    cout << "Berapa banyak yang ingin dikembalikan? Lebih dari satu (Y/T) : "; cin >> jbuku;

    string bpinjam[100];

    if (jbuku == 'Y' || jbuku == 'y') 
	{
        cout << "Masukkan jumlah buku : "; cin >> i;
        for (x = 0; x < i; x++) 
		{
            cout << "Judul buku yang ingin dikembalikan: "; cin >> bpinjam[x];
        }
    } 
	else if (jbuku == 'T' || jbuku == 't') 
	{
        cout << "Judul buku yang dikembalikan: "; cin >> bpinjam[0];
        i = 1;
    }

    cout << "Apakah Anda ingin mengembalikan buku tersebut? Ya (Y/T) : "; cin >> kembali;
    if (kembali == "Y" || kembali == "y") 
	{
        cout << "Berhasil!!" << endl;
    }

    cout << "Lihat riwayat/selesai : "; cin >> rpinjam;
    if (rpinjam == "selesai") 
	{
        cout << "Silahkan kembali lagi" << endl;
    } 
	else if (rpinjam == "riwayat") 
	{
        system("cls");
        cout << "\t\t\tRiwayat Pengembalian" << endl;
        cout << "\t\t\t__________________\n" << endl;
        cout << "------------------------------------------------------------------\n";
        cout << " No  Nama Peminjam\t NIM\t  Judul Buku\t Ket  \n";
        cout << "------------------------------------------------------------------\n";
        for (int k = 0; k < i; k++) 
		{
            cout << k + 1 << "\t  " << npinjam << "\t\t" << apinjam << "\t\t" << bpinjam[k] << "\tdikembalikan" << endl;
        }
    }
}

void cari(string &pencarian) 
{
    cout << "========================================================================================================================" << endl;
    cout << "Ketikkan judul/keyword yang ingin Anda cari: "; cin >> pencarian;

    if (pencarian == "pulang" || pencarian == "pulang pergi" || pencarian == "pergi" || pencarian == "hujan") 
	{
        cout << "Berada di rak 19A" << endl;
    } 
	else if (pencarian == "bumi" || pencarian == "nebula" || pencarian == "bulan" || pencarian == "matahari" || pencarian == "bintang") 
	{
        cout << "Berada di rak 19B" << endl;
    } 
	else if (pencarian == "rindu") 
	{
        cout << "Berada di rak 19A" << endl;
    } 
	else if (pencarian == "alvaska") 
	{
        cout << "Berada di rak 23A" << endl;
    } 
	else 
	{
        cout << "Belum tersedia" << endl;
    }
}

int main() 
{
	int x, i;
	string kondisi, npinjam, apinjam, kembali, rpinjam, judulBuku, jumlahBuku, bukuKeluar, kode, pencarian, menu;
	char jbuku, ch;
	
    login:
    string user = "";
    string pass = "";
    cout << "\n\n\n\n\n\n\n\n";
    cout << "\t\t ------- Program Aplikasi Sederhana Perpustakaan --------\n\n";
    cout << "\t\t\t  Username : "; cin >> user;
    cout << "\t\t\t  Password : ";
    ch = _getch();

    while (ch != 13) 
	{
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    cout << endl;

    system("pause");
    system("cls");
    goto menu;

    menu:
    cout << "========================================================================================================================" << endl;
    cout << "                                  Selamat Datang di Perpustakaan Amikom                                                          " << endl;
    cout << "========================================================================================================================" << endl;

    cout << "-------- Menu ----------\n";
    cout << " 1. Daftar Buku       \n";
    cout << " 2. Peminjaman      \n";
    cout << " 3. Pengembalian    \n";
    cout << " 4. Cari   \n";
    cout << " 5. Exit                \n";
    cout << "----------------------\n";
    cout << "Masukan Pilihan anda[ 1 s.d. 5 ] = "; cin >> kondisi;
    system("cls");

    if (kondisi == "1") 
	{
        daftarbuku();
        system("pause");
        system("cls");
        goto menu;
    }

    if (kondisi == "2") 
	{
        Pinjam(npinjam, apinjam, rpinjam, jbuku, i,x);
        system("pause");
        system("cls");
        goto menu;
    }

    if (kondisi == "3") 
	{
        Kembalikan(npinjam, apinjam, kembali, rpinjam, jbuku, i, x);
        system("pause");
        system("cls");
        goto menu;
    }

    if (kondisi == "4") 
	{
        cari(pencarian);
        system("pause");
        system("cls");
        goto menu;
    }

    if (kondisi == "5") 
	{
        cout << "-- Anda Telah Logout -- \n";
        cout << "-- Program Aplikasi Perpustakaan Sederhana  --\n";
        system("pause");
        system("cls");
        goto login;
    }

    return 0;
}

