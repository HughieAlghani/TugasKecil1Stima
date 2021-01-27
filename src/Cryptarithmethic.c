#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define boolean unsigned char
#define true 1
#define false 0

// Cek keunikan
boolean unik(int angka[]){
    int i, j;
    boolean unik = true;
    for (i = 0; i <= 8; i++){
        for (j = i + 1; j <= 9; j++){
            if (angka[i] = angka[j]){
                unik = false;
				break;
            }
        }
    }
    return unik;
}

// Assign nilai
void assign(int nilai, int angka[]){
    int i, n;
    n = nilai;
    for (i = 9; i >= 0; i--){
        angka[i] = n % 10;
        n /= 10;
    }
}

// Prosedur permutasi
void permutasi(int nilai, int angka[]){
    nilai += 1;
    assign(nilai, angka);
    while (!unik(angka)){
        while (nilai <= 9876543210){
            nilai += 1;
            assign(nilai, angka);
            if (unik(angka)){
                break;
            }
        }
        if (nilai > 9876543210){
            break;
        }
    }
}

// Ambil value
void value(int *a, char word[], int length, char huruf[], int angka[]){
    int i, j, k;
    *a = 0;
    for (i = 0; i < length - 1; i++){
        for (j = 0; j <= 9; j++){
            if (word[i] == huruf[j]){
                k = j;
				break;
            }
        }
        *a = (*a * 10) + angka[k];
    }
}

// Cek hasil
boolean hasil(int value1, int value2, int value3){
    if ((value1 + value2) == value3){
        return true;
    }
    else {
        return false;
    }
}

// KAMUS
    int i, j, k;
    FILE *fptr;
    char word1[100];
    char word2[100];
    char garis[100];
    char word3[100];
    int value1, value2, value3;
    int nilai = 1023456789;
    int angka[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
    int length1, length2, length3, length4;
    char huruf[15];
    int percobaan, banyak_huruf;

// MAIN
int main(){
    // Ambil kata
    if ((fptr = fopen("test4.txt","r")) == NULL){
        printf("File tidak ditemukan!");
        exit(1);
    }

    fgets(word1, 100, fptr);
    fgets(word2, 100, fptr);
    fgets(garis, 100, fptr);
    fgets(word3, 100, fptr);

    fclose(fptr);

    int length1 = strlen(word1);
    int length2 = strlen(word2);
    int length3 = strlen(word3);

    printf("Soal :\n");
    for (j = 0; j < (length3 - length1); j++){
        printf(" ");
    }
    printf("%s", word1);
    for (j = 0; j < (length3 - length2); j++){
        printf(" ");
    }
    printf("%s", word2);
    printf("%s", garis);
    printf("%s", word3);
    printf("\n");

    printf("Solusi :\n");

    // Ambil huruf unik dari kata 1
    huruf[0] = word1[0];
    banyak_huruf = 1;
    for (i = 1; i < length1 - 1; i++){
        if (word1[i] != ' '){
            j = 0;
            while (j < 10){
				if (huruf[j] == '\0'){
                    huruf[j] = word1[i];
                    banyak_huruf += 1;
					break;
                }
                else if (huruf[j] == word1[i]){
					break;
                }
                else if (huruf[j] != word1[i]){
                    j++;
                }
            }
        }
    }

    // Ambil huruf unik dari kata 2
    for (i = 0; i < length2 - 1; i++){
        if (word2[i] != ' '){
            j = 0;
            while (j < 10){
				if (huruf[j] == '\0'){
                    huruf[j] = word2[i];
                    banyak_huruf += 1;
					break;
                }
                else if (huruf[j] == word2[i]){
					break;
                }
                else if (huruf[j] != word2[i]){
                    j++;
                }
            }
        }
    }

    // Ambil huruf unik dari kata 3
    for (i = 0; i < length3 - 1; i++){
        if (word3[i] != ' '){
            j = 0;
            while (j < 10){
				if (huruf[j] == '\0'){
                    huruf[j] = word3[i];
                    banyak_huruf += 1;
					break;
                }
                else if (huruf[j] == word3[i]){
					break;
                }
                else if (huruf[j] != word3[i]){
                    j++;
                }
            }
        }
    }

    // Cek banyak huruf unik
    if (banyak_huruf > 10){
        printf("Huruf lebih banyak dari 10!");
        exit(1);
    }

    // Brute Force
    value(&value1, word1, length1, huruf, angka);
    value(&value2, word2, length2, huruf, angka);
    value(&value3, word3, length3, huruf, angka);
    percobaan = 1;
    while ((!hasil(value1, value2, value3)) && (nilai <= 9876543210)) {
        permutasi(nilai, angka);
        percobaan += 1;
        value(&value1, word1, length1, huruf, angka);
        value(&value2, word2, length2, huruf, angka);
        value(&value3, word3, length3, huruf, angka);
    }

    if (nilai > 9876543210){
        printf("Tidak ada solusi");
        exit(1);
    }
    else {
        for (j = 0; j < (length3 - length1); j++){
            printf(" ");
        }
        for (i = 0; i < length1 - 1; i++){
            for (j = 0; j <= 9; j++){
                if (word1[i] == huruf[j]){
                    k = j;
                }
            }
            printf("%d",angka[k]);
        }
        printf("\n");

        for (j = 0; j < (length3 - length2); j++){
            printf(" ");
        }
        for (i = 0; i < length2 - 1; i++){
            if (word2[i] != ' '){
                for (j = 0; j <= 9; j++){
                    if (word2[i] == huruf[j]){
                        k = j;
                    }
                }
                printf("%d",angka[k]);
            }
        }
        printf("\n");

        printf("%s", garis);

        for (i = 0; i < length3 - 1; i++){
            if (word3[i] != ' '){
                for (j = 0; j <= 9; j++){
                    if (word3[i] == huruf[j]){
                        k = j;
                    }
                }
                printf("%d",angka[k]);
            }
        }
        printf("\n");

        printf("Banyak percobaan = %d\n", percobaan);
    }
    return 0;
}
