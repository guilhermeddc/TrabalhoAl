#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


typedef struct Produto {
    int id;
    char nome[30];
    float preco;
    int qtd;
}prod ;

prod *a;

prod AdicionarProduto(int n, prod x[n]) {
    printf("\n\nAdicionar Produtos: \n\n");
    for (int i = 0; i < n; ++i) {
        printf("Id: ");
        scanf("%d", &x[i].id);
        printf("Nome: ");
        gets(x[i].nome);
        printf("Preco: ");
        scanf("%f", &x[i].preco);
        printf("Quantidade: ");
        scanf("%d", &x[i].qtd);
    }
}

void CriaArquivoOuAbreArquivo(char *n) {
    a = (prod *) malloc(sizeof(prod));
    if (access(n, F_OK) != -1) {
        // existe
        FILE *f = fopen(n, "r");
        int cod = fread(a, sizeof(prod), 1, f);
        fclose(f);
    } else {
        // nao existe
        printf("Arquivo criado!\n\n");
    }
}

void InseriDadosNoArquivo(prod *a, char *arq, int num) {
    int i;
    FILE *f = fopen(arq, "a");
    for (i = 0; i < num; ++i) {
        fprintf(f, "%d|%s|%.2f|%d\n", a[i].id, a[i].nome, a[i].preco, a[i].qtd);
    }
    fclose(f);
}

prod LeArquivo(char *arq) {
    FILE *f;
    char buffer[57];
    int i;
    f = fopen(arq, "r");
    printf("\nConteudo do arquivo %s:\n\n", arq);
    for (i = 0; (!feof(f)); i++) {
        fgets(buffer, 57, f);
        printf("%s", buffer);
    }
    fclose(f);
}

int main() {
    int exercicio;
    do {
        printf("\n\nEscolha uma opção:\n\n");
        printf("Digite 1 para Adicionar um novo produto.\n");
        printf("Digite 2 para Buscar um produto pelo seu nome.\n");
        printf("Digite 3 para Atualizar um produto.\n\n");
        printf("Digite 4 para Listar todos produtos.\n\n");
        printf("Digite 5 para Remover um produto.\n\n");
        scanf("%d", &exercicio);
        switch (exercicio) {
            case 1: {

                break;
            }
            case 2: {

                break;
            }
            case 3: {

                break;
            }
            case 4: {

                break;
            }
            case 5: {

                break;
            }
            default: {
                printf("\n\nDigito invalido!\n\n");
            }
        }
        system("cls");
    } while (exercicio);
    return 0;
}