#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int n;
bool createsMST(int u, int v, bool inMST[]){
   if(u == v)
      return false;

   if(inMST[u] == false && inMST[v] == false)
      return false;

   else if(inMST[u] == true && inMST[v] == true)
      return false;

   return true;
}

void MinSpanningTree(int cost[][MAX])
{
   bool inMST[MAX]; memset(inMST,false,MAX);
   inMST[0] = true;
   int edgeNo = 0, MSTcost = 0;
   while (edgeNo < n - 1)
    {
      int min = INT_MAX, a = -1, b = -1;
      for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++)
            if (cost[i][j] < min)
               if (createsMST(i, j, inMST))
                {
                  min = cost[i][j];
                  a = i; b = j;
                }

      if (a != -1 && b != -1) // Something has to be selected for MST
      {
         cout<<"Edge "<<++edgeNo<<" : ("<<a<<" , "<<b<<" ) : cost = "<<min<<endl;
         MSTcost += min;
         inMST[b] = inMST[a] = true;
      }
    }
   cout<<"Cost of Minimum spanning tree = "<<MSTcost;

}

int main()
{
    cout<<"\nEnter the no. of vertices: "; cin>>n;
    int cost[n][MAX];
    cout<<"\nEnter the cost adjacency matrix (should be symmetric for undirected graph):-\n";
    cout<<"   ";
    for(int k=0;k<n;k++)
      cout<<k<<" ";
    cout<<endl;
    cout<<"   ";
    for(int k=0;k<n;k++)
      cout<<"- ";
    cout<<endl;
    for(int i=0;i<n;i++)
    {
     cout<<i<<"| ";
     for(int j=0;j<n;j++)
     {
      cin>>cost[i][j];
      if(cost[i][j]==0)
        cost[i][j]=INT_MAX;
     }
    }

   cout<<"\nThe Minimum spanning tree for the given tree is :\n";
   MinSpanningTree(cost); // Prim's Algorithm
   cout<<endl;
   return 0;
}
