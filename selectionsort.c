#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerar_vetor (int v[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        v[i] = rand() * rand() % (n * 10);
    }
}

void selection (int v[], int n) {
    int i, j, menor, aux;
    for(i=0; i< n-1; i++) {
        menor = i;
        for(j = i+1; j< n; j++) {
            if(v[j] < v[menor]) {
                menor = j;
            }
        }
        if (i != menor) {
            aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
        }
    }
}

void exibir_vetor (int v[], int n, char * mensagem) {
    int i;
    printf("\n%s\n", mensagem);
    for(i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
}

int main () {
    int n;
    int *v;
    long ini, fim;
    
    printf("Digite o tamanho do vetor (0 encerra): ");
    scanf("%d", &n);
    srand(time(0)); // srand = seed rand

    while (n>0) {
        v = (int *) malloc (n*sizeof(int));
        gerar_vetor(v, n);
        // exibir_vetor(v, n, "Vetor nao ordenado:");
        ini = time(0);
        selection(v, n);
        fim = time(0);
        // exibir_vetor(v, n, "Vetor ordenado:");
        printf("\n\nTempo de ordenacao: %ld\n\n\n", fim-ini);
        free(v);
        printf("Digite o tamanho do vetor (0 encerra): ");
        scanf("%d", &n);
    }

    return 0;
}