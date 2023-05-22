#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int vetor[5] = {5,3,1,4,2};
int contador;


//escreva um algoritimo que ordene uma amostra num√©rica
void ImprimirFunc(int qtd){
	printf("\n");
	for (int i=0; i<qtd; i++)
		if (i<qtd-1) printf("%i, ", vetor[i]);
		else printf("%i. (OperaÁıes de Troca: %i)", vetor[i],contador);

}

void bubbleSort(int qtd) {
  int aux; contador = 0;
  for(int i=0; i<qtd -1; i++)
    for(int j=0; j<qtd-1 -i; j++)
      if(vetor[j] > vetor[j+1]){
        aux = vetor[j];
        vetor[j] = vetor[j+1];
        vetor[j+1] = aux;
        contador++;
      }
}



void seletionSort(int qtd){
	int aux;
	int contador = 0;
	for(int i=0; i<qtd-1; i++)
 		for(int j=i+1; j<qtd; j++)
 			if(vetor[j] < vetor[i]){
 				aux = vetor[j];
				vetor[j] = vetor[i];
				vetor[i] = aux;
				contador ++;
 		}

}

int main(){
	setlocale(LC_ALL,"Portuguese");
	ImprimirFunc(5);
	bubbleSort(5);
	//selectionSort(5)
	ImprimirFunc(5);
}
