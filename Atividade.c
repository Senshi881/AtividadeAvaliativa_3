/*
Implementar um sistema de controle de estoque com as funcionalidades de cadastrar produtos, consultar produtos, gerar relatório de produtos e remover produtos do estoque. 
Funções que deverão estar presentes no código:

Função que inicializa uma lista vazia; (0,5 ponto)
Função que adiciona um novo produto à lista de estoque. Ela solicita ao usuário informações como código, descrição, quantidade e valor do produto. (0,5 ponto)
Função que percorre a lista de estoque e imprime um relatório com as informações de cada produto, incluindo código, descrição, quantidade e valor. (0,5 ponto)
Função que permite ao usuário pesquisar um produto pelo código. (0,5 ponto)
Função que permite ao usuário remover um produto do estoque. Ela solicita o código do produto a ser removido e busca na lista o produto correspondente. Se encontrar o
produto, o remove da lista. Caso contrário, exibe uma mensagem informando que o produto não está cadastrado. (1,0 ponto)

O sistema deverá exibir um menu com as opções disponíveis e realizar as chamadas correspondentes às funções acima, de acordo com a escolha do usuário. 
O loop deverá continuar até que o usuário escolha sair do programa.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MaxProdutos 100

typedef struct{
    int codigo, quantidade;
    char descricao[20];
    double valorP;
}Produto;

typedef struct{
    Produto estoque[MaxProdutos];
    int totalProdutos;
}ControleEstoque;

void inicializarEstoque(ControleEstoque *controle){
    controle->totalProdutos = 0;
}

void cadastrarProduto(int *totalProdutos, Produto estoque[]){
    if(*totalProdutos < MaxProdutos){
        printf("\nQual e o codigo do produto? ");
        scanf("%d", &estoque[*totalProdutos].codigo);
        while(getchar() != '\n');
        printf("\nQual e o nome do produto? ");
        fgets(estoque[*totalProdutos].descricao, sizeof(estoque[*totalProdutos].descricao), stdin);
        estoque[*totalProdutos].descricao[strcspn(estoque[*totalProdutos].descricao, "\n")] = '\0';
        fflush(stdin);
        printf("\nQual e o valor do produto? ");
        scanf("%lf", &estoque[*totalProdutos].valorP);
        while(getchar() != '\n');
        printf("\nSao quantos produtos? ");
        scanf("%d", &estoque[*totalProdutos].quantidade);
        while(getchar() != '\n');
        (*totalProdutos)++;
    }else{
        printf("\n*LIMITE DE CADASTRO ATINGIDO*");
    }
}

void consultarProduto(Produto estoque[], int totalProdutos){
    int modificar;
    int codigoF, naoEncontrado = 0;
    printf("\nInsira o codigo do produto: ");
    scanf("%d", &codigoF);
    while(getchar() != '\n');
    for(int i = 0; i < totalProdutos; i++){
        if(codigoF == estoque[i].codigo){
            printf("\n*PRODUTO ENCONTRADO*\nCodigo fornecido: %d; \nProduto: %d;\nCodigo: %d;\nDescricao: %s;\nValor: R$%.2lf;\nQuantidade: %d;\n",codigoF, i + 1, estoque[i].codigo, estoque[i].descricao, estoque[i].valorP, estoque[i].quantidade);
            for (int i = 0; i < 1; i++){
                printf("\nO que deseja modificar do produto %d? \nCodigo - 1; \nDescricao - 2; \nValor - 3; \nQuantidade - 4;\n", i + 1);
                scanf("%d", &modificar);
                while(getchar() != '\n');
                switch(modificar){
                    case 1:
                    printf("\nInsira o novo codigo do produto %d: ", i + 1);
                    scanf("%d", &estoque[i].codigo);
                    while(getchar() != '\n');
                    printf("\n*CODIGO MODIFICADO*");
                    break;
                    case 2:
                    printf("\nInsira o novo nome do produto %d: ", i + 1);
                    fgets(estoque[i].descricao, sizeof(estoque[i].descricao), stdin);
                    estoque[i].descricao[strcspn(estoque[i].descricao, "\n")] = '\0';
                    fflush(stdin);
                    printf("*\nDESCRICAO MODIFICADA*");
                    break;
                    case 3:
                    printf("\nInsira o novo valor do produto %d: ", i + 1);
                    scanf("%lf", &estoque[i].valorP);
                    while(getchar() != '\n');
                    printf("\n*VALOR MODIFICADO*");
                    break;
                    case 4:
                    printf("\nInsira a nova quantidade do produto %d: ", i + 1);
                    scanf("%d", &estoque[i].quantidade);
                    while(getchar() != '\n');
                    printf("\n*QUANTIDADE MODIFICADA*");
                    break;
                    default:
                    printf("\n*INSIRA UMA OPCAO VALIDA*");
                    i--;
                    break;
                }
            }
            naoEncontrado = 1;
        }else if(i == 99 && naoEncontrado == 0){
            printf("\nNao encontra-se produto com codigo %d no estoque", codigoF);
        }
    }
}

void listarProdutos(int totalProdutos, Produto estoque[]){
    printf("\nFoi adicionado um total de %d produtos;", totalProdutos);
    for(int i = 0; i < totalProdutos; i++){
        printf("\nO Produto %d possui: \nCODIGO: %d;\nDESCRICAO: %s;\nVALOR: R$%.2lf;\nQUANTIDADE: %d;\n", i + 1, estoque[i].codigo, estoque[i].descricao, estoque[i].valorP, estoque[i].quantidade);
    }
}

void procurarProduto(int totalProdutos, Produto estoque[]){
    int codigoF, naoEncontrado = 0;
    printf("\nInsira o codigo do produto: ");
    scanf("%d", &codigoF);
    while(getchar() != '\n');
    for(int i = 0; i < totalProdutos; i++){
        if(codigoF == estoque[i].codigo){
            printf("\n*PRODUTO ENCONTRADO*\nCodigo fornecido: %d; \nProduto: %d;\nCodigo: %d;\nDescricao: %s;\nValor: R$%.2lf;\nQuantidade: %d;\n",codigoF, i + 1, estoque[i].codigo, estoque[i].descricao, estoque[i].valorP, estoque[i].quantidade);
            naoEncontrado = 1;
        }else if(i == 99 && naoEncontrado == 0){
            printf("\nNao encontra-se produto com codigo %d no estoque", codigoF);
        }
    }
}

void excluirProduto(int totalProdutos, Produto estoque[]){
    int codigoF, naoEncontrado = 0;
    printf("\nInsira o codigo do produto: ");
    scanf("%d", &codigoF);
    while(getchar() != '\n');
    for(int i = 0; i < totalProdutos; i++){
        if(codigoF == estoque[i].codigo){
            printf("\n*PRODUTO ENCONTRADO*\nCodigo fornecido: %d; \nProduto: %d;\nCodigo: %d;\nDescricao: %s;\nValor: R$%.2lf;\nQuantidade: %d;\n",codigoF, i + 1, estoque[i].codigo, estoque[i].descricao, estoque[i].valorP, estoque[i].quantidade);
            naoEncontrado = 1;
        }else if(i == 99 && naoEncontrado == 0){
            printf("\n*PRODUTO NAO CADASTRADO*");
        }
        
        if(naoEncontrado == 1){
            int resposta;
            printf("\nTem certeza que deseja excluir esse produto? \nSIM - 0; \nNAO - 1;\n");
            scanf("%d", &resposta);
            while(getchar() != '\n');
            if(resposta == 0){
                estoque[i].codigo = 0;
                strncpy(estoque[i].descricao, "Sem informacoes", sizeof(estoque[i].descricao) - 1);
                estoque[i].valorP = 0;
                estoque[i].quantidade = 0;
                printf("\n*PRODUTO EXCLUIDO COM EXITO*");
            } else{
                printf("\n*PRODUTO MANTIDO*");
            }
        }
    }
}

int main(){
    ControleEstoque controle;
    inicializarEstoque(&controle);
    int totalProdutos = 0, reset = 0;
    Produto Estoque[MaxProdutos];
    do{
        int respostaAcao = 0;
        respostaAcao = 0;
        printf("\nO que deseja? \n1 - Cadastrar um novo produto; \n2 - Consultar produto;\n3 - Listar produtos;\n4 - Procurar produto por codigo;\n5 - Excluir produto por codigo;\n");
        scanf("%d", &respostaAcao);
        while(getchar() != '\n');
        switch(respostaAcao){
            case 1:
            cadastrarProduto(&totalProdutos, Estoque);
            break;
            case 2:
            consultarProduto(Estoque, totalProdutos);
            break;
            case 3:
            listarProdutos(totalProdutos, Estoque);
            break;
            case 4:
            procurarProduto(totalProdutos, Estoque);
            break;
            case 5:
            excluirProduto(totalProdutos, Estoque);
            break;
            default:
            printf("\n*RESPOSTA INVALIDA*");
            break;
        }
        printf("\nDeseja realizar mais alguma acao? \n0 - SIM;\n1 - NAO;\n");
        scanf("%d", &reset);
        while(getchar() != '\n');
    }while(reset != 1);

    return 0;
}