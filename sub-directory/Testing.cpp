#include<iostream>

using namespace std;

int main()
{
  int T; cin>>T;
  for(int t=1;t<=T;t++)
  {
   int n,x; cin>>n>>x; int A[n]={0};
   for(int i=0;i<n;i++) cin>>A[i];

   int stops=-1,d=x-1;
   while(d<n)
    d+=A[d], stops++;

   cout<<stops<<endl;

   d=x-1;
   for(int j=0;j<stops;j++,d+=A[d])
     cout<<d+1<<" ";
   cout<<endl;
  }

  return 0;
}
