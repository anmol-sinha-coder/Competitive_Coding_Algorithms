#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

struct edge
{
	char destination;
	struct edge *chain;
};

struct vertex
{
	struct vertex *next;
	char vert_name;
	struct edge *adjacent;
}*head=NULL;
struct vertex *find_vert(char item);

int n=1,a[20][20]={0};
void Insert_vertex(char name)
{   n++;
	struct vertex *vtx,*new;
	vtx=(struct vertex *)malloc(sizeof(struct vertex));
	vtx->vert_name = name;
	vtx->next=NULL;
	vtx->adjacent=NULL;

	if(head==NULL)
	{
		head=vtx;
		return;
	}
	new=head;
	while( new->next!=NULL)
		new=new->next;
	new->next=vtx;
}/*End of Insert_vertex()*/

void Delete_vertex(char u)
{   n--;
	struct vertex *vtx,*temp;
	if(head->vert_name == u)
	{
		vtx=head;
		head=head->next;
		free(vtx);
		return;
	}
	temp=head;
	while(temp->next->next != NULL)
	{
		if(temp->next->vert_name==u)
		{
			vtx=temp->next;
			temp->next=vtx->next;
			free(vtx);
			return;
		}
		temp=temp->next;
	}
	if(temp->next->vert_name==u)
	{
		vtx=temp->next;
		free(vtx);
		temp->next=NULL;
	}
}/*End of Delete_vertex()*/

void delvertex_edge(char u)
{
	struct vertex *new;
	struct edge *temp,*head_edge,*vtx;
	new=head;
	while(new!=NULL)
	{
		/* new->adjacent points to first vertex of edge chained list */
		if(new->adjacent->destination == u)
		{
			vtx=new->adjacent;
			new->adjacent=new->adjacent->chain;
			free(vtx);
			continue; /* continue searching in another edge lists */
		}
		temp=new->adjacent;
		while(temp->chain->chain != NULL)
		{
			if(temp->chain->destination==u)
			{
				vtx=temp->chain;
				temp->chain=vtx->chain;
				free(vtx);
				continue;
			}
			temp=temp->chain;
		}/*End of while*/
		if(temp->chain->destination==u)
		{
			vtx=temp->chain;
			free(vtx);
			temp->chain=NULL;
		}
		new=new->next;
	}
}

void Insert_edge(char u,char v)
{
	struct vertex *vert_u,*vert_v;
	struct edge *new,*vtx;
	vert_u=find_vert(u);
	vert_v=find_vert(v);

	if(vert_u==NULL )
	{
		printf("Source vertex not present ,first Insert vertex %c\n",u);
		return;
	}
	if(vert_v==NULL )
	{
		printf("destination vertex not present ,first Insert vertex %c\n",v);
		return;
	}
	vtx=(struct edge *)malloc(sizeof(struct edge));
	vtx->destination=v;
	vtx->chain=NULL;
    a[(int)(u-64)][(int)(v-64)]=1;

	if(vert_u->adjacent==NULL)
	{
		 vert_u->adjacent=vtx;
		  return;
	}
	new=vert_u->adjacent;
	while(new->chain!=NULL)
		new=new->chain;
	new->chain=vtx;

}

struct vertex *find_vert(char item)
{
	struct vertex *trav,*vert_;
	trav=head;
	while(trav)
	{
		if(item==trav->vert_name)
		   return vert_=trav;
		else
			trav=trav->next;
	}

	return NULL;
}

bool search_edge(char u,char v)
{
	struct vertex *vert_u,*vert_v;
	struct edge *new,*vtx,*temp;
	vert_u=find_vert(u);
    vert_v=find_vert(v);

	if(vert_u==NULL )
	{
		printf("Source vertex not present\n");
		return 0;
	}

    if(vert_u==NULL )
	{
		printf("destinationination vertex not present\n");
		return 0;
	}

	if(vert_u->adjacent->destination == v)
	{
        printf("Edge exists !\n");
		return 1;
	}
	temp=vert_u->adjacent;
	while(temp->chain->chain != NULL)
	{
		if(temp->chain->destination==v)
		{
			printf("Edge exists !\n");
			return 1;
		}
		temp=temp->chain;
	}
	if(temp->chain->destination==v)
	{
	 printf("Edge exists !\n");
     return 1;
	}
	printf("This edge is not present in the graph\n");
    return 0;
}

