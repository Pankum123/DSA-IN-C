#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct Stack{
  int arr[MAX];
  int top;
};


void initstack(struct Stack *stack){
  stack->top=-1;
}

int isFull(struct Stack *stack){
  return stack->top==MAX-1;
}

int isEmpty(struct Stack *stack){
  return stack->top==-1;
}

void push(struct Stack *stack,int value){
  if(isFull(stack))
    printf("stack overflow\n");
  else{
    stack->arr[++(stack->top)] = value;
    printf("%d pushed onto stack\n",value);
  }
}

int pop(struct Stack *stack){
  if(isEmpty(stack)){
    printf("stack underflow\n");
    return -1;
  }
  return (stack->arr[(stack->top)--]);
}

int peek(struct Stack *stack){
  if(isEmpty(stack)){
    printf("stack underflow\n");
    return -1;
  }
  else 
    return (stack->arr[stack->top]);
}

int main(){
  struct Stack stack;
  initstack(&stack);

  push(&stack,1);
  push(&stack,2);
  push(&stack,3);
  push(&stack,4);
  push(&stack,5);
  push(&stack,6);
  printf("peek value is %d\n",peek(&stack));
  printf("%d is poped \n",pop(&stack));
  printf("peek value is %d\n",peek(&stack));

return 0;
}