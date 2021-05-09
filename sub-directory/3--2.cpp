#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool UDF_1(int A[],int n)
{
 int occ=0,c=0,val;
 for(int i=0;i<n;i++,c=0)
  for(int j=0;j<n;j++)
   if(A[i]==A[j])
    if(++c > occ)
    {
     occ=c;
     val=A[i];
    }

 printf("Most occuring element is "<<val<<", it occurs "<<occ<<" times !"<<endl;
 if(occ>=n/2)
    return 1;
 else
    return 0;
}

bool UDF_2(int A[],int n)
{
   int big=A[0];
   for(int i=0;i<n;i++)
    if(big<A[i])
     big=A[i];

  int c[1+big]={0},occ=0,val;
  for (int j = 0; j < n; j++)
   c[A[j]]++;
  for (int i = 0; i <= big; i++)
   if(c[i]>occ)
    occ=c[val=i];

 printf("\nMost occuring element is "<<val<<", it occurs "<<occ<<" times !"<<endl;
 if(occ>=n/2)
    return 1;
 else
    return 0;
}

int main()
{
 int n;
 printf("Enter number of elements required: "; cin>>n;
 int A[n];
 printf("Enter "<<n<<" elements: ";
  for(int i=0;i<n;i++) cin>>A[i];

  if(UDF_1(A,n))
    printf("Yes, occurences is more than n/2 !!";
  else
    printf("No, occurences is less than n/2 !!";
  printf("\n-------------------------------\n";

    if(UDF_2(A,n))
    printf("Yes, occurences is more than n/2 !!";
  else
    printf("No, occurences is less than n/2 !!";

    printf("\n_____________________\n";

  return 0;
}
