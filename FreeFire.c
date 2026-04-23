#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 20

// Struct do componente
typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;

// Variável global para contar comparações
int comparacoes = 0;

// Função para remover '\n' do fgets
void limparNewline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

// Mostrar componentes
void mostrarComponentes(Componente c[], int n) {
    printf("\n--- LISTA DE COMPONENTES ---\n");
    for(int i = 0; i < n; i++) {
        printf("%d. Nome: %s | Tipo: %s | Prioridade: %d\n",
               i+1, c[i].nome, c[i].tipo, c[i].prioridade);
    }
}

// Bubble Sort por nome
void bubbleSortNome(Componente c[], int n) {
    int comparacoes = 0;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            comparacoes++;
            if(strcmp(c[j].nome, c[j+1].nome) > 0) {
                Componente temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
            }
        }
    }
}

// Insertion Sort por tipo
void insertionSortTipo(Componente c[], int n) {
    comparacoes = 0;
    for(int i = 1; i < n; i++) {
        Componente chave = c[i];
        int j = i - 1;

        while(j >= 0 && strcmp(c[j].tipo, chave.tipo) > 0) {
            comparacoes++;
            c[j+1] = c[j];
            j--;
        }
        comparacoes++;
        c[j+1] = chave;
    }
}

// Selection Sort por prioridade
void selectionSortPrioridade(Componente c[], int n) {
    comparacoes = 0;
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            comparacoes++;
            if(c[j].prioridade < c[min].prioridade) {
                min = j;
            }
        }
        Componente temp = c[i];
        c[i] = c[min];
        c[min] = temp;
    }
}

// Busca binária por nome
int buscaBinariaPorNome(Componente c[], int n, char chave[]) {
    int inicio = 0, fim = n - 1;

    while(inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(c[meio].nome, chave);

        if(cmp == 0)
            return meio;
        else if(cmp < 0)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

// Medir tempo de execução
void medirTempo(void (*algoritmo)(Componente[], int), Componente c[], int n) {
    clock_t inicio, fim;

    inicio = clock();
    algoritmo(c, n);
    fim = clock();

    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\nComparações: %d", comparacoes);
    printf("\nTempo de execução: %f segundos\n", tempo);
} // --> ChatGPT

// Função principal
int main() {
    Componente componentes[MAX];
    int n;

    printf("Quantos componentes deseja cadastrar (max 20)? ");
    scanf("%d", &n);
    getchar();

    // Entrada de dados
    for(int i = 0; i < n; i++) {
        printf("\nComponente %d\n", i+1);

        printf("Nome: ");
        fgets(componentes[i].nome, 30, stdin);
        limparNewline(componentes[i].nome);

        printf("Tipo: ");
        fgets(componentes[i].tipo, 20, stdin);
        limparNewline(componentes[i].tipo);

        printf("Prioridade (1-10): ");
        scanf("%d", &componentes[i].prioridade);
        getchar();
    }

    int opcao;
    char chave[30];

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Ordenar por Nome (Bubble Sort)\n");
        printf("2 - Ordenar por Tipo (Insertion Sort)\n");
        printf("3 - Ordenar por Prioridade (Selection Sort)\n");
        printf("4 - Buscar componente-chave (Busca Binária)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                medirTempo(bubbleSortNome, componentes, n);
                mostrarComponentes(componentes, n);
                break;

            case 2:
                medirTempo(insertionSortTipo, componentes, n);
                mostrarComponentes(componentes, n);
                break;

            case 3:
                medirTempo(selectionSortPrioridade, componentes, n);
                mostrarComponentes(componentes, n);
                break;

            case 4:
                printf("Digite o nome do componente-chave: ");
                fgets(chave, 30, stdin);
                limparNewline(chave);

                int pos = buscaBinariaPorNome(componentes, n, chave);

                if(pos != -1)
                    printf("Componente encontrado na posição %d!\n", pos+1);
                else
                    printf("Componente NÃO encontrado.\n");

                break;
        }

    } while(opcao != 0);

    return 0;
}