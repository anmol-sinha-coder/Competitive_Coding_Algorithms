#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
 int t; cin>>t;
 bool flag=false;
 int a[t],b[t];
 for(int i=0;i<t;i++)
    cin>>a[i]>>b[i];

 for(int i=0,count=0;i<t;i++,count=0)
   for(int j=(i+1)%t;count++<t;j=(j+1)%t)
     if(abs(a[j]-a[i])>=b[i] && ((a[j]-a[i])*b[i])>0)
        flag=true;

 if(flag)
    cout<<"YES";
 else
    cout<<"NO";

return 0;
}
