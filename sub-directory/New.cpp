#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
 int n;
 cin>>n;
 for(int c=1;c<=n;c++)
 {
 char S[100]; //NESTING DEPTHS
 int big=INT_MIN;
 gets(S);
 for(int i=0;i<strlen(S);i++)
  if(isdigit(S[i]))
   if((int)S[i]-48 > big)
    big=(int)S[i]-48;
   else ;
  else
   exit(0);

 char N[100]="";
 int j=0,pos=0;
 int d1=0,d2;
 for(int i=0;i<strlen(S);i++)
 {
  d2=(int)S[i]-48;
  while(j-pos < d1-d2)
   N[j++]=')';
  while(j-pos < d2-d1)
   N[j++]='(';
  N[j++]=S[i];
  pos=j;
  d1=d2;
 }
 while(j-pos < d2)
  N[j++]=')';
 N[j++]='\0';

 cout<<"Case #"<<c<<": ";
 puts(N);
 }
 return 0;
}
