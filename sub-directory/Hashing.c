#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define size 23
int HT[size],count=0;

//LINEAR PROBING
void LP_Insert(int val)
{ count++;
 if(HT[val%size]==INT_MIN)
 {
  HT[val%size]=val;
  return;
 }
 for(int i=val%size+1;i<size;i++)
 if(HT[i]==INT_MIN)
 {
  HT[i]=val;
  return;
 }
 for(int i=val%size-1;i>=0;i--)
 if(HT[i]==INT_MIN)
 {
  HT[i]=val;
  return;
 }
 count--;
}

void LP_Delete(int val)
{ count--;
  if(HT[val%size]==val)
 {
  HT[val%size]=INT_MIN;
  return;
 }
 for(int i=val%size+1;i<size;i++)
 if(HT[i]==val)
 {
  HT[i]=INT_MIN;
  return;
 }
 for(int i=val%size-1;i>=0;i--)
 if(HT[i]==val)
 {
  HT[i]=INT_MIN;
  return;
 }
 count++;
}

void LP_Search(int val)
{
 if(HT[val%size]==val)
 {
  printf("Element found !");
  return;
 }
 for(int i=val%size+1;i<size;i++)
 if(HT[i]==val)
 {
  printf("Element found !");
  return;
 }
 for(int i=val%size-1;i>=0;i--)
 if(HT[i]==val)
 {
  printf("Element found !");
  return;
 }
 printf("Element NOT found !");
}

//QUADRATIC PROBING
void QP_Insert(int val)
{ count++;
 if(HT[val%size]==INT_MIN)
 {
  HT[val%size]=val;
  return;
 }
 for(int i=val%size+1,j=1;i<size;j++,i=val%size+j*j)
 if(HT[i]==INT_MIN)
 {
  HT[i]=val;
  return;
 }
 count--;
}

void QP_Delete(int val)
{ count--;
 if(HT[val%size]==val)
 {
  HT[val%size]=INT_MIN;
  return;
 }
 for(int i=val%size+1,j=1;i<size;j++,i=val%size+j*j)
 if(HT[i]==val)
 {
  HT[i]=INT_MIN;
  return;
 }
 count++;
}

void QP_Search(int val)
{
 if(HT[val%size]==val)
 {
  printf("Element found !");
  return;
 }
 for(int i=val%size+1,j=1;i<size;j++,i=val%size+j*j)
 if(HT[i]==val)
 {
  printf("Element found !");
  return;
 }
 printf("Element NOT found !");
}

//DOUBLE HASHING
void DH_Insert(int val)
{ count++;
 int h2=val%7+1;
 if(HT[val%size]==INT_MIN)
 {
  HT[val%size]=val;
  return;
 }
 for(int j=1,i=(val%size)+j*h2;j<size;j++)
 if(HT[i]==INT_MIN)
 {
  HT[i]=val;
  return;
 }
 count--;
}

void DH_Delete(int val)
{ count--;
  int h2=val%7+1;
 if(HT[val%size]==val)
 {
  HT[val%size]=INT_MIN;
  return;
 }
 for(int j=1,i=(val%size)+j*h2;j<size;j++)
 if(HT[i]==val)
 {
  HT[i]=INT_MIN;
  return;
 }
 count++;
}

void DH_Search(int val)
{
  int h2=val%7+1;
 if(HT[val%size]==val)
 {
  printf("Element found !");
  return;
 }
 for(int j=1,i=(val%size)+j*h2;j<size;j++)
 if(HT[i]==val)
 {
  printf("Element found !");
  return;
 }
 printf("Element NOT found !");
}

void Display()
{
 printf(" |");
 for(int i=0;i<size;i++)
  if(HT[i]!=INT_MIN)
   printf("%d,",HT[i]);
  else
   printf("_,");
 printf("\b|\n");
}

int main()
{
 for(int i=0;i<size;i++)
  HT[i]=INT_MIN;
 int c;
 printf(" 1. Linear Probing\n 2. Quadratic Probing\n 3. Double Hashing\n");
 printf("Enter your option(1-3): "); scanf("%d",&c);
 switch(c)
 {
  case 1:do
        {int ch,key;
         printf(" 1. Insert\n 2. Delete\n 3. Search\n 4. Display\n 5. Exit\n");
         printf("Enter choice(1-5): ");
         scanf("%d",&ch);
         switch(ch)
         {
          case 1: printf("Enter key (to insert): "); scanf("%d",&key);
                  LP_Insert(key);
          break;
          case 2: printf("Enter key (to delete): "); scanf("%d",&key);
                  LP_Delete(key);
          break;
          case 3: printf("Enter key (to search): "); scanf("%d",&key);
                  LP_Search(key); printf("\n");
          break;
          case 4: Display();
          break;
          case 5: exit(0);
          break;
          default:printf("Wrong Choice!\n");
         }
         printf("_______________________________\n");
        }while(count!=size);
  printf("Hash Table is full !!\t"); Display();
  break;
  case 2:do
        {int ch,key;
         printf(" 1. Insert\n 2. Delete\n 3. Search\n 4. Display\n 5. Exit\n");
         printf("Enter choice(1-5): ");
         scanf("%d",&ch);
         switch(ch)
         {
          case 1: printf("Enter key (to insert): "); scanf("%d",&key);
                  QP_Insert(key);
          break;
          case 2: printf("Enter key (to delete): "); scanf("%d",&key);
                  QP_Delete(key);
          break;
          case 3: printf("Enter key (to search): "); scanf("%d",&key);
                  QP_Search(key); printf("\n");
          break;
          case 4: Display();
          break;
          case 5: exit(0);
          break;
          default:printf("Wrong Choice!\n");
         }
         printf("_______________________________\n");
        }while(count!=size);
  printf("Hash Table is full !!\t"); Display();
  break;
  case 3:do
        {int ch,key;
         printf(" 1. Insert\n 2. Delete\n 3. Search\n 4. Display\n 5. Exit\n");
         printf("Enter choice(1-5): ");
         scanf("%d",&ch);
         switch(ch)
         {
          case 1: printf("Enter key (to insert): "); scanf("%d",&key);
                  DH_Insert(key);
          break;
          case 2: printf("Enter key (to delete): "); scanf("%d",&key);
                  DH_Delete(key);
          break;
          case 3: printf("Enter key (to search): "); scanf("%d",&key);
                  DH_Search(key); printf("\n");
          break;
          case 4: Display();
          break;
          case 5: exit(0);
          break;
          default:printf("Wrong Choice!\n");
         }
         printf("_______________________________\n");
        }while(count!=size);
         printf("Hash Table is full!\t"); Display();
  break;
  default:printf("Wrong Option!\n");
 }

 return 0;
}
