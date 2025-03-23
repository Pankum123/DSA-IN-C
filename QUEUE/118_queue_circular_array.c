#include<stdio.h>
//#include<stdlib.h>
#define MAX 5

struct Queue{
  int arr[MAX];
  int front;
  int rear;
};

void initqueue(struct Queue *queue){
  queue->front = queue->rear = -1;
}

int isFull(struct Queue *queue){
  return ((queue->rear+1)%MAX == queue->front);
}

int isEmpty(struct Queue *queue){
  return (queue->rear==-1);
}


void enqueue(struct Queue *queue,int value){
  if(isFull(queue)){
    printf("\nqueue overFlow");
    return;
  }
  if(isEmpty(queue)){
    queue->front = (queue->front+1)%MAX;
  }
  queue->rear = (queue->rear+1)%MAX;
  queue->arr[queue->rear] = value;
}

int dqueue(struct Queue *queue){
  if(isEmpty(queue)){
    printf("queue underflow\n");
    return -1;
  }

   int x = queue->arr[queue->front];
   if(queue->front==queue->rear)
    queue->rear = queue->front = -1;
   else
    queue->front = (queue->front+1)%MAX;

    return x;
}

int peek(struct Queue *queue){
  if(isEmpty(queue)){
    printf("\nqueue underflow");
    return -1;
  }
  return (queue->arr[queue->front]);
}

void display(struct Queue *queue){
  if(isEmpty(queue)){
    printf("queue is empty\n");
    return;
  }
  int i = queue->front;
  while(i!=queue->rear){
    printf("%d ",queue->arr[i]);
    i = (i+1)%MAX;
  }
  printf("%d\n",queue->arr[queue->rear]);
}


int main(){
  struct Queue queue;
  initqueue(&queue);
  enqueue(&queue,1);
  enqueue(&queue,2);
  enqueue(&queue,3);
  enqueue(&queue,4);
  enqueue(&queue,5);
  display(&queue);
  printf("peek value is = %d\n",peek(&queue));

  printf("%d is poped\n",dqueue(&queue));
  display(&queue);
  printf("peek value is = %d\n",peek(&queue));

  printf("%d is poped\n",dqueue(&queue));
  display(&queue);
  printf("peek value is = %d\n",peek(&queue));

  printf("%d is poped\n",dqueue(&queue));
  display(&queue);
  printf("peek value is = %d\n",peek(&queue));

  enqueue(&queue,6);
  enqueue(&queue,7);
  display(&queue);
  printf("peek value is = %d\n",peek(&queue));

  printf("%d is poped\n",dqueue(&queue));
  display(&queue);
  printf("peek value is = %d\n",peek(&queue));

  printf("%d is poped\n",dqueue(&queue));
  display(&queue);
  printf("peek value is = %d\n",peek(&queue));

  enqueue(&queue,8);
  enqueue(&queue,9);
  display(&queue);
  printf("peek value is = %d\n",peek(&queue));


  
return 0;
}