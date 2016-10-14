#include <stdio.h>
#include <stdlib.h>


int invertido(int* vet, int tam) {

	int i;

	for (i = 0; i < tam - 1; i++) {
		if (vet[i] < vet[i+1])
			return 0;
	}

	return 1;
}



void bubbleMod (int *vet, int tam) {

	int i, ini, fim, aux;

	ini = 0;
	fim = tam - 1;

	while (ini < fim) {

		for (i = 0; i < tam - 2; i++) {

			if (vet[i] > vet[(i+2)%tam] && i < (i+2)%tam) {
				aux = vet[i]; 
				vet[i] = vet[(i+2)%tam]; 
				vet[(i+2)%tam] = aux;
			}
		}

		fim--;
	}
}



void Ordena (int *vet, int tam, int *tam_r) {

	int *res, tam_ini, j, moveu, volta, ida, aux, i, start;
	tam_ini = 10;
	moveu = 1;
	
	
	res = malloc(tam_ini*(sizeof(int)));

	if (tam%2 == 0) {

		bubbleMod(vet, tam);		
	}

	else {

		if (invertido(vet, tam)) {
			while (tam >= 3) {
				bubbleMod(vet, tam);
				tam -= 2;
			}	
		}

		else { 
			
			while (moveu == 1) {

				moveu = 0;
				for (i = 0; i < tam; i++) {

					if (vet[i] > vet[(i+2)%tam] && i < (i+2)%tam) {
						
						aux = vet[i]; 
						vet[i] = vet[(i+2)%tam]; 
						vet[(i+2)%tam] = aux;
						
						moveu = 1;
						

						printf("cond1: ");
						for (j = 0; j < tam; j++)
							printf("%d ", vet[j]);
							
						printf("\n");
					}
					
					else if (vet[i] > vet[(i+1)%tam] && i < (i+1)%tam) {
						
						volta = (tam)/2;
						ida = volta - 1;
						i = (i-2)%tam;
						if (i < 0)
							i += tam;
						
						while (volta) {			
												
							aux = vet[(i+2)%tam]; 
							vet[(i+2)%tam] = vet[i]; 
							vet[i] = aux;

							if (volta == 2)
								start = i;
							
 							printf("troca ");
							for (j = 0; j < tam; j++) {
								printf("%d ", vet[j]);
							}
							printf("\n");
							
							i = (i-2)%tam;
							if (i < 0)
								i += tam;
							printf("prox indice %d\n", i );
							
							volta--;
							printf("volta\n");
						}

						for (j = 0; j < tam; j++)
							printf("%d ", vet[j]);
							
						printf("\n");
						
						while (ida) {
							i = start;
							printf("indice %d\n", i );
							aux = vet[i]; 
							printf("o que esta no indice %d\n", aux );
							vet[i] = vet[(i+2)%tam]; 
							vet[(i+2)%tam] = aux;

							i = (i+2)%tam;
							ida--;
							printf("ida\n");
						}
						
						printf("cond2: ");
						for (j = 0; j < tam; j++) 
							printf("%d ", vet[j]);
						printf("\n");
						moveu = 1;
						return;
					}				
				}
			}
			
				
			for (i = 0; i < tam; i++)
				printf("%d ", vet[i]);
			
			printf("\n");		
		}		
	}
}




int main () {

	int tam_vet, i;
	int *vetor, *resultado, *tam_res;

	scanf("%d", &tam_vet);
	
	vetor = malloc(tam_vet*sizeof(int));
	tam_res = malloc(sizeof(int));
	
	*tam_res = 0;
	
	for (i = 0; i < tam_vet; i++)
		scanf("%d", &vetor[i]);

	printf("Vetor antes: ");
	for (i = 0; i < tam_vet; i++)
		printf("%d ", vetor[i]);

	printf("\n");

	Ordena (vetor, tam_vet, tam_res);
	
	printf("Vetor depois: ");
	for (i = 0; i < tam_vet; i++)
		printf("%d ", vetor[i]);

	printf("\n");
	return 0;
}