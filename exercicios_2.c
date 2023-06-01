#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Funcionario {
    char nome[50];
    float salario;
    struct Funcionario* proximo;
} Funcionario;

typedef struct ListaFuncionarios {
    Funcionario* primeiro;
} ListaFuncionarios;

void inserir(ListaFuncionarios* lista, char nome[], float salario) {
    Funcionario* novo_funcionario = (Funcionario*)malloc(sizeof(Funcionario));
    strcpy(novo_funcionario->nome, nome);
    novo_funcionario->salario = salario;
    novo_funcionario->proximo = NULL;

    if (lista->primeiro == NULL || salario >= lista->primeiro->salario) {
        novo_funcionario->proximo = lista->primeiro;
        lista->primeiro = novo_funcionario;
    }
    else {
        Funcionario* atual = lista->primeiro;
        while (atual->proximo != NULL && salario < atual->proximo->salario) {
            atual = atual->proximo;
        }
        novo_funcionario->proximo = atual->proximo;
        atual->proximo = novo_funcionario;
    }
}

void exibir(ListaFuncionarios* lista) {
    Funcionario* atual = lista->primeiro;
    while (atual != NULL) {
        printf("Nome: %s, Salário: %.2f\n", atual->nome, atual->salario);
        atual = atual->proximo;
    }
}

void exibirMaiorSalario(ListaFuncionarios* lista) {
    Funcionario* atual = lista->primeiro;
    float maiorSalario = 0;

    // Encontra o maior salário
    while (atual != NULL) {
        if (atual->salario > maiorSalario) {
            maiorSalario = atual->salario;
        }
        atual = atual->proximo;
    }

    // Exibe os funcionários com o maior salário
    atual = lista->primeiro;
    while (atual != NULL) {
        if (atual->salario == maiorSalario) {
            printf("Funcionário com maior salário:\n");
            printf("Nome: %s, Salário: %.2f\n", atual->nome, atual->salario);
        }
        atual = atual->proximo;
    }
}

float calcularMediaSalarios(ListaFuncionarios* lista) {
    Funcionario* atual = lista->primeiro;
    float somaSalarios = 0;
    int contador = 0;

    // Calcula a soma dos salários e o contador
    while (atual != NULL) {
        somaSalarios += atual->salario;
        contador++;
        atual = atual->proximo;
    }

    // Calcula a média dos salários
    float mediaSalarios = somaSalarios / contador;
    return mediaSalarios;
}

int contarFuncionariosSuperior(ListaFuncionarios* lista, float valor) {
    Funcionario* atual = lista->primeiro;
    int contador = 0;

    // Conta o número de funcionários com salário superior ao valor fornecido
    while (atual != NULL) {
        if (atual->salario > valor) {
            contador++;
        }
    }
}