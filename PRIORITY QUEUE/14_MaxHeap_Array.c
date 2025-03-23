#include<stdio.h>
#define MAX 50

struct MaxHeap{
  int idx;
  int arr[MAX];
};

void init_Heap(struct MaxHeap *heap){
  heap->idx = 1;
  for(int i = 1; i < MAX; i++){
    heap->arr[i] = 0;
  }
}

int isEmpty(struct MaxHeap *heap){
  return heap->idx == 1;
}

int isFull(struct MaxHeap *heap){
  return heap->idx == MAX + 1;
}

int top(struct MaxHeap *heap){
  return heap->arr[1];
}

int size(struct MaxHeap *heap){
  if(heap->idx==1) return -1;
  return heap->idx-1;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void push(struct MaxHeap *heap,int value){
  if(isFull(heap)){
    printf("Heap overflow\n");
    return;
  }
  heap->arr[heap->idx] = value;
  int i = heap->idx;
  heap->idx++;
  //swapping of i with parent till i==1
  while(i!=1){
    int parent = i/2;
    if(heap->arr[i] > heap->arr[parent])
      swap(&heap->arr[i],&heap->arr[parent]);
    else break;
    i = parent;
  }
}

int pop(struct MaxHeap *heap){
  if(isEmpty(heap)){
    printf("heap underflow\n");
    return -1;
  }
  int x = heap->arr[1];
  heap->idx--;
  heap->arr[1] = heap->arr[heap->idx];
  //Rearrangement
  int i = 1;
  while(1){
    int left = 2*i, right = 2*i-1;
    if(left > heap->idx-1) break;
    if(right > heap->idx-1){
      if(heap->arr[i] < heap->arr[left]){
        swap(&heap->arr[i],&heap->arr[left]);
        i = left;
      }
      else break;
    }

    if(heap->arr[left] > heap->arr[right]){
      if(heap->arr[i] < heap->arr[left]){
        swap(&heap->arr[i],&heap->arr[left]);
        i = left;
      }
      else break;
    }
    else{
      if(heap->arr[i] < heap->arr[right]){
        swap(&heap->arr[i],&heap->arr[right]);
        i = right;
      }
      else break;
    }
  }
  return x;
}

void sorting(struct MaxHeap *heap){
  while(!isEmpty(heap)){
    printf("%d ",top(heap));
    pop(heap);
  }
}

void display(struct MaxHeap *heap){
  if(isEmpty(heap)){
    printf("heap is empty\n");
    return;
  }
  for(int i = 1; i <= heap->idx-1; i++){
    printf("%d ",heap->arr[i]);
  }
  printf("\n");
}

int main(){
  struct MaxHeap pq;
  init_Heap(&pq);

  // push(&pq,10);
  // push(&pq,20);
  // display(&pq);
  // printf("top = %d, size = %d\n",top(&pq),size(&pq));
  // push(&pq,11);
  // push(&pq,2);
  // display(&pq);
  // printf("top = %d, size = %d\n",top(&pq),size(&pq));
  // pop(&pq);
  // display(&pq);
  // printf("top = %d, size = %d\n",top(&pq),size(&pq));

  push(&pq,35);
  display(&pq);
  push(&pq,16);
  display(&pq);
  push(&pq,19);
  display(&pq);
  push(&pq,23);
  display(&pq);
  push(&pq,55);
  display(&pq);
  push(&pq,7);
  display(&pq);
  push(&pq,8);
  display(&pq);
  push(&pq,15);
  display(&pq);
  push(&pq,12);
  display(&pq);
  push(&pq,9);
  display(&pq);
  printf("sorted element is :\n");
  sorting(&pq);

return 0;
}