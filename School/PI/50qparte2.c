#include <stdio.h>

typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;


//1 

int length (LInt l){
  int tamanho = 0;
  while(l->prox != NULL){
    tamanho++;
  }
  return tamanho;
}

//2

void freeL(LInt l) {
    LInt atual = l;
    LInt proximo;
    
    while (atual != NULL) {
        proximo = atual->prox; 
        free(atual); 
        atual = proximo; 
    }
}

//3 

void imprimeL (LInt l){
  while (l->prox != NULL)
  {
    printf( "%d ", l->valor );
    l = l->prox;
  }  
}


//4

LInt reverseL(LInt l){
	LInt front, back = NULL;

	while(l->prox!= NULL) {
		front = l->prox;
		l->prox = back;
		back = l;
		l = front;
	}

	return back;
}


//5 

void insertOrd(LInt *l, int n) {
    LInt novo = malloc(sizeof(struct lligada));
    novo->valor = n;
    novo->prox = NULL;
    LInt atual = *l;
    if (atual == NULL || n < atual->valor) {
        novo->prox = atual;
        atual = novo;
        return;
    }

    while (atual->prox != NULL && n > atual->prox->valor) {
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
}

//6 

int removeOneOrd (LInt *l, int x){
    int ans = 1;
    
    for (; *l && (*l)->valor < x; l = &(*l)->prox);
    
    if (*l && (*l)->valor == x) {
        ans = 0;
        LInt temp = *l;
        *l = (*l)->prox;
        free(temp);
    }
    
    return ans;
}

//7

void merge(LInt *r, LInt a, LInt b){
    
	while(a != NULL || b != NULL){
		if( (a != NULL && b != NULL && a->valor < b->valor) || b == NULL){
			*r = a;
			a = a->prox;
		} else {
			*r = b;
			b = b->prox;
		}
		r = &( (*r)->prox);
	}
	*r = NULL;
}


//8 

void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
  while(l){
  if (l->valor<x) {
    (*mx) = l;
    mx = &((*mx)->prox);
  }
  else {
    (*Mx) = l;
    Mx = &( (*Mx)->prox);
  }
  l=l->prox;
  }
  *mx = NULL;
  *Mx = NULL;
}

//9

LInt parteAmeio (LInt *l){
    int meio = length(*l)/2;

    if(meio == 0) 
    	return NULL;
    
    LInt y = (*l);
    LInt prev = NULL;
    for(int i = 0; i < meio; i++) {
        prev = (*l);
        (*l) = (*l)->prox;
    }
    prev->prox = NULL;
    return y;
}

//10

int removeAll(LInt *l, int x) {
    int count = 0;

    while ((*l)->prox != NULL) {
        if ((*l)->valor == x) {
            LInt temp = *l;
            *l = (*l)->prox;
            free(temp);
            count++;
        } else {
            l = &(*l)->prox;
        }
    }

    return count;
}

//11 ver outra vez 

int removeDups(LInt *l) {
    int count = 0;
    LInt current = *l;

    while (current != NULL && current->prox != NULL) {
        LInt runner = current;

        while (runner->prox != NULL) {
            if (runner->prox->valor == current->valor) {
                LInt temp = runner->prox;
                runner->prox = runner->prox->prox;
                free(temp);
                count++;
            } else {
                runner = runner->prox;
            }
        }

        current = current->prox;
    }

    return count;
}

//12 vdr outra vez 

int removeMaiorL(LInt *l){
	LInt maior;
	LInt ant;
	LInt aux = *l;
	
	int maiorValor = 0;

	for(; aux ; aux = aux->prox ){
		if(aux->valor > maiorValor){
			maiorValor = aux->valor;
			maior = aux;
		}
	}

	while(aux->valor != maiorValor){
		ant = aux;
		aux = aux->prox;
	}
    
    ant->prox = maior->prox;
    free(maior);
    *l = NULL;
    
	return maiorValor;
}

//13

void init(LInt *l){

	while( (*l)->prox != NULL ){
		l = &(*l)->prox;
  }
  
	free(*l);
	*l = NULL;
}

//14 ver outra vez 
void appendL(LInt *l, int x) {
    LInt newNode = malloc(sizeof(struct lligada));
    newNode->valor = x;
    newNode->prox = NULL;

    if (*l == NULL) {
        *l = newNode;
    } else {
        LInt current = *l;
        while (current->prox != NULL) {
            current = current->prox;
        }
        current->prox = newNode;
    }
}

