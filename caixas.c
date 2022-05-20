/*
Laboratório de Algoritmos e Estrutura de Dados I
Professora: Natalia Batista
Aluno:      Nasser Rafael Franca Kilesse
Matricula:  20193018051
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    
    FILE *file;
    int N, valorCaixa, fileira, caixa, maior = 0;
    char nomeArquivo[100];

    printf("Digite o nome do arquivo de entrada: ");
    
    scanf("%s",nomeArquivo);

    file = fopen(nomeArquivo,"r");
    
    if(file == NULL){                                               // se o arquivo não for localizado, o programa fecha
        printf("Nao foi possivel abrir o arquivo!\n");
        exit(0);
    }
    
    fscanf(file,"%d",&N);

    if(N == 0){
        printf("'N' deve ser maior que 0!");
        exit(0);
    }

    if(N > 20){
        printf("'N' deve ser menor ou igual a 20!");
        exit(0);
    }

    int matriz[N][N];

    for(int linha = 0; linha < N; linha++){                         // preenche a matriz quadrada com zeros, pora que a soma dos valores nao seja influenciada
        for(int coluna = 0; coluna < N; coluna++)
            matriz[linha][coluna] = 0;
    }

    /*for(int linha = 0; linha < N; linha++){     
        for(int coluna = 0; coluna < N; coluna++)                   // printa a matriz quadrada nula
            printf("%d ",matriz[linha][coluna]);
        printf("\n");  
    }*/

    for(int linha = 0; linha < N; linha++){                         // percorre o arquivo e insere seus valores em uma matriz
        for(int coluna = 0; coluna <= linha; coluna++){
            fscanf(file,"%d", &valorCaixa);
            matriz[linha][coluna] = valorCaixa;
        }
    }

    /*for(int linha = 0; linha < N; linha++){                       // printa a matriz triangular preenchida com os valores do arquivo txt
        for(int coluna = 0; coluna <= linha; coluna++)
            printf("%d ",matriz[linha][coluna]);
        printf("\n");  
    }*/

    for(int linha = N - 1; linha >= 0; linha--){                    // percorre a matriz para checar o maior resultado
        for(int coluna = linha; coluna >= 0; coluna--){
            int soma = matriz[linha][coluna];                       // pega o valor na posicao atual da matriz para ser testado

            for(int a = linha - 1; a >= 0; a--){                    // faz a soma do valor da caixa com os das caixas das fileiras acima
                for(int b = a; b >= 0; b--)
                    soma += matriz[a][b];
            }

            if(soma > maior){
                maior = soma;
                fileira = linha + 1;
                caixa = coluna + 1;
            }
        }
    }

    printf("Resposta: fileira %d, caixa %d.", fileira, caixa);

    fclose(file);
    return 0;
 }