#include<iostream>
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

struct Processor
{
 int AT;
 int BT;
};

int n;
int index(Processor*,int);
int main()
{
 int sum=0,c=0,I=0;
 cout<<"Enter number of Processors: "; cin>>n;
 Processor *P = new Processor[n];
 cout<<"\tA.T   B.T\n";
 for(int i=0;i<n;i++)
 {
  cout<<"P-"<<i+1<<"\t ";
  cin>>P[i].AT>>P[i].BT;
  sum+=P[i].BT;
 }

cout<<endl<<" |"<<c;
while(c<sum)
{
 int t=0;
 while(I==index(P,c)) //while(P[I].BT!=0)
 {
  if(P[I].BT==0)
   break;
  t++;
  c++;
  P[I].BT--;
 }
 for(int j=1;j<=t;j++)cout<<"-";
 Sleep(100);
 cout<<"{P"<<I+1<<"}";
 Sleep(100);
 for(int j=1;j<=t;j++)cout<<"-";
 cout<<c;
  I=index(P,c);
 }
 cout<<"|"<<endl;
 return 0;
}

int index(Processor P[],int c)
{
 int cur=INT_MAX,pos=0;
 for(int i=0;i<n;i++)
  if(P[i].AT<=c && P[i].BT<=cur && P[i].BT)
    cur=P[pos=i].BT;
   else if(!P[i].BT)
    cur=INT_MAX;
 return pos;
}
