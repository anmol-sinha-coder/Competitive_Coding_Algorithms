#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void combo(int C[],int lb,int n,int r);
void append(int C[],int);
void trunc(int C[]);
int *A=new int;
int n,r,limit,flag=0;
int main()
{
 cin>>limit;
 cin>>n;
 for(int i=0;i<n;i++)
  cin>>A[i];

for(int r=n;r>=1;r--)
{
 int C[r];
 combo(C,0,n,r);
 if(flag)break;
}

 delete A;
 cout<<endl;
 return 0;
}

static int k=0;
void append(int C[],int ch)
{
 C[k]=ch;
 k++;
}

void trunc(int C[])
{
 k--;
}

static int ti=0,tlb=0;
void combo(int C[],int lb,int n,int r)
{
 if(lb<=r)
 {
  for(int i=lb;i<=n;i++)
   {
    if((tlb<lb && ti<i) || (tlb>=lb && ti>=i))
    {
     append(C,n-1-i);
     ti=i;tlb=lb;
     combo(C,lb+1,n,r);
     trunc(C);
    }
   }
 }
 else
 {
  int sum=0;
  for(int i=0;i<r;i++)
    sum+=A[C[i]];
  if(sum<=limit)
  {
    cout<<r<<endl;
    for(int i=r-1;i>=0;i--)cout<<C[i]<<" ";
    cout<<endl;
    flag=1;
    exit(0);
  }
 }
}
