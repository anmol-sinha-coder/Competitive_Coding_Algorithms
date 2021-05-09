#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int trap_water(int A[],int n)
{
  int l_r[n]={0}, r_l[n]={0}, water=0;
  for(int i=1;i<=n-1-1;i++)
   if(A[i-1]>A[i])
    l_r[i]=A[i-1]-A[i];

  for(int j=n-1-1;j>=1;j--)
   if(A[j+1]>A[j])
    r_l[j]=A[j+1]-A[j];

  for(int i=1;i<=n-1-1;i++)
    water+=min(l_r[i],r_l[i]);

  return water;
}

int main()
{
 int n;  cin>>n;
 int A[n];
 for(int i=0;i<n;i++)
    cin>>A[i];

 cout<<"Total water = "<<trap_water<<endl;

 return 0;
}
