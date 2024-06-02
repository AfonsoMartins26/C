typedef struct slist {
    int valor;
    struct slist *prox;
} * LInt;

typedef LInt Stack;

typedef struct {
    LInt inicio, fim;
} Queue;

typedef struct dlist {
    int valor;
    struct dlist *ant, *prox;
} * DList;

typedef struct {
    DList back, front;
} Deque;

LInt newLInt(int x, LInt xs) {
    LInt r = malloc(sizeof(struct slist));
    if (r != NULL) {
        r->valor = x;
        r->prox = xs;
    }
    return r;
}

//1

//a
void initStack(Stack *s) {
    *s = NULL;
}

//b
int SisEmpty(Stack s) {
    return s == NULL;
}

//c

int push(Stack *s, int x) {
    *s = newLInt(x, *s);
    return *s != NULL;
}

//d

int pop(Stack *s, int *x) {
    if (SisEmpty(*s))
        return 0;
    *x = (*s)->valor;
    LInt temp = *s;
    *s = (*s)->prox;
    free(temp);
    return 1;
}

//e

int top(Stack s, int *x) {
    if (SisEmpty(s))
        return 0;
    *x = s->valor;
    return 1;
}

//2

//a
void initQueue(Queue *q) {
    q->inicio = q->fim = NULL;
}

//b
int QisEmpty(Queue q) {
    return q.inicio == NULL;
}

//c

int enqueue(Queue *q, int x) {
    LInt novo = newLInt(x, NULL);
    if (novo == NULL)
        return 0;
    if (QisEmpty(*q))
        q->inicio = novo;
    else
        q->fim->prox = novo;
    q->fim = novo;
    return 1;
}

//d

int dequeue(Queue *q, int *x) {
    if (QisEmpty(*q))
        return 0;
    *x = q->inicio->valor;
    LInt temp = q->inicio;
    q->inicio = q->inicio->prox;
    free(temp);
    if (q->inicio == NULL)
        q->fim = NULL;
    return 1;
}


//e

int front(Queue q, int *x) {
    if (QisEmpty(q))
        return 0;
    *x = q.inicio->valor;
    return 1;
}


//4

//a
void initDeque(Deque *q) {
    q->back = q->front = NULL;
}

//b

int DisEmpty(Deque q) {
    return q.back == NULL && q.front == NULL;
}

//c

int pushBack(Deque *q, int x) {
    DList novo = malloc(sizeof(struct dlist));
    if (novo == NULL)
        return 0;
    novo->valor = x;
    novo->prox = NULL;
    if (DisEmpty(*q))
        q->front = novo;
    else {
        novo->ant = q->back;
        q->back->prox = novo;
    }
    q->back = novo;
    return 1;
}

//d

int pushFront(Deque *q, int x) {
    DList novo = malloc(sizeof(struct dlist));
    if (novo == NULL)
        return 0;
    novo->valor = x;
    novo->ant = NULL;
    if (DisEmpty(*q))
        q->back = novo;
    else {
        novo->prox = q->front;
        q->front->ant = novo;
    }
    q->front = novo;
    return 1;
}

//e

int popBack(Deque *q, int *x) {
    if (DisEmpty(*q))
        return 0;
    *x = q->back->valor;
    DList temp = q->back;
    q->back = q->back->ant;
    if (q->back != NULL)
        q->back->prox = NULL;
    else
        q->front = NULL;
    free(temp);
    return 1;
}

//f

int popFront(Deque *q, int *x) {
    if (DisEmpty(*q))
        return 0;
    *x = q->front->valor;
    DList temp = q->front;
    q->front = q->front->prox;
    if (q->front != NULL)
        q->front->ant = NULL;
    else
        q->back = NULL;
    free(temp);
    return 1;
}

//g

int popMax(Deque *q, int *x) {
    if (DisEmpty(*q))
        return 0;
    DList current = q->front;
    DList maxNode = q->front;
    *x = q->front->valor;

    while (current != NULL) {
        if (current->valor > *x) {
            *x = current->valor;
            maxNode = current;
        }
        current = current->prox;
    }

    if (maxNode->ant != NULL)
        maxNode->ant->prox = maxNode->prox;
    else
        q->front = maxNode->prox;

    if (maxNode->prox != NULL)
        maxNode->prox->ant = maxNode->ant;
    else
        q->back = maxNode->ant;

    free(maxNode);
    return 1;
}

//h

int back(Deque q, int *x) {
    if (DisEmpty(q))
        return 0;
    *x = q.back->valor;
    return 1;
}

//i

int front(Deque q, int *x) {
    if (DisEmpty(q))
        return 0;
    *x = q.front->valor;
    return 1;
}