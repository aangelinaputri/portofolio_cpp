#include <iostream>
#include <string>
using namespace std;

int main() {
    string data[100];
    int n;

    cout << "======================================" << endl;
    cout << "   PROGRAM PENGURUTAN NAMA TEMAN KELAS" << endl;
    cout << "   Oleh: Angelina Putri Ariani" << endl;
    cout << "======================================" << endl;

    cout << "\nMasukkan jumlah nama: ";
    cin >> n;

    cout << "\n--- Input Nama Teman ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nama ke-" << i + 1 << ": ";
        cin >> data[i];
    }

    cout << "\nDaftar Nama (Sebelum Pengurutan):" << endl;
    cout << "----------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << data[i] << endl;
    }

    char pilih;
    cout << "\n======================================" << endl;
    cout << "Pilih metode pengurutan:" << endl;
    cout << "1. Ascending (A-Z)" << endl;
    cout << "2. Descending (Z-A)" << endl;
    cout << "Pilihan Anda: ";
    cin >> pilih;
    cout << "======================================" << endl;

    if (pilih == '1') {
        // Bubble Sort Ascending
        for (int i = 1; i < n; i++) {
            for (int j = n - 1; j >= i; j--) {
                if (data[j] < data[j - 1]) {
                    string temp = data[j];
                    data[j] = data[j - 1];
                    data[j - 1] = temp;
                }
            }
        }

        cout << "\nHasil Pengurutan (Ascending):" << endl;
        cout << "----------------------------------" << endl;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ". " << data[i] << endl;
        }

    } else if (pilih == '2') {
        // Bubble Sort Descending
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (data[j] < data[j + 1]) {
                    string temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }

        cout << "\nHasil Pengurutan (Descending):" << endl;
        cout << "----------------------------------" << endl;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ". " << data[i] << endl;
        }

    } else {
        cout << "\nPilihan tidak tersedia." << endl;
    }

    cout << "\n======================================" << endl;
    cout << "Program selesai. Terima kasih :)" << endl;
    cout << "======================================" << endl;

    return 0;
}

