#include<stdio.h>
#include<stdlib.h>
#include "pilha.h"

void CriaPilhaVazia(pilha *s){
s->topo = malloc(sizeof(pilha));
s->fundo = s->topo;
s->topo->prox  = NULL; 
}

int pilhaVazia(pilha *s){
return s->topo == s->fundo;
}

void empilha(pilha *s, int x){
    nodo *novo = malloc(sizeof(nodo));
    novo->prox = s->topo;
    s->topo->item = x;
    s->topo = novo;
}

int desempilha(pilha *s){
nodo *aux = malloc(sizeof(nodo));
int x = -1;
   if(pilhaVazia(s)){
           printf("Underflow \n"); 
           return x;   
   }
    else{
        aux = s->topo;
        s->topo = aux->prox;
        x = aux->prox->item;
        return x;        
    }
free(aux);
}

void apagaPilha(pilha *s){
while(!pilhaVazia)
    desempilha(s);
free(s->topo);
s->topo = NULL;
s->fundo = NULL;
}

int main(){
pilha *s = malloc(sizeof(pilha));
CriaPilhaVazia(s);
int i,n;
printf("tamanho do pilha \n");
scanf("%d", &n);
for(i=0;i<n;i++){
    empilha(s,i);
    printf("elemento empilhado %d \n",i);
}


while(!pilhaVazia(s)){
    i = desempilha(s);
    printf("desempilhado  %d \n",i);
}

free(s);
}
