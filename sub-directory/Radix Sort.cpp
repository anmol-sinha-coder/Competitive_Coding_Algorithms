#include<iostream>
#include<bits/stdc++.h>
#define MAX 20
using namespace std;

void count_sort()
{
   int big=A[0];
   for(int i=0;i<n;i++)
    if(big<A[i])
     big=A[i];

   int c[1+big]={0},B[n]={0};
  for (int i = 0; i <= big; i++)
   c[i] = 0;
  for (int j = 0; j < n; j++)
   c[A[j]]++;
  for (int i = 0; i <= big; i++)
   c[i] += c[i-1];
  for (int j = n-1; j >= 0; j--)
   B[--c[A[j]]] = A[j];
}

int Large(int A[], int n)
{
    int mx = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] > mx)
            mx = A[i];
    return mx;
}

void Radix_Sort(int A[], int n)
{
 int m = Large(A, n);
 //Do counting sort for every digit. Note that instead of passing digit number, exp is passed. exp is 10^i where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
    {
     int B[n],count[MAX]={0};
    for (int i = 0; i < n; i++)
        count[(A[i]/exp)%10]++;
    // Change count[i] so that count[i] now contains actual position of this digit in B[]
    for (int i = 1; i < MAX; i++)
        count[i] += count[i - 1]; //providing positional weightage to each digit value
    // Build the B Array
    for (int i = n - 1; i >= 0; i--)
        B[--count[(A[i]/exp)%10]] = A[i];
    // Copy the B Array to A[], so that A[] now contains sorted numbers according to current digit
    for (int i = 0; i < n; i++)
        A[i] = B[i];
    }
}

int main()
{
 int n;
 cout<<"Enter number of elements required: ";
 cin>>n;
 int A[n];
 cout<<"Enter "<<n<<" elements: ";
 for(int i=0;i<n;i++)
  cin>>A[i];
 Radix_Sort(A,n);
 cout<<"___________________________________________\nFinal Sorted Array:-\n";
 for(int i=0;i<n;i++)
  cout<<A[i]<<",";
 cout<<"\b \n";

 return 0;
}
