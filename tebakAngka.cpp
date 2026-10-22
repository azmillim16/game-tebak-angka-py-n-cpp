#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

int main() {
    srand(time(0)); // Inisialisasi seed untuk angka acak berdasarkan waktu saat ini

    int level;
    bool exit_game = false;

    do {
        cout << "\n=========================================\n";
        cout << "Selamat datang di permainan tebak angka!\n";
        cout << "Menu Utama: \n";
        cout << "Silahkan memilih tingkat kesulitan: \n";
        cout << "1. Mudah\n";
        cout << "2. Sedang\n";
        cout << "3. Sulit\n";
        cout << "4. Exit\n";
        cout << "=========================================\n";
        cout << "Masukkan pilihan tingkat kesulitan (1-4): ";
        
        cin >> level;

        // Validasi input menu
        if (level < 1 || level > 4) {
            cout << "Pilihan tidak valid. Silakan pilih 1-4.\n";
            continue; // Kembali ke awal menu
        }

        if (level == 4) {
            cout << "Terima kasih telah bermain. Sampai jumpa!\n";
            exit_game = true;
            break; // Keluar dari loop utama
        }

        int max_number;
        int maksimal_tebakan;

        if (level == 1) {
            max_number = 50;
            maksimal_tebakan = 10;
        } else if (level == 2) {
            max_number = 100;
            maksimal_tebakan = 7;
        } else {
            max_number = 500;
            maksimal_tebakan = 5;
        }

        int jumlah_tebakan = 0;
        cout << "\nKamu memiliki maksimal " << maksimal_tebakan << " kali kesempatan.\n";

        
        // Ditambah 1 agar rentangnya menjadi 1 sampe max_number
        int angka_benar = (rand() % max_number) + 1;
        int user_number = 0;
        bool tebakan_benar = false;

        while (jumlah_tebakan < maksimal_tebakan) {
            cout << "Masukkan angka tebakanmu (1-" << max_number << "): ";
            cin >> user_number;
            jumlah_tebakan++;

            if (user_number == angka_benar) {
                cout << "Selamat! Tebakanmu benar.\n";
                tebakan_benar = true;
                break; // Keluar dari loop tebakan karena sudah benar
            } else if (user_number < angka_benar) {
                cout << "Tebakanmu terlalu kecil. Coba lagi.\n";
            } else {
                cout << "Tebakanmu terlalu besar. Coba lagi.\n";
            }
            
            // sisa kesempatan
            if (jumlah_tebakan < maksimal_tebakan) {
                 cout << "Sisa kesempatan: " << maksimal_tebakan - jumlah_tebakan << "\n\n";
            }
        }

        int sisa_tebakan = maksimal_tebakan - jumlah_tebakan;
        // Rumus skor 
        
        int skor = 0;
        
        if (tebakan_benar) {
            // Tambah 1 pada sisa tebakan 
            skor = (sisa_tebakan + 1) * 10; 
        }

        if (!tebakan_benar) {
            cout << "\nSayang sekali, kamu sudah menebak " << maksimal_tebakan << " kali. Angka yang benar adalah " << angka_benar << ".\n";
        }

        cout << "Skor kamu: " << skor << "\n";
        
         char lanjut;
        cout << "\nIngin melanjutkan game? (y/n): ";
        cin >> lanjut;
        
        if (lanjut == 'n' || lanjut == 'N') {
            cout << "Terima kasih telah bermain. Sampai jumpa!\n";
            exit_game = true;
        }


    } while (!exit_game); 

    return 0;
}