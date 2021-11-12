#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

struct Stack {
  int top, size, capacity;
  int *array;
};

struct Stack *create_stack(int capacity) {
  struct Stack *stack = (struct Stack*) malloc(sizeof(struct Stack));
  stack->top = -1;
  stack->size = 0;
  stack->capacity = capacity;
  stack->array = (int*) malloc(sizeof(int) * stack->capacity);
}

void destroy_stack(struct Stack *stack) {
  free(stack->array);
  free(stack);
}

bool empty(struct Stack *stack) {
  return (stack->size == 0) ? true : false;
}

bool full(struct Stack *stack) {
  return (stack->size == stack->capacity) ? true : false;
}

void push(struct Stack *stack, int val) {
  if(full(stack)) {
    printf("push: stack is full\n");
    return;
  }
  stack->array[++stack->top] = val;
  stack->size++;
}

void pop(struct Stack *stack) {
  if(empty(stack)) {
    printf("pop: stack is empty\n");
    return;
  }
  int val = stack->array[stack->top--];
  stack->size--;
}

int gettop(struct Stack *stack) {
  if(empty(stack))
    printf("gettop: stack is empty\n");
  return stack->top;
}

int main() {
  int capacity = 8;
  struct Stack *stack = create_stack(capacity);
  for(int i=0; i<capacity; i++)
    push(stack, rand() % (64 - 0) + 0);

  destroy_stack(stack);
  return 0;
}
