#include <stdio.h>
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

//search data in linkedlist
void search()
{
  if (head == NULL)
  {
    printf("\nlinkedlist is empty");
    return;
  }
  struct Node *ptr = head;
  int x;
  printf("\nenter a number you want to search ");
  scanf("%d", &x);
  while (ptr != NULL)
  {
    if (ptr->data == x)
    {
      break;
    }
    ptr = ptr->next;
  }
  if (ptr != NULL)
    printf("\nelement is present");
  else
    printf("\nelement is not present");
}

//insert a node at beg
void insertAtBeg()
{
  struct Node *temp = NULL, *ptr = NULL;
  int x;
  printf("\nenter a number you want to inser beg ");
  scanf("%d", &x);
  temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = x;
  temp->next = NULL;
  if (head == NULL)
    head = temp;
  else
  {
    temp->next = head;
    head = temp;
  }
}

//insert a node at end
void insertAtEnd()
{
  struct Node *temp = NULL, *ptr = NULL;
  int x;
  printf("\nenter a number you want to insert end ");
  scanf("%d", &x);
  temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = x;
  temp->next = NULL;
  if (head == NULL)
    head = temp;
  else
  {
    ptr = head;
    while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }
    ptr->next = temp;
  }
}

//delete a node at beg
void deleteAtBeg(){
  struct Node *ptr=head;
  head=head->next;
  ptr->next=NULL;
  free(ptr);
}

//delete at end
void deleteAtEnd(){
  struct Node *ptr,*ptr1;
  ptr=head;
  ptr1=head->next;
  while(ptr1->next != NULL){
    ptr1=ptr1->next;
    ptr=ptr->next;
  }
  ptr->next=NULL;
  free(ptr1);
}

int main()
{
  create();
  display();
  
  insertAtBeg();
  display();

  insertAtEnd();
  display();

  deleteAtBeg();
  display();

  deleteAtEnd();
  display();

  search();
  

  return 0;
}