#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define Q_CAP 8

int Q[Q_CAP];

int front = -1;
int back = -1;

void reset() {
  int front = -1;
  int back = -1;
}

bool empty() {
  if(front == -1)
    return true;
  return front > back? true : false;
}

void push(int x) {
  if(back == Q_CAP-1)
    printf("Q is full. Can't push %d\n", x);
  else {
    if(front == -1)  // if pushing first element
      front = 0;
    Q[++back] = x;
  }
}

int pop() {
  if(empty()) {
    printf("ERROR : Q is empty.\n");
    return -1;
  }
  int x = Q[front++];
  if(front == Q_CAP) {  // if popping last element
    front = -1;
    back = -1;
  }
  return x;
}

void print_q() {
  printf("front : %d\tback : %d\n", Q[front], Q[back]);
  for(int i=0; i<Q_CAP; i++)
    printf("%d ", Q[i]);
  printf("\n");
}

int main(void) {
  for(int i=0; i<Q_CAP+4; i++) {
    push(rand() % (1024 - 0) + 0);
  }
  print_q();

  for(int i=0; i<Q_CAP && !empty(); i++) {
    printf("pop : %d\n", pop());
  }

  for(int i=0; i<Q_CAP+4; i++) {
    push(rand() % (1024 - 0) + 0);
  }
  print_q();
  return 0;
}
