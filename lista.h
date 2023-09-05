#include<stdio.h>
#include<stdlib.h>

typedef struct nodo_t{
int item;
struct nodo_t *prox;
}nodo;

typedef struct{
nodo *prim;
nodo *ult;
}lista;

void criaListaVazia(lista *l);
int listaVazia(lista *l);
nodo *listaBuscar(lista *l, int x);
nodo *buscaPosicao(lista *l, int p);
void inserirInicio(lista *l, int x);
void inserirFinal(lista *l, int x);
void inserirPosicao(lista *l, int x, int p);
int removerInicio(lista *l);
int removerFinal(lista *l);
int removerPosicao(lista *l , int p);
void imprimir_linear(lista *l);
void apagaLista(lista *l);
