#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

struct Queue {
  int front, back, size;
  int capacity;
  int *array;
};

struct Queue *create_q(int capacity) {
  struct Queue *q = (struct Queue*) malloc(sizeof(struct Queue));
  q->capacity = capacity;
  q->front = 0;
  q->back = q->capacity - 1;
  q->size = 0;
  q->array = (int*) malloc(sizeof(int) * q->capacity);
  return q;
}

void destroy_q(struct Queue *q) {
  free(q->array);
  free(q);
}

bool empty(struct Queue *q) {
  return q->size == 0 ? true : false;
}

bool full(struct Queue *q) {
  return q->size == q->capacity ? true : false;
}

void push_back(struct Queue *q, int x) {
  if(full(q)) {
    printf("Queue is full\n");
    return;
  } else {
    q->back = (q->back + 1) % q->capacity; 
    q->array[q->back] = x;
    q->size++;
  }
}

int pop_front(struct Queue *q) {
  if(empty(q)) {
    printf("Queue is empty\n");
    return INT_MIN;
  } else {
    int x = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return x;
  }
}

void show(struct Queue *q) {
  int i = q->front;
  int j = q->back;
  while(i!=j) {
    printf("%d ", q->array[i]);
    i = (i+1) % q->capacity;
  }
  printf("\n");
}

int main() {
  int capacity=8;
  struct Queue *q = create_q(capacity);

  for(int i=0; i<capacity; i++)
    push_back(q, rand() % (256 - 0) + 0);
  show(q);

  pop_front(q);
  pop_front(q);
  pop_front(q);
  show(q);

  push_back(q, rand() % (256 - 0) + 0);
  push_back(q, rand() % (256 - 0) + 0);
  show(q);

  destroy_q(q);
  return 0;
}
