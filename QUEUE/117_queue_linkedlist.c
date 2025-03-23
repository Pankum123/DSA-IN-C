#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
};

struct Queue{
  struct Node *front;
  struct Node *rear;
};


void initqueue(struct Queue *queue){
  queue->front = queue->rear = NULL;
}

int isEmpty(struct Queue *queue){
  return (queue->front==NULL);
}


void enqueue(struct Queue *queue,int value){
  struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
  temp->data = value;
  temp->next = NULL;
 if(isEmpty(queue)){
  queue->front = queue->rear = temp;
 }
 else{
  queue->rear->next = temp;
  queue->rear = temp;
 }
}

int dequeue(struct Queue *queue){
  if (isEmpty(queue))
  {
    printf("\nqueue is empty");
    return -1;
  }
  int x = queue->front->data;

  struct Node *temp = queue->front;
  
  if(queue->front==queue->rear)
    queue->front = queue->rear = NULL;
  else
    queue->front = queue->front->next;

  temp->next = NULL;
  free(temp);
  return x;
}

void display(struct Queue *queue){
  if(isEmpty(queue)){
    printf("queue is empty\n");
    return;
  }
  struct Node *temp = queue->front;
  while(temp != NULL){
    printf("%d ",temp->data);
    temp = temp->next;
  }
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

  printf("\n%d is poped \n",dequeue(&queue));

  display(&queue);

return 0;
}