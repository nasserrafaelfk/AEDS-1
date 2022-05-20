#include <stdlib.h>
#include <stdio.h>

int mdc(int a, int b){
    if(a % b != 0){
        int aux;
        aux = a;
        a = b;
        b = aux % b;
    }
    else
        return b;
    mdc(a,b);
    return b;
}

int main(){
    int a,b;
    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &a, &b);
    if(a<b){
        int aux;
        aux=a;
        a=b;
        b=aux;
    }
    printf("Resultado: %d",mdc(a,b));
    return 0;
}