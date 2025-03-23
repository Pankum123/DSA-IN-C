#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct Stack{
  int arr[MAX];
  int top;
};

struct Stack stack1;
struct Stack stack2;

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
   // printf("%d pushed onto stack\n",value);
  }
}

int pop(struct Stack *stack){
  if(isEmpty(stack)){
    printf("stack underflow\n");
  }
  else{
    return (stack->arr[(stack->top)--]);
  }
}

int peek(struct Stack *stack){
  if(isEmpty(stack)){
    printf("stack underflow\n");
    return -1;
  }
  else 
    return (stack->arr[stack->top]);
}

void enqueue(int x){
  push(&stack1,x);
}

int dqueue(){
   if(isEmpty(&stack1)){
    printf("queue is empty\n");
    return -1;
   }
   else{
      while(!isEmpty(&stack1)){
        push(&stack2,pop(&stack1));
      }
      int x = pop(&stack2);
      while(!isEmpty(&stack2)){
        push(&stack1,pop(&stack2));
      }
      return x;
   }
}

void display(){
  if(isEmpty(&stack1)){
    printf("queue empty hai\n");
    return;
  }
  while(!isEmpty(&stack1)){
    push(&stack2,pop(&stack1));
  }
  while(!isEmpty(&stack2)){
    printf("%d ",peek(&stack2));
    push(&stack1,pop(&stack2));
  }
}


int main(){
  initstack(&stack1);
  initstack(&stack2);
  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);
  enqueue(5);
  display();
  printf("\n%d is poped \n",dqueue());
  display();
  printf("\n%d is poped \n",dqueue());
  display();
  printf("\n%d is poped \n",dqueue());
  display();
  // printf("\n%d is poped \n",dqueue());
  // display();
  // printf("\n%d is poped \n",dqueue());
  // display();
  enqueue(10);
  printf("\n");
  display();
  enqueue(20);
  printf("\n");
  display();
  enqueue(30);
  printf("\n");
  display();



return 0;
}