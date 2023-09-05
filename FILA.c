#include<stdio.h>
#include<stdlib.h>
#include "fila.h"

void criaFilaVazia(fila *q){
q->inicio = malloc(sizeof(nodo));
q->fim = q->inicio;
q->inicio->prox = NULL;
}

int filaVazia(fila *q){
    return q->inicio == q->fim;
}

void enfileira(fila *q, int x){
    q->fim->prox = malloc(sizeof(nodo));
    q->fim = q->fim->prox;
    q->fim->item = x;
    q->fim->prox = NULL;
}

int desenfileira(fila *q){
int x = -1;
    if(filaVazia(q)){
        printf("Underflow: fila vazia \n");    
        return x;
    }
    else{
    nodo *aux = q->inicio;
    q->inicio = q->inicio->prox;
    x = q->inicio->item;
    aux->prox = NULL;
    free(aux);
    return x;
    }
}

void apagaFila(fila *q){
    while(!filaVazia(q)){
        desenfileira(q);
    }
    free(q->inicio);
    q->inicio = NULL;
    q->fim  = NULL;
}

int main(){
fila *q = malloc(sizeof(fila));
criaFilaVazia(q);
int i;
for(i = 0 ; i<10; i++){
    enfileira(q,i);
    printf("enfileirou %d \n",i);
}
while(!filaVazia(q)){
    i = desenfileira(q);
    printf("desenfileirou %d \n",i);
}

free(q);
}