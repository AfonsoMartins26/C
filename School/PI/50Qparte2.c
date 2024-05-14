typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;

//1

int length (LInt l){
  int count = 0;
  while(l->prox != NULL){
    count++;
    l = l->prox;
  }
  return count;
}

//2
 
void freeL (LInt l){
  LInt aux;
  while(l!=NULL) {
    aux=l;
    l=l->prox;
    free(aux);
}
}

//3

void imprimeL (LInt l){
  while (l->prox != NULL)
  {
  printf( "%d\n", l->valor );
  l = l->prox;
  }
}

//4

LInt reverseL(LInt l){
	LInt front, back = NULL;

	while(l) {
		front = l->prox;
		l->prox = back;
		back = l;
		l = front;
	}

	return back;
}


//5 não faz sentido a lsita ser ordenada do maior elemnto para o menor mas ok 

void insertOrd (LInt *l, int n){
  LInt nova;
  nova = malloc(sizeof(struct lligada));
  nova->valor = n;
  nova->prox = NULL;
  while(*l !=NULL && (*l)->valor< n){
    l = &( (*l)->prox);
  }
  nova->prox = (*l);  // vai passar de NULL para o valor 
  (*l) = nova; // como vai passar a ser nova vai ter o elemento 
}

//outra resolucao 

