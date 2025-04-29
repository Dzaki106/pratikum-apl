#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Game {
    string nama;
    int harga;
    int tahunRilis;
};

void tampilkanMenu(int &pilihan) {
    cout << "\n=== Menu Toko Game Online ===\n";
    cout << "1. Tambah Game\n";
    cout << "2. Lihat Daftar Game\n";
    cout << "3. Update Game\n";
    cout << "4. Hapus Game\n";
    cout << "5. Sorting Game\n";
    cout << "6. Keluar\n";
    cout << "Pilih menu: ";
    cin >> pilihan;
    cin.ignore();
}

void tampilkanDaftarGame(Game daftarGame[], int jumlahGame) {
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
}

void tambahGame(Game daftarGame[], int &jumlahGame) {
    if (jumlahGame < 100) {
        cout << "\nMasukkan Nama Game: ";
        getline(cin, daftarGame[jumlahGame].nama);
        cout << "Masukkan Harga Game: ";
        cin >> daftarGame[jumlahGame].harga;
        cout << "Masukkan Tahun Rilis Game: ";
        cin >> daftarGame[jumlahGame].tahunRilis;
        jumlahGame++;
        cout << "Game berhasil ditambahkan!\n";
    } else {
        cout << "Kapasitas game penuh!\n";
    }
}

void updateGame(Game daftarGame[], int jumlahGame) {
    if (jumlahGame > 0) {
        tampilkanDaftarGame(daftarGame, jumlahGame);
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
    } else {
        cout << "Tidak ada game yang tersedia untuk diupdate.\n";
    }
}

void hapusGame(Game daftarGame[], int &jumlahGame) {
    if (jumlahGame > 0) {
        tampilkanDaftarGame(daftarGame, jumlahGame);
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
    } else {
        cout << "Tidak ada game yang tersedia untuk dihapus.\n";
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

void sortNamaDescending(Game daftarGame[], int jumlahGame) {
    for (int i = 0; i < jumlahGame-1; i++) {
        for (int j = 0; j < jumlahGame-i-1; j++) {
            if (daftarGame[j].nama < daftarGame[j+1].nama) {
                swap(daftarGame[j], daftarGame[j+1]);
            }
        }
    }
}

void sortHargaAscending(Game daftarGame[], int jumlahGame) {
    for (int i = 0; i < jumlahGame-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < jumlahGame; j++) {
            if (daftarGame[j].harga < daftarGame[min_idx].harga) {
                min_idx = j;
            }
        }
        swap(daftarGame[min_idx], daftarGame[i]);
    }
}

void sortTahunDescending(Game daftarGame[], int jumlahGame) {
    for (int i = 1; i < jumlahGame; i++) {
        Game key = daftarGame[i];
        int j = i-1;
        
        while (j >= 0 && daftarGame[j].tahunRilis < key.tahunRilis) {
            daftarGame[j+1] = daftarGame[j];
            j--;
        }
        daftarGame[j+1] = key;
    }
}

void menuSorting(Game daftarGame[], int jumlahGame) {
    int pilihan;
    do {
        cout << "\n=== Menu Sorting ===\n";
        cout << "1. Urutkan berdasarkan Nama (Z-A)\n";
        cout << "2. Urutkan berdasarkan Harga (Termurah-Termahal)\n";
        cout << "3. Urutkan berdasarkan Tahun Rilis (Terbaru-Terlama)\n";
        cout << "4. Kembali ke Menu Utama\n";
        cout << "Pilih menu sorting: ";
        cin >> pilihan;
        cin.ignore();

        if (jumlahGame == 0 && pilihan != 4) {
            cout << "Tidak ada game yang tersedia untuk diurutkan.\n";
            continue;
        }

        switch (pilihan) {
            case 1:
                sortNamaDescending(daftarGame, jumlahGame);
                cout << "Data game berhasil diurutkan berdasarkan nama (Z-A)!\n";
                tampilkanDaftarGame(daftarGame, jumlahGame);
                break;
            case 2:
                sortHargaAscending(daftarGame, jumlahGame);
                cout << "Data game berhasil diurutkan berdasarkan harga (termurah-termahal)!\n";
                tampilkanDaftarGame(daftarGame, jumlahGame);
                break;
            case 3:
                sortTahunDescending(daftarGame, jumlahGame);
                cout << "Data game berhasil diurutkan berdasarkan tahun rilis (terbaru-terlama)!\n";
                tampilkanDaftarGame(daftarGame, jumlahGame);
                break;
            case 4:
                cout << "Kembali ke menu utama.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (pilihan != 4);
}

int main() {
    Game daftarGame[100];
    int jumlahGame = 0;

    if (!login()) {
        return 0;
    }

    int pilihan;
    do {
        tampilkanMenu(pilihan);

        switch (pilihan) {
            case 1:
                tambahGame(daftarGame, jumlahGame);
                break;
            case 2:
                tampilkanDaftarGame(daftarGame, jumlahGame);
                break;
            case 3:
                updateGame(daftarGame, jumlahGame);
                break;
            case 4:
                hapusGame(daftarGame, jumlahGame);
                break;
            case 5:
                menuSorting(daftarGame, jumlahGame);
                break;
            case 6:
                cout << "Terima kasih telah menggunakan program ini!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (pilihan != 6);

    return 0;
}