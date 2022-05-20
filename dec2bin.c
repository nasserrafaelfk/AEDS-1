#include <stdlib.h>
#include <stdio.h>

int dec2bin(int dec){
    int aux;
    if(dec != 0){
        aux = dec;
        dec /= 2;
        dec2bin(dec);
        printf("%d", aux % 2);
    }
    else
        return 1;
    return 1;
}

int main(){
    int dec;
    printf("Digite um numero inteiro: ");
    scanf("%d", &dec);
    if(dec == 0){
        printf("Resultado: 0");
        return 0;
    }
    printf("Resultado: ");
    dec2bin(dec);
    return 0;
}