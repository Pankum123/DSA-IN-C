#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

struct Stack{
  char arr[MAX];
  int top;
};
// struct Stack *stack;

void initStack(struct Stack *stack){
  stack->top=-1;
}

int isFull(struct Stack *stack){
  return stack->top==MAX-1;
}

int isEmpty(struct Stack *stack){
  return stack->top==-1;
}

void push(struct Stack *stack,char value){
  if(isFull(stack)){
    printf("Stack overFlow\n");
  }
  else{
    stack->arr[++(stack->top)]=value;
   // printf("\n%c pushed onto stack",value);
  }
}

char pop(struct Stack *stack){
  if(isEmpty(stack)){
    printf("Stack underflow\n");
    return '0';
  }
  else return (stack->arr[(stack->top)--]);
}

char peek(struct Stack *stack){
  if(isEmpty(stack)){
    printf("Stack underflow");
    return -1;
  }
  else return (stack->arr[stack->top]);
}

void printstack(struct Stack *stack){
  if(isEmpty(stack)) return;
  char x = peek(stack);
  pop(stack);
  printf("%c ",x);
  printstack(stack);
  push(stack,x);
}

void infixTopostfix(char *str){
  struct Stack *stack;
  stack = (struct Stack*) malloc(sizeof(struct Stack));
  initStack(stack);
  char ans[50];
  char ch;
  int count=0;
  int n=strlen(str);
  for(int i=0;i<n;i++){
    ch=str[i];
    if(ch=='('){
      push(stack,'(');
    } 
    else if(ch=='+' || ch=='-'){
        while(peek(stack) != '(' ){
        ans[count++]=peek(stack);
        pop(stack);
        }
        push(stack,ch);
    }
    else if(ch=='*' || ch=='/'){
      if(peek(stack)=='+' || peek(stack)=='-'){
         push(stack,ch);
      }
      else{
        while(peek(stack) != '(' && peek(stack) != '+' && peek(stack) != '-'){
        ans[count++]=peek(stack);
        pop(stack);
        }
        push(stack,ch);
      }
    }
    else if(ch==')'){
      while(peek(stack) != '(' ){
        ans[count++]=peek(stack);
        pop(stack);
      }
      pop(stack);
    }
    else{
      ans[count++]=ch;
    }
  }
  ans[count]='\0';
  printf("%s",ans);
}


int main(){
  char str[]="(((3+4)*2)/7)";
 // printf("%s",str);
  infixTopostfix(str);
return 0;
}