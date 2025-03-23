#include <stdio.h>
// #include<stdlib.h>
#define MAX 5

struct Queue
{
  int arr[MAX];
  int front;
  int rear;
};

void initqueue(struct Queue *queue)
{
  queue->front = queue->rear = -1;
}

int isFull(struct Queue *queue)
{
  return (queue->rear == MAX - 1);
}

int isEmpty(struct Queue *queue)
{
  return (queue->rear == -1);
}

void enqueue(struct Queue *queue, int value)
{
  if (isFull(queue))
  {
    printf("\nqueue overFlow");
    return;
  }
  if (isEmpty(queue))
    queue->front = 0;

  queue->arr[++(queue->rear)] = value;
  printf("\n%d pushed onto queue", value);
}

int dqueue(struct Queue *queue)
{
  if (isEmpty(queue))
  {
    printf("\nqueue underflow");
    return -1;
  }

  int x = (queue->arr[queue->front]);
    if (queue->rear == queue->front)
      queue->front = queue->rear = -1;  
    else
      queue->front += 1;
    return x;
}

int peek(struct Queue *queue)
{
  if(isEmpty(queue)){
    printf("\nqueue underflow");
    return -1;
  }
  return (queue->arr[queue->front]);
}

void display(struct Queue *queue)
{
  if(isEmpty(queue)){
    printf("\nqueue is empty");
    return;
  }
  for (int i = queue->front; i <= queue->rear; i++)
  {
    printf("%d ", queue->arr[i]);
  }
}

int main()
{
  struct Queue queue;
  initqueue(&queue);
  enqueue(&queue, 1);
  enqueue(&queue, 2);
  enqueue(&queue, 3);
  enqueue(&queue, 4);
  enqueue(&queue, 5);
  enqueue(&queue, 6);
  printf("\n");
  display(&queue);

  printf("\npeek value is = %d", peek(&queue));

   printf("\n%d is poped\n", dqueue(&queue));
  display(&queue);

  printf("\npeek value is = %d", peek(&queue));

  return 0;
}