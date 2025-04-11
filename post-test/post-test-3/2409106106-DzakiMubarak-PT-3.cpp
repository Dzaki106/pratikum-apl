#include <iostream>
#include <string>
using namespace std;

struct Game {
    string nama;
    int harga;
    int tahunRilis;
};

int tampilkanMenu() {
    int pilihan;
    cout << "\n=== Menu Toko Game Online ===\n";
    cout << "1. Tambah Game\n";
    cout << "2. Lihat Daftar Game\n";
    cout << "3. Update Game\n";
    cout << "4. Hapus Game\n";
    cout << "5. Keluar\n";
    cout << "Pilih menu: ";
    cin >> pilihan;
    cin.ignore();
    return pilihan;
}

int tampilkanDaftarGame(Game daftarGame[], int jumlahGame) {
    if (jumlahGame == 0) {
        cout << "\nTidak ada game yang tersedia.\n";
    } else {
        cout << "\n=== Daftar Game ===\n";
        for (int i = 0; i < jumlahGame; i++) {
            cout << "ID: " << i + 1 << endl;
            cout << "Nama Game: " << daftarGame[i].nama << endl;
            cout << "Harga: Rp" << daftarGame[i].harga << endl;
            cout << "Tahun Rilis: " << daftarGame[i].tahunRilis << endl;
            cout << "----------------------------\n";
        }
    }
    return jumlahGame;
}

bool tambahGame(Game daftarGame[], int &jumlahGame) {
    if (jumlahGame < 100) {
        cout << "\nMasukkan Nama Game: ";
        getline(cin, daftarGame[jumlahGame].nama);
        cout << "Masukkan Harga Game: ";
        cin >> daftarGame[jumlahGame].harga;
        cout << "Masukkan Tahun Rilis Game: ";
        cin >> daftarGame[jumlahGame].tahunRilis;
        jumlahGame++;
        cout << "Game berhasil ditambahkan!\n";
        return true;
    } else {
        cout << "Kapasitas game penuh!\n";
        return false;
    }
}

bool login() {
    string nama, nim;
    int percobaan = 0;
    
    while (percobaan < 3) {
        cout << "Masukkan Nama: ";
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);

        if (nama == "Dzaki Mubarak" && nim == "2409106106") {
            cout << "Login berhasil!\n";
            return true;
        } else {
            percobaan++;
            cout << "Login gagal. Percobaan tersisa: " << 3 - percobaan << endl;
        }
    }
    
    cout << "Anda telah melebihi batas percobaan login. Program berhenti.\n";
    return false;
}

int main() {
    Game daftarGame[100];
    int jumlahGame = 0;

    if (!login()) {
        return 0;
    }

    while (true) {
        int pilihan = tampilkanMenu();

        switch (pilihan) {
            case 1:
                tambahGame(daftarGame, jumlahGame);
                break;
                
            case 2:
                tampilkanDaftarGame(daftarGame, jumlahGame);
                break;
                
            case 3: {
                int jumlah = tampilkanDaftarGame(daftarGame, jumlahGame);
                if (jumlah > 0) {
                    int id;
                    cout << "Masukkan ID Game yang ingin diupdate: ";
                    cin >> id;
                    cin.ignore();

                    if (id > 0 && id <= jumlahGame) {
                        cout << "Masukkan Nama Game Baru: ";
                        getline(cin, daftarGame[id - 1].nama);
                        cout << "Masukkan Harga Game Baru: ";
                        cin >> daftarGame[id - 1].harga;
                        cout << "Masukkan Tahun Rilis Game Baru: ";
                        cin >> daftarGame[id - 1].tahunRilis;
                        cout << "Game berhasil diupdate!\n";
                    } else {
                        cout << "ID tidak valid!\n";
                    }
                }
                break;
            }
                
            case 4: {
                int jumlah = tampilkanDaftarGame(daftarGame, jumlahGame);
                if (jumlah > 0) {
                    int id;
                    cout << "Masukkan ID Game yang ingin dihapus: ";
                    cin >> id;

                    if (id > 0 && id <= jumlahGame) {
                        for (int i = id - 1; i < jumlahGame - 1; i++) {
                            daftarGame[i] = daftarGame[i + 1];
                        }
                        jumlahGame--;
                        cout << "Game berhasil dihapus!\n";
                    } else {
                        cout << "ID tidak valid!\n";
                    }
                }
                break;
            }
                
            case 5:
                cout << "Terima kasih telah menggunakan program ini!\n";
                return 0;
                
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    }

    return 0;
}