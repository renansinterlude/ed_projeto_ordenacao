#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gera_vetor (int v[], int n) {
    int i;
    for (i=0; i<n; i++) {
        v[i] = rand() * rand() % (n*10); // numero lido pelo usuario * 10 = intervalo de 100
    }
}

void bubble(int v[], int n) {
    int i, j, aux;
    for(i=1; i<n; i++) {
        for (j=0; j<n-i; j++){
            if(v[j] > v[j+1]) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                // essas três linhas estão basicamente trocando o numero de j por j+1 e vice-versa
            }
        }
    }
}

void exibe_vetor(int v[], int n, const char * msg) { // const (constante) garante que o tipo passado só pode ser char
    int i;
    printf("\n%s\n", msg);
    for(i=0; i<n; i++) {
        printf("%d ", v[i]);
    }
}

int main() {
    int n, result_busca_simples, result_busca_binaria, x;
    int *v;
    long ini, fim;
    
    printf("Digite o tamanho do vetor (0 encerra): ");
    scanf("%d", &n);
    srand (time(0));
    while (n>0) {
        v = (int *) malloc (n*sizeof(int));
        gera_vetor(v, n);
        // exibe_vetor(v, n, "Vetor gerado");
        
        ini = time(0); 
        bubble(v, n);
        fim = time(0);
        // exibe_vetor(v, n, "Vetor ordenado");
        printf("\nTempo de ordenacao: %ld", fim-ini);
        free(v); 

        printf("\nDigite o tamanho do vetor (0 encerra): ");
        scanf("%d", &n);
    }
}