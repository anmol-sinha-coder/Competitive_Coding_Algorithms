#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> absolutePermutation(int n, int k)
{
 vector<int> A(n,-1); bool abs_perm=true;

 for(int pos=0;pos<n;pos++)
    if(pos+1-k>=0 && A[pos-k]==-1)
     A[pos-k]=pos+1;
    else if(pos+1+k<=n && A[pos+k]==-1)
     A[pos+k]=pos+1;

 for(int i=0;i<n;i++)
  if(A[i]==-1 || abs(A[i]-(i+1))!=k)
   return {-1};

 return A;
}

int main()
{
  int n=8,k=2;
  vector<int> A = absolutePermutation(n,k);
  for(int i=0;i<A.size();i++)
    cout<<A[i]<<",";
  cout<<"\b \n";

 return 0;
}
