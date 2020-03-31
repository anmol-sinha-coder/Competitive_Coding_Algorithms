#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void power_set(char P[],int lb,int ub);
void append(char P[],char);
void trunc(char P[]);

char A[100]="";
int l;
int main()
{
 char P[100]="";
 cout<<"Enter string: ";
 gets(A);
 l=strlen(A);
 power_set(P,0,l-1);
 cout<<endl;
  system("PAUSE");
 return 0;
}

static int k=0,n=0;
void append(char P[],char ch)
{
 P[k++]=ch;
 P[k]='\0';
}

void trunc(char P[])
{
 P[--k]='\0';
}

static int ti=0,tlb=0;
void power_set(char P[],int lb,int ub)
{
 if(lb<=ub) // OR A[l-1]!=P[strlen(P)-1]
 {
  for(int i=lb;i<=ub;i++)
   {
    if((tlb<lb && ti<i) || (tlb>=lb && ti>=i))
    {
     append(P,A[i]);
     ti=i;
     tlb=lb;
     power_set(P,lb+1,ub);
     n++;
     cout<<endl<<" ("<<n<<")"<<P;
     trunc(P);
    }
   }
 }
}
/*
static int k=0,m=0;
int *P=new int;
void append(int A[],int ch)
{
 A[k++]=ch;
 //P[k]='\0';
}

void trunc(int A[])
{
 k--;
 //P[k]='\0';
}

static int ti=0,tlb=0;
void power_set(int A[],int lb,int ub)
{
 if(lb<=ub) // OR A[l-1]!=P[strlen(P)-1]
 {
  for(int i=lb;i<=ub;i++)
   {
    if((tlb<lb && ti<i) || (tlb>=lb && ti>=i))
    {
     append(A,P[i]);
     ti=i;
     tlb=lb;
     power_set(A,lb+1,ub);
//     cout<<endl<<" ("<<n<<")";
for(int i=0;i<k;i++)
    cout<<A[i]<<",";
cout<<endl;
  //   if(lb>=2)
//     permute(A,0,lb);
     trunc(A);
    }
   }
 }
}

int main()
{
    int n,x;
 cout<<"Enter number of elements required: ";
 cin>>n;
 cout<<"Enter "<<n<<" numbers: ";
 for(int i=0;i<n;i++)
  cin>>P[i];
 cout<<"Enter Required Number:";
 cin>>x;
 int A[n];
 power_set(A,0,n-1);

 delete P;
cout<<endl;
 return 0;
}

*/
