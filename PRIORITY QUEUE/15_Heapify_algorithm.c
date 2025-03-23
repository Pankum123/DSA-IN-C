//convert given array to heap
#include<stdio.h>

void display(int arr[],int n){
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int i,int arr[],int n){
  while(1){
    int left = 2*i, right = 2*i+1;
    if(left >= n) break;
    if(right >= n){
      if(arr[i] > arr[left]){
        swap(&arr[i],&arr[left]);
        i = left;
      }
      else break;
    }
    else
    if(arr[left] < arr[right]){
      if(arr[i] > arr[left]){
        swap(&arr[i],&arr[left]);
        i = left;
      }
      else break;
    }
    else{
      if(arr[i] > arr[right]){
        swap(&arr[i],&arr[right]);
        i = right;
      }
      else break;
    }
  }
}
int main(){

  int arr[] = {-1,10,2,14,11,1,4};
  int n = sizeof(arr)/4;

  display(arr,n);

  for(int i = n/2; i>=1; i--){
    heapify(i,arr,n);
  }

  display(arr,n);


return 0;
}