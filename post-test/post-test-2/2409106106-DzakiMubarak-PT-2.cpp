#include <iostream>
#include <string>
using namespace std;

void tampilkanMenu() {
    cout << "\n=== Menu Toko Game Online ===\n";
    cout << "1. Tambah Game\n";
    cout << "2. Lihat Daftar Game\n";
    cout << "3. Update Game\n";
    cout << "4. Hapus Game\n";
    cout << "5. Keluar\n";
    cout << "Pilih menu: ";
}

void tampilkanDaftarGame(string namaGame[], int hargaGame[], int tahunRilis[], int jumlahGame) {
    if (jumlahGame == 0) {
        cout << "\nTidak ada game yang tersedia.\n";
    } else {
        cout << "\n=== Daftar Game ===\n";
        for (int i = 0; i < jumlahGame; i++) {
            cout << "ID: " << i + 1 << endl;
            cout << "Nama Game: " << namaGame[i] << endl;
            cout << "Harga: Rp" << hargaGame[i] << endl;
            cout << "Tahun Rilis: " << tahunRilis[i] << endl;
            cout << "----------------------------\n";
        }
    }
}

int main() {
    string namaGame[100];
    int hargaGame[100];
    int tahunRilis[100];
    int jumlahGame = 0;

    string nama, nim;
    int percobaan = 0;
    bool loginBerhasil = false;

    while (percobaan < 3 && !loginBerhasil) {
        cout << "Masukkan username: ";
        getline(cin, nama);
        cout << "Masukkan password: ";
        getline(cin, nim);

        if (nama == "Dzaki Mubarak" && nim == "2409106106") {
            loginBerhasil = true;
            cout << "Login berhasil!\n";
        } else {
            percobaan++;
            cout << "Login gagal. Percobaan tersisa: " << 3 - percobaan << endl;
        }
    }

    if (!loginBerhasil) {
        cout << "Anda telah melebihi batas percobaan login. Program berhenti.\n";
        return 0;
    }

    int pilihan;
    bool keluar = false;

    while (!keluar) {
        tampilkanMenu();
        cin >> pilihan;
        cin.ignore(); 

        switch (pilihan) {
            case 1: 
                if (jumlahGame < 100) {
                    cout << "\nMasukkan Nama Game: ";
                    getline(cin, namaGame[jumlahGame]);
                    cout << "Masukkan Harga Game: ";
                    cin >> hargaGame[jumlahGame];
                    cout << "Masukkan Tahun Rilis Game: ";
                    cin >> tahunRilis[jumlahGame];
                    jumlahGame++;
                    cout << "Game berhasil ditambahkan!\n";
                } else {
                    cout << "Kapasitas game penuh!\n";
                }
                break;

            case 2: 
                tampilkanDaftarGame(namaGame, hargaGame, tahunRilis, jumlahGame);
                break;

            case 3: 
                if (jumlahGame > 0) {
                    int id;
                    tampilkanDaftarGame(namaGame, hargaGame, tahunRilis, jumlahGame);
                    cout << "Masukkan ID Game yang ingin diupdate: ";
                    cin >> id;
                    cin.ignore();

                    if (id > 0 && id <= jumlahGame) {
                        cout << "Masukkan Nama Game Baru: ";
                        getline(cin, namaGame[id - 1]);
                        cout << "Masukkan Harga Game Baru: ";
                        cin >> hargaGame[id - 1];
                        cout << "Masukkan Tahun Rilis Game Baru: ";
                        cin >> tahunRilis[id - 1];
                        cout << "Game berhasil diupdate!\n";
                    } else {
                        cout << "ID tidak valid!\n";
                    }
                } else {
                    cout << "Tidak ada game yang tersedia untuk diupdate.\n";
                }
                break;

            case 4: 
                if (jumlahGame > 0) {
                    int id;
                    tampilkanDaftarGame(namaGame, hargaGame, tahunRilis, jumlahGame);
                    cout << "Masukkan ID Game yang ingin dihapus: ";
                    cin >> id;

                    if (id > 0 && id <= jumlahGame) {
                        for (int i = id - 1; i < jumlahGame - 1; i++) {
                            namaGame[i] = namaGame[i + 1];
                            hargaGame[i] = hargaGame[i + 1];
                            tahunRilis[i] = tahunRilis[i + 1];
                        }
                        jumlahGame--;
                        cout << "Game berhasil dihapus!\n";
                    } else {
                        cout << "ID tidak valid!\n";
                    }
                } else {
                    cout << "Tidak ada game yang tersedia untuk dihapus.\n";
                }
                break;

            case 5: 
                keluar = true;
                cout << "Terima kasih telah menggunakan program ini!\n";
                break;

            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    }

    return 0;
}