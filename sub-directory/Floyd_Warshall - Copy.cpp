#include<iostream>
#include<iomanip>
#define MAX 100
using namespace std;

int n;
void floydWarshal(int Adj_Mat_Graph[MAX][MAX])
{
   int cost[MAX][MAX];    //defined to store shortest distance from any node to any node
   for(int i = 0; i<n; i++)
      for(int j = 0; j<n; j++)
         cost[i][j] = Adj_Mat_Graph[i][j];     //copy Adj_Mat_Graph to new matrix

   for(int k = 0; k<n; k++) {
      for(int i = 0; i<n; i++)
         for(int j = 0; j<n; j++)
            if(cost[i][k]+cost[k][j] < cost[i][j])
               cost[i][j] = cost[i][k]+cost[k][j];
   }
     cout << "\n\nThe matrix for Floyd-Warshall:" << endl;
   for(int i = 0; i<n; i++)
   {
      for(int j = 0; j<n; j++)
         cout << setw(3) << cost[i][j];
      cout << endl;
   }
}

int main()
{
int Adj_Mat_Graph[MAX][MAX];
cout<<"Enter number of Nodes: "; cin>>n;
cout<<"Enter Graph Adjacency Matrix: \n";
for(int i=0;i<n;i++)
 for(int j=0;j<n;j++)
     cin>>Adj_Mat_Graph[i][j];

 floydWarshal(Adj_Mat_Graph);

/*
   0  3  6  999 999 999 999
   3  0  2   1  999 999 999
   6  2  0   1   4   2  999
 999  1  1   0   2  999  4
 999 999 4   2   0   2   1
 999 999 2  999  2   0   1
 999 999 999 4   1   1   0
*/
return 0;
}