//15 

void concatL (LInt *a, LInt b){

	while( *a ){
		a = &( (*a)->prox );
}

	(*a) = b;
}

//16

LInt cloneL (LInt l){
    LInt r = NULL;
    LInt sitio;

    sitio = &r;
    while (l->prox != NULL)
    {
        (*sitio)->valor = l->valor;
		l = l->prox;
		sitio = &( (*sitio)->prox );
    }
    *sitio = NULL;

    return r;
}


//17
 
LInt cloneRev (LInt l) {
    LInt new = NULL, list = NULL;

    for (; l; l = l->prox) {
        new = malloc(sizeof(struct lligada));
        new->valor = l->valor;
        new->prox = list;
        list = new;
    }
    
    return list;
}

//18 

int maximo (LInt l){
    int maior = 0;
    while(l){
        if (l->valor > maior)
        {
           maior = l->valor;
           l = l->prox;
        }
        else{
            l = l->prox;
        }
    }
    return maior;
}


//19 não sei se está certo 

int take (int n, LInt *l){
    int i;
    if(length(l)<=n){
        return length(l);
    }
    else {

	while( i < n && *l ){
		l = &(*l)->prox;
		i++;
	}
	while(*l){
		LInt temp = (*l)->prox;
		free(*l);
	    *l = temp;
	}

	return n;
    }

}

//20 

int drop(int n, LInt *l) {
    int count = 0;
    LInt temp;

    if (length(*l) <= n) {
        while (*l) {
            temp = *l;
            *l = (*l)->prox;
            free(temp);
            count++;
        }
    } else { 
        for (int i = 0; i < n; i++) {
            temp = *l;
            *l = (*l)->prox;
            free(temp);
            count++;
        }
    }
    return count;
}

//21 

LInt Nforward (LInt l, int N){
    for(int i = 0;i <N,i++){
        l = l->prox;
    }
    return l;
}

//22 

int listToArray(LInt l, int v[], int N) {
    if (l == NULL || N <= 0) {
        return 0; 
    }

    int count = 0;
    int i;
    for (i = 0; i < N && l != NULL; i++) {
        v[i] = l->valor;
        l = l->prox;
        count++;
    }
    return count;
}

//23 

LInt arrayToList(int v[], int N) {
    LInt inicio = NULL;
    LInt atual = NULL;

    if (N > 0) {
        for (int i = 0; i < N; i++) {
            LInt novo = malloc(sizeof(struct lligada));
            novo->valor = v[i];
            novo->prox = NULL;

            if (inicio == NULL) {
                inicio = novo;
                atual = novo;
            } else {
                atual->prox = novo;
                atual = atual->prox;
            }
        }
    }
    return inicio;
}

//24 

LInt somasAcL(LInt l) {
    LInt res = NULL;
    LInt atualRes = NULL;
    int soma = 0;

    while (l) {
        LInt novo = malloc(sizeof(struct lligada));
        soma += l->valor;
        novo->valor = soma;
        novo->prox = NULL;

        if (res == NULL) {
            res = novo;
            atualRes = novo;
        } else {
            atualRes->prox = novo;
            atualRes = atualRes->prox;
        }

        l = l->prox;
    }

    return res;
}


//25

void remreps (LInt l){
    for (; l; l = l->prox) {
        LInt *c = &(l->prox);
        while (*c && (*c)->valor == l->valor) {
            LInt temp = *c;
            *c = (*c)->prox;
            free(temp);
        }
    }
}

//26 

LInt rotateL(LInt l){
	
	if(!l || !(l->prox))
		return l;
	
	LInt aux = l;
	LInt head = l->prox;

	while(aux->prox)
		aux = aux->prox;

	aux->prox = l;
	l->prox = NULL;

	return head;
}


//27

LInt parte (LInt l){
    LInt head, *p = &head, *i = &l;
    int j;
    for (j = 0; *i; j++) {
        if ((j%2)) {
            *p = *i;
            *i = (*i)->prox;
            p = &(*p)->prox;
           
        }
        else 
            i = &(*i)->prox;
    }
    *p = NULL;
    return head;
}

