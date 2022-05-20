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

    int tamanhoVetor,//------------------------------------------------------------------------ tamanho do vetor contido no arquivo
        flag = 1,//---------------------------------------------------------------------------- define se o elemento ja foi registrado (flag = 0) ou nao (flag = 1)
        quantidade = 1,//---------------------------------------------------------------------- quantidade de elementos em um segmento
        tamSeg = 1,//-------------------------------------------------------------------------- tamanho do vetor tipoSegmento
        pos = 0,//----------------------------------------------------------------------------- posição do vetor
        vetorSegmento[10000],//---------------------------------------------------------------- vetor que contem o tipo de cada segmento
        vetorElementos[10000],//--------------------------------------------------------------- vetor que contem a quantidade de elementos dos segmentos
        tipoSegmento[10000],//----------------------------------------------------------------- vetor que contem cada tipo de elemento dos segmentos
        vetor[10000],//------------------------------------------------------------------------ vetor do arquivo .txt
        **matriz;//---------------------------------------------------------------------------- matriz que recebe os valores dos vetores Segmento e Elementos
    
    char nomeArquivo[100];

    printf("Digite o nome do arquivo: ");
    
    scanf("%s",nomeArquivo);

    file = fopen(nomeArquivo,"r");
    
    if(file == NULL){//------------------------------------------------------------------------ se o arquivo não for localizado, o programa fecha
        printf("Nao foi possivel abrir o arquivo!\n");
        exit(0);
    }

    fscanf(file,"%d", &tamanhoVetor);

    for(int i = 0; i < tamanhoVetor; i++){//--------------------------------------------------- coloca os elementos do arquivo em um vetor
        fscanf(file,"%d", &vetor[i]);
    }

    for(int i = 0; i < tamanhoVetor; i++){//--------------------------------------------------- registra os tipos de segmento 
        for(int j = 0; j < tamSeg; j++){
            if(tipoSegmento[j] == vetor[i]){//------------------------------------------------- se o elemento do vetor ja foi registrado como um tipo de segmento, entre
                flag = 0;
            }
        }
        if(flag == 1){//----------------------------------------------------------------------- se o elemento ainda nao foi registrado, entre
            tipoSegmento[pos] = vetor[i];//---------------------------------------------------- registra o elemento como um tipo de segmento
            pos++;
            tamSeg++;
        }
        flag = 1;
    }

    for(int i = 0, aux; i <= pos; i++){//------------------------------------------------------ coloca os tipos de segmento em ordem crescente
		for(int j = 0; j < pos; j++){
			if(tipoSegmento[j] > tipoSegmento[j+1]){
				aux = tipoSegmento[j];
				tipoSegmento[j] = tipoSegmento[j+1];
				tipoSegmento[j+1] = aux;
			}
		}
	}

    for(int i = 0, pos = 0; i < tamanhoVetor; i++){//------------------------------------------ checa qual o tipo de segmento de cada segmento
        for(int j = 0; j < tamSeg; j++){
            if(tipoSegmento[j] == vetor[i]){
                vetorSegmento[pos] = j + 1;
                pos++;
                while(vetor[i] == vetor[i + 1]){
                    i++;
                }
            }
        }
    }

    pos = 0;

    for(int i = 0; i < tamanhoVetor; i++){//--------------------------------------------------- conta a quantidade de elementos de cada segmento
        if(vetor[i] == vetor[i + 1]){
            while(vetor[i] == vetor[i + 1] && (i + 1) < tamanhoVetor){
                i++;
                quantidade++;
            }
            vetorElementos[pos] = quantidade;
            pos++;
            quantidade = 1;
        }
    }

    matriz = (int **) malloc(2 * sizeof(int *));//--------------------------------------------- aloca dinamicamente as linhas da matriz

    for(int i = 0; i < 2; i++){//-------------------------------------------------------------- aloca dinamicamente as colunas da matriz
        matriz[i] = (int *) malloc(pos * sizeof(int));
    }

    for(int i = 0; i < 2; i++){//-------------------------------------------------------------- coloca as informacoes na matriz
        for(int j = 0; j < pos; j++){
            if(i == 0)
                matriz[i][j] = vetorSegmento[j];
            if(i == 1)
                matriz[i][j] = vetorElementos[j];
        }
    }

    printf("Matriz:\n");

    for(int i = 0; i < 2; i++){//-------------------------------------------------------------- printa a matriz
        for(int j = 0; j < pos; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    fclose(file);
    return 0;
 }
 