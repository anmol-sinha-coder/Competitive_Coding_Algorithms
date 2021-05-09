#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool ispr(int n)
{
 int A[]={2,3,5,7};
 int f1=0,fp=0;
 for(int i=2;i<n;i++)
  if(n%i==0 && n!=i)
  {
   f1=1;
   break;
  }

  while(n)
  {
   for(int i=0;i<4;i++)
    if(A[i] == n%10)
     fp=1;
   n/=10;
  }
  if(fp && f1)
    return true;
  else
    return false;

}

int main()
{
 int n;
 cout<<"Enter a number: "; cin>>n;
 if(ispr(n))
    cout<<"Yes";
 else
    cout<<"No";
 cout<<endl;

 return 0;
}
