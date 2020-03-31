#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct HT
{
 struct node *head;
 int count;
}*chain;

int size;

void Insert(int value)
{
    //create a newnode with value
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    //calculate hash key
    int key = value % size;

    //check if chain[key] is empty
    if(chain[key].head == NULL)
        chain[key].head = newNode;
    //collision
    else
    {
        //add the node at the end of chain[key].
        struct node *temp = chain[key].head;
        while(temp->next)
          temp = temp->next;

        temp->next = newNode;
    }
}

void Display()
{
    int i;

    for(i = 0; i < size; i++)
    {
        struct node *temp = chain[i].head;
        printf(" [%d] | ",i);
        while(temp)
        {
            printf("%d --> ",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void Delete(int value)
{
  int addr=value%size;
 if(chain[addr].head!=NULL)
 {
   if(chain[addr].head->data==value)
   {
    struct node *t=chain[addr].head;
    chain[addr].head=chain[addr].head->next;
    free(t);
    return;
   }
   struct node *temp,*adj;
   for(temp=chain[addr].head;temp->next->next!=NULL && temp->next->data!=value;temp=temp->next);
    if(temp->next->data==value)
    {
     adj=temp->next;
     temp->next=adj->next;
     if(adj!=NULL)
     free(adj);
    }
 }
}

int main()
{
 char w='y';
 printf("Enter size of table: "); scanf("%d",&size);
 chain=(struct HT*)calloc(size,sizeof(struct HT));
 do
 { int ch,key;
  printf(" 1. Insert\n 2. Delete\n 3. Display\n 4. Exit\n");
  printf("Enter choice(1-4):");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1: printf("Enter key (to insert): "); scanf("%d",&key);
           Insert(key);
   break;
   case 2: printf("Enter key (to delete): "); scanf("%d",&key);
           Delete(key);
   break;
   case 3: Display();
   break;
   case 4: exit(0);
   break;
   default:printf("Wrong Choice!\n");
  }
  printf("_______________________________\n");
 }while(w=='y');

    return 0;
}
