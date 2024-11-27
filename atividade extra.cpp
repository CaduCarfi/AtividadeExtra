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
//Gera uma ordenaçao por Troca do tipo BubbleSort
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
//Gera uma ordenaçao por Inserção do tipo InsertionSort
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
//Gera uma ordenaçao por Seleção do tipo SelectionSort
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
//Função para printar na tela os vetores
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
    printf("\nNúmeros aleatórios únicos: ");
    for (int x = 0; x < num; x++) {
        printf(" [%d] ", v[x]);
    }
    //Tabela para usuario escolher tipo de ordenação
    printf("\n");
    printf("\nx=============================================x\n");
    printf("|                  TABELA                     |");
	printf("\n|----------- [Escolha o metodo] --------------|");
	printf("\n|------------ (1) BubbleSort -----------------|");
	printf("\n|----------- (2) InsertionSort ---------------|");
	printf("\n|----------- (3) SelectionSort ---------------|");
	printf("\nx=============================================x\n");
	printf("\nQual metodo você deseja: ");
	scanf("%d", &escolha);
	//If para escolha de ordenação
	if(escolha == 1) {
	    int bubbleV[num];									//Criação da variavel para receber função
	    for (int x = 0; x < num; x++) bubbleV[x] = v[x];
	    ordemBubbleSort(bubbleV, num); 						//Chamada da função de ordenação Bubble
	    printf("\nVetor ordenado com Bubble Sort: "); 
	    printv(bubbleV, num);								//Chamada da função para printar na tela
	} else if (escolha == 2) {
	    int insertionV[num];								//Criação da variavel para receber função
	    for (int x = 0; x < num; x++) insertionV[x] = v[x]; 
	    ordemInsertionSort(insertionV, num);				//Chamada da função de ordenação insertion
	    printf("\nVetor ordenado com Insertion Sort: ");
	    printv(insertionV, num);							//Chamada da função para printar na tela
	} else if (escolha == 3) {
	    int selectionV[num];								//Criação da variavel para receber função
	    for (int x = 0; x < num; x++) selectionV[x] = v[x]; 
	    ordemSelectionSort(selectionV, num);				//Chamada da função de ordenação Selection
	    printf("\nVetor ordenado com Selection Sort: ");
	    printv(selectionV, num);							//Chamada da função para printar na tela
	} else {
		printf("\nVALOR INCORRETO");
	}
	return 0;
}

