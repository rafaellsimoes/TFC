#include<stdio.h>
#include<stdlib.h>

typedef struct nodo_t{
int item;
struct nodo_t *prox;
}nodo;

typedef struct{
nodo *topo, *fundo;
}pilha;

void CriaPilhaVazia(pilha *s);
int pilhaVazia(pilha *s);
void empilha(pilha *s, int x);
int desempilha(pilha *s);

