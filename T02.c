#include <stdio.h>

int main() {
    int N;
    int kelompokDipilih;
    int jumlahKelompok = 3; // misalnya ada 3 kelompok
    int total = 0;

    printf("Masukkan jumlah data: ");
    scanf("%d", &N);

    int nilai[N];

    // Input nilai
    printf("Masukkan %d nilai:\n", N);
    for(int i = 0; i < N; i++) {
        printf("Nilai ke-%d: ", i+1);
        scanf("%d", &nilai[i]);
    }

    // Input kelompok yang ingin dijumlahkan
    printf("Masukkan kode kelompok (1-3): ");
    scanf("%d", &kelompokDipilih);

    // Proses penjumlahan
    for(int i = 0; i < N; i++) {
        int kelompok = (i % jumlahKelompok) + 1;

        if(kelompok == kelompokDipilih) {
            total += nilai[i];
        }
    }

    printf("Total nilai kelompok %d adalah: %d\n", kelompokDipilih, total);

    return 0;
}