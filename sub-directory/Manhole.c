
#include<stdio.h>
#include<conio.h>
#include<stddef.h>
#include<stdlib.h>
#include<unistd.h>
#include<dos.h>
#include<math.h>
#include<time.h>

void main()
{
    printf("___________THE DRUNKEN MAN AND THE MAN-HOLE___________\n\n");
 int f,b,h,i,p=0,s=0,m=0;
 printf("Enter number of forward steps: ");
 scanf("%d",&f);
 printf("Enter number of backward steps: ");
 scanf("%d",&b);
 printf("Enter the position of manhole: ");
 scanf("%d",&h);

 while(p!=h)
{
  i=1;
     printf("\n---------------------\n %d moves completed\n---------------------",m);
  while(i<=f)
  {
   printf("\n(%d) #%d#",s,p);
   if(p==h)
    break;
   p++;
   i++;
   s++;
  }
  if(p!=h)
  m++;

  printf("\n---------------------\n %d moves completed\n---------------------",m);
  i=1;
  while(i<=b)
  {
   printf("\n(%d) #%d#",s,p);
   if(p==h)
    break;
   p--;
   i++;
   s++;
  }
  if(p!=h)
   m++;


}
printf("\n\n   He is in the manhole now !!!!!  ",m);
 printf("\n\n");


//DIAGRAMATIC REPRESENTATION
 system("pause");
 printf("\n\n\n\n");
 system("cls");
 printf("\n\n");
 printf("   HERE ");
  usleep(150000);
 printf("HE ");
  usleep(150000);
 printf("GOES ");
  usleep(150000);
 printf(".");
  usleep(150000);
 printf(".");
  usleep(150000);
 printf(".");
  usleep(150000);
 printf(".");
  usleep(150000);
 printf(".");
  usleep(150000);
 printf(".");
  usleep(150000);
 printf(".");
  usleep(150000);
 printf(".");
  usleep(500000);
  usleep(500000);
printf("\n\n\n\n");
 p=1;
 printf("\t| ");
 usleep(500000);
 while(p!=h)
 {
  i=1;
  while(i<=f)
  {

   if(p==h)
    {
    printf("O\b");
    break;
    }
   else
    printf("X");
   p++;
   i++;
   s++;
   usleep(150000);
   usleep(150000);
   usleep(150000);
   usleep(150000);
   usleep(150000);
   printf("\b-");
  }

  m++;
  i=1;
  while(i<=b)
  {
   if(p==h)
    {
    printf("(O)");
    usleep(500000);
    printf("\n\n\n\n\n\n       ' Down ");
   usleep(200000);
    printf("the ");
   usleep(200000);
    printf("man-hole ");
   usleep(200000);
    printf("he ");
   usleep(200000);
    printf("goes ");
   usleep(200000);
    printf("!!!!! '");
   usleep(500000);
   usleep(500000);
   usleep(500000);

    break;
    }
    else
    {
    printf("\b\bX-");
   usleep(150000);
   usleep(150000);
   usleep(150000);
   usleep(150000);
   usleep(150000);
   printf("\b\b-");
    }
   p--;
   i++;
   s++;
  }
m++;

 }

 printf("\n\n\n");
}
