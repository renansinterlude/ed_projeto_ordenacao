#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerar_vetor (int v[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        v[i] = rand() * rand () % (n * 10);
    }
}

void insertion (int v[], int n) {
    int i, j, aux;
    for(i = 1; i < n; i++) {
        aux = v[i];
        for(j = i; (j > 0) && (aux < v[j-1]); j--) { 
            v[j] = v[j-1];
        }
        v[j] = aux;
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
    int n, i = 0, t;
    int *v;
    long ini, fim;

    printf("Digite o tamanho do vetor (0 encerra): ");
    scanf("%d", &n);

    srand(time(0)); // srand = seed rand

    while (n > 0) {
        printf("\nTamanho: %d", n);
        v = (int *) malloc (n*sizeof(int));
        gerar_vetor(v, n);
        // exibir_vetor(v, n, "Vetor nao ordenado:");
        ini = time(0);
        insertion(v, n);
        fim = time(0);
        // exibir_vetor(v, n, "Vetor ordenado:");
        printf("\n\nTempo de ordenacao: %ld\n\n\n", fim-ini);
        free(v);
        printf("Digite o tamanho do vetor (0 encerra): ");
        scanf("%d", &n);
    }


    return 0;
}