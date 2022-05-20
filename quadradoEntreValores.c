#include <stdio.h>
#include <stdlib.h>

int quadrado(int a, int b){
    if(b-1 != 0){
        printf("%d ", a*a);
        a++;
        b--;
        quadrado(a,b);
    }
    else
        return 1;
}

int main(){
    int a,b;
    printf("Digite os valores: ");
    scanf("%d %d", &a, &b);
    if(a>b){
        int aux;
        aux = b;
        b = a;
        a = aux;
    }
    printf("Resultado: ");
    quadrado(a,b);
    return 0;
}