#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define MAX 1000
int cnt=0, n;
void DFS(int i, int G[MAX][MAX], int visited[MAX], int color[MAX], int br)
{
    int j;
    printf("\t%d",i); if(br==0)cnt++;
    visited[i]=1;
    color[i]=br;
    for(j=1;j<=n;j++)
        if(!visited[j] && G[i][j]==1)
            DFS(j,G,visited,color,br);
}

int main()
{ //red=0     black=1
  int q, r,c;
  cin>>n;
  int G[MAX][MAX],visit[MAX],color[MAX];

  for(int i=0;i<=n;i++)
   for(int j=0;j<=n;j++)
    G[i][j]=color[i]=visit[i]=0;

  for(int i=1;i<=n-1;i++)
   {
    cin>>r>>c;
    G[r][c]=G[c][r]=1;
   }
   cin>>q;
   int id, p;
  for(int i=1;i<=q;i++)
{
    cin>>id>>p;  int count=0;
    switch(id)
    {
     case 1:
        DFS(p,G,visit,color,0);
        for(int i=1;i<=n;i++)
            visit[i]=0;
     break;
     case 2:
         DFS(p,G,visit,color,1);
        for(int i=1;i<=n;i++)
            visit[i]=0;
     break;
     case 3:
          cout<<cnt;

     break;
    }
    cnt=0;
}


    return 0;
}
