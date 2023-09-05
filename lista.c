#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

void criaListaVazia(lista *l){
l->prim = NULL;
l->ult = NULL;
}

int listaVazia(lista *l){
return (l->prim == NULL);
}

nodo *listaBuscar(lista *l, int x){
nodo *aux;
aux = l->prim;
while(aux != NULL && aux->item != x){
	aux = aux->prox;
}
return aux;
}

nodo *buscaPosicao(lista *l, int p){
nodo *aux;
aux = l->prim;
int c = 1;
while(aux != NULL && c < p ){
	c++;
	aux = aux->prox;
}
return aux;
}

void inserirInicio(lista *l, int x){
nodo *novo = malloc(sizeof(nodo));
novo->item = x;
novo->prox = l->prim;
l->prim = novo;
// Se a lista estiver vazia
if(listaVazia(l)){ l->ult = l->prim;}
}

void inserirFinal(lista *l, int x){
nodo *novo = malloc(sizeof(nodo));
novo->item = x;
novo->prox = NULL;
// se a lista estiver vazia
if(l->prim == NULL){
	l->prim = novo;
	l->ult = l->prim;
}
else{
l->ult->prox = novo;
l->ult = novo;
}

}

void inserirPosicao(lista *l, int x, int p){
nodo *anterior;
nodo *posterior;
nodo *novo = malloc(sizeof(nodo));
if(p == 1)
	inserirInicio(l,x);
else{
	anterior = l->prim;
	novo->item = x;
	// Busca na posição anterior a p
	anterior = buscaPosicao(l,p-1);
	// Insere entre os nodos
	// Anterior e Posterior
	posterior = anterior->prox;
	anterior->prox = novo;
	novo->prox = posterior;
	if(posterior == NULL){
		l->ult  = novo;	
	}
}
}


int removerInicio(lista *l){
int x = 0;
nodo *aux = malloc(sizeof(nodo));
nodo *anterior;
if(listaVazia(l)){
	printf("Underflow: Lista Vazia \n");
	return x = -1;
}
else{
aux = l->prim;
x = aux->item;
l->prim = l->prim->prox;
// Verifica se tem apenas um nó
if(l->prim == NULL){
	l->ult = NULL;
}
aux->prox = NULL;
free(aux);
return x;
}

}

int removerFinal(lista *l){
int x;
nodo *aux = malloc(sizeof(nodo));
nodo *anterior;
nodo *posterior;
if(listaVazia(l)){
	printf("Underflow: Lista Vazia \n");
	return x = -1;
}
else{
	if(l->prim == l->ult && !listaVazia(l)){
		aux = l->prim;
		l->prim = NULL;
		l->ult = NULL;		
	}
	else{
		anterior = l->prim;
		while(anterior->prox != l->ult){
			anterior = anterior->prox;			
		}
		aux = l->ult;
		anterior->prox = NULL;
		l->ult = anterior; 	
	}
	x = aux->item;
	aux->prox = NULL;
	free(aux);
	return x;
}
}

int removerPosicao(lista *l , int p){
int x;
nodo *aux = malloc(sizeof(nodo));
nodo *anterior;
nodo *posterior;
if(listaVazia(l)){
	printf("Underflow: Lista Vazia \n");
	return x = -1;
}

else{
	if(p == 1){
		x = removerInicio(l);
		return x;
	}
	else{
		anterior = buscaPosicao(l,p-1);
		aux = anterior->prox;
		posterior = aux->prox;
		anterior->prox = posterior;
		if(aux = l->ult){
			l->ult = anterior;			
		}
		x = aux->item;
		aux->prox = NULL;
		free(aux);
		return x;
	}
	
}
}

void imprimir_linear(lista *l){
nodo *aux = malloc(sizeof(nodo));
aux = l->prim;
while(aux != NULL){
	printf("Na lista %d \n",aux->item);
	aux = aux->prox;
}
free(aux);
}

void apagaLista(lista *l){
nodo *aux = malloc(sizeof(nodo));
aux = l->prim;

while(l->prim != NULL){
	l->prim = l->prim->prox;
	free(aux);
	aux = l->prim;
}
}

int tamanho(lista *l){
int c = 0;
if(l->prim == l->ult && !listaVazia(l))
	return c = 1;

else{
	while(l->prim != NULL){
		l->prim = l->prim->prox;
		c++;

	}

}
return c;
}

int main(){
lista *l = malloc(sizeof(lista));
criaListaVazia(l);
int i, n=8;
int y = 0,t;
for(i=0;i<n;i++){inserirFinal(l,i);}
inserirPosicao(l,3,9);
imprimir_linear(l);

while(!listaVazia(l)){
y = removerInicio(l);
printf("Fora da lista %d \n",y);
}

apagaLista(l);
free(l);
return 0;
}
