#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do aluno
typedef struct Aluno {
    char nome[50];
    float nota;
    struct Aluno* proximo;
    struct Aluno* anterior;
} Aluno;

// Função para criar um novo nó aluno
Aluno* criarAluno(char nome[], float nota) {
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    strcpy(novoAluno->nome, nome);
    novoAluno->nota = nota;
    novoAluno->proximo = NULL;
    novoAluno->anterior = NULL;
    return novoAluno;
}

// Função para inserir um aluno no início da lista
void inserirAluno(Aluno** lista, Aluno* aluno) {
    if (*lista == NULL) {
        *lista = aluno;
    } else {
        aluno->proximo = *lista;
        (*lista)->anterior = aluno;
        *lista = aluno;
    }
}

// Função para exibir a lista de alunos com nota 7 ou superior
void exibirAlunos(Aluno* lista) {
    Aluno* atual = lista;
    int encontrou = 0;
    printf("Alunos com nota 7 ou superior:\n");
    while (atual != NULL) {
        if (atual->nota >= 7.0) {
            printf("Nome: %s, Nota: %.2f\n", atual->nome, atual->nota);
            encontrou = 1;
        }
        atual = atual->proximo;
    }
    if (!encontrou) {
        printf("Nenhum aluno com nota 7 ou superior encontrado.\n");
    }
}

// Função principal
int main() {
    Aluno* lista = NULL;
    int i;
    
    // Cadastro dos 5 alunos
    for (i = 0; i < 5; i++) {
        char nome[50];
        float nota;
        
        printf("Aluno %d:\n", i+1);
        printf("Nome: ");
        fgets(nome, 50, stdin);
        printf("Nota final: ");
        scanf("%f", &nota);
        getchar(); // Limpar o caractere de nova linha do buffer
        
        Aluno* novoAluno = criarAluno(nome, nota);
        inserirAluno(&lista, novoAluno);
    }
    
    // Exibir alunos com nota 7 ou superior
    exibirAlunos(lista);
    
    return 0;
}
