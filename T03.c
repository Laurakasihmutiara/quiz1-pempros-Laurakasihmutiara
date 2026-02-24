#include <stdio.h>
#include <string.h>

#define MAX 100

// ================== STRUCT ==================

struct Pelanggan {
    int id;
    char nama[50];
};

struct Transaksi {
    int idTransaksi;
    int idPelanggan;
    float berat;
    float totalBayar;
    char status[20];
};

struct Stok {
    char namaBarang[50];
    int jumlah;
};

// ================== GLOBAL ==================

struct Pelanggan pelanggan[MAX];
struct Transaksi transaksi[MAX];
struct Stok stok[10];

int jumlahPelanggan = 0;
int jumlahTransaksi = 0;
int jumlahStok = 0;

// ================== FUNCTION ==================

void tambahPelanggan() {
    printf("\n=== Tambah Pelanggan ===\n");
    pelanggan[jumlahPelanggan].id = jumlahPelanggan + 1;
    printf("Nama Pelanggan: ");
    scanf(" %[^\n]", pelanggan[jumlahPelanggan].nama);

    jumlahPelanggan++;
    printf("Pelanggan berhasil ditambahkan!\n");
}

void tambahTransaksi() {
    int id;
    float hargaPerKg = 7000;

    printf("\n=== Transaksi Baru ===\n");
    printf("Masukkan ID Pelanggan: ");
    scanf("%d", &id);

    transaksi[jumlahTransaksi].idTransaksi = jumlahTransaksi + 1;
    transaksi[jumlahTransaksi].idPelanggan = id;

    printf("Berat Cucian (kg): ");
    scanf("%f", &transaksi[jumlahTransaksi].berat);

    transaksi[jumlahTransaksi].totalBayar =
        transaksi[jumlahTransaksi].berat * hargaPerKg;

    strcpy(transaksi[jumlahTransaksi].status, "Diproses");

    jumlahTransaksi++;

    printf("Transaksi berhasil ditambahkan!\n");
}

void cekStatus() {
    int id;
    printf("\nMasukkan ID Transaksi: ");
    scanf("%d", &id);

    for (int i = 0; i < jumlahTransaksi; i++) {
        if (transaksi[i].idTransaksi == id) {
            printf("Status: %s\n", transaksi[i].status);
            return;
        }
    }

    printf("Transaksi tidak ditemukan!\n");
}

void updateStatus() {
    int id;
    printf("\nMasukkan ID Transaksi: ");
    scanf("%d", &id);

    for (int i = 0; i < jumlahTransaksi; i++) {
        if (transaksi[i].idTransaksi == id) {
            printf("Masukkan Status Baru: ");
            scanf(" %[^\n]", transaksi[i].status);
            printf("Status berhasil diupdate!\n");
            return;
        }
    }

    printf("Transaksi tidak ditemukan!\n");
}

void laporan() {
    printf("\n=== Laporan Transaksi ===\n");

    for (int i = 0; i < jumlahTransaksi; i++) {
        printf("ID: %d | Pelanggan: %d | Berat: %.2f kg | Total: %.2f | Status: %s\n",
               transaksi[i].idTransaksi,
               transaksi[i].idPelanggan,
               transaksi[i].berat,
               transaksi[i].totalBayar,
               transaksi[i].status);
    }
}

void tambahStok() {
    printf("\n=== Tambah Stok ===\n");
    printf("Nama Barang: ");
    scanf(" %[^\n]", stok[jumlahStok].namaBarang);

    printf("Jumlah: ");
    scanf("%d", &stok[jumlahStok].jumlah);

    jumlahStok++;
    printf("Stok berhasil ditambahkan!\n");
}

void lihatStok() {
    printf("\n=== Data Stok ===\n");

    for (int i = 0; i < jumlahStok; i++) {
        printf("%s - %d\n", stok[i].namaBarang, stok[i].jumlah);
    }
}

// ================== MAIN ==================

int main() {
    int pilihan;

    do {
        printf("\n=== SISTEM LAUNDRY ===\n");
        printf("1. Tambah Pelanggan\n");
        printf("2. Transaksi Baru\n");
        printf("3. Cek Status\n");
        printf("4. Update Status\n");
        printf("5. Laporan\n");
        printf("6. Tambah Stok\n");
        printf("7. Lihat Stok\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: tambahPelanggan(); break;
            case 2: tambahTransaksi(); break;
            case 3: cekStatus(); break;
            case 4: updateStatus(); break;
            case 5: laporan(); break;
            case 6: tambahStok(); break;
            case 7: lihatStok(); break;
            case 0: printf("Terima kasih!\n"); break;
            default: printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 0);

    return 0;
}