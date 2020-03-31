#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

struct node
{
   int data;
   struct node *left;
   struct node *right;
};

struct stack
{
 struct node *data;
 struct stack *next;
}*top;

void push(struct node *val)
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

struct node* peek()
{
  printf("%d,",top->data->data);
  return top->data;
}

bool Empty()
{
  if(!top)
   return 1;
  else
   return 0;
}

void iter_inorder(struct node *root)
{
 struct node *temp=root;
 while(temp || !Empty())
 {
  for(;temp;temp=temp->left)
   push(temp);

  temp=peek();
  pop();
  temp=temp->right;

 }
}

void iter_preorder(struct node *root)
{
 struct node *temp=root;

}

// Compute the "height" of a tree -- the number of nodes along the
// longest path from the root node down to the farthest leaf node.
int height(struct node* temp)
{
    if (temp==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(temp->left);
        int rheight = height(temp->right);

        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else
            return(rheight+1);
    }
}

static int sum=0;
void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
     {
      printf("%c ",237);
      return;
     }
    int p=pow(2,height(root))-level-1;
    if (level == 1)
       {printf(" %*d",p,root->data);sum+=root->data;}
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

void LevelOrder(struct node *root)
{
    int h = height(root);
    if(!h)return;
    for (int i=1; i<=h; i++)
    {
 //    for(int j=h;j>=i;j--)
 //     printf(" ");
     printGivenLevel(root, i);
     printf("\n");
    }
}

void InOrder(struct node *root)
 {
   if (root)
   {
      InOrder(root->left);
      printf("%d,",root->data);
      InOrder(root->right);
   }
}

void PreOrder(struct node *root)
 {
   if (root)
   {
      printf("%d,",root->data);
      PreOrder(root->left);
      PreOrder(root->right);
   }
}

void PostOrder(struct node *root)
 {
   if (root)
   {
      PostOrder(root->left);
      PostOrder(root->right);
      printf("%d,",root->data);
   }
}

struct node* insertNode(struct node* newnode, int val)
{
   if (newnode == NULL)
   {
   newnode = (struct node*)malloc(sizeof(struct node));
   newnode->data = val;
   newnode->left = newnode->right = NULL;
   return newnode;
   }
   if (newnode->data>val)
      newnode->left  = insertNode(newnode->left, val);
   else
      newnode->right = insertNode(newnode->right, val);
   return newnode;
}

struct node *searchNode(struct node *root, int val) //Do not assign this function to root, as it will permanently alter it
{
   if (!root)
   {
    printf("Element does NOT exist !\n");
    return NULL;
   }
     if(root->data > val)
      root=searchNode(root->left,val);
else if(root->data < val)
      root=searchNode(root->right,val);
else if(root->data == val)
     {
      printf("Element exists !\n");
      return root;
     }
}

struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else if(key==root->data)
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
       int ch;
sel:  printf("Enter your selection:-\n 1. Inorder Predecessor replaces root\n 2. Inorder Successor replaces root\n Choice: "); scanf("%d",&ch);
       if(ch==1)
       {
        // node with two children: Get the inorder predecessor (largest
        // in the left subtree)
        struct node* temp = root->left;
        while(temp->right)temp=temp->right;

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->left = deleteNode(root->left, temp->data);
       }
       else if(ch==2)
        {
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = root->right;
        while(temp->left)temp=temp->left;

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
        }
      else goto sel;
    }
    return root;
}

static int c=0;
void count(struct node *root)
{
 if(root)
 {
  c++;
  count(root->left);
  count(root->right);
 }
}

struct node *small(struct node *root)
{
 if(root->left)
  return small(root->left);

 return root;
}

struct node *large(struct node *root)
{
 if(root->right)
  return large(root->right);

 return root;
}

struct node *leafDelete(struct node *root)
{
 if(root)
 {
  if(!root->left && !root->right){root=deleteNode(root,root->data); return NULL;}
  root->left=leafDelete(root->left);
  root->right=leafDelete(root->right);
 }
}

struct node *kthSmall(struct node *root,int k)
{
 if(root)
 {
  struct node *l=kthSmall(root->left,k);
  if(l) return l;
  if(++c==k)
    return root;
  return kthSmall(root->right,k);
 }
}

struct node *kthLarge(struct node *root,int k)
{
 if(root)
 {
  struct node *r=kthLarge(root->right,k);
  if(r) return r;
  if(++c==k)
    return root;
  return kthLarge(root->left,k);
 }
}

struct node *LCA(struct node *root,struct node *t1,struct node *t2)
{
 if(!root || !t1 || !t2) return NULL;

 if(t1->data > root->data && t2->data > root->data)
  root=LCA(root->right,t1,t2);

 if(t1->data <= root->data && t2->data <= root->data)
  root=LCA(root->left,t1,t2);
 return root;
}

int main()
{
struct node *root=NULL;

do
{int num,ch,k;
 printf("1. Insert\n2. In_Order\n3. Pre_Order\n4. Post_Order\n5. Search\n6. K'th Largest and Smallest values\n7. Delete\n8. Level_Order\n9. Exit\nEnter Choice(1-8):");scanf("%d",&ch);
 switch(ch)
 {
  case 1: printf("Enter value to insert: "); scanf("%d",&num);
          root=insertNode(root,num);
  break;
  case 2: printf("In-Order traversal of the Binary Search Tree is: ");
          iter_inorder(root);
          printf("\b \n");
  break;
  case 3:printf("Pre-Order traversal of the Binary Search Tree is: ");
          PreOrder(root);
          printf("\b \n");
  break;
  case 4: printf("Post-Order traversal of the Binary Search Tree is: ");
          PostOrder(root);
          printf("\b \n");
  break;
  case 5: ; struct node *temp1,*temp2,*temp;
          printf("Enter 1st value to search: "); scanf("%d",&num);
          temp1=searchNode(root,num);
          printf("Enter 2nd value to search: "); scanf("%d",&num);
          temp2=searchNode(root,num);
          temp=LCA(root,temp1,temp2);
          if(temp)printf("The Common Ancestor is: %d\n",temp->data);
  break;
  case 6: printf("Enter k = "); scanf("%d",&k);
          printf("K'th Smallest value = %d\n",kthSmall(root,k)->data); c=0;
          printf("K'th Largest value = %d\n",kthLarge(root,k)->data); c=0;
          count(root); printf("Number of Nodes = %d\n",c); c=0;
  break;
  case 7: printf("Enter value to delete: ");scanf("%d",&num);
          root=deleteNode(root,num);
  break;
  case 8: printf("The tree looks like :-\n");
          LevelOrder(root); sum=0;
          //printGivenLevel(root,3);
          //printf("\nSum of tree = %d\nHeight of tree = %d\n",sum,height(root));
  break;
  case 9: exit(0);
  break;
 }
 printf("_____________________________________________________________________________________________\n");
}while(1);

return 0;
}
