#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void permute(char A[],int lb,int ub);
//void sw(char&,char&);

int main()
{
    int l=0;
    char A[100]="";
    cout<<"Enter string sequence: ";
    gets(A);
    l=strlen(A);
    permute(A,0,l-1);
    system("PAUSE");
    cout<<endl;
    return 0;
}

void sw(char &a, char &b)
{
    char t;
    t=a;
    a=b;
    b=t;
}

static int f;
void permute(char A[],int lb,int ub)
{
if(lb<=ub)
  {
   for(int i=lb;i<=ub;i++)
   {
       int flag=1;
      for(int j=lb;j<i;j++)
       if(A[j]==A[i])
        flag=0;

     if(flag)
     {
      sw(A[i],A[lb]);
      permute(A,lb+1,ub);
      sw(A[i],A[lb]);
     }
   }
  }
  else
  {
  f++;
  cout<<" ("<<f<<")"<<A<<"\n";
  }
}