void insertOrd(LInt *l, int elemento) {
    LInt novo = malloc(sizeof(struct lligada));
    novo->valor = elemento;
    novo->prox = NULL;

    if (*l == NULL || elemento <= (*l)->valor) {
        novo->prox = *l;
        *l = novo;
    } else {
        LInt atual = *l;
        while (atual->prox != NULL && atual->prox->valor < elemento) {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
    }
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

void merge (LInt *r, LInt a, LInt b){
  while(a != NULL || b != NULL){
    if ((a != NULL && b!NULL && a->valor < b->valor)|| b == NULL ){
        *r = a;
        a = a->prox;
    }
    else {
      *r = b;
      b = b->prox;
    }
    r = &((*r)->prox);
  }
  r* = NULL; //iltimo elemento 
}

//8

void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
  while(l){
    if(l->valor<x){
      *mx = l;
      mx = &((*mx)->prox);
    }
    else{
      *Mx = l;
      Mx =&((*Mx)->prox);
    }
    l=l->prox;
  }
  *mx=NULL;
  *Mx=NULL;
}

//9

LInt parteAmeio(LInt *l) {
    int n = length(*l) / 2;

    if (n == 0) return NULL;

    LInt x = (*l);
    LInt y = NULL;
    
    for (int i = 0; i < n; i++) {
        y = (*l);
        *l = (*l)->prox;
    }

    y->prox = NULL;
    return x;
}


//10

int removeAll(LInt *l, int n) {
    int count = 0;
    LInt temp;
    while (*l != NULL) {
        if ((*l)->valor == n) {
            temp = *l;
            *l = (*l)->prox;
            free(temp);
            count++;
        } 
            l = &((*l)->prox);
    }
    return count;
}

//11

int removeDups(LInt *l) {
  int count = 0;
  for (int i = 0 ;i < length(*l);i++){
    LInt primerio = (*l);
    LInt segundo = (*l)->prox;
    for (i = 0;i < length(*l);i++){
      if(primerio->valor == (*l)->valor){
        count++;
        primerio->prox = segundo->prox;
        free(segundo);
      }
      else {
        primerio = segundo;
      }
    }
    return count;
  }
}


//12

int removeMaiorL(LInt *l) {

    int maiorvalor = (*l)->valor;
    LInt temp = *l;
    LInt anterior = NULL;

    while (temp->prox != NULL) {
        if (temp->prox->valor > maiorvalor) {
            maiorvalor = temp->prox->valor;
            anterior = temp;
        }
        temp = temp->prox;
    }

    if (anterior == NULL) {
        temp = *l;
        *l = (*l)->prox;
    } else {
        temp = anterior->prox;
        anterior->prox = temp->prox;
    }

    int valorRemovido = temp->valor;
    free(temp);
    return valorRemovido;
}


//13

void init (LInt *l){
  LInt temp;
  while ((*l)->prox != NULL){
    l = &((*l)->prox);
  }
  temp = *l;
  *l =NULL;
  free(temp);
}

//14


void appendL(LInt *l, int n) {
    LInt mais;
    mais = malloc(sizeof(struct lligada));
    mais->prox = NULL;
    mais->valor = n;

    if (*l == NULL) {
        *l = mais;
    } else {
        LInt temp = *l;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = mais
    }
}

//15

void concatL(LInt *a, LInt b) {
    if (*a == NULL) {
        *a = b;
    } else {
        LInt temp = *a;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = b;
    }
}


//16

LInt cloneL (LInt l){
    LInt r = NULL;
    LInt sitio;

    while (l->prox != NULL)
    {
        (*sitio)->valor = l->valor;
		    l = l->prox;
		    sitio = &( (*sitio)->prox );
    }
    *sitio = NULL;

    return sitio;
}


//17

LInt cloneRev(LInt l) {
    LInt nova_lista = NULL;

    while (l != NULL) {
        LInt novo_no = malloc(sizeof(struct lligada));
        novo_no->valor = l->valor;
        novo_no->prox = nova_lista;
        nova_lista = novo_no;
        l = l->prox;
    }
    nova_lista =  NULL;
    return nova_lista;
}

// 18

int maximo (LInt l){
  int maior = 0;

    while (l){
      if(l->valor >maior){
        maior = l->valor;
      }
      l = l->prox;
  }
  return maior;
}

//19 

int take(int n, LInt *l){
	int i = 0;

	while( i < n && *l ){
		l = &(*l)->prox;
		i++;
	}

	if(!(*l))
		return i;
	
	while(*l){
		LInt temp = (*l)->prox;
		free(*l);
	    *l = temp;
	}

	return n;
}

//20

int drop(int n, LInt *l){

	if(!(*l))
		return 0;

    int i = 0;
	while(i < n && (*l) ){
		LInt temp = (*l);
		*l = (*l)->prox;
		free(temp);
		i++;
	}

	return i;
}

//21

LInt Nforward (LInt l, int N){
  if  (!l || !N) return NULL;
  for(int i = 0;i<N;i++) {
    l =l->prox;
}
return l;
}

//22

int listToArray(LInt l, int v[], int N) {
    int i = 0;
    while (l && i < N) {
        v[i] = l->valor;
        l = l->prox;
        i++;
    }
    return i;
}


//23

LInt arrayToList(int v[], int N){
	LInt head;
	LInt *r = &head;
	int i;

	for(i=0; i < N; i++){
		*r = malloc(sizeof(struct lligada));
		(*r)->valor = v[i];
		r = &(*r)->prox;
	}

	*r = NULL;
	return head;
}


// 24

LInt somasAcL (LInt l){
  LInt temp;
  LInt *s = &temp;
  int soma = 0;
  for(;l ; s = &(*s)->prox){
    *s = malloc(sizeof(struct lligada));
    soma+=l->valor;
    (*s)->valor = soma;
    l = l->prox;
  }
  *s= NULL;
  return temp;
}

//25

void remreps (LInt l){
  LInt *a ;
  int valor ;
  for(;l ;l = l->prox){
    *a = &(l)->prox;
    while (*a && (*a)->valor == l->valor){
      LInt temp  = *a;
      *a = (*a)->prox;
      free(temp);
    }    
  }
}


//26

LInt rotateL(LInt l) {
    if (l == NULL || l->prox == NULL)
        return l;
    
    LInt atual = l;
    LInt novo_primeiro = l->prox;
    
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    
    atual->prox = l;
    l->prox = NULL;
    
    return novo_primeiro;
}


//27

LInt parte(LInt l) {
    LInt y = NULL;
    LInt y_tail = NULL;
    LInt prev = NULL;
    LInt curr = l;
    int pos = 0;

    while (curr != NULL) {
        if (pos % 2 == 0) {
            if (prev == NULL) {
                l = curr->prox;
            } else {
                prev->prox = curr->prox;
            }

            if (y == NULL) {
                y = curr;
                y_tail = curr;
            } else {
                y_tail->prox = curr;
                y_tail = curr;
            }

            curr = curr->prox;
            y_tail->prox = NULL;
        } else {
            prev = curr;
            curr = curr->prox;
        }

        pos++;
    }

    return y;
}