#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *left;
   struct node *right;
};

void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
     {
      printf("# ");
      return;
     }
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

void LevelOrder(struct node* root)
{
    int h = height(root);
    for (int i=1; i<=h; i++)
    {
     for(int j=h;j>=i;j--)
      printf(" ");
     printGivenLevel(root, i);
     printf("\n");
    }
}

void InOrder(struct node *root)
 {
   if (root != NULL)
   {
      InOrder(root->left);
      printf("%d,",root->data);
      InOrder(root->right);
   }
}
struct node* insertNode(struct node* newnode, int val)
{
   if (newnode == NULL)
   {
   struct node *temp = (struct node*)malloc(sizeof(struct node));
   temp->data = val;
   temp->left = temp->right = NULL;
   return temp;
   }
   if (val%2)
      newnode->left  = insertNode(newnode->left, val);
   else if (val > newnode->data)
      newnode->right = insertNode(newnode->right, val);
   return newnode;
}
/*                              __ 4 __
                               /       \
                              2         5
                            /   \      / \
                           0     3    #   9
                          / \   / \      / \
                         #   # #   #    #   #                        */
int main()
{
struct node *root=NULL;
root=insertNode(root,4);
     insertNode(root,5);
     insertNode(root,2);
     insertNode(root,9);
     insertNode(root,1);
     insertNode(root,3);
   printf("In-Order traversal of the Binary Search Tree is: ");
   InOrder(root);
   printf("\n\nTHE TREE LOOKS LIKE:-\n");
   LevelOrder(root);
   return 0;
}
