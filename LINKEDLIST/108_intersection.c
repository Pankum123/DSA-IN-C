#include<stdio.h>
#include<stdlib.h>


struct Node
{
  int data;
  struct Node *next;
};

struct Node *head1;
struct Node *head2;
struct Node *head3;

//create linked list
struct Node* create(struct Node* head)
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
      printf("enter the data that you want insert ");
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

  return head;
}

//display linkedlist
void display(struct Node* head)
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

//insert at end
void insertAtEnd(int x){
  struct Node *temp = NULL, *ptr = NULL;
  temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = x;
  temp->next = NULL;
  if (head3 == NULL)
    head3 = temp;
  else
  {
    ptr = head3;
    while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }
    ptr->next = temp;
  }
}

//intersection of two linked list
void interSection(){
  struct Node* ptr1 = head1;
  struct Node* ptr2 = head2;
  while(ptr1 != NULL){
    ptr2=head2;
    while(ptr2 != NULL){
      if(ptr1->data == ptr2->data) {
         insertAtEnd(ptr1->data);
         break;
      }
      ptr2 = ptr2->next;
    }
    ptr1 = ptr1->next;
  }
}



int main(){

  printf("first linked list\n");
  head1=create(head1);
  printf("\nsecond linked list is\n");
  head2=create(head2);
  
  display(head1);
  display(head2);

  printf("\n intersection of two linked list ");
  interSection();
  display(head3);

return 0;
}