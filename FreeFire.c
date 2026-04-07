#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.
#define TAM_STR 50
#define MAX_BAG 10

typedef struct{
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

void exibirMenu(int totalItens);
void inserirItem(Item mochila[], int *total);
void listarItens(Item mochila[], int total);
int buscarItem(Item mochila[], int total, char nomeBusca[]);
void removerItem(Item mochila[], int *total);

int main() {
    // Menu principal com opções:
    // 1. Adicionar um item
    // 2. Remover um item
    // 3. Listar todos os itens
    // 4. Ordenar os itens por critério (nome, tipo, prioridade)
    // 5. Realizar busca binária por nome
    // 0. Sair

    // A estrutura switch trata cada opção chamando a função correspondente.
    // A ordenação e busca binária exigem que os dados estejam bem organizados.

    return 0;
}

void inserirItem(Item mochila[], int *total) {
    if (*total >= MAX_BAG) {
        printf("Mochila cheia!\n");
        return;
    }

    printf("\n--- Adicionar Item ---\n");

    printf("Nome: ");
    fgets(mochila[*total].nome, TAM_STR, stdin);
    mochila[*total].nome[strcspn(mochila[*total].nome, "\n")] = '\0';

    printf("Tipo: ");
    fgets(mochila[*total].tipo, TAM_STR, stdin);
    mochila[*total].tipo[strcspn(mochila[*total].tipo, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &mochila[*total].quantidade);
    getchar();

    (*total)++;

    printf("Item adicionado com sucesso!\n");
}

void listarItens(Item mochila[], int total) {
    printf("\n--- Itens na Mochila ---\n");

    if (total == 0) {
        printf("Mochila vazia!\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("\nItem %d\n", i + 1);
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n", mochila[i].quantidade);
    }
    printf("\nPressione ENTER para continuar...\n");
    getchar();
}

int buscarItem(Item mochila[], int total, char nomeBusca[]) {
    for (int i = 0; i < total; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            return i;
        }
    }
    return -1;
}

void removerItem(Item mochila[], int *total) {
    char nomeBusca[TAM_STR];

    printf("\nDigite o nome do item a remover: ");
    fgets(nomeBusca, TAM_STR, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    int pos = buscarItem(mochila, *total, nomeBusca);

    if (pos == -1) {
        printf("Item nao encontrado!\n");
        return;
    }

    // desloca os itens
    for (int i = pos; i < *total - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    (*total)--;

    printf("Item removido com sucesso!\n");
}

void exibirMenu(int totalItens) {
    printf("\n=================================\n");
    printf("   MOCHILA DE SOBREVIVENCIA\n");
    printf("=================================\n");
    printf("Itens: %d/%d\n\n", totalItens,MAX_BAG);

    printf("1 - Adicionar item\n");
    printf("2 - Remover item\n");
    printf("3 - Listar itens\n");
    printf("4 - Buscar item\n");
    printf("0 - Sair\n");

    printf("\nEscolha uma opcao: ");
}
// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).

// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".

// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
