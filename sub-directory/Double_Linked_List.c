#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct Node
{
 int key;
 struct Node *next;
 struct Node *prev;
}*head,*tail;

static int count=0;
void Insert_Begin()
{
 struct Node *nn=(struct Node *)malloc(sizeof(struct Node));
 printf("Enter key: ");
 scanf("%d",&(nn->key));
 if(head==NULL && tail==NULL)
 {
  head=tail=nn;
  nn->next=NULL;
  return;
 }
 nn->next=head;
 head->prev=nn;
 head=nn;
}

void Insert_End()
{
 struct Node *nn=(struct Node *)malloc(sizeof(struct Node));
 printf("Enter key: ");
 scanf("%d",&(nn->key));
 if(head==NULL && tail==NULL)
 {
  head=tail=nn;
  nn->next=NULL;
  return;
 }
 nn->prev=tail;
 tail->next=nn;
 tail=nn;
 nn->next=NULL;
}

void Insert(int pos)
{
 if(pos<=count+1 && pos>0)
  count++;
 else
  return;
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
 struct Node *temp=head;
 if(pos<count)
 {
 struct Node *nn=(struct Node*)malloc(sizeof(struct Node));
 printf("Enter key: ");
 scanf("%d",&nn->key);
  for(int i=1;i<pos-1 && temp->next!=NULL;i++,temp=temp->next);
  nn->next=temp->next;
  nn->prev=temp;
  temp->next->prev=nn;
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
  head=head->next;
  free(head->prev);head->prev=NULL;
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
  tail=tail->prev;
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
  struct Node* temp=head;
 for(int i=1;i<pos-1 && temp->next!=NULL;i++,temp=temp->next);
  printf("Deleted Items: \n");
  printf("%d\n",temp->next->key);
  struct Node *trans=temp->next;
  temp->next=temp->next->next;
  temp->next->next->prev=temp;
  free(trans);trans=NULL;
}

void Display()
{
 struct Node *temp;
 if(head==NULL)
 {
  printf("No element in List!\n"); //Underflow
  return;
 }
   printf("---------------------------------------------\n");
  for(temp=head;temp!=NULL;temp=temp->next)
   printf(" %d <==>",temp->key);
  printf(" []\n");
  for(temp=tail;temp!=NULL;temp=temp->prev)
   printf(" %d <==>",temp->key);
  printf(" []\n");
}

void Reverse()
{

 struct Node *temp=head,*trans=head->next;
 while(trans!=NULL)
 {
  struct Node *adj=trans;
  trans=trans->next;
  adj->next=temp;
  temp->prev=adj;
  adj->prev=trans;
  temp=adj;
 }
//tail->prev=NULL;
head->next=NULL;//initial node to be connected
tail=head;
head=temp;
}

void swap(int pos1,int pos2)
{
 struct Node *a=head,*b=head,*t;
 for(int i=1;i<pos1-1 && a->next!=NULL;i++,a=a->next);
 for(int i=1;i<pos2-1 && b->next!=NULL;i++,b=b->next);
 t=a->next;
 a->next=b->next;
 b->next=t;
}

int main()
{
 char w='y';
 do
 { // All positions start from 1 !
  int ch=0,p=0,q=0;
  printf("1. Insert Element\n2. Delete Element\n3. Display Elements\n4. Reverse\n5. Sort\n6. Exit\n");
  printf("Enter choice (1-4):");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:printf("Enter position to enter element (Natural Number):");
          scanf("%d",&p);
          Insert(p);
          printf("Total Number of Nodes: %d\n",count);
   break;
   case 2:printf("Enter position to delete element (Natural Number):");
          scanf("%d",&p);
          Delete(p);
          printf("Total Number of Nodes: %d\n",count);
   break;
   case 3:Display();
   break;
   case 4:Reverse();
   break;
   case 5:printf("Enter the 2 positions to swap:");
          scanf("%d%d",&p,&q);
          swap(p,q);
   break;
   case 6:exit(0);
   break;
   default:printf("Wrong Choice! ");
  }
/*  printf("Want to Enter more? (Y/N): ");
  scanf(" %c",&w);
*/
  printf("_____________________________________________________________________________\n");
 }while(w=='Y' || w=='y');
return 0;
}
