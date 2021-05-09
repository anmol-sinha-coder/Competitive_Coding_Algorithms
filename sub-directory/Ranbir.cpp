#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
 int n,k,p;   cin>>n>>k>>p;
 int A[n]; for(int j=0;j<n;j++) cin>>A[j];
 cout<<endl;
 for(int i=0;i<p;i++)
 {
  int small=INT_MAX, pos=0;
  for(int j=0;j<n;j++)
    if(A[j]<small)
     small=A[pos=j];

  if(pos<k)
    for(int j=0;j<k;j++)
      ++A[j];
  else
    for(int j=pos-k+1;j<=pos;j++)
      ++A[j];
  for(int i=0;i<n;i++)cout<<A[i]<<","; cout<<"\b \n";
 }

 int sm=INT_MAX;
 for(int i=0;i<n;i++)
    if(A[i]<sm)
      sm=A[i];
 cout<<"Maximized small value = "<<sm<<endl;

 return 0;
}
