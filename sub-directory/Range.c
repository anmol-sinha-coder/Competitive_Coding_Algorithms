#include<stdio.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dos.h>
#include<math.h>
#include<time.h>
#include<string.h>

void main()
{
 char S[500]="",ch;
 int l,i,j,n,cnt=0,t1,t2;
 printf("Enter the string: ");
 scanf("%s",S);
 l=strlen(S);

for(i=0;i<l;i++)
{
  n=S[i];

  for(j=1;j<=n;j++)
    if(n%j==0)
      cnt++;

  if(cnt!=2)  //If number 'n' is not prime
  {
   t1=n;
   t2=n;
  while(1)   //INFINITE LOOP
  {
     cnt=0;
     t1--;
     for(j=1;j<=t1;j++)
     {
      if(t1%j==0)
      cnt++;
     }
     if(cnt==2)
     {
         n=t1;
         break;
     }

     cnt=0;
     t2++;
     for(j=1;j<=t2;j++)
     {
      if(t2%j==0)
      cnt++;
     }
     if(cnt==2)
     {
         n=t2;
         break;
     }

  }
 }
 S[i]=n;
 cnt=0;
}

 printf("The Dhananjay MAGICAL WORD is: %c%s%c\n\n",34,S,34);
}
