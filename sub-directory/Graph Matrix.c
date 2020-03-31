#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int a[20][20], q[20]={0}, visited[20]={0}, reach[20]={0}, n, i, j, f = 0, r = 0;

void bfs(int v)
{
 for(i = 1; i <= n; i++)
  if(a[v][i] && !visited[i])
   q[r++] = i;

 if(f <= r)
 {
  if(!visited[v]) printf("%c,",64+v);
  visited[v] = 1;
  bfs(q[f++]);
 }
}

void dfs(int v)
{
 int i;
 reach[v]=1;
  printf("%c,",64+v);
 for(i=1;i<=n;i++)
  if(a[v][i] && !reach[i])
   dfs(i);
}

int create()
{
int v;
char ch;
 printf("\n Enter number of vertices: ");
 scanf("%d", &n);
 printf("\n Enter graph data in matrix form:\n");
 printf("\t"); for(int i=1;i<=n;i++)printf("%c ",64+i); printf("\n\t"); for(int i=1;i<=n;i++) printf("|_"); printf("\b \n");
 for(i=1; i<=n; i++)
 {
   printf("   %c|\t",64+i);
  for(j=1;j<=n;j++)
   scanf("%d", &a[i][j]);
 }

  printf("\n Enter the starting vertex (%c-%c): ",64+1,64+n);
  scanf(" %c", &ch);
  v=ch-64;

 return v;
}

void Delete(int )

int main()
{
 int v;

 v=create();
 printf("\nBreadth first search: ");
 bfs(v); printf("\b ");
 printf("\nDepth first search: ");
 dfs(v); printf("\b \n");

 return 0;
}
