#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 100

int main() {
    FILE* file = fopen("sehirkodlari.txt", "r");
    if (file == NULL) {
        printf("Dosya acilamadi \n");
        return 1;
    }

    char sehir[MAX_LINE];
    char kod[10];
    char girilen_kod[10];
    int found = 0;

    printf("Trafik kodunu giriniz: ");
    scanf("%s", girilen_kod);

    while (fscanf(file, "%s %[^\n]", kod, sehir) != EOF) {
        if (strcmp(kod, girilen_kod) == 0) {
            printf("%s Dogu Karadeniz bolgesinde yer alir.\n", sehir);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Dogu Karadeniz bolgesinde bulunamadi\n");
    }

    fclose(file);
    return 0;
}