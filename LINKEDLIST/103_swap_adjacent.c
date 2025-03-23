#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};
struct Node *head;

// create linked list
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

// display linkedlist
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

void swap_adj()
{
  if(head==NULL || head->next==NULL){
    return;
  }
  struct Node *p, *q, *r;
  p = head;
  q = head->next;
  p->next = q->next;
  q->next = p;
  head = q;
  while (p->next != NULL)
  {
    r = p;
    p = p->next;
    q = p->next;
    if (q!=NULL)
    {
      p->next = q->next;
      q->next = p;
      r->next = q;
    }
  }
}

int main()
{
  create();
  display();
  swap_adj();
  display();
  return 0;
}