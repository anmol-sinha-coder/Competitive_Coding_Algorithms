#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int LIS(int A[],int n)
{
 int max=0, lis[n];
 for(int i=0;i<n;i++)
  lis[i]=1;
 for(int i=n-1;i>=0;i--)
   for(int j=i+1;j<n;j++)
     if(A[i]<A[j] && lis[i]<lis[j]+1)
      lis[i]=lis[j]+1;

 for(int i=0;i<n;i++)
    if(max<lis[i])
     max=lis[i];

 return max;
}

int main()
{
 int n;
 cout<<"Enter number of elements: ";  cin>>n;
 int A[n];
 cout<<"Enter "<<n<<" elements: ";
 for(int i=0;i<n;i++) cin>>A[i];

 cout<<"Length of longest increasing subsequence is "<<LIS(A,n);

 return 0;
}
