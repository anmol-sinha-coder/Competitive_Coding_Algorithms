#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Result(char V[], int n)
{
 int A[n]={0},B[n]={0},_[n]={0}; char C[]="";
 int a=0, b=0, o=0;
 for(int i=0;i<n;i++)
   if(V[i]=='A')
    A[a++]=i;
   else if(V[i]=='B')
    A[b++]=i;
   else
    _[o++]=i;

 int A_count=0, B_count=0;
 for(int j=0;j<o;j++)



}

int main()
{
 int n;  cout<<"Enter size of election voters: "; cin>>n;
 cout<<"Enter the sequence:  ";
 char V[n]; for(int i=0;i<n;i++)cin>>V[i];
 Result(V,n);
 cout<<endl;
 return 0;
}
