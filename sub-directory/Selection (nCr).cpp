#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iomanip>
#include<string.h>
using namespace std;

int hcf(int,int,int,int);
void combo(int C[],int lb,int n,int r);
void append(int C[],int);
void trunc(int C[]);

int *A=new int;
int sum=0;
int n,r;
int main()
{
 cout<<"Enter n: ";
 cin>>n;
for(int i=0;i<n;i++)
 A[i]=i+1;
 cout<<"Enter r: ";
 cin>>r;
  int C[r];
  combo(C,0,n,r);

 delete A;
 cout<<endl;
 return 0;
}

int hcf(int a,int b,int c,int d)
{
 int gcd=1,small=a<b && a<c && a<d?a:b<c && b<d?b:c<d?c:d;
 for(int i=1;i<=small;i++)
  if(a%i==0 && b%i==0 && c%i==0 && d%i==0)
    gcd=i;
  return gcd;
}

static int k=0,nCr=0;
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
     ti=i;
     tlb=lb;
     combo(C,lb+1,n,r);
     trunc(C);
    }
   }
 }
 else
 {
     nCr++;
     cout<<"("<<nCr<<") ";
    for(int i=0;i<r;i++)
     cout<<C[i]<<",";
    cout<<"\b"<<endl;
 }
}

/*
static int ti=0,tlb=0;
void combo(int C[],int lb,int n,int r)
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
     combo(C,lb+1,n,r);
     trunc(C);
    }
   }
 }
 else
 {
     nCr++;
     cout<<"("<<nCr<<") ";
    for(int i=0;i<r;i++)
     cout<<C[i]<<",";
    cout<<"\b"<<endl;
 }
}
*/
