#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
 int n;
 cin>>n;
 char Q[n]="";
 for(int i=0;i<n;i++) cin>>Q[i];
 for(int i=0;i<n;i++)
    cout<<Q[i]<<" ";
cout<<endl;

 int i=n/2,j=n/2;
 while(i<n && j>=0)
     if(Q[i]=='-' && Q[j]=='-'){i++;}
else if(Q[i]=='-' && Q[j]=='A'){Q[i++]='A';}
else if(Q[i]=='-' && Q[j]=='B'){Q[i++]='B';}
else if(Q[i]=='A' && Q[j]=='-'){Q[j--]='A';}
else if(Q[i]=='A' && Q[j]=='A'){i++;}
else if(Q[i]=='A' && Q[j]=='B'){i++;j--;}
else if(Q[i]=='B' && Q[j]=='-'){Q[j--]='B';}
else if(Q[i]=='B' && Q[j]=='A'){i++;j--;}
else if(Q[i]=='B' && Q[j]=='B'){i++;}

for(int i=0;i<n;i++)
    cout<<Q[i]<<" ";
cout<<endl;



 return 0;
}
