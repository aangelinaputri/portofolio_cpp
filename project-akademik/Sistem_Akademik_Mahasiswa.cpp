#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <conio.h>

using namespace std;

void tampilkanGaris(int panjang = 50, char karakter = '=') {
    for (int i = 0; i < panjang; i++) {
        cout << karakter;
    }
    cout << endl;
}

struct Mahasiswa {
    int id;
    string nama;
    float nilai[10];
    int jumlahNilai;
};

struct Stack {
    Mahasiswa data[100];
    int top = -1;

    void push(const Mahasiswa& mhs) {
        if (top < 99) {
            data[++top] = mhs;
        } else {
            cout << "Stack penuh, tidak dapat menambahkan data baru.\n";
        }
    }

    Mahasiswa pop() {
        if (top >= 0) {
            return data[top--];
        } else {
            cout << "Stack kosong.\n";
            return Mahasiswa{};
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

struct Queue {
    Mahasiswa data[100];
    int front = 0, rear = -1, size = 0;

    void enqueue(const Mahasiswa& mhs) {
        if (size < 100) {
            rear = (rear + 1) % 100;
            data[rear] = mhs;
            size++;
        } else {
            cout << "Queue penuh, tidak dapat menambahkan data baru.\n";
        }
    }

    Mahasiswa dequeue() {
        if (size > 0) {
            Mahasiswa mhs = data[front];
            front = (front + 1) % 100;
            size--;
            return mhs;
        } else {
            cout << "Queue kosong.\n";
            return Mahasiswa{};
        }
    }

    bool isEmpty() {
        return size == 0;
    }
};

void tampilkanMenu() {
    tampilkanGaris(50, '=');
    cout << setw(30) << "=== Sistem Akademik ===" << endl;
    tampilkanGaris(50, '-');
    cout << setw(5) << "1." << " Tambah Mahasiswa\n";
    cout << setw(5) << "2." << " Input Nilai Mahasiswa\n";
    cout << setw(5) << "3." << " Tampilkan Data Mahasiswa\n";
    cout << setw(5) << "4." << " Urutkan dan Tampilkan Mahasiswa (Berdasarkan ID)\n";
    cout << setw(5) << "5." << " Cari Mahasiswa Berdasarkan Nama\n";
    cout << setw(5) << "6." << " Hapus Data Mahasiswa Berdasarkan ID\n";
    cout << setw(5) << "7." << " Tampilkan Riwayat Penambahan Mahasiswa\n";
    cout << setw(5) << "8." << " Proses Antrean Mahasiswa\n";
    cout << setw(5) << "9." << " Keluar\n";
    tampilkanGaris(50, '-');
    cout << "Pilih opsi: ";
}

void tampilkanData(Mahasiswa* daftarMahasiswa, int jumlah) {
    if (jumlah == 0) {
        cout << "Belum ada data mahasiswa.\n";
        return;
    }

    tampilkanGaris(50, '=');
    cout << "| " << setw(5) << "ID" << " | " << setw(20) << "Nama Mahasiswa"
         << " | " << setw(5) << "Nilai" <<setw(5)<<" | " << endl;
    tampilkanGaris(50, '-');

    for (int i = 0; i < jumlah; i++) {
        cout << "| " << setw(5) << daftarMahasiswa[i].id << " | " << setw(20) << daftarMahasiswa[i].nama << " | ";
        for (int j = 0; j < daftarMahasiswa[i].jumlahNilai; j++) {
            cout << daftarMahasiswa[i].nilai[j];
            if (j < daftarMahasiswa[i].jumlahNilai - 1) cout << ", ";
        }
        cout << " |" << endl;
    }
    tampilkanGaris(50, '=');
}

void urutkanMahasiswa(Mahasiswa* daftarMahasiswa, int jumlah) {
    for (int i = 1; i < jumlah; i++) { 
        for (int j = jumlah - 1; j >= i; j--) { 
            if (daftarMahasiswa[j].id < daftarMahasiswa[j - 1].id) {
                Mahasiswa temp = daftarMahasiswa[j];
                daftarMahasiswa[j] = daftarMahasiswa[j - 1];
                daftarMahasiswa[j - 1] = temp;
            }
        }
    }
    cout << "Data mahasiswa berhasil diurutkan berdasarkan ID.\n";
}

void cariMahasiswaByNama(Mahasiswa* daftarMahasiswa, int jumlah, const string& nama) {
    bool ditemukan = false;
    for (int i = 0; i < jumlah; i++) {
        if (daftarMahasiswa[i].nama.find(nama) != string::npos) {
            cout << "ID: " << daftarMahasiswa[i].id
                 << ", Nama: " << daftarMahasiswa[i].nama << "\n";
            ditemukan = true;
        }
    }
    if (!ditemukan) {
        cout << "Mahasiswa dengan nama '" << nama << "' tidak ditemukan.\n";
    }
}

void hapusMahasiswa(Mahasiswa* daftarMahasiswa, int& jumlah, int id) {
    int index = -1;
    for (int i = 0; i < jumlah; i++) {
        if (daftarMahasiswa[i].id == id) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < jumlah - 1; i++) {
            daftarMahasiswa[i] = daftarMahasiswa[i + 1];
        }
        jumlah--;
        cout << "Mahasiswa dengan ID " << id << " berhasil dihapus.\n";
    } else {
        cout << "Mahasiswa dengan ID tersebut tidak ditemukan.\n";
    }
}

int main() {
    Mahasiswa daftarMahasiswa[100];
    Stack stackRiwayat;
    Queue queueProses;
    int jumlahMahasiswa = 0;
    int pilihan;
    char ch;

login:
    string user = "", pass = "";
    cout << "\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t ---------- Sistem Akademik Mahasiswa --------\n\n";
    cout << "\t\t\t\tSilahkan login dengan username dan password Anda!\n";
    cout << "\t\t\t\tUsername : "; cin >> user;
    cout << "\t\t\t\tPassword : ";
    ch = _getch(); 

    while (ch != 13) { 
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    cout << endl;

    if (user != "admin" || pass != "admin") {
        cout << "Username atau password salah. Silakan coba lagi.\n";
        system("pause");
        system("cls");
        goto login;
    }

    system("pause");
    system("cls");

menu:
    do {
        tampilkanMenu();
        cin >> pilihan;
        switch (pilihan) {
            case 1: {
                if (jumlahMahasiswa < 100) {
                    Mahasiswa mhs;
                    cout << "Masukkan ID Mahasiswa: ";
                    cin >> mhs.id;
                    cin.ignore();
                    cout << "Masukkan Nama Mahasiswa: ";
                    getline(cin, mhs.nama);
                    mhs.jumlahNilai = 0;
                    daftarMahasiswa[jumlahMahasiswa++] = mhs;
                    stackRiwayat.push(mhs);
                    queueProses.enqueue(mhs);
                    cout << "Mahasiswa berhasil ditambahkan.\n";
                } else {
                    cout << "Kapasitas penuh.\n";
                }
                system("pause");
                system("cls");
                break;
            }
            case 2: {
                cout << "Masukkan ID Mahasiswa: ";
                int id;
                cin >> id;

                int index = -1;
                for (int i = 0; i < jumlahMahasiswa; i++) {
                    if (daftarMahasiswa[i].id == id) {
                        index = i;
                        break;
                    }
                }

                if (index != -1) {
                    Mahasiswa& mhs = daftarMahasiswa[index];
                    cout << "Masukkan nilai (maksimum 10 nilai, ketik -1 untuk selesai): ";
                    float nilai;
                    while (mhs.jumlahNilai < 10 && cin >> nilai && nilai != -1) {
                        mhs.nilai[mhs.jumlahNilai++] = nilai;
                    }
                    cout << "Nilai berhasil ditambahkan.\n";
                } else {
                    cout << "Mahasiswa dengan ID tersebut tidak ditemukan.\n";
                }
                system("pause");
                system("cls");
                break;
            }
            case 3:
                tampilkanData(daftarMahasiswa, jumlahMahasiswa);
                system("pause");
                system("cls");
                break;

            case 4:
                urutkanMahasiswa(daftarMahasiswa, jumlahMahasiswa);
                tampilkanData(daftarMahasiswa, jumlahMahasiswa);
                system("pause");
                system("cls");
                break;

            case 5: {
                cout << "Masukkan nama mahasiswa yang ingin dicari: ";
                cin.ignore();
                string nama;
                getline(cin, nama);
                cariMahasiswaByNama(daftarMahasiswa, jumlahMahasiswa, nama);
                system("pause");
                system("cls");
                break;
            }
            case 6: {
                cout << "Masukkan ID Mahasiswa yang ingin dihapus: ";
                int id;
                cin >> id;
                hapusMahasiswa(daftarMahasiswa, jumlahMahasiswa, id);
                system("pause");
                system("cls");
                break;
            }
            case 7: {
                cout << "\nRiwayat Penambahan Mahasiswa :\n";
                while (!stackRiwayat.isEmpty()) {
                    Mahasiswa mhs = stackRiwayat.pop();
                    cout << "ID: " << mhs.id << ", Nama: " << mhs.nama << "\n";
                }
                system("pause");
                system("cls");
                break;
            }
            case 8: {
                cout << "\nProses Antrean Mahasiswa :\n";
                while (!queueProses.isEmpty()) {
                    Mahasiswa mhs = queueProses.dequeue();
                    cout << "ID: " << mhs.id << ", Nama: " << mhs.nama << "\n";
                }
                system("pause");
                system("cls");
                break;
            }

            case 9:
                cout << "Keluar dari sistem.\n";
                system("cls");
                goto login;
                break;

            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
                break;
        }
    } while (pilihan != 9);

    return 0;
}

