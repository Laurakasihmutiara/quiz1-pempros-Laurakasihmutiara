#include <stdio.h>
#include <string.h>

int main() {
    
    // Data menu
    char kode_menu[4][5] = {"NGS", "AP", "GG", "ES"};
    char nama_menu[4][30] = {
        "Nasi Goreng Spesial",
        "Ayam Penyet",
        "Gado-Gado",
        "Es Teh"
    };
    int harga[4] = {25000, 20000, 15000, 5000};
    
    char input_kode[10];
    int porsi;
    int total = 0;
    
    printf("=== WARUNG MAK ROBY ===\n");
    
    while(1) {
        printf("\nMasukkan kode menu (atau END untuk selesai): ");
        scanf("%s", input_kode);
        
        if(strcmp(input_kode, "END") == 0) {
            break;
        }
        
        printf("Masukkan porsi Butet: ");
        scanf("%d", &porsi);
        
        int ditemukan = 0;
        
        for(int i = 0; i < 4; i++) {
            if(strcmp(input_kode, kode_menu[i]) == 0) {
                int subtotal = harga[i] * porsi;
                total += subtotal;
                
                printf("%s x%d = %d\n", nama_menu[i], porsi, subtotal);
                
                ditemukan = 1;
                break;
            }
        }
        
        if(ditemukan == 0) {
            printf("Kode tidak ditemukan!\n");
        }
    }
    
    printf("\n========================\n");
    printf("Total Belanja : Rp %d\n", total);
    
    // Cek kupon
    if(total >= 200000) {
        printf("Selamat! Anda mendapat Kupon Kuning\n");
    } else if(total >= 100000) {
        printf("Selamat! Anda mendapat Kupon Biru\n");
    } else {
        printf("Maaf, belum mendapat kupon\n");
    }
    
    printf("========================\n");
    
    return 0;
}