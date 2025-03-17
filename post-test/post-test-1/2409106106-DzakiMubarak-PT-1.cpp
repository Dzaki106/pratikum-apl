#include <iostream>
#include <string>
using namespace std;

bool bilangan_prima(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

bool bagihabisdengang2dan3tidakdengan5(int n) {
    return (n % 2 == 0 && n % 3 == 0 && n % 5 != 0);
}

void showMenu() {
    int pilihan, kode;

    while (true) {
        cout << "\nPilih menu verifikasi kode sandi:" << endl;
        cout << "1. Cek verifikasi kode sandi adalah bilangan prima" << endl;
        cout << "2. Cek verifikasi kode sandi habis dibagi 2 dan 3, tetapi tidak habis dibagi 5" << endl;
        cout << "3. Keluar dari program" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        if (pilihan == 3) {
            cout << "Terimah kasih telah menggunakan program ini.selamat tinggal!" << endl;
            break;
        }

        if (pilihan != 1 && pilihan != 2) {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            continue;
        }

        cout << "Masukkan kode sandi (100 > kode sandi > 9999): ";
        cin >> kode;

        if (kode <= 100 || kode > 99999) {
            cout << "Kode sandi tidak valid. Harus lebih dari 100 dan tidak lebih dari 99999." << endl;
            continue;
        }

        if (pilihan == 1) {
            if (bilangan_prima(kode)) {
                cout << "Kode sandi " << kode << " adalah bilangan prima." << endl;
            } else {
                cout << "Kode sandi " << kode << " bukan bilangan prima." << endl;
            }
        } else if (pilihan == 2) {
            if (bagihabisdengang2dan3tidakdengan5(kode)) {
                cout << "Kode sandi " << kode << " habis dibagi 2 dan 3, tetapi tidak habis dibagi 5." << endl;
            } else {
                cout << "Kode sandi " << kode << " tidak memenuhi kriteria (habis dibagi 2 dan 3, tetapi tidak habis dibagi 5)." << endl;
            }
        }
    }
}

int main() {
    string username, password;

    cout << "=== Selamat datang ===" << endl;
    cout << "Silakan login untuk melanjutkan." << endl;

    while (true) {
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (username == "dzaki_mubarak" && password == "2409106106") { 
            cout << "Login berhasil! Selamat datang, " << username << "!" << endl;
            showMenu(); 
            break; 
        } else {
            cout << "Login gagal. Username atau password salah. Silakan coba lagi." << endl;
        }
    }

    return 0;
}