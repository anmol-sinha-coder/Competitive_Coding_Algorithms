#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct City
{int g,p;};

int main()
{
 int n,q;
 cin>>n>>q;
 int D[n-1]; City C[n];
 for(int i=0;i<n-1;i++) cin>>D[i];
 for(int i=0;i<n;i++) cin>>C[i].g>>C[i].p;
 for(int Q=1;Q<=q;Q++)
 {
  int x,y;
  cin>>x>>y;
  int cost=0, gas=0;
  for(int ct=x-1; ct<y-1; ct++)
  {
   gas += C[ct].g;
   if(D[ct]>gas)
    cost += C[ct].p * (D[ct]-gas), gas=D[ct];
   gas-=D[ct];
  }
  cout<<cost<<endl;
 }

    return 0;
}
