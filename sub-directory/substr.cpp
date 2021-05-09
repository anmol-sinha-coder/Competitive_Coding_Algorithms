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

int sub_arr(char S[],char T[]) // cannot count overlapping sequences, nor perform rotation
{
 int count=0; char sub[100]="";

 for(int i=0,j=0;i<strlen(S);i++,count+=strcmp(sub,T)==0?1:0) // O(n) mai banaaya! :)
  if(S[i]==T[j%=strlen(T)])
   *(&(sub[++j-1]=T[j-1])+1)='\0';
  else
   sub[j=0]='\0';

  return count;
}

int sub_rotate(char S[],char T[],int r) //can perform rotation, but not overlap recognition
{
 int cnt=0;
 char sub[100]="";

 for(int i=0,j=0;i<r;i++,cnt+=strcmp(sub,T)==0?1:0) // O(n) mai banaaya! :)
  if(S[i%strlen(S)]==T[j%=strlen(T)])
   *(&(sub[++j-1]=T[j-1])+1)='\0';
  else
   sub[j=0]='\0';

  return cnt;
}

int main()
{
 char S[100]="",T[100]=""; time_t s=0,e=0;
 cin.getline(S,100);
 cin.getline(T);
 s=clock();
 cout<<"Total (overlap and non-overlap) substrings="<<sub_over(S,T);
 e=clock();

 return 0;
}
