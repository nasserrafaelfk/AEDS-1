#include <stdlib.h>
#include <stdio.h>

int mult(int base, int exp){
    int resultado;
    if(exp == 1)
        return base;
    if(exp == 0)
        return 1;
    else{
        resultado = base * mult(base,exp - 1);
    }
    return resultado;
}

int main(){
    int base,exp;
    printf("Digite a base e o expoente inteiros: ");
    scanf("%d %d", &base, &exp);
    printf("Resultado: %d",mult(base,exp));
    return 0;
}