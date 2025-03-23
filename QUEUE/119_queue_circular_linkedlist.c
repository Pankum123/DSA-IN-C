#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Queue
{
  struct Node *front;
  struct Node *rear;
};

void initqueue(struct Queue *queue)
{
  queue->front = queue->rear = NULL;
}

int isEmpty(struct Queue *queue)
{
  return (queue->front == NULL);
}

void push(struct Queue *queue, int value)
{
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = value;
  temp->next = NULL;
  if (isEmpty(queue))
  {
    queue->front = queue->rear = temp;
    queue->rear->next = queue->front;
  }
  else
  {
    queue->rear->next = temp;
    queue->rear = temp;
    queue->rear->next = queue->front;
  }
}

int pop(struct Queue *queue)
{
  if (isEmpty(queue))
  {
    printf("\nqueue is empty");
    return -1;
  }
  struct Node *temp = queue->front;
  int x = queue->front->data;
  if (queue->front == queue->rear)
  {
    queue->front = queue->rear = NULL;
    temp->next = NULL;
    free(temp);
    return x;
  }
  else
  {
    queue->front = queue->front->next;
    queue->rear->next = queue->front;
    temp->next = NULL;
    free(temp);
    return x;
  }
}

void display(struct Queue *queue)
{
  if (isEmpty(queue))
  {
    printf("queue is empty\n");
    return;
  }
  struct Node *temp = queue->front;
  while (temp != queue->rear)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("%d \n", temp->data);
}

int main()
{
  struct Queue queue;
  initqueue(&queue);

  push(&queue, 1);
  push(&queue, 2);
  push(&queue, 3);
  push(&queue, 4);
  push(&queue, 5);

  display(&queue);

  printf("%d is poped\n", pop(&queue));

  display(&queue);

  return 0;
}