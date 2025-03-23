#include <stdio.h>
// #include<stdlib.h>
#define MAX 5

struct Dqueue
{
  int arr[MAX];
  int front;
  int rear;
};

void initqueue(struct Dqueue *dqueue)
{
  dqueue->front = dqueue->rear = -1;
}


int isFull(struct Dqueue *dqueue)
{
  return (dqueue->front==0 && dqueue->rear == MAX - 1 || dqueue->front==dqueue->rear+1);
}

int isEmpty(struct Dqueue *dqueue)
{
  return (dqueue->front==-1);
}

void insertFront(struct Dqueue *dqueue, int value)
{
  if(isFull(dqueue)){
    printf("\nstack overflow\n");
    return;
  }
  if(isEmpty(dqueue)) dqueue->front = dqueue->rear = 0;
  else if(dqueue->front==0) dqueue->front = MAX-1;
  else dqueue->front--;
  dqueue->arr[dqueue->front] = value;
  printf("%d is pushed onto front\n",value); 
}

int deleteFront(struct Dqueue *dqueue){
  if(isEmpty(dqueue)){
    printf("\ndqueue underflow");
    return -1;
  }
  int x = dqueue->arr[dqueue->front];
  if(dqueue->front==dqueue->rear) dqueue->front=dqueue->rear = -1;
  else if(dqueue->front==MAX-1) dqueue->front = 0;
  else dqueue->front++;
  return x;
}

void insertRear(struct Dqueue *dqueue, int value)
{
  if(isFull(dqueue)){
    printf("\nstack overflow\n");
    return;
  }
  if(isEmpty(dqueue)) dqueue->front=dqueue->rear=0;
  else if(dqueue->rear==MAX-1) dqueue->rear = 0;
  else dqueue->rear++;
  dqueue->arr[dqueue->rear] = value;
  printf("%d is pushed onto rear\n",value);
}

int deleteRear(struct Dqueue *dqueue){
  if(isEmpty(dqueue)){
    printf("\ndqueue underflow");
    return -1;
  }
  int x = dqueue->arr[dqueue->rear];
  if(dqueue->front==dqueue->rear) dqueue->front=dqueue->rear = -1;
  else if(dqueue->rear==0) dqueue->rear = MAX-1;
  else dqueue->rear--;
  return x;
}



void display(struct Dqueue *dqueue)
{
  if(isEmpty(dqueue)){
    printf("\ndqueue is empty\n");
    return;
  }
  int i = dqueue->front;
  while(i != dqueue->rear){
    printf("%d ",dqueue->arr[i]);
    if(i==MAX-1) i = 0;
    else i++;
  }  
  printf("%d \n",dqueue->arr[i]);
}

int main()
{
  struct Dqueue dqueue;
  initqueue(&dqueue);

  // insertFront(&dqueue,1);
  // insertFront(&dqueue,2);
  // insertFront(&dqueue,3);
  // insertFront(&dqueue,4);
  // insertFront(&dqueue,5);
  // insertFront(&dqueue,6);

  insertRear(&dqueue,1);
  // insertRear(&dqueue,2);
  // insertRear(&dqueue,3);
  // insertRear(&dqueue,4);
  // insertRear(&dqueue,5);
  // insertRear(&dqueue,6);

  // display(&dqueue);

  // deleteFront(&dqueue);
  // display(&dqueue);

  // deleteFront(&dqueue);

  display(&dqueue);
  deleteRear(&dqueue);
  display(&dqueue);

  
  
  return 0;
}