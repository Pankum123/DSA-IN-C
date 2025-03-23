#include<stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};
struct Node *head;

//create linked list
void create()
{
  int x;
  char ch;
  struct Node *temp = NULL, *ptr = NULL;
  do
  {
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
      printf("\n memory allocation failed");
    else
    {
      printf("\nenter the data that you want insert ");
      scanf("%d", &x);

      temp->data = x;
      temp->next = NULL;

      if (head == NULL)
        head = temp;
      else
      {
        ptr = head;
        while (ptr->next != NULL)
          ptr = ptr->next;
        ptr->next = temp;
      }
    }
    printf("insert new node click y ");
    getchar();
    scanf("%c", &ch);
  } while (ch == 'y' || ch == 'Y');
}

//display linkedlist
void display()
{
  if (head == NULL)
  {
    printf("\nlinkedlist is empty");
    return;
  }
  struct Node *ptr = head;
  printf("\n");
  while (ptr != NULL)
  {
    printf("%d->", ptr->data);
    ptr = ptr->next;
  }
}

void nthNode_last(){
  int n;
  printf("\nenter a nth number from end = ");
  scanf("%d",&n);
  struct Node *slow,*fast;
  slow=fast=head;

  for(int i=1;i<n;i++) fast = fast->next;

  while(fast->next != NULL){
    slow = slow->next;
    fast = fast->next;
  }

  printf("\nNth node from end is = %d",slow->data);
}
int main(){
  create();
  display();
  nthNode_last();
return 0;
}