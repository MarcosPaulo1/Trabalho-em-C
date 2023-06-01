#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do produto
typedef struct Produto {
    int codigo;
    float preco;
    int quantidade;
    struct Produto *prox;
} Produto;

// Função para cadastrar um novo produto
Produto* cadastrarProduto(Produto *lista) {
    Produto *novoProduto = (Produto*) malloc(sizeof(Produto));
    printf("Digite o código do produto: ");
    scanf("%d", &(novoProduto->codigo));
    printf("Digite o preço do produto: ");
    scanf("%f", &(novoProduto->preco));
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &(novoProduto->quantidade));
    novoProduto->prox = lista;
    return novoProduto;
}

// Função para exibir os produtos cadastrados
void exibirProdutos(Produto *lista) {
    printf("Produtos cadastrados:\n");
    Produto *atual = lista;
    while (atual != NULL) {
        printf("Código: %d\n", atual->codigo);
        printf("Preço: %.2f\n", atual->preco);
        printf("Quantidade: %d\n", atual->quantidade);
        printf("----------------------\n");
        atual = atual->prox;
    }
}

// Função para aplicar desconto aos produtos
void aplicarDesconto(Produto *lista, int percentualDesconto) {
    Produto *atual = lista;
    while (atual != NULL) {
        float desconto = (percentualDesconto / 100.0) * atual->preco;
        atual->preco -= desconto;
        atual = atual->prox;
    }
}

// Função para exibir os produtos com mais de 500 unidades em estoque
void exibirProdutosEstoque(Produto *lista) {
    printf("Produtos com mais de 500 unidades em estoque:\n");
    Produto *atual = lista;
    while (atual != NULL) {
        if (atual->quantidade > 500) {
            printf("Código: %d\n", atual->codigo);
            printf("Preço: %.2f\n", atual->preco);
            printf("Quantidade: %d\n", atual->quantidade);
            printf("----------------------\n");
        }
        atual = atual->prox;
    }
}

int main() {
    Produto *lista = NULL; // Inicializa a lista vazia

    // Cadastra 5 produtos
    for (int i = 0; i < 5; i++) {
        printf("Cadastro do produto %d:\n", i+1);
        lista = cadastrarProduto(lista);
    }

    // Exibe os produtos cadastrados
    exibirProdutos(lista);

    // Aplica desconto
    int percentualDesconto;
    printf("Digite o percentual de desconto: ");
    scanf("%d", &percentualDesconto);
    aplicarDesconto(lista, percentualDesconto);

    // Exibe os produtos com desconto
    printf("Produtos com desconto:\n");
    exibirProdutos(lista);

    // Exibe os produtos com mais de 500 unidades em estoque
}
   
