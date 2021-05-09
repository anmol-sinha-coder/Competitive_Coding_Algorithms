#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sub_over(char S[],char T[]) // can recognize overlapping sequence as well as non-overlapping sequences, but no rotation
{
 int count=0,pos=0; char sub[100]="";
 for(int i=0,j=0;i<strlen(S);i++,count+=strcmp(sub,T)==0?((i=pos)==i)&&((j=0)==j):0,pos=(S[i]==T[0] && j>1)?i:pos)// O(n) mai banaaya! :)
  if(S[i]==T[j%=strlen(T)])
   *(&(sub[++j-1]=T[j-1])+1)='\0';
  else if(S[i]!=T[j%=strlen(T)])
   sub[j=0]='\0';

  return count;
}

int main()
{
 time_t s=0,e=0;
 cout<<scientific<<setprecision(3);
 for(int k=5000;k<=50000;k+=5000)
 {
  char S[k+1]="",T[k+1]="";
  for(int i=0;i<k;i++)
   S[i]=T[i]=i%256;
  s=clock();
  for(int i=0;i<999;i++)
   sub_over(S,T);
  e=clock();
  cout<<(long double)(e-s)/(1000*CLOCKS_PER_SEC)<<endl;
 }

 return 0;
}
