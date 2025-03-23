#include <stdio.h>

int quick(int *a,int beg, int end)
{
  int left = beg;
  int right = end;
  int loc = beg;

  while (1)
  {
    while (a[loc] <= a[right] && loc != right)
    {
      right = right - 1;
    }

    if (loc == right)
      return loc;

    if (a[loc] > a[right])
    {
      int temp = a[loc];
      a[loc] = a[right];
      a[right] = temp;
    }

    loc = right;

    while (a[left] <= a[loc] && left != loc)
    {
      left = left + 1;
    }

    if (loc == left)
      return loc;

    if (a[left] > a[loc])
    {
      int temp = a[loc];
      a[loc] = a[left];
      a[left] = temp;
    }

    loc = left;
  }
}

// void quickSort(int arr[], int low, int high) {

//     if (low < high) {
//         int pi = quick(arr, low, high);

//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }

void quickSort(int *a,int n){
  int top = 0;
  if(n>1) {
    top = top + 1;
    int lower = 0;
    int upper = n;
    
    while(top!=0){
      int beg = lower;
      int end = upper;
          top = top-1;
      int loc = quick(a,beg,end);

      if(beg<loc-1){
        top = top +1;
        lower = beg;
        upper = loc-1;
      }
    
      if(loc+1 < end){
        top = top + 1;
        lower = loc+1;
        upper = end;
      }
    }
  }
}

int main()
{
  int a[10] = {5, 1, 3, 6, 2, 4, 0, 7, 8, 9};
   quickSort(a,10);

  for(int i=0;i<10;i++){
    printf("%d ",a[i]);
  }
  return 0;
}