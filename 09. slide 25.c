#include <stdio.h>

int main() {
    char barang[5][50];
    int stok[5];
    int pilihan;
    int nomorRak;
    int jumlah;

    // Input nama barang dan stok awal
    printf("===== PENGATURAN AWAL GUDANG =====\n");

    for (int i = 0; i < 5; i++) {
        printf("\nMasukkan nama barang untuk rak %d: ", i + 1);
        scanf(" %49[^\n]", barang[i]);

        printf("Masukkan stok awal: ");
        scanf("%d", &stok[i]);

        while (stok[i] < 0) {
            printf("Stok tidak boleh negatif!\n");
            printf("Masukkan stok awal lagi: ");
            scanf("%d", &stok[i]);
        }
    }

    // Menu utama
    do {
        printf("\n===== SISTEM GUDANG =====\n");
        printf("1. Lihat stok semua rak\n");
        printf("2. Tambah stok\n");
        printf("3. Kurangi stok\n");
        printf("4. Tampilkan histogram\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        // Menu 1: Melihat stok
        if (pilihan == 1) {
            printf("\n===== DAFTAR STOK GUDANG =====\n");

            for (int i = 0; i < 5; i++) {
                printf("Rak %d - %s: %d unit\n",
                       i + 1, barang[i], stok[i]);
            }
        }

        // Menu 2: Menambah stok
        else if (pilihan == 2) {
            printf("Pilih nomor rak (1-5): ");
            scanf("%d", &nomorRak);

            if (nomorRak < 1 || nomorRak > 5) {
                printf("Nomor rak tidak valid!\n");
            } else {
                printf("Jumlah stok yang ditambahkan: ");
                scanf("%d", &jumlah);

                if (jumlah <= 0) {
                    printf("Jumlah harus lebih dari 0!\n");
                } else {
                    stok[nomorRak - 1] += jumlah;

                    printf("Stok %s sekarang: %d unit\n",
                           barang[nomorRak - 1],
                           stok[nomorRak - 1]);
                }
            }
        }

        // Menu 3: Mengurangi stok
        else if (pilihan == 3) {
            printf("Pilih nomor rak (1-5): ");
            scanf("%d", &nomorRak);

            if (nomorRak < 1 || nomorRak > 5) {
                printf("Nomor rak tidak valid!\n");
            } else {
                printf("Jumlah stok yang dikurangi: ");
                scanf("%d", &jumlah);

                if (jumlah <= 0) {
                    printf("Jumlah harus lebih dari 0!\n");
                } else if (jumlah > stok[nomorRak - 1]) {
                    printf("Gagal! Stok tidak mencukupi.\n");
                    printf("Stok tersedia: %d unit\n",
                           stok[nomorRak - 1]);
                } else {
                    stok[nomorRak - 1] -= jumlah;

                    printf("Stok %s sekarang: %d unit\n",
                           barang[nomorRak - 1],
                           stok[nomorRak - 1]);
                }
            }
        }

        // Menu 4: Menampilkan histogram horizontal
        else if (pilihan == 4) {
            printf("\n===== HISTOGRAM STOK GUDANG =====\n");

            for (int i = 0; i < 5; i++) {
                printf("%-12s: ", barang[i]);

                for (int j = 0; j < stok[i]; j++) {
                    printf("#");
                }

                printf(" (%d unit)\n", stok[i]);
            }
        }

        // Menu 5: Keluar
        else if (pilihan == 5) {
            printf("Program gudang selesai. Terima kasih!\n");
        }

        else {
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }

    } while (pilihan != 5);

    return 0;
}