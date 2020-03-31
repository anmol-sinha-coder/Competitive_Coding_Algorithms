#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void permute(int*,int,int);
void swap(int&,int&);
void eval(int*,int,int);

char S[10]="-+x";
int n,x;
 int *A=new int;
int main()
{
cout<<"Enter number of values required:";
cin>>n;
cout<<"Enter "<<n<<" numbers: ";
 for(int i=0;i<n;i++)
  cin>>A[i];
cout<<"Enter value which the above should equal: ";
cin>>x;
 permute(A,0,n-1);

 delete A;
 cout<<endl;
 return 0;
}

static int c=0,f=0;
static int v=0;
void eval(int A[],int lb,int ub)
{
 int t,k;
if(lb<=ub)
 {
      t=v;
 for(int j=1;j<=3;j++)
  {
      v=t;
    if(j==1){v-=A[lb];}
    if(j==2){v+=A[lb];}
    if(j==3){v*=A[lb];}
    eval(A,lb+1,ub);
  }
 }
  else
  {
    c++;
   if(x==v)
    {
    cout<<endl<<" ("<<f<<"."<<c<<")\t\t"<<A[0];
    k=c-1;
   for(int j=n-2;j>=0;j--)
     {
     int p=pow(3,j);
     t=k/p;
     cout<<S[t]<<A[n-1-j];
     k%=p;
     }
    std::cout<<std::showpos<<" = "<<v;
    std::cout<<std::noshowpos;
    }
  }
}

void swap(int &a,int &b)
 {
    int t;
    t=a;
    a=b;
    b=t;
 }

void permute(int A[],int lb,int ub)
{
if(lb<=ub)
  {
   for(int i=lb;i<=ub;i++)
   {
       int flag=1;
      for(int j=lb;j<i;j++)
       if(A[j]==A[i])
        flag=0;

     if(flag!=0)
     {
      swap(A[lb],A[i]);
      permute(A,lb+1,ub);
      swap(A[lb],A[i]);
     }
   }
  }
  else
  {
   c=0;v=A[0];f++;
   eval(A,1,n-1);
  // cout<<endl<<"_________________________________________________________________________________________________"<<endl;
  }
}
