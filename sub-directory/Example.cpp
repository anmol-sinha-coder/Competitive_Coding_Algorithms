#include<iostream>
#include<bits/stdc++.h>

struct Vertices
{
int Jug_1, Jug_2;
Vertices *link;
}*root, *left, *right;

void DFS()
{
Vertices *temp;
temp=left;
printf("DFS Result\nStart State  ::  (%d , %d)\n", root->Jug_1, root->Jug_2);
printf("Possible DFS Result 1\n");
   while(1)
    {
    printf("(%d , %d)\n", temp->Jug_1, temp->Jug_2);
    if(temp->link == NULL)
     break;
    temp = temp->link;
}
temp = right;
printf("Possible DFS Result 2\n");
   while(1)
    {
    printf("(%d , %d)\n", temp->Jug_1, temp->Jug_2);
    if(temp->link == NULL)
    break;
    temp = temp->link;
    }
}

int isNodePresent(Vertices *nextState, int capacity_1, int capacity_2, int reqJug1, int reqJug2)
{
Vertices *temp;
if((nextState->Jug_1 == reqJug1) && (nextState->Jug_2 == reqJug2))
return(0);
if((nextState->Jug_1 == capacity_1) && (nextState->Jug_2 == capacity_2))
return(1);
if((nextState->Jug_1 == 0) && (nextState->Jug_2 == 0))
return(1);
temp = left;
while(1)
{
if((temp->Jug_1 == nextState->Jug_1) && (temp->Jug_2 == nextState->Jug_2))
 return(1);
else if(temp->link == NULL)
break;
else
temp = temp->link;
}
temp = right;

while(1)
{
if((temp->Jug_1 == nextState->Jug_1) && (temp->Jug_2 == nextState->Jug_2))
 return(1);
else if(temp->link == NULL)
break;
temp = temp->link;
}
return(0);
}

Vertices* genNewState(Vertices *currentState, int capacity_1, int capacity_2, int reqJug1, int reqJug2)
{
int d;
Vertices *nextState;
nextState = (Vertices*)malloc(sizeof(Vertices));
nextState->Jug_1 = capacity_1;
nextState->Jug_2 = currentState->Jug_2;
if(isNodePresent(nextState, capacity_1, capacity_2, reqJug1, reqJug2) != 1)
return(nextState);
nextState->Jug_1 = currentState->Jug_1;
nextState->Jug_2 = capacity_2;
if(isNodePresent(nextState, capacity_1, capacity_2, reqJug1, reqJug2) != 1)
return(nextState);
nextState->Jug_1 = 0;
nextState->Jug_2 = currentState->Jug_2;

if(isNodePresent(nextState, capacity_1, capacity_2, reqJug1, reqJug2) != 1)
 return(nextState);
nextState->Jug_2 = 0;
nextState->Jug_1 = currentState->Jug_1;
if(isNodePresent(nextState, capacity_1, capacity_2, reqJug1, reqJug2) != 1)
 return(nextState);
if((currentState->Jug_2 < capacity_2) && (currentState->Jug_1 != 0))
 {
 d = capacity_2 - currentState->Jug_2;
 if(d >= currentState->Jug_1)
 {
 nextState->Jug_1 = 0;
 nextState->Jug_2 = currentState->Jug_2 + currentState->Jug_1;
 }
else
 {
 nextState->Jug_1 = currentState->Jug_1 - d;
 nextState->Jug_2 = currentState->Jug_2 + d;
 }
 if(isNodePresent(nextState, capacity_1, capacity_2, reqJug1, reqJug2) != 1)
  return(nextState);
}
 if((currentState->Jug_1 < capacity_1) && (currentState->Jug_2 != 0))
 {
 d = capacity_1 - currentState->Jug_1;
 if(d >= currentState->Jug_2)
 {
  nextState->Jug_2 = 0;
  nextState->Jug_1 = currentState->Jug_1 + currentState->Jug_2;
 }
 else
 {
  nextState->Jug_2 = currentState->Jug_2 - d;
  nextState->Jug_1 = currentState->Jug_1 + d;
 }
if(isNodePresent(nextState, capacity_1, capacity_2, reqJug1, reqJug2) != 1)
 return(nextState);
}
 return(NULL);
}

void generateTree(int capacity_1, int capacity_2, int reqJug1, int reqJug2)
{
int flag1, flag2;
Vertices *tempLeft, *tempRight;
root  = (Vertices*)malloc(sizeof(Vertices));
root->Jug_1 = 0; root->Jug_2 = 0; root->link = NULL;
left = (Vertices*)malloc(sizeof(Vertices));
left->Jug_1 = 0; left->Jug_2 = capacity_2; left->link = NULL;
right = (Vertices*)malloc(sizeof(Vertices));
right->Jug_1 = capacity_1; right->Jug_2 = 0; right->link = NULL;
tempLeft = left;
tempRight = right;
while(1)
{
flag1 = 0; flag2 = 0;
if((tempLeft->Jug_1 != reqJug1) || (tempLeft->Jug_2 != reqJug2))
{
tempLeft->link = genNewState(tempLeft, capacity_1, capacity_2, reqJug1, reqJug2);
tempLeft = tempLeft->link;
tempLeft->link = NULL;
flag1 = 1;
}
if((tempRight->Jug_1 != reqJug1) || (tempRight->Jug_2 != reqJug2))
{
tempRight->link = genNewState(tempRight, capacity_1, capacity_2, reqJug1, reqJug2);
tempRight = tempRight->link;
tempRight->link = NULL;
flag2 = 1;
}

if((flag1 == 0) && (flag2 == 0))
 break;
}
}

int main()
{
int capacity_1, capacity_2, reqJug1, reqJug2;
//clrscr();
printf("Enter the maximum capacity of jug1     ::     ");
scanf("%d", &capacity_1);
printf("Enter the maximum capacity of jug2     ::     ");
scanf("%d", &capacity_2);
printf("Enter the required water in jug1     ::     ");
scanf("%d", &reqJug1);
printf("Enter the required water in jug2     ::     ");
scanf("%d", &reqJug2);
generateTree(capacity_1, capacity_2, reqJug1, reqJug2);
DFS();
return 0;
}
