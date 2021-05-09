#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Tree {
   char data;
   int freq;
   Tree *left, *right;
};

Tree *getNode(char d, int f) {
   Tree *nN = new Tree;
   nN->data = d;
   nN->freq = f;
   nN->left = NULL;
   nN->right = NULL;
   return nN;
}

Tree *findMinNode(queue<Tree*>&q1, queue<Tree*>&q2) {
   Tree *minNode;
   if(q1.empty()) { //if first queue is empty, delete and return Tree from second queue
      minNode = q2.front();
      q2.pop();
      return minNode;
   }

   if(q2.empty()) { //if second queue is empty, delete and return Tree from first queue
      minNode = q1.front();
      q1.pop();
      return minNode;
   }

   if((q1.front()->freq) < (q2.front()->freq)) { //find smaller from two queues
      minNode = q1.front();
      q1.pop();
      return minNode;
   }else {
      minNode = q2.front();
      q2.pop();
      return minNode;
   }
}

Tree *huffmanTree(char data[], int frequency[], int n) {
   Tree *c0, *c1, *par;// child-1, child-2, parent
   Tree *nN; //New Node
   queue<Tree*> qu1, qu2; // C++ STL queue

   for(int i = 0; i<n; i++) { //add all Tree to queue 1
      nN = getNode(data[i], frequency[i]);
      qu1.push(nN);
   }

   while(!(qu1.empty() && (qu2.size() == 1))) {
      c0 = findMinNode(qu1, qu2); //find two minimum as two child
      c1 = findMinNode(qu1, qu2);
      Tree *nN = getNode('#', c0->freq+c1->freq);

      //intermediate Tree holds special character
      par = nN;
      par->left = c0;
      par->right = c1;
      qu2.push(par); //add sub tree into queue 2
   }

   Tree *retNode = qu2.front();
   qu2.pop();
   return retNode;
}

void getCodes(Tree *root, int A[], int n) {  //A to store the code
   if(root->left != NULL) {
      A[n] = 0;
      getCodes(root->left, A, n+1);
   }

   if(root->right != NULL) {
      A[n] = 1;
      getCodes(root->right, A, n+1);
   }

   if(root->left == NULL && root->right == NULL) {  // when root is leaf Tree
      cout << root->data << ": ";

      for(int i = 0; i<n; i++)
         cout << A[i];
      cout << endl;
   }
}

int main() {
   char data[] =  { 'a', 'b', 'c', 'd', 'e', 'f' };
   int frequency[] = { 38, 14, 11, 15, 12, 10 };
   int n = sizeof(data)/sizeof(data[0]);

   Tree *root = huffmanTree(data, frequency, n);
   int A[50], top = 0;
   getCodes(root, A, top);
return 0;
}
