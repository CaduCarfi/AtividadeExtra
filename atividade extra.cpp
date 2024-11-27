#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
//----------------------------------------------------------
//Gera numeros aleatorios de 0 a 50
void randomicos(int *v, int n) {
    for (int x = n - 1; x > 0; x--) {
        int y = rand() % (x + 1); 
        int tmp = v[x];
        v[x] = v[y];
        v[y] = tmp;
    }
}
//----------------------------------------------------------
//Gera uma ordena�ao por Troca do tipo BubbleSort
void ordemBubbleSort(int *v, int tam) {
    for (int x = 0; x < tam - 1; x++) {
        for (int y = 0; y < tam - x - 1; y++) {
            if (v[y] > v[y + 1]) {
                int tmp = v[y];
                v[y] = v[y + 1];
                v[y + 1] = tmp;
            }
        }
    }
}
//----------------------------------------------------------
//Gera uma ordena�ao por Inser��o do tipo InsertionSort
void ordemInsertionSort(int *v, int tam) {
    for (int x = 1; x < tam; x++) {
        int chave = v[x];
        int y = x - 1;
        while (y >= 0 && v[y] > chave) {
            v[y + 1] = v[y];
            y--;
        }
        v[y + 1] = chave;
    }
}
//----------------------------------------------------------
//Gera uma ordena�ao por Sele��o do tipo SelectionSort
void ordemSelectionSort(int *v, int tam) {
    for (int x = 0; x < tam - 1; x++) {
        int nindx = x;
        for (int y = x + 1; y < tam; y++) {
            if (v[y] < v[nindx]) {
                nindx = y;
            }
        }
        int tmp = v[nindx];
        v[nindx] = v[x];
        v[x] = tmp;
    }
}
//----------------------------------------------------------
//Fun��o para printar na tela os vetores
void printv(int *v, int tam) {
    for (int x = 0; x < tam; x++) {
        printf(" [%d] ", v[x]);
    }
    printf("\n");
}
//----------------------------------------------------------
int main() {
	setlocale(LC_ALL,"portuguese");
	
	int num = 50, escolha; 
    int v[num];
    
    for (int x = 0; x < num; x++) {
        v[x] = x;
    }

    srand(time(NULL));
    randomicos(v, num);
    
    //printa os numeros aleatorios
    printf("\nN�meros aleat�rios �nicos: ");
    for (int x = 0; x < num; x++) {
        printf(" [%d] ", v[x]);
    }
    //Tabela para usuario escolher tipo de ordena��o
    printf("\n");
    printf("\nx=============================================x\n");
    printf("|                  TABELA                     |");
	printf("\n|----------- [Escolha o metodo] --------------|");
	printf("\n|------------ (1) BubbleSort -----------------|");
	printf("\n|----------- (2) InsertionSort ---------------|");
	printf("\n|----------- (3) SelectionSort ---------------|");
	printf("\nx=============================================x\n");
	printf("\nQual metodo voc� deseja: ");
	scanf("%d", &escolha);
	//If para escolha de ordena��o
	if(escolha == 1) {
	    int bubbleV[num];									//Cria��o da variavel para receber fun��o
	    for (int x = 0; x < num; x++) bubbleV[x] = v[x];
	    ordemBubbleSort(bubbleV, num); 						//Chamada da fun��o de ordena��o Bubble
	    printf("\nVetor ordenado com Bubble Sort: "); 
	    printv(bubbleV, num);								//Chamada da fun��o para printar na tela
	} else if (escolha == 2) {
	    int insertionV[num];								//Cria��o da variavel para receber fun��o
	    for (int x = 0; x < num; x++) insertionV[x] = v[x]; 
	    ordemInsertionSort(insertionV, num);				//Chamada da fun��o de ordena��o insertion
	    printf("\nVetor ordenado com Insertion Sort: ");
	    printv(insertionV, num);							//Chamada da fun��o para printar na tela
	} else if (escolha == 3) {
	    int selectionV[num];								//Cria��o da variavel para receber fun��o
	    for (int x = 0; x < num; x++) selectionV[x] = v[x]; 
	    ordemSelectionSort(selectionV, num);				//Chamada da fun��o de ordena��o Selection
	    printf("\nVetor ordenado com Selection Sort: ");
	    printv(selectionV, num);							//Chamada da fun��o para printar na tela
	} else {
		printf("\nVALOR INCORRETO");
	}
	return 0;
}

