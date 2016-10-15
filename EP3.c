#include <stdio.h>
#include <stdlib.h>

/*
 Função que verifica se o vetor está com
 os elementos em ordem invertida.
*/
int invertido(int* vet, int tam) {

    int i;

    for (i = 0; i < tam - 1; i++) {
        if (vet[i] < vet[i+1])
            return 0;
    }

    return 1;
}

/*
 Função que faz a tresreversão,
 dado a posição do vetor.
*/
void troca (int *vet, int i, int tam) {
    
    int aux;

    aux = vet[i]; 
    vet[i] = vet[(i+2)%tam]; 
    vet[(i+2)%tam] = aux;
}

/*
 Função utilizada pela OrdenaPar, 
 para verificar se o vetor foi 
 efetivamente ordenado.
*/
int verifica (int* vet, int tam) {

    int j;

    for (j = 0; j < tam - 1; j++) {
        
        if (vet[j] > vet[j + 1])
            return 0;
    }

    return 1;
}

void bubbleModPar (int *vet, int tam, int *res, int *t_res) {

    int i, ini, fim;

    *t_res = 0;
    ini = 0;
    fim = tam - 1;

    while (ini < fim) {

        for (i = 0; i < tam - 2; i++) {

            if (vet[i] > vet[(i+2)%tam] && i < (i+2)%tam) {
                
                res [*t_res] = i;
                *t_res += 1;    
                troca(vet, i, tam);
            }
        }

        fim--;
    }
}

void ordenaPar (int* vet, int tam) {

    int *res, *tam_r;
    int j;

    res = malloc((tam - 1)*(sizeof(int)));
    tam_r = malloc(sizeof(int));
        
    bubbleModPar(vet, tam, res, tam_r);

    if (verifica(vet, tam)) {
        
        for (j = 0; j < *tam_r; j++)
            printf("%d\n", res[j]);
    }

    else
        printf("Nao e possivel\n");
}

/*
 Versão modificada do BubbleSort utilizada pela função
 OrdenaImpar, no caso do vetor estar invertido.
 A única modificação dessa versão é que, ao invés de checar
 o elemento imediatamente depois, ela checa pulando um,
 para poder fazer a tresreversão.
*/
void bubbleModImp (int *vet, int tam) {

    int i, ini, fim;

    ini = 0;
    fim = tam - 1;

    while (ini < fim) {

        for (i = 0; i < tam - 2; i++) {

            if (vet[i] > vet[(i+2)%tam] && i < (i+2)%tam) {
                    
                printf("%d\n", i);
                troca(vet, i, tam);
            }
        }

        fim--;
    }
}

/*
 Se o vetor tem tamanho ímpar, essa será a função usada.
*/
void OrdenaImpar (int *vet, int tam) {

    int moveu, volta, ida, i, in_ida;
    
    in_ida = 0;
    moveu = 1;
    
    /*
     No caso do vetor estar simplesmente invertido, 
     uma versão modificada do BubbleSort é chamada 
     para ordená-lo.
    */   
    if (invertido(vet, tam)) {
        
        while (tam >= 3) {
            bubbleModImp(vet, tam);
            tam -= 2;
        }
    }

    /*
     Em um caso mais complicado, até nenhum movimento ser possível,
     ou seja, o vetor estar ordenado, o algoritmo verificará se é 
     possível fazer a tresreversão diretamente, ou, para trocar dois
     elementos seguidos, uma sequência pré-definida de tresreversões.
    */
    else { 
            
        while (moveu == 1) {

            moveu = 0;
            for (i = 0; i < tam; i++) {

                if (vet[i] > vet[(i+2)%tam] && i < (i+2)%tam) {
                        
                    printf("%d\n", i);
                    troca(vet, i, tam);
                    
                    moveu = 1;
                }
                    
                else if (vet[i] > vet[(i+1)%tam] && i < (i+1)%tam) {
                        
                    volta = (tam)/2;
                    ida = volta - 1;
                        
                    i = (i-2)%tam;
                    if (i < 0)
                        i += tam;
                        
                    while (volta) {         
                            
                        printf("%d\n", i);
                        troca (vet, i, tam);

                        if (volta == 2)
                            in_ida = i;

                        i = (i-2)%tam;
                        if (i < 0)
                            i += tam;
                        volta--;
                    }
                        
                    i = in_ida;
                        
                    while (ida) {

                        printf("%d\n", i);
                        troca (vet, i, tam);
                           
                        i = (i+2)%tam;
                        ida--;
                    }
                        
                    moveu = 1;              
                }
            }     
        }       
    }
}

/*
 Lê os dados da entrada e prepara o vetor.
 Verifica se o tamanho do vetor é ímpar ou par 
 e chama as funções específicas para cada caso.
*/
int main () {

    int tam_vet, i, j;
    int *vetor;

    j = scanf("%d", &tam_vet);
    
    vetor = malloc(tam_vet*sizeof(int));
    
    for (i = 0; i < tam_vet; i++)
        j = scanf("%d", &vetor[i]);

    if (tam_vet%2)
        OrdenaImpar(vetor, tam_vet);
    else
        ordenaPar(vetor, tam_vet);    
    
    return 0;
}