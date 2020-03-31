#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct stack
{
 int data;
 struct stack *next;
}*top;

void push(int val)
{
 if(!top)
 {
  top=(struct stack*)malloc(sizeof(struct stack));
  top->next=NULL;
  top->data=val;
  return;
 }
 struct stack *nn=(struct stack*)malloc(sizeof(struct stack));
 nn->data=val;
 nn->next=top;
 top=nn;
}

void pop()
{
 if(!top)return;
 struct stack *temp=top;
 top=top->next;
 free(temp);
}

int peek()
{
    printf("%d,",top->data);
    return top->data;
}

bool Empty()
{
 if(!top)
    return 1;
 else
    return 0;
}

void Display()
{
 if(!Empty())
 {
  peek();
  pop();
  Display();
 }
}

int main()
{
 for(int i=1;i<=10;i++)
  push(i);
  Display();

 return 0;
}
