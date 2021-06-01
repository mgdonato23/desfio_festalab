#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bug {
    char nome[50];
    int idade;
    int prioridade;

} Bug;

typedef struct No {
    Bug c;
    struct No *proximo;
} No;

typedef struct Lista {
    int qtd;
    No *topo;
} Lista;


Lista *criar() {
    Lista *li = (Lista*) malloc(sizeof(Lista));
    li->qtd = 0;
    li->topo = NULL;

    return li;
}


void inserir(Lista *l, Bug pbug) {
    No* start = l->topo;

    No *elemento = (No*) malloc(sizeof(No));
    elemento->c = pbug;

    if(l->topo == NULL){
        l->topo = elemento;
        elemento->proximo = NULL;

    }

    else if(l->topo->c.prioridade < pbug.prioridade){
        elemento->proximo = l->topo;
        l->topo = elemento;
    }
    else {

        while (start->proximo != NULL &&
            start->proximo->c.prioridade >= pbug.prioridade) {
            start = start->proximo;
        }

        elemento->proximo = start->proximo;
        start->proximo = elemento;
    }

    l->qtd++;
}

int vazia(Lista *l) {
    return (l->topo == NULL);
}

void imprimir(Lista *l) {
    if(l == NULL)
        printf("\nLista vazia!");
    else {
            No *q = l->topo;
            printf("Sequencia <-");
            while(q != NULL){
            printf("%s - ", q->c.nome);
            q = q->proximo;
        }
    }
}

int cadastraBug(Lista *l) {
    if( l == NULL){
        printf("\nCrie uma lista primeiro!");
        return 0;
    }

    Bug c;

    printf("Título:\n");
    scanf("%s", c.nome);
    printf("Idade(quantos dias atras ele foi reportado):\n");
    scanf("%d", &c.idade);
    printf("Prioridade? [1- CRÍTICO / 0 - NORMAL]:\n");
    scanf("%d", &c.prioridade);

    if(c.idade >= 1){
        c.prioridade = 1;
    }

    inserir(l, c);
    return 1;

}

int main(void)
{

    Lista *l;
    int continuar=1;

        do
        {
            printf("\n--------------------------------------\n");
            printf("\nBem vindo ao desafio da FestaLab\n\n");
            printf("1. Criar Lista\n");
            printf("2. Inserir Bug\n");
            printf("3. Imprimir lista de bugs\n");
            printf("\n--------------------------------------\n");

            scanf("%d", &continuar);
            system("cls || clear");

            switch(continuar)
            {
                case 1:
                    l = criar();
                    printf("Lista criada com sucesso!\n");
                    break;

                case 2:
                    cadastraBug(l);
                    break;

                case 3:
                    imprimir(l);
                    break;


                default:
                    printf("Digite uma opcao valida\n");
            }
        } while(continuar);


    return 0;
}
