#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int r,n,k=0;
struct Processor
{
 int *MR;
 int *AR;
}*P;

bool safe(Processor*,int*);
bool exists(int*,int);
int main()
{

 cout<<"Enter number of processors: ";
 cin>>n;
 cout<<"Enter number of resources: ";
 cin>>r;
 cout<<" \t"<<"Max\t"<<"Alloc"<<endl;
 P=new Processor[n];
 for(int i=0;i<n;i++)
 {
  cout<<"P-"<<i+1<<"\t";
  P[i].MR=new int[r];
  for(int j=0;j<r;j++)
   cin>>P[i].MR[j];
  P[i].AR=new int[r];
  for(int j=0;j<r;j++)
   cin>>P[i].AR[j];
 }
 int avbl[r];
 cout<<"Enter Available resources: "<<endl;
 for(int j=0;j<r;j++)
  cin>>avbl[j];
 if(safe(P,avbl))
    cout<<"In Safe State !"<<endl;
 else
    cout<<"Not in Safe State !"<<endl;

 return 0;
}

bool safe(Processor P[],int av[])
{
 int t[n]={0};
 for(int I=0;I<n;I++)
 {
  for(int i=0;i<n;i++)
  {
   int c=0; //counter
   for(int j=0;j<r;j++)
    if(av[j] >= P[i].MR[j]-P[i].AR[j] && !exists(t,i+1))
      ++c;
   if(c==r && !exists(t,i+1))
   {
    for(int j=0;j<r;j++)
     av[j]+=P[i].AR[j];
    t[k++]=i+1;
    for(int j=0;j<r;j++)
     cout<<av[j]<<" ";
    cout<<"\b "<<endl;
   }
  }
  if(k==n)
  {
   cout<<endl<<"Safe Sequence:";
   for(int i=0;i<n;i++)
    cout<<" P-"<<t[i]<<",";
   cout<<endl;
   return 1;
  }
 }
 return 0;
}

bool exists(int *temp,int pi)
{
 for(int i=0;i<=k;i++)
  if(pi==temp[i])
   return 1;
 return 0;
}
