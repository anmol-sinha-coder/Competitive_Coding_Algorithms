#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void all(int A[],int lb,int ub,int v);
int main()
{
 int o,b,l;
 cout<<"Enter maximum possible number of lock (numeration starts from 0):"; //Lock starts from number 1
 cin>>b;
 cout<<"Enter number of spaces in lock (denoted by letters): ";
 cin>>o;  //Number of Looping Variables are boxes available ; 'n' is the object types OR possible number values
 int O[o];  //Number of combinations = b^o
 cout<<"\nLOCK |";
 for(char i=65;i<=64+o;i++)
    cout<<"\t"<<i;
 cout<<endl<<"SPACE|_______________________________________________________________________________________________________"<<endl<<" []\t"<<endl;
 all(O,0,o-1,b);
 cout<<endl;
  system("PAUSE");
 return 0;
}

static int n=0;
void all(int A[],int lb,int ub,int v)
{
 if(lb<=ub)
 {
   for(int j=0;j<=v;j++)
   {
    A[lb]=j;
    all(A,lb+1,ub,v);
   }
 }
 else
 {
  n++;
  cout<<" ("<<n<<")";
  for(int k=0;k<=ub;k++)
  cout<<"\t"<<A[k];
  cout<<endl;
 }
}
