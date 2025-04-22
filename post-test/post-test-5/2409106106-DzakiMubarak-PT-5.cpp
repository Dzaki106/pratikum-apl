#include <iostream>
#include <string>
using namespace std;

struct Game {
    string nama;
    int harga;
    int tahunRilis;
};

void tampilkanMenu(int *pilihan) {
    cout << "\n=== Menu Toko Game Online ===\n";
    cout << "1. Tambah Game\n";
    cout << "2. Lihat Daftar Game\n";
    cout << "3. Update Game\n";
    cout << "4. Hapus Game\n";
    cout << "5. Keluar\n";
    cout << "Pilih menu: ";
    cin >> *pilihan;  
    cin.ignore();
}

void tampilkanDaftarGame(Game *daftarGame, int jumlahGame) {
    if (jumlahGame == 0) {
        cout << "\nTidak ada game yang tersedia.\n";
    } else {
        cout << "\n=== Daftar Game ===\n";
        for (int i = 0; i < jumlahGame; i++) {
            cout << "ID: " << i + 1 << endl;
            cout << "Nama Game: " << (daftarGame + i)->nama << endl;  
            cout << "Harga: Rp" << (daftarGame + i)->harga << endl;
            cout << "Tahun Rilis: " << (daftarGame + i)->tahunRilis << endl;
            cout << "----------------------------\n";
        }
    }
}

void tambahGame(Game *daftarGame, int *jumlahGame) {
    if (*jumlahGame < 100) {
        cout << "\nMasukkan Nama Game: ";
        getline(cin, (daftarGame + *jumlahGame)->nama);
        cout << "Masukkan Harga Game: ";
        cin >> (daftarGame + *jumlahGame)->harga;
        cout << "Masukkan Tahun Rilis Game: ";
        cin >> (daftarGame + *jumlahGame)->tahunRilis;
        (*jumlahGame)++;
        cout << "Game berhasil ditambahkan!\n";
    } else {
        cout << "Kapasitas game penuh!\n";
    }
}

void updateGame(Game *daftarGame, int jumlahGame) {
    if (jumlahGame > 0) {
        tampilkanDaftarGame(daftarGame, jumlahGame);
        int id;
        cout << "Masukkan ID Game yang ingin diupdate: ";
        cin >> id;
        cin.ignore();

        if (id > 0 && id <= jumlahGame) {
            Game *gamePtr = daftarGame + (id - 1);  
            cout << "Masukkan Nama Game Baru: ";
            getline(cin, gamePtr->nama);
            cout << "Masukkan Harga Game Baru: ";
            cin >> gamePtr->harga;
            cout << "Masukkan Tahun Rilis Game Baru: ";
            cin >> gamePtr->tahunRilis;
            cout << "Game berhasil diupdate!\n";
        } else {
            cout << "ID tidak valid!\n";
        }
    } else {
        cout << "Tidak ada game yang tersedia untuk diupdate.\n";
    }
}

void hapusGame(Game *daftarGame, int *jumlahGame) {
    if (*jumlahGame > 0) {
        tampilkanDaftarGame(daftarGame, *jumlahGame);
        int id;
        cout << "Masukkan ID Game yang ingin dihapus: ";
        cin >> id;

        if (id > 0 && id <= *jumlahGame) {
            for (int i = id - 1; i < *jumlahGame - 1; i++) {
                *(daftarGame + i) = *(daftarGame + i + 1);  
            }
            (*jumlahGame)--;
            cout << "Game berhasil dihapus!\n";
        } else {
            cout << "ID tidak valid!\n";
        }
    } else {
        cout << "Tidak ada game yang tersedia untuk dihapus.\n";
    }
}


void login(bool &statusLogin) {
    string nama, nim;
    int percobaan = 0;
    
    while (percobaan < 3 && !statusLogin) {
        cout << "Masukkan Nama: ";
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);

        if (nama == "Dzaki Mubarak" && nim == "2409106106") {
            statusLogin = true;
            cout << "Login berhasil!\n";
        } else {
            percobaan++;
            cout << "Login gagal. Percobaan tersisa: " << 3 - percobaan << endl;
        }
    }
}

int main() {
    Game daftarGame[100];
    int jumlahGame = 0;
    bool statusLogin = false;

    login(statusLogin);
    
    if (!statusLogin) {
        cout << "Anda telah melebihi batas percobaan login. Program berhenti.\n";
        return 0;
    }

    while (true) {
        int pilihan;
        tampilkanMenu(&pilihan); 

        switch (pilihan) {
            case 1:
                tambahGame(daftarGame, &jumlahGame);  
                break;
                
            case 2:
                tampilkanDaftarGame(daftarGame, jumlahGame);  
                break;
                
            case 3:
                updateGame(daftarGame, jumlahGame);  
                break;
                
            case 4:
                hapusGame(daftarGame, &jumlahGame);  
                break;
                
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