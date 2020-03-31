
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

void main()
{
    printf("1/2=%f",(float)(1/2));
 int n,x,y;
 printf("Enter n = ");
 scanf("%d",&n);
 int A[n],d=n;
 printf("Enter %d elements:",n);
 for(int i=0;i<n;i++)
  {scanf("%d",A+i);}
  printf("Enter x and y: ");
 scanf("%d%d",&x,&y);

 for(int i=0;i<n;i++)
  if(A[i]==x)
   for(int j=0;j<n;j++)
    if(A[j]==y && A[i]==x && abs(i-j)<d)
     d=abs(i-j);

 printf("Minimum Distance = %d",d);
 printf("\n");
}

/*
#include<stdio.h>
#include<stdlib.h>

void main()
{
 int **A,**B,p,q,r,**AB;
 printf("Enter p,q,r respectively:");
 scanf("%d%d%d",&p,&q,&r);
 A=(int**)malloc(p*sizeof(int*));
 B=(int**)malloc(q*sizeof(int*));
 AB=(int**)malloc(p*sizeof(int*));
  for(int i=0;i<p;i++)
    *(A+i)=(int*)malloc(q*sizeof(int));
  for(int i=0;i<q;i++)
    *(B+i)=(int*)malloc(r*sizeof(int));
  for(int i=0;i<p;i++)
   *(AB+i)=(int*)malloc(r*sizeof(int));

  if(A && B && AB)
  {
   printf("Enter elements for %d x %d matrix:\n",p,q);
   for(int i=0;i<p;i++)
    for(int j=0;j<q;j++)
     scanf("%d",*(A+i)+j);
 printf("\n");
   printf("Enter elements for %d x %d matrix:\n",q,r);
   for(int i=0;i<q;i++)
    for(int j=0;j<r;j++)
     scanf("%d",*(B+i)+j);
 printf("\n");
    for(int i=0;i<p;i++)
    {
    for(int j=0;j<q;j++)
     printf("%3d",*(*(A+i)+j));
     printf("\n");
  }
 printf("\n");
   for(int i=0;i<q;i++)
   {
    for(int j=0;j<r;j++)
     printf("%3d",*(*(B+i)+j));
   printf("\n");
   }
   printf("\n");
 for(int i=0;i<p;i++)
  for(int j=0;j<r;j++)
   *(*(AB+i)+j)=0;
 for(int i=0;i<p;i++)
  for(int j=0;j<r;j++)
   for(int k=0;k<q;k++)
   *(*(AB+i)+j)+=*(*(A+i)+k) * *(*(B+k)+j);
   for(int i=0;i<p;i++)
   {
  for(int j=0;j<r;j++)
   printf("%3d",*(*(AB+i)+j));
  printf("\n");
   }
  free(A);free(B);free(AB);
  }
}
*/
/*
#include<stdio.h>
#include<limits.h>

// A C++ class to represent k stacks in a single array of size n
struct kStacks
{
    int *arr;   // Array of size n to store actual content to be stored in stacks
    int *top;   // Array of size k to store indexes of top elements of stacks
    int *next;  // Array of size n to store next entry in all stacks
                // and free list
    int n, k;
    int free; // To store beginning index of free list
    //constructor to create k stacks in an array of size n
//constructor to create k stacks in an array of size n
void create(int k1, int n1)
{
    // Initialize n and k, and allocate memory for all arrays
    k = k1, n = n1;
    arr = (int*)malloc(n*sizeof(int));
    top = (int*)malloc(k*sizeof(int));
    next =(int*)malloc(n*sizeof(int));

    // Initialize all stacks as empty
    for (int i = 0; i < k; i++)
        top[i] = -1;

    // Initialize all spaces as free
    free = 0;
    for (int i=0; i<n-1; i++)
        next[i] = i+1;
    next[n-1] = -1;  // -1 is used to indicate end of free list
}
    // A utility function to check if there is space available
    int isFull()   {  return (free == -1);  }

    // To push an item in stack number 'sn' where sn is from 0 to k-1
// To push an item in stack number 'sn' where sn is from 0 to k-1
void push(int item, int sn)
{
    // Overflow check
    if (isFull())
    {
        cout << "\nStack Overflow\n";
        return;
    }

    int i = free;      // Store index of first free slot

    // Update index of free slot to index of next slot in free list
    free = next[i];

    // Update next of top and then top for stack number 'sn'
    next[i] = top[sn];
    top[sn] = i;

    // Put the item in array
    arr[i] = item;
}

    // To pop an from stack number 'sn' where sn is from 0 to k-1
// To pop an from stack number 'sn' where sn is from 0 to k-1
int pop(int sn)
{
    // Underflow check
    if (isEmpty(sn))
    {

         cout << "\nStack Underflow\n";
         return INT_MAX;
    }


    // Find index of top item in stack number 'sn'
    int i = top[sn];

    top[sn] = next[i];  // Change top to store next of previous top

    // Attach the previous top to the beginning of free list
    next[i] = free;
    free = i;

    // Return the previous top item
    return arr[i];
}

    // To check whether stack number 'sn' is empty or not
    bool isEmpty(int sn)  {  return (top[sn] == -1); }
}ks;

/* Driver program to test twStacks class */
/*
int main()
{
    // Let us create 3 stacks in an array of size 10
    int k = 3, n = 10;

    // Let us put some items in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);

    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);

    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;

    return 0;
}
*/
