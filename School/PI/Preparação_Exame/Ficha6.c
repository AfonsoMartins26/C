#include <stdio.h>
#include <stdlib.h>

#define Max 10

//1

struct staticStack {
int sp;
int values [Max];
} STACK, *SStack;

//a

void SinitStack (SStack s){
  s->sp=0;
}

//b 

int SisEmpty (SStack s){
  if(s->sp == 0){
    return 1;
  }
  else return 0 ;
}

//c 

int Spush (SStack s, int x){
  if (s->sp == Max) {
    return 1;
  }
  else{
    s->values[s->sp] = x;
    s->sp++;
    return 0;
  }
}

//d 

int Spop (SStack s, int *x){
  if (s->sp == 0 ){
    return 1;
  }
  else {
    s->sp--;
    *x=s->values[s->sp];
    s->sp++;
    return 0;
  } 
}

//e 

int Stop (SStack s, int *x){
  if (s->sp == 0) return 1;
  else {
    *x = s->values[s->sp];
    return 0;
  }
}


//2 

struct staticQueue {
int front;
int length;
int values [Max];
} QUEUE, *SQueue;

//a 
void SinitQueue (SQueue q){
    q->length = 1;
    q->front = 0;
}

//b 

int SisEmptyQ (SQueue q){
  if (q->length==0) return 1;
  else return 0;
}

//c 

int Senqueue(SQueue q, int x) {
    if (q->length >= Max) {
        return 1; 
    } else {
        int rear = (q->front + q->length) % Max; 
        q->values[rear] = x;
        q->length++; 
        return 0; 
    }
}

//d

int Sdequeue(SQueue q, int *x) {
    if(SisEmptyQ(q)) {
        return 1;
    }

    *x = q->values[q->front];
    q->front = (q->front + 1) % Max;
    q->length--;

    return 0;
}


//e 

int Sfront(SQueue q, int *x) {
    if(SisEmptyQ(q)) {
        return 1;
    }

    *x = q->values[q->front];

    return 0;
}

//3

typedef struct dinStack {
    int size;
    int sp;
    int *values;
} *DStack;

void DinitStack(DStack s) {
    s->size = 2;
    s->sp = 0;
    s->values = (int *)malloc(s->size * sizeof(int));
}

int DisEmpty(DStack s) {
    return s->sp == 0;
}

int Dpush(DStack s, int x) {
    if (s->sp >= s->size) {
        s->size *= 2;
        s->values = (int *)realloc(s->values, s->size * sizeof(int));
        if (s->values == NULL) {
            return 1;
        }
    }
    s->values[s->sp++] = x;
    return 0;
}

int Dpop(DStack s, int *x) {
    if (DisEmpty(s)) {
        return 1;
    }
    *x = s->values[--s->sp];
    return 0;
}

int Dtop(DStack s, int *x) {
    if (DisEmpty(s)) {
        return 1;
    }
    *x = s->values[s->sp - 1];
    return 0;
}

void DdestroyStack(DStack s) {
    free(s->values);
    free(s);
}


typedef struct dinQueue {
    int size;
    int front;
    int length;
    int *values;
} *DQueue;

void DinitQueue(DQueue q) {
    q->size = 2;
    q->front = 0;
    q->length = 0;
    q->values = (int *)malloc(q->size * sizeof(int));
}

int DisEmptyQ(DQueue q) {
    return q->length == 0;
}

int Denqueue(DQueue q, int x) {
    if (q->length >= q->size) {
        q->size *= 2;
        q->values = (int *)realloc(q->values, q->size * sizeof(int));
        if (q->values == NULL) {
            return 1;
        }
    }
    int rear = (q->front + q->length) % q->size;
    q->values[rear] = x;
    q->length++;
    return 0;
}

int Ddequeue(DQueue q, int *x) {
    if (DisEmptyQ(q)) {
        return 1;
    }
    *x = q->values[q->front];
    q->front = (q->front + 1) % q->size;
    q->length--;
    return 0;
}

int Dfront(DQueue q, int *x) {
    if (DisEmptyQ(q)) {
        return 1;
    }
    *x = q->values[q->front];
    return 0;
}

void DdestroyQueue(DQueue q) {
    free(q->values);
    free(q);
}
