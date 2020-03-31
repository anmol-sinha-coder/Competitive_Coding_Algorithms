#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

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
void Insert_vertex(char vertex_vert_name)
{   n++;
	struct vertex *vtx,*new;
	vtx=(struct vertex *)malloc(sizeof(struct vertex)); //Dynamically allocating for creation function of vertex
	vtx->vert_name=vertex_vert_name;
	vtx->next=NULL;
	vtx->adjacent=NULL;

	if(head==NULL)   // The conditions to check for position of insertion begin here
	{
		head=vtx;
		return;
	}
	new=head;
	while( new->next!=NULL)  // Insert at end function implemented
		new=new->next;
	new->next=vtx;
}/*End of Insert_vertex()*/

void Delete_vertex(char u)
{   n--;                       //The specific node or vertex is deleted from Linked list
	struct vertex *vtx,*temp;
	if(head->vert_name == u)   // we perform a search for vertex and determine its locaton/position
	{
		vtx=head;
		head=head->next;     //for deletion of head, we move head one step head before deallocating memory for vtx
		free(vtx);
		return;
	}
	temp=head;
	while(temp->next->next != NULL)
	{
		if(temp->next->vert_name==u)
		{
			vtx=temp->next;
			temp->next=vtx->next;  // This is deletion of linked list from any position
			free(vtx);             //The position is determined by name of vertex
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
	struct vertex *new;             //This function deletes all egdes coming to this node or vertex
	struct edge *temp,*head_edge,*vtx;
	new=head;
	while(new!=NULL)
	{
		/* new->adjacent points to first vertex of edge chained list */
		if(new->adjacent->destination == u)  //A search is performed for all possible nodes whose destination value is the required one
		{                                    //They are henceforth deleted
			vtx=new->adjacent;
			new->adjacent=new->adjacent->chain;
			free(vtx);
			continue; /* continue searching in another edge lists */
		}
		temp=new->adjacent;
		while(temp->chain->chain != NULL) //deletion if we have an intermediate node
		{
			if(temp->chain->destination==u)
			{
				vtx=temp->chain;
				temp->chain=vtx->chain;
				free(vtx);
				continue;
			}
			temp=temp->chain;
		}
		if(temp->chain->destination==u) //deletion if node is last
		{
			vtx=temp->chain;
			free(vtx);
			temp->chain=NULL;
		}
		new=new->next;
	}
}

void Insert_edge(char u,char v)
{                              //This function adds an edge for already existing vertices
	struct vertex *locu,*locv;
	struct edge *new,*vtx;
	locu=find_vert(u);        //The two vertices' location is found and determined
	locv=find_vert(v);

	if(locu==NULL )
	{
		printf("Source vertex not present ,first Insert vertex %c\n",u);
		return;
	}
	if(locv==NULL )
	{
		printf("destination vertex not present ,first Insert vertex %c\n",v);
		return;
	}
	vtx=(struct edge *)malloc(sizeof(struct edge));
	vtx->destination=v;                             // The destination value of each vertex is supplied to form an edge
	vtx->chain=NULL;
    a[(int)(u-64)][(int)(v-64)]=1;

	if(locu->adjacent==NULL)
	{
		 locu->adjacent=vtx;                      //the adjacent value is filled to complete adjacency matrix values
		  return;
	}
	new=locu->adjacent;
	while(new->chain!=NULL)
		new=new->chain;
	new->chain=vtx;                   //the value of vtx is linked to the end to make it an edge

}

struct vertex *find_vert(char item) //This function searches for a vertex and returns its location
{
	struct vertex *new,*loc;
	new=head;
	while(new!=NULL)
	{
		if(item==new->vert_name)
		{                         // location is determined and returned
			loc=new;
			return loc;
		}
		else
			new=new->next;
	}
	loc=NULL;
	return loc;
}

bool search_edge(char u,char v) //This function searches whether the edge exists or not
{
	struct vertex *locu,*locv;
	struct edge *new,*vtx,*temp;
	locu=find_vert(u);
    locv=find_vert(v);

	if(locu==NULL )
	{
		printf("Source vertex not present\n");
		return 0;
	}

    if(locu==NULL )
	{
		printf("destination vertex not present\n");
		return 0;
	}

	if(locu->adjacent->destination == v) //If vertex points to second vertex (the destination), the edge exists
	{
        printf("Edge exists !\n");
		return 1;
	}
	temp=locu->adjacent;
	while(temp->chain->chain != NULL)
	{
		if(temp->chain->destination==v)
		{
			printf("Edge exists !\n"); //If first vertex's adjacent points to second vertex, the edge exists
			return 1;
		}
		temp=temp->chain;
	}
	if(temp->chain->destination==v)
	{
	 printf("Edge exists !\n");  //If first vertex's destination value is equal to second, then edge exists and is returned
     return 1;
	}
	printf("This edge is not present in the graph\n"); //Finally if none of above conditions are met, edge cannot be present in graph
    return 0;
}

void del_edge(char u,char v) //The delete edge function deletes the required edge value
{
	struct vertex *locu,*locv;
	struct edge *new,*vtx,*temp;
	locu=find_vert(u);

	if(locu==NULL )
	{
		printf("Source vertex not present\n");
		return;
	}
    a[(int)(u-64)][(int)(v-64)]=0;
	if(locu->adjacent->destination == v) //The delete edge function simply searches for the edge just like search edge function
	{                                    //frees the destination vertex or adjacent value
		vtx=locu->adjacent;
		locu->adjacent=locu->adjacent->chain;
		free(vtx);
		return;
	}
	temp=locu->adjacent;
	while(temp->chain->chain != NULL)
	{                                  //The function is very similar to search edge function
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

void display()                            //The Display function displays the Graph like an adjacency matrix for each vertex
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
void bfs(int v)                  //The BFS function is for Breadth First Traversal of the Graph
{                                //In this function the Queue used is recursively filled, or deleted
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
{                      //In this, the Depth First Traversal is implemented for the Graph
 int i;                //In this we make use of internal stack of C. Hence recursion is used for this function
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
