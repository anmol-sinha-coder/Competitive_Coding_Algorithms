#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct Node
{
 int ID;
 struct Node *next;
}*head;

static int count=0;
void Insert_Begin()
{
 struct Node *nn=(struct Node *)malloc(sizeof(struct Node));
 printf("Enter ID: ");
 scanf("%d",&(nn->ID));

 if(head==NULL)
 {
  head=nn;
  nn->next=NULL;
  return;
 }
 nn->next=head;
 head=nn;
}

void Insert_End()
{
 struct Node *nn=(struct Node *)malloc(sizeof(struct Node));
 printf("Enter ID: ");
 scanf("%d",&(nn->ID));
 if(head==NULL)
 {
  head=nn;
  nn->next=NULL;
  return;
 }
 struct Node *temp = head;
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
 struct Node *nn=(struct Node *)malloc(sizeof(struct Node));
 printf("Enter ID: ");
 scanf("%d",&nn->ID);
  for(int i=1;i<pos-1 && temp->next!=NULL;i++,temp=temp->next);
  nn->next=temp->next;
  temp->next=nn;
 }
}

void Delete_Begin()
{
 if(head==NULL)
 {
  printf("List is Empty!"); //Underflow
  return;
 }
 if(head->next==NULL)
 {
  printf("Deleted Items: ");
  printf("%d",head->ID);
  free(head);
  head=NULL;
  return;
 }
  struct Node* temp=head;
  printf("Deleted Items: ");
  printf("%d\n",temp->ID);
  head=head->next;
  free(temp);
}

void Delete_End()
{
 if(head==NULL)
 {
  printf("List is Empty!"); //Underflow
  return;
 }
 if(head->next==NULL)
 {
  printf("Deleted Items: ");
  printf("%d\n",head->ID);
  free(head);
  head=NULL;
  return;
 }
  struct Node* temp=head;
  for(;temp->next->next!=NULL;temp=temp->next);
  printf("Deleted Items: ");
  printf("%d\n",temp->next->ID);
  free(temp->next);
  temp->next=NULL;
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
  printf("Deleted Items: ");
  printf("%d\n",temp->next->ID);
  struct Node *trans=temp->next;
  temp->next=temp->next->next;
  free(trans);trans=NULL;
}

void Display()
{
 struct Node *temp=head;
 if(head==NULL)
 {
  printf("No element in List!\n"); //Underflow
  return;
 }
   printf("---------------------------------------------\n");
  for(;temp!=NULL;temp=temp->next)
  {
   printf(" %d -->",temp->ID);
  }
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
  temp=adj;
 }
head->next=NULL;
head=temp;
}

void swap(int pos_a,int pos_b)
{
struct Node *temp;
 for(temp=head;temp->next!=NULL;temp=temp->next);
  temp->next=head;

 struct Node *a,*b,*ta=head,*tb=head;
 for(int i=1;i<pos_a-1 && ta->next!=NULL;i++,ta=ta->next);
 for(int i=1;i<pos_b-1 && tb->next!=NULL;i++,tb=tb->next);
 if(pos_a==1)
  ta=temp;
 if(pos_a==count)
  temp=tb->next;

 if(pos_b==1)
  tb=temp;
 if(pos_b==count)
  temp=ta->next;

  a = ta->next;
  b = tb->next;
  ta->next=b;
  tb->next=a;
  tb=a->next;
  a->next=b->next;
  b->next=tb;

head=temp->next;
for(temp=head;temp->next!=head;temp=temp->next);
temp->next=NULL;
}

void Bubble_Sort()
{
 struct Node *tempi=head;
 for(int i=1;i<count || tempi->next->next!=NULL;i++,tempi=tempi->next)
 {
  struct Node *tempj=head;
  for(int j=1;j<count || tempj->next->next!=NULL;j++,tempj=tempj->next)
   if(tempj->ID > tempj->next->ID)
    swap(j,j+1);
 }
}

struct Node* Merge_Sort(struct Node *head)
{
 if (!head || !head->next)
        return head;

 struct Node *right = head,
             *temp  = head,
             *last  = head,
             *result = NULL,
             *next   = NULL,
             *tail   = NULL;

    // Find halfway through the head (by running two pointers, one at twice the speed of the other).
    while (temp && temp->next)
    {
        last = right;
        right = right->next;
        temp = temp->next->next;
    }

    // Break the head in two. (prev pointers are broken here, but we fix later)
    last->next = NULL;

    // Recurse on the two smaller heads:
    head = Merge_Sort(head);
    right = Merge_Sort(right);

    // Merge:
    while (head || right)
    {
        // Take from empty heads, or compare:
        if (!right) {
            next = head;
            head = head->next;
        } else if (!head) {
            next = right;
            right = right->next;
        } else if (head->ID < right->ID) {
            next = head;
            head = head->next;
        } else {
            next = right;
            right = right->next;
        }
  /*      if (!result) {
            result=next;
        } else {
            tail->next=next;
        }
        next->prev = tail;  // Optional.
        tail = next;*/
    }
    return result;
}


/*
void Show_set()
{
 struct Node *temp1,*temp2,*trav;
for(temp1=head;temp1->next!=NULL;temp1=temp1->next)
{
 int s=temp1->ID+temp1->next->ID;
 for(temp2=temp1->next;temp2->next!=NULL;)
 {
  if(temp2->next->ID!=s)
   {
    for(trav=temp1;trav!=temp2->next;trav=trav->next)
     printf("%d,",trav->ID);
    printf("\n");
    //s=0;
    break;
   }
  else
   {s+=temp2->next->ID;temp2=temp2->next;}
 }
}
}
*/
void Reorder()
{
 struct Node *temp1=head,*last1,*temp2,*trav;
 for(last1=head;last1->next!=NULL;last1=last1->next);
 for(int i=1;i<=count/2;i++)
 {
  trav=temp1->next;
  for(temp2=trav->next;temp2->next!=last1;temp2=temp2->next);
  temp1->next=last1;
  last1->next=trav;
  temp1=trav;
  last1=temp2;
 }
trav->next=NULL;
}

int main()
{
 char w='y';
 do
 { // All positions start from 1 !
  int ch=0,p=0,q=0;
  printf("1. Insert Element\n2. Delete Element\n3. Display Elements\n4. Special Reverse Attachment\n5. Sort\n6. Exit\n");
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
   printf("\n\n");
   //Show_set();
   break;
   case 4:Reverse();
       //Reorder();
   break;
   case 5:head=Merge_Sort(head);
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
