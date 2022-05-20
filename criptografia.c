/*
Laboratório de Algoritmos e Estrutura de Dados I
Professora: Natalia Batista
Aluno:      Nasser Rafael Franca Kilesse
Matricula:  20193018051
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    FILE *file;
    int  position = 0;
    char caracter,nomeArquivo[100], vetorCifrado[20000], vetorAuxiliar[20000];

    printf("Digite o nome do arquivo: ");
    
    scanf("%s",nomeArquivo);

    file = fopen(nomeArquivo,"r");
    
    if(file == NULL){//----------------------------------------------------------------------- se o arquivo não for localizado, o programa fecha
        printf("Nao foi possivel abrir o arquivo!\n");
        exit(0);
    }

    printf("\n");
    printf("--------------------\n");
    printf("Mensagem codificada:\n");
    printf("--------------------\n");

    while(fscanf(file,"%c",&caracter) != EOF){//---------------------------------------------- coloca os caracteres do arquivo .txt nos vetores principal e auxiliar
        vetorCifrado[position] = caracter;
        vetorAuxiliar[position] = caracter;
        printf("%c",vetorCifrado[position]);//------------------------------------------------ printa o vetor codificado
        position++;
    }

    printf("\n");

    //position -= 1;//------------------------------------------------------------------------ descomentar para rodar no runcodes

    int length = position;//------------------------------------------------------------------ tamanho do vetor

    for(int i = length, position = 0; i > (length/2); i -= 4, position += 4){//--------------- permuta os elementos do vetor
        vetorAuxiliar[position + 1] = vetorCifrado[i - 1];
        vetorAuxiliar[position] = vetorCifrado[i - 2];
        
        vetorAuxiliar[i - 1] = vetorCifrado[position + 1];
        vetorAuxiliar[i - 2] = vetorCifrado[position];
    }

    for(int i = 0; i < length; i += 2){//----------------------------------------------------- espelha os elementos do vetor
        caracter = vetorAuxiliar[i + 1];
        vetorAuxiliar[i + 1] = vetorAuxiliar[i];
        vetorAuxiliar[i] = caracter;
    }

    for(int i = 0; i < length; i++){//-------------------------------------------------------- decifra a Cifra de César deslocada em 5 posições
        if(vetorAuxiliar[i] == '#')
            vetorAuxiliar[i] = ' ';
        else if((vetorAuxiliar[i] - 5) < 64)
            vetorAuxiliar[i] += 21;
        else if(((vetorAuxiliar[i] - 5)) < 97 && ((vetorAuxiliar[i] - 5) > 90))
            vetorAuxiliar[i] += 21;
        else
            vetorAuxiliar[i] -= 5;
    }

    printf("----------------------\n");
    printf("Mensagem decodificada:\n");
    printf("----------------------\n");

    for(int i = 0; i < length; i++){//-------------------------------------------------------- printa o vetor decodificado
        printf("%c", vetorAuxiliar[i]);
    }

    fclose(file);
    return 0;
 }