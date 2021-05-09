#include <iostream>
#include <bits/stdc++.h>
#define MAX_LIMIT 100
using namespace std;

int i,j,k;
int minimum,min_cost=0,cost[MAX_LIMIT][MAX_LIMIT],parent[MAX_LIMIT];

int find(int i)
{
    while(parent[i])
     i=parent[i];

    return i;
}

bool Union(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}

int main()
{
    int a,b,u,v,n;
    cout<<"\t_________________Implementation of Kruskal's algorithm_________________\n";
    cout<<"\nEnter the no. of vertices: "; cin>>n;
    cout<<"\nEnter the cost adjacency matrix (should be symmetric for undirected graph):-\n";
    cout<<"   ";
    for(int k=1;k<=n;k++)
      cout<<k<<" ";
    cout<<endl;
    cout<<"   ";
    for(int k=1;k<=n;k++)
      cout<<"- ";
    cout<<endl;
    for(i=1;i<=n;i++)
    {
     cout<<i<<"| ";
     for(j=1;j<=n;j++)
     {
      cin>>cost[i][j];
      if(cost[i][j]==0)
        cost[i][j]=INT_MAX;
     }
    }

    printf("\nThe edges of Minimum Cost Spanning Tree are:-\n");
    for(int x=1;x<n;x++)
    {
        minimum=INT_MAX;
        for(int i=1;i<=n;i++)
            for(j=1;j <= n;j++)
                if(cost[i][j] < minimum)
                {
                    minimum=cost[i][j];
                    a=u=i;  b=v=j;
                }

        u=find(u);
        v=find(v);
        if(Union(u,v))
        {
            cout<<"("<<x<<")\tEdge-("<<a<<","<<b<<") = "<<minimum<<endl;
            min_cost +=minimum;
        }
        cost[a][b]=cost[b][a]=INT_MAX;
    }

    printf("\n\tMinimum cost = %d\n",min_cost);
    return 0;
}
