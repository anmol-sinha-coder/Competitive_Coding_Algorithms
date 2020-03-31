#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char Stack[100]="";
int top=-1,size=100;
void Display();
int prec(char c)
{
 if(c=='^')
  return 6;
 if(c=='*' || c=='/' || c=='%')
  return 5;
 if(c=='+' || c=='-')
  return 4;
 if(c=='&')
  return 3;
 if(c=='|')
  return 2;
 else
 return 0;
}

void Push(char c)
{
 if(size-1==top)
    return;
 Stack[++top]=c;
}

int Pop()
{if(top==-1)
  return -1;
 return top--;
}

char Peek()
{
 if(top!=-1)
 return Stack[top];
}

void Infix_to_Postfix(char In[],char Post[])
{
 int l=strlen(In),k=0;
 In[l]=')';In[++l]='\0';
 Push('(');
Display();printf("\n");
 for(int i=0;i<l;i++)        //Modification for unary operators
  if(In[i]=='!' || In[i]=='~')
  {
   for(int j=l;j>=i;j--)
    In[j+1]=In[j];
   In[i]='(';
   i++;
   l++;
   if(In[i+1]=='(')
   {
    for(k=i+1;In[k]!=')';k++);
   for(int j=l;j>=k;j--)
    In[j+1]=In[j];
   In[k]=')';
   l++;
   }
  }
k=0;l=strlen(In);
printf("\n%s\n",In);
for(int i=0;i<l;i++)
 {
  if(isalpha(In[i]))
   Post[k++]=In[i];
  else if((prec(In[i])>prec(Peek()) || In[i]=='(' ))
  {
    Push(In[i]);
  }
  else if((prec(In[i])<=prec(Peek())) || In[i]==')')
  {
    while(Peek()!='(')
   {
    Post[k++]=Peek();
    Pop();
   }
   if(In[i]!=')')
    Push(In[i]);
   else
    Pop();
  }
 }
 In[--l]='\0';
}

void Display()
{
 if(Pop()==-1)
    return;
printf("%d",Pop());
 Display();
}

void Reversal(char A[])
{
 int l=strlen(A);
 for(int i=0,j=l-1;i<=l/2,j>=l/2;i++,j--)
 {
  char t=A[i];
  A[i]=A[j];
  A[j]=t;
 }
 for(int i=0;i<l;i++)
 {
  if(A[i]=='(')
   A[i]=')';
  else if(A[i]==')')
   A[i]='(';
 }
}

void main()
{
 char In[100],Post[100]="",Pre[100]="";
 printf("Enter Infix Expression: ");
 gets(In);
 Infix_to_Postfix(In,Post);
 printf("# %s\n",In);
 printf("Postfix Expression: %s\n",Post);
 Reversal(In);
 Infix_to_Postfix(In,Pre);
 Reversal(Pre);
 printf("Prefix Expression: %s\n",Pre);
}
