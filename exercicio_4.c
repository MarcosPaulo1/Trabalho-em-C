#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Funcionario {
    char nome[50];
    float salario;
    struct Funcionario* proximo;
    struct Funcionario* anterior;
} Funcionario;

typedef struct ListaFuncionarios {
    Funcionario* primeiro;
    Funcionario* ultimo;
} ListaFuncionarios;

void inserir(ListaFuncionarios* lista, char nome[50], float salario) {
    Funcionario* novo_funcionario = (Funcionario*)malloc(sizeof(Funcionario));
    strcpy(novo_funcionario->nome, nome);
    novo_funcionario->salario = salario;
    novo_funcionario->proximo = NULL;
    novo_funcionario->anterior = NULL;

    if (lista->primeiro == NULL) {
        lista->primeiro = novo_funcionario;
        lista->ultimo = novo_funcionario;
    } else if (salario <= lista->primeiro->salario) {
        novo_funcionario->proximo = lista->primeiro;
        lista->primeiro->anterior = novo_funcionario;
        lista->primeiro = novo_funcionario;
    } else if (salario >= lista->ultimo->salario) {
        novo_funcionario->anterior = lista->ultimo;
        lista->ultimo->proximo = novo_funcionario;
        lista->ultimo = novo_funcionario;
    } else {
        Funcionario* atual = lista->primeiro;
        while (atual->proximo && atual->proximo->salario < salario) {
            atual = atual->proximo;
        }

        novo_funcionario->proximo = atual->proximo;
        novo_funcionario->anterior = atual;
        atual->proximo->anterior = novo_funcionario;
        atual->proximo = novo_funcionario;
    }
}

void exibir_salarios(ListaFuncionarios* lista, float imposto) {
    Funcionario* atual = lista->primeiro;
    while (atual) {
        float salario_liquido = atual->salario * (1 - imposto / 100);
        printf("%s: R$%.2f\n", atual->nome, salario_liquido);
        atual = atual->proximo;
    }
}

void exibir_por_letra(ListaFuncionarios* lista, char letra) {
    Funcionario* atual = lista->primeiro;
    while (atual) {
        if (tolower(atual->nome[0]) == tolower(letra)) {
            printf("%s\n", atual->nome);
        }
        atual = atual->proximo;
    }
}

int main() {
    ListaFuncionarios lista;
    lista.primeiro = NULL;
    lista.ultimo = NULL;

    char nome[50];
    float salario;

    for (int i = 0; i < 6; i++) {
        printf("Digite o nome do funcionário: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';
        
        printf("Digite o salário do funcionário: ");
        scanf("%f", &salario);
        getchar(); // Limpa o buffer do teclado
        
        inserir(&lista, nome, salario);
        printf("\n");
    }

    float imposto;
    printf("Digite a porcentagem do imposto a ser aplicado: ");
    scanf("%f", &imposto);
    printf("\nSalários dos funcionários - após dedução do imposto:\n");
    exibir_salarios(&lista, imposto);

    char letra;
    printf("\nDigite a letra para filtrar os funcionários por nome: ");
    scanf(" %c", &letra);
    printf("\nFuncionários cujos nomes começam com a letra '%c':\n", letra);
    exibir_por_letra(&lista, letra);

    return 0;
}
