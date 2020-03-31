#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iomanip>
#include<string.h>
using namespace std;

void rect(int C[][2],int lb,int n,int r);
void append(int C[][2],int);
void trunc(int C[][2]);
int *A[2]=new int;
int n,r;
int main()
{
cout<<"Enter n: ";
cin>>n;
cout<<"Enter "<<n<<" co-ordinates: ";
for(int i=0;i<n;i++)
 for(int j=0;j<2;j++)
 cin>>A[i][j];

int C[r];
 rect(C,0,n,r);

 delete A;
 cout<<endl;
 return 0;
}

static int k=0,nCr=0;
void append(int C[][2],int ch)
{
 C[k]=ch;
 k++;
}

void trunc(int C[][2])
{
 k--;
}

static int ti=0,tlb=0;
void rect(int C[][2],int lb,int n,int r)
{
 if(lb<=r)
 {
  for(int i=lb;i<=n;i++)
   {
    if((tlb<lb && ti<i) || (tlb>=lb && ti>=i))
    {
     append(C,A[i]);
     ti=i;
     tlb=lb;
     rect(C,lb+1,n,r);
     trunc(C);
    }
   }
 }
 else
 {
    nCr++;
    cout<<endl<<" ("<<nCr<<")";
    for(int j=0;j<r;j++)
     cout<<C[j];
 }
}
