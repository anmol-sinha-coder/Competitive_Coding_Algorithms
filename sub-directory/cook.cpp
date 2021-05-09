#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int ways=0, // ways to distribute tasks among cooks
    n,m ;
void chef(int x[], int y[], int lb, int ub)
{
 static int *c=new int[ub-lb+1];
 if(lb<=ub)
 {
  for(int i=x[lb];i<=y[lb];i++)
  {
    c[lb]=i;
    chef(x,y,lb+1,ub);
  }
 }
 else
 {
   int sum=0;
   for(int i=0;i<=ub;i++)
    sum+=c[i]; //cout<<" "<<c[i]<<"\t";

   if(sum==n)
    ways++;

 }

}

int main()
{
   cin>>n>>m; int x[m],y[m];
   for(int j=0;j<m;j++) cin>>x[j]>>y[j];
   //c = new int[m]; for(int i=0;i<m;i++) c[i]=x[i]-1;
   cout<<endl;
   chef(x,y,0,m-1);
    cout<<"Distributions = "<<ways<<endl;

  return 0;
}
