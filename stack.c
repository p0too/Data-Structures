#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define true 1
#define false 0
#define ST_CAP 16

int stack[ST_CAP];
int top = -1;

int isempty() {
  return top <= -1 ? true : false;
}

int isfull() {
  return (top >= ST_CAP-1) ? true : false;
}

void push(int x) {
  assert(!isfull() && "Stack Overflow");
  stack[++top] = x;
}

int pop() {
  assert(!isempty() && "Stack Underflow");
  int x = stack[top--];
  return x;
}

void print_stack() {
  for(int i=ST_CAP-1; i>=0; i--)
    printf("%d\n", stack[i]);
}

int main(void) {
  for(int i=0; i<16; i++)
    push(rand() % (1024 - 0) + 0);
  
  print_stack();
  printf("top = %d\n", top);

  for(int i=0; i<16; i++)
    pop();
   
  return 0;
}
