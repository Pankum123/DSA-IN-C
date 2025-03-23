#include<stdio.h>
#define MAX 5

struct Element{
  int data;
  int priority;
};

struct Pqueue{
  struct Element elements[MAX];
  int rear;
};

int initpqueue(struct Pqueue *pq){
  pq->rear = -1;
}

int isEmpty(struct Pqueue *pq){
  return (pq->rear==-1);
}

void enqueue(struct Pqueue *pq,int value,int priority){
  if(pq->rear==MAX-1) {
    printf("pqueue is Full\n");
    return;
  }
  pq->rear++;
  pq->elements[pq->rear].data = value;
  pq->elements[pq->rear].priority = priority;
  printf("%d is pushed onto pqueue\n",value);
}

int highestPriorityIndex(struct Pqueue *pq){
  int hp = 0;
  for(int i = 1;i<=pq->rear;i++){
    if(pq->elements[hp].priority < pq->elements[i].priority) {
      hp = i;
    }
  }
  return hp;
}

int peek(struct Pqueue *pq){
  if(pq->rear==-1){
    printf("\npqueue is empty");
    return -1;
  }
  return (pq->elements[highestPriorityIndex(pq)].data);
}

void display(struct Pqueue *pq){
  if(pq->rear==-1){
    printf("\npqueue is empty");
    return;
  }
  for(int i = 0;i<=pq->rear;i++){
    printf("value is = %d end priority is =%d \n",pq->elements[i].data,pq->elements[i].priority);
  }
}

int dequeue(struct Pqueue *pq){
  if(pq->rear==-1){
    printf("\npqueue is empty");
    return -1;
  }
  int hp = highestPriorityIndex(pq);
  int x = pq->elements[hp].data;

  for(int i = hp;i<=pq->rear;i++){
    pq->elements[i].data =pq->elements[i+1].data;
    pq->elements[i].priority=pq->elements[i+1].priority; 
  }
  pq->rear--;

  return x;
}

int main(){
  struct Pqueue pq;
  initpqueue(&pq);
  enqueue(&pq,1,2);
  enqueue(&pq,2,1);
  enqueue(&pq,3,5);
  enqueue(&pq,4,3);
  enqueue(&pq,5,4);
  enqueue(&pq,6,4);

  display(&pq);
  printf("\npeek value is = %d",peek(&pq));
  printf("\n%d is poped\n",dequeue(&pq));
  display(&pq);
  printf("\npeek value is = %d",peek(&pq));
  printf("\n%d is poped\n",dequeue(&pq));
  display(&pq);
  printf("\npeek value is = %d\n",peek(&pq));

  enqueue(&pq,6,15);
  enqueue(&pq,7,13);
  enqueue(&pq,8,0);
  display(&pq);
  printf("\npeek value is = %d",peek(&pq));



return 0;
}