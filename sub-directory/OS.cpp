#include<iostream>
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

struct Processor
{
 bool flag;
 unsigned long TAT,BT,AT;
 int exec;
 char val;
};

int n;
void Sort(Processor arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
    for (j = 0; j < n-1; j++)
     if (arr[j].AT > arr[j+1].AT)
      {
       int t0=arr[j].BT; arr[j].BT=arr[j+1].BT; arr[j+1].BT=t0;
       int t1=arr[j].AT; arr[j].AT=arr[j+1].AT; arr[j+1].AT=t1;
       int t2=arr[j].exec; arr[j].exec=arr[j+1].exec; arr[j+1].exec=t2;
      char t3=arr[j].val;arr[j].val=arr[j+1].val;arr[j+1].val=t3;
      }
}

int index(Processor P[],int c,int t)
{
 int cur=INT_MAX,count=0;
 static int pos=0;
 if(t==2)
  while(!P[pos=(++pos)%n].exec && ++count<=n);
 else
  for(int i=0;i<n;i++)
   if(P[i].AT<=c && P[i].exec<cur && P[i].exec)
    cur=P[pos=i].exec;
   else if(!P[i].exec)
    cur=INT_MAX;

 return pos;
}

int main()
{
 printf("Standard Terms: \tAT-->Arrival Time\tBT-->Burst Time\n\t\t TAT-->Turnaround Time\tWT-->Wait Time\n"<<endl;
 int sum=0,c=0,I=0,t=0;
 printf("Enter number of Processors: "; scanf(n;
 Processor *P = new Processor[n];
 printf("\tAT  BT\n";
 for(int i=0;i<n;i++)
 {
  printf("P-"<<i+1<<"\t ";
  scanf(P[i].AT>>P[i].exec;
  P[i].val=i+49; P[i].flag=1; P[i].TAT=0;
  sum+=(P[i].BT=P[i].exec);
 }
 Sort(P,n);

printf(endl<<" |"<<c;
while(c<sum)
{
 t=0;
 if(P[I].flag)
 {
  P[I].flag=0;
  P[I].TAT=c;
 }
 while(t<2) // while(P[I].exec!=0)
 {
  c++;
  t++;
  P[I].exec--;
  if(!P[I].exec){P[I].TAT=c-P[I].TAT; break;}
  if(I!=index(P,c,t) && t!=2 || I==index(P,c,t) && t==2) break; //if(!P[I].exec || I!=index(P,c,t) && t!=2)
 }
  for(int j=1;j<=t;j++)printf("--";
  Sleep(100);
  printf("{P"<<P[I].val<<"}";
  //if(!t)printf("===";
  Sleep(100);
  for(int j=1;j<=t;j++)printf("--";
  printf(c;
  I=index(P,c,t);
 }
 printf("|"<<endl<<endl;
 printf(" P\tAT\tWT\tTAT\n_____________________________\n";
 for(int i=0;i<n;i++)
  printf("P-"<<P[i].val<<"\t"<<P[i].AT<<"\t"<<(P[i].TAT-P[i].BT)<<"\t"<<P[i].TAT<<endl;

 return 0;
}
