#include <stdio.h>
#include <stdlib.h>

int Digitos(int N){
    int cont;
    if(N < 10){
        return 1;
    }
    else{
        N /= 10;
        cont = 1 + Digitos(N);
    }
    return cont;
}

int main(){
    int N;
    printf("Digite um numero inteiro: ");
    scanf("%d", &N);
    printf("Resultado: %d", Digitos(N));
    return 0;
}