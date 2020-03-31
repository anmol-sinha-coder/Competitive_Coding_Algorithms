#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct Node
{
 int ID;
 int pr;
 struct Node *next;
}*head[5];


static int count=0;
void Insert_Begin()
{
 struct Node *nn=(struct Node *)malloc(sizeof(struct Node));
 printf("Enter ID: ");
 scanf("%d",&(nn->ID));
 printf("Enter priority(1-5): ");
 scanf("%d",&(nn->pr));

 if(head[0]==NULL)
 {
  head[0]=nn;
  nn->next=NULL;
  return;
 }
 nn->next=head[0];
 head[0]=nn;
}

void Insert_End()
{
 struct Node *nn=(struct Node *)malloc(sizeof(struct Node));
 printf("Enter ID: ");
 scanf("%d",&(nn->ID));
 printf("Enter priority(1-5): ");
 scanf("%d",&(nn->pr));

 if(head[0]==NULL)
 {
  head[0]=nn;
  nn->next=NULL;
  return;
 }
 struct Node *temp = head[0];
 for(;temp->next!=NULL;temp=temp->next);
 temp->next=nn;
 temp=nn;
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
  return;l2
 }
 if(pos==count)
 {
  Insert_End();
  return;
 }
 struct Node *temp=head[0];
 if(pos<count)
 {
 struct Node *nn=(struct Node *)malloc(sizeof(struct Node));
 printf("Enter ID: ");
 scanf("%d",&nn->ID);
 printf("Enter priority(1-5): ");
 scanf("%d",&(nn->pr));
  for(int i=1;i<pos-1 && temp->next!=NULL;i++,temp=temp->next);
  nn->next=temp->next;
  temp->next=nn;
 }
}

void Delete_Begin()
{
 if(head[0]==NULL)
 {
  printf("List is Empty!"); //Underflow
  return;
 }
 if(head[0]->next==NULL)
 {
  printf("Deleted Item: ");
  printf("%d",head[0]->ID);
  free(head[0]);
  head[0]=NULL;
  return;
 }
  struct Node* temp=head[0];
  printf("Deleted Item: ");
  printf("%d\n",temp->ID);
  head[0]=head[0]->next;
  free(temp);
}

void Delete_End()
{
 if(head[0]==NULL)
 {
  printf("List is Empty!"); //Underflow
  return;
 }
 if(head[0]->next==NULL)
 {
  printf("Deleted Item: ");
  printf("%d\n",head[0]->ID);
  free(head[0]);
  head[0]=NULL;
  return;
 }
  struct Node* temp=head[0];
  for(;temp->next->next!=NULL;temp=temp->next);
  printf("Deleted Item: ");
  printf("%d\n",temp->next->ID);
  free(temp->next);
  temp->next=NULL;
}

void Delete(int pos)
{
 if(head[0]==NULL)
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

  struct Node* temp=head[0];
 for(int i=1;i<pos-1 && temp->next!=NULL;i++,temp=temp->next);
  printf("Deleted Item: ");
  printf("%d\n",temp->next->ID);
  struct Node *trans=temp->next;
  temp->next=temp->next->next;
  free(trans);trans=NULL;
}

void Display(struct Node *head)
{
 struct Node *temp=head;
 if(head==NULL)
 {
  printf("No element in List of this priority!\n"); //Underflow
  return;
 }
   printf("---------------------------------------------\n");
  for(;temp!=NULL;temp=temp->next)
  {
   printf(" %d -->",temp->ID);
  }
  printf(" []\n");
}

void Bubble_Sort()
{
 struct Node *tempi=head[0];
 for(int i=1;i<=count && tempi->next!=NULL;i++,tempi=tempi->next)
 {
  struct Node *tempj=head[0];
  for(int j=1;j<=count && tempj->next!=NULL;j++,tempj=tempj->next)
   if(tempj->pr > tempj->next->pr)
    {
     int t1=tempj->ID;
     tempj->ID=tempj->next->ID;
     tempj->next->ID=t1;

     int t2=tempj->pr;
     tempj->pr=tempj->next->pr;
     tempj->next->pr=t2;
    }
 }
}

void Part()
{
 struct Node *temp;
 for(int i=0;i<5;i++)
  if(head[i])
  {
   for(temp=head[i];temp->next!=NULL && temp->next->pr==temp->pr;temp=temp->next);
   head[i+1]=temp->next;
   temp->next=NULL;
  }

}

int main()
{
 char w='y';
 do
 { // All positions start from 1 !
  int ch=0,p=0,q=0;
  printf("1. Insert Element\n2. Delete Element\n3. Display Elements\n4. Sort\n5. Exit\n");
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
   case 3:Display(head[0]);
          printf("\n\n");
   break;
   case 4:Bubble_Sort();Part();
          Display(head[0]);printf("\n");
          Display(head[1]);printf("\n");
          Display(head[2]);printf("\n");
          Display(head[3]);printf("\n");
          Display(head[4]);printf("\n");
   break;
   case 5:exit(0);
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
