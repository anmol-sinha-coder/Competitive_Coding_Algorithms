#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sub_rotate(char S[],char T[],int r)
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
 char S[100]="codechef",T[100]="chefcode"; time_t s=0,e=0;
 s=clock();
 //cin.getline(S,100);
 //cin.getline(T,100);
 //cout<<S<<"\t"<<T<<endl;
 int n=3; //cin>>n;
 for(int i=0;i<n;i++)
 {
  int r; //cin>>r;
  if(i==0)r=4; else if(i==1)r=12; else r=1455;
  cout<<sub_rotate(S,T,r)<<endl;
 }
 e=clock();
 cout<<scientific<<setprecision(3)<<(long double)(e-s)/(CLOCKS_PER_SEC);
 return 0;
}
