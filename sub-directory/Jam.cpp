#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
 int n,rev=0,d=0;
 cout<<"Enter number: "; cin>>n;
 while(n)
  rev = 10*rev + n%10;

 while(rev)
 {
  d=n%10;
  for(int i=0;i<n;i++)
    cout<<"(";

  n/=10;
 }


 return 0;
}
