#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>


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

void createLoop(){
  struct Node *ptr=head;
  while(ptr->next != NULL) ptr=ptr->next;
  ptr->next=head->next;
}

bool checkLoop(){
  struct Node *slow,*fast;
  slow=head;
  fast=head->next;
  while(fast!=NULL && fast->next!=NULL){
    if(slow->data==fast->data){
      return true;
    }
    slow=slow->next;
    fast=fast->next->next;
  }
  return false;
}

int main(){
  create();
  display();
  createLoop();
  bool ans = checkLoop();
  printf("\n ans = %d",ans);

return 0;
}