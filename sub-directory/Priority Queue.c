#include<stdio.h>
#include<stdlib.h>

#include <stdio.h>
#include <stdlib.h>

// struct node
struct node
{
    int data;
    // Lower values indicate higher priority
    int priority;
    struct node* next;

}*head;

// Function to Create A New struct node
struct node* Insert(int d, int p)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;

    return temp;
}

// Return the value at head
int peek()
{
    return head->data;
}

// Removes the element with the
// highest priority form the list
void pop()
{
    struct node* temp = head;
    head = head->next;
    free(temp);
}

// Function to push according to priority
struct node *push(int d, int p)
{
    if(!head)
    {
    head = (struct node*)malloc(sizeof(struct node));
    head->data = d;
    head->priority = p;
    head->next = NULL;
    return head;
    }

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;

    struct node* start = head;
    // Special Case: The head of list has lesser
    // priority than new node. So insert new
    // node before head node and change head node.
    if (head->priority > p)
    { // Insert New struct node before head
        temp->next = head;
        head = temp;
    }
    else
    {
        // Traverse the list and find a
        // position to insert new node
        while (start->next != NULL && start->next->priority < p)
            start = start->next;

        // Either at the ends of the list
        // or at required position
        temp->next = start->next;
        start->next = temp;
    }
  return head;
}

// Function to check is list is empty
int isEmpty()
{
    return (head == NULL);
}

// Driver code
int main()
{
    // Create a Priority Queue
    // 7->4->5->6
    head = push( 4, 1);
    head = push( 5, 2);
    head = push( 6, 3);
    head = push( 7, 0);

    while (!isEmpty())
    {
        printf("%d ", peek());
        pop();
    }
    return 0;
}

/*
 struct struct node
{
 int key;
 int pr;
 struct struct node *next;
}*head,*tail;

static int count=0;
void Insert_Begin()
{
 struct struct node *nn=(struct struct node *)malloc(sizeof(struct struct node));
 printf("Enter key: ");
 scanf("%d",&(nn->key));
 if(head==NULL && tail==NULL)
 {
  head=tail=nn;
  nn->next=NULL;
  return;
 }
 nn->next=head;
 head=nn;
}

void Insert_End()
{
 struct struct node *nn=(struct struct node *)malloc(sizeof(struct struct node));
 printf("Enter key: ");
 scanf("%d",&(nn->key));
 printf("Enter priority: ");
 scanf("%d",&(nn->pr));
 if(head==NULL && tail==NULL)
 {
  head=tail=nn;
  nn->next=NULL;
  return;
 }
 tail->next=nn;
 tail=nn;
 nn->next=NULL;
}

void Insert(int pos)
{
 if(pos<=count+1 && pos>0)
  count++;
 else
  {printf("nope!");return;}
 if(pos==1)
 {
  Insert_Begin();
  return;
 }
 if(pos==count)
 {
  Insert_End();
  return;
 }
 struct struct node *temp=head;
 if(pos<count)
 {
 struct struct node *nn=(struct struct node*)malloc(sizeof(struct struct node));
 printf("Enter key: ");
 scanf("%d",&nn->key);
  for(int i=1;i<pos-1 && temp->next!=NULL;i++,temp=temp->next);
  nn->next=temp->next;
  temp->next=nn;
 }
}

void Delete_Begin()
{
 if(head==NULL && tail==NULL)
 {
  printf("List is Empty!"); //Underflow
  return;
 }
 if(head==tail)
 {
  printf("Deleted Items: \n");
  printf("%d",head->key);
  free(head);free(tail);
  head=NULL;tail=NULL;
  return;
 }
  printf("Deleted Items: \n");
  printf("%d\n",head->key);
  struct struct node *temp=head;
  head=head->next;
  free(temp);temp=NULL;
}

void Delete_End()
{
 if(head==NULL && tail==NULL)
 {
  printf("List is Empty!"); //Underflow
  return;
 }
 if(head==tail)
 {
  printf("Deleted Items: \n");
  printf("%d\n",head->key);
  free(head);free(tail);
  head=tail=NULL;
  return;
 }
  printf("Deleted Items: \n");
  printf("%d\n",tail->key);
  free(tail->next);
  tail->next=NULL;
}

void Delete(int pos)
{
 if(head==NULL)
 {
  printf("List is Empty!"); //Underflow
  return;
 }
 count--;
 if(pos==1)
 {
  Delete_Begin();
  return;
 }
 if(pos==count+1)
 {
  Delete_End();
  return;
 }
  struct struct node* temp=head;
 for(int i=1;i<pos-1 && temp->next!=NULL;i++,temp=temp->next);
  printf("Deleted Items: \n");
  printf("%d\n",temp->next->key);
  struct struct node *trans=temp->next;
  temp->next=temp->next->next;
  free(trans);trans=NULL;
}

void Display()
{
 struct struct node *temp;
 if(head==NULL)
 {
  printf("No element in List!\n"); //Underflow
  return;
 }
   printf("---------------------------------------------\n");
  for(temp=head;temp!=NULL;temp=temp->next)
   printf(" %d |",temp->key);
}

Insert_Priority()
{
 struct struct node *nn;
 printf("Enter info: ");
 scanf("%d",nn->info);
 printf("Enter priority: ");
 scanf("%d",nn->pr);

 if(head==NULL)
 {
  head=nn;
  nn->next=NULL;
 }
 struct struct node *temp;
 for(temp=head;temp->next->pr>temp->pr && temp->next!=NULL;temp=temp->next)
 {
  nn->next=temp->next;
  temp->next=nn;
 }

}

int main()
{
 char w='y';
 do
 { // All positions start from 1 !
  int ch=0;
  printf("1. Insert Element\n2. Delete Element\n3. Display Elements\n4. Exit\n");
  printf("Enter choice (1-4):");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:Insert_Priority();
          printf("Total Number of struct nodes: %d\n",count);
   break;
   case 2:Delete_Begin();
          printf("Total Number of struct nodes: %d\n",count);
   break;
   case 3:Display();
   printf("\n\n");
   break;
   case 4:exit(0);
   break;
   default:printf("Wrong Choice! ");
  }
  printf("Want to Enter more? (Y/N): ");
  scanf(" %c",&w);

  printf("_____________________________________________________________________________\n");
 }while(w=='Y' || w=='y');
return 0;
}
*/
