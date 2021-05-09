#include<iostream>
//#include<bits/stdc++.h>
using namespace std;

int main()
{
 int act;
 cin>>act;
 int A[act][2];
 char S[100];
 for(int i=0;i<act;i++)
  for(int j=0;j<2;j++)
   cin>>A[i][j];

 int i=0;
 S[i++]='C';
 while(i<act)
 {
  i++;
 }
 S[i]='\0';
 puts(S);

 return 0;
}
