#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Stack{
  struct Node *top;
};



void initstack(struct Stack *stack){
  stack->top=NULL;
}

void push(struct Stack *stack,int x){
  struct Node *temp;
  temp=(struct Node*) malloc(sizeof(struct Node));
  if(!temp){
    printf("\n memory allocation faild");
    return;
  }
  temp->data=x;
  printf("%d is pushed \n",temp->data);
  temp->next=stack->top;
  stack->top=temp;
}

int isEmpty(struct Stack *stack){
  return (stack->top==NULL);
}

int pop(struct Stack *stack){
  if(isEmpty(stack)){
    printf("\n stack overflow");
    return -1;
  }
  int y;
  struct Node *temp;
  y = stack->top->data;
  temp=stack->top;
  stack->top=stack->top->next;
  temp->next=NULL;
  free(temp);
  return y;
}

int peek(struct Stack *stack){
  if(isEmpty(stack)){
    printf("\n stack is empty ");
    return -1;
  }
  return (stack->top->data);
}


int main(){
  struct Stack stack;
  initstack(&stack);
  push(&stack,1);
  push(&stack,2);
  push(&stack,3);
  // push(&stack,4);
  // push(&stack,5);
  // push(&stack,6);
  printf("peek value is %d\n",peek(&stack));
  printf("%d is poped \n",pop(&stack));
  printf("peek value is %d",peek(&stack));
return 0;
}