#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int cap1,cap2,init1,init2,fin1,fin2,**V,**E; unsigned int depth_limit,x=0;
vector<int> action;
bool state(int jug_1,int jug_2) // Adjacency Matrix representation for Graph with Depth First Search node expansion
{
 static int seq=1,cond;
 V[jug_1][jug_2]=seq++;
 if(jug_1==fin1 && jug_2==fin2 && seq-1<=depth_limit)
 {
  cout<<endl<<" ";
  for(int s=1;s<=seq-1;s++)
   for(int i=0;i<=cap1;i++)
    for(int j=0;j<=cap2;j++)
     if(V[i][j]==s)
      cout<<"["<<i<<","<<j<<"] >-{"<<action[s-1]<<".}-> ";
  cout<<"\b\b\b\b\b\b\b\b\b         \n";
  cout<<"Total states: "<<seq-1<<endl; cond=9;
  return x=1;
 }
 else
  cond=0;

  if(jug_1<cap1) // 1
   if(V[cap1][jug_2]==0)
   {
    action.push_back(cond=1);
    E[jug_1*cap1 + jug_2][cap1*cap1 + jug_2]=V[jug_1][jug_2];
    state(cap1,jug_2);
    E[jug_1*cap1 + jug_2][cap1*cap1 + jug_2]=0;
    V[cap1][jug_2]=0; seq--;
    action.pop_back();
   }

  if(jug_2<cap2) // 2
   if(V[jug_1][cap2]==0)
   {
    action.push_back(cond=2);
    E[jug_1*cap1 + jug_2][jug_1*cap1 + cap2]=V[jug_1][jug_2];
    state(jug_1,cap2);
    E[jug_1*cap1 + jug_2][jug_1*cap1 + cap2]=0;
    V[jug_1][cap2]=0; seq--; cond=9;
    action.pop_back();
   }

  if(jug_1>0) // 3
   if(V[0][jug_2]==0)
   {
    action.push_back(cond=3);
    E[jug_1*cap1 + jug_2][0*cap1 + jug_2]=V[jug_1][jug_2];
    state(0,jug_2);
    E[jug_1*cap1 + jug_2][0*cap1 + jug_2]=0;
    V[0][jug_2]=0; seq--;
    action.pop_back();
   }

  if(jug_2>0) // 4
   if(V[jug_1][0]==0)
   {
    action.push_back(cond=4);
    E[jug_1*cap1 + jug_2][jug_1*cap1 + 0]=V[jug_1][jug_2];
    state(jug_1,0);
    E[jug_1*cap1 + jug_2][jug_1*cap1 + 0]=0;
    V[jug_1][0]=0; seq--;
    action.pop_back();
   }

  if(jug_1+jug_2>=cap1 && jug_2>0) // 5
   if(V[cap1][jug_2-(cap1-jug_1)]==0)
   {
    action.push_back(cond=5);
    E[jug_1*cap1 + jug_2][cap1*cap1 + (jug_2-(cap1-jug_1))]=V[jug_1][jug_2];
    state(cap1,jug_2-(cap1-jug_1));
    E[jug_1*cap1 + jug_2][cap1*cap1 + jug_2-(cap1-jug_1)]=0;
    V[cap1][jug_2-(cap1-jug_1)]=0; seq--;
    action.pop_back();
   }

  if(jug_1+jug_2>=cap2 && jug_1>0) // 6
   if(V[jug_1-(cap2-jug_2)][cap2]==0)
   {
    action.push_back(cond=6);
    E[jug_1*cap1+jug_2][(jug_2-(cap1-jug_1))*cap1 + cap2]=V[jug_1][jug_2];
    state(jug_1-(cap2-jug_2),cap2);
    E[jug_1*cap1 + jug_2][(jug_2-(cap1-jug_1))*cap1 + cap2]=0;
    V[jug_1-(cap2-jug_2)][cap2]=0; seq--;
    action.pop_back();
   }

  if(jug_1+jug_2<=cap1 && jug_2>0) // 7
   if(V[jug_1+jug_2][0]==0)
   {
    action.push_back(cond=7);
    E[jug_1*cap1+jug_2][(jug_1+jug_2)*cap1 + 0]=V[jug_1][jug_2];
    state(jug_1+jug_2,0);
    E[jug_1*cap1 + jug_2][(jug_1+jug_2)*cap1 + 0]=0;
    V[jug_1+jug_2][0]=0; seq--;
    action.pop_back();
   }

  if(jug_1+jug_2<=cap2 && jug_1>0) // 8
   if(V[0][jug_1+jug_2]==0)
   {
    action.push_back(cond=8);
    E[jug_1*cap1 + jug_2][0*cap1 + (jug_1+jug_2)]=V[jug_1][jug_2];
    state(0,jug_1+jug_2);
    E[jug_1*cap1 + jug_2][0*cap1 + (jug_1+jug_2)]=0;
    V[0][jug_1+jug_2]=0; seq--;
    action.pop_back();
   }
 //action.pop_back();
 if(cond==0)
  return 0;
return x;
}

/*
void DFS(int jug_1,jug_2,int number_of_states) // Min state representation
{

    // Print the current node
    cout << start << " ";

    // Set current node as visited
    V[jug_1][jug_2] = true;

    for (int i = 0; i < v; i++)
        if (E[][i] == 1 && (!V[jug_1][jug_2]))
            DFS(i,);
}
*/

int main()
{
 cout<<"                  "<<"Jug-1  Jug-2"<<endl;
 cout<<"Enter capacities:     "; cin>>cap1>>cap2;
 cout<<"Enter initial states: "; cin>>init1>>init2;
 cout<<"Enter final states:   "; cin>>fin1>>fin2;
 cout<<"Enter Depth Limit: "; cin>>depth_limit;
 cout<<endl<<"RULE/ACTIONS:-\n|{1.}| Fill up Jug-1 upto brim.\n|{2.}| Fill up Jug-2 upto brim.\n|{3.}| Empty Jug-1 completely.\n|{4.}| Empty Jug-2 completely.";
 cout<<endl<<"|{5.}| Pour water into Jug-1 until its filled up, from Jug-2.\n|{6.}| Pour water from Jug-1, into Jug-2 until it is filled up completely.\n|{7.}| Pour entire contents of Jug-2 into Jug-1 until Jug-2 is empty.\n|{8.}| Pour entire contents of Jug-1 into Jug-2 until Jug-1 is empty.\n";
 cout<<endl;
 V=new int*[cap1+1]; for(int p=0;p<cap1+1;p++)*(V+p)=new int[cap2+1];
 E=new int*[(cap1+1)*(cap2+1)]; for(int p=0;p<(cap1+1)*(cap2+1);p++)*(E+p)=new int[(cap1+1)*(cap2+1)];
 for(int i=0; i<(cap1+1)*(cap2+1); i++) // Initializing all to 0
  for(int j=0;j<(cap1+1)*(cap2+1); j++)
   E[i][j]=V[i%(cap1+1)][j%(cap2+1)]=0;

 int jug1=init1,jug2=init2;
 if(state(jug1,jug2))
  cout<<endl<<"Hence solution exists !"<<endl;
 else
  cout<<endl<<"Solution state does not exist !"<<endl<<endl;

 return 0;
}