void del_edge(char u,char v)
{
	struct vertex *vert_u,*vert_v;
	struct edge *new,*vtx,*temp;
	vert_u=find_vert(u);

	if(vert_u==NULL )
	{
		printf("Source vertex not present\n");
		return;
	}
    a[(int)(u-64)][(int)(v-64)]=0;
	if(vert_u->adjacent->destination == v)
	{
		vtx=vert_u->adjacent;
		vert_u->adjacent=vert_u->adjacent->chain;
		free(vtx);
		return;
	}
	temp=vert_u->adjacent;
	while(temp->chain->chain != NULL)
	{
		if(temp->chain->destination==v)
		{
			vtx=temp->chain;
			temp->chain=vtx->chain;
			free(vtx);
			return;
		}
		temp=temp->chain;
	}
	if(temp->chain->destination==v)
	{
		vtx=temp->chain;
		free(vtx);
		temp->chain=NULL;
		return;
	}
	printf("This edge not present in the graph\n");
}

void display()
{
	struct vertex *new;
	struct edge *temp;

	new=head;
	while(new!=NULL)
	{
		printf("%c ->",new->vert_name);
		temp=new->adjacent;
		while(temp!=NULL)
		{
			printf(" %c",temp->destination);
			temp=temp->chain;
		}
		printf("\n");
		new=new->next;
	 }
}

int q[20]={0}, visited[20]={0}, reach[20]={0}, f = 0, r = 0;
void bfs(int v)
{
 for(int i = 1; i <= n; i++)
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


int main()
{
	int ch;
	char vertex,beginning,destination;
	do
	{
		printf("1. Insert a vertex\n");
		printf("2. Insert an edge\n");
		printf("3. Delete a vertex\n");
		printf("4. Delete an edge\n");
		printf("5. Display\n");
		printf("6. Breadth First Search(BFS)\n");
		printf("7. Depth First Search(DFS)\n");
		printf("8. Search an edge\n");
		printf("9. Exit\n");
		printf(" Enter choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
		 case 1:
			printf("Enter a vertex to be Inserted : ");
			fflush(stdin);
			scanf("%c",&vertex);
			Insert_vertex(vertex);
			break;
		 case 2:
			printf("Enter an edge to be Inserted : ");
			fflush(stdin);
			scanf("%c %c",&beginning,&destination);
			Insert_edge(beginning,destination);
			break;
		 case 3:
			printf("Enter a vertex to be Deleted : ");
			fflush(stdin);
			scanf("%c",&vertex);
			/*This fn Deletes the vertex from header vertex list*/
			Delete_vertex(vertex);
			/* This fn Deletes all edges coming to this vertex */
			delvertex_edge(vertex);
			break;
		 case 4:
			printf("Enter an edge to be Deleted : ");
			fflush(stdin);
			scanf("%c %c",&beginning,&destination);
			del_edge(beginning,destination);
			break;
		 case 5:
			display();
			break;
         case 6:
            printf("Enter heading vtx: "); scanf(" %c",&vertex);
            bfs((int)vertex-64);
            printf("\b \n");
         break;
         case 7:
            printf("Enter heading vtx: "); scanf(" %c",&vertex);
            dfs((int)vertex-64);
            printf("\b \n");
         break;
		 case 8:
            printf("Enter an edge to be searched : ");
			fflush(stdin);
			scanf("%c %c",&beginning,&destination);
			search_edge(beginning,destination);
         break;
         case 9: exit(0);
		 default:
			printf("Wrong choice\n");
		 }
        printf("__________________________________\n");
	}while(1);
 return 0;
}
