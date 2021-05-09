#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int n;

// MAX HEAP
void heapify_down(int arr[],int n, int i)
{
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        // Recursively heapify_down the affected sub-tree
        heapify_down(arr,n, largest);
    }
}

void heapify_up(int arr[], int i)
{
    int parent = (i - 1) / 2;
    if (arr[parent] > 0)
    {   // For Max-Heap, If current node is greater than its parent, Swap both of them and call heapify again for the parent
        if (arr[i] > arr[parent])
        {
            swap(arr[i], arr[parent]);
            // Recursively heapify the parent node
            heapify_up(arr, parent);
        }
    }

}

/*
// MIN_HEAP
void heapify_down(int arr[],int n, int i)
{
    int smallest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If largest is not root
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        // Recursively heapify_down the affected sub-tree
        heapify_down(arr,n, smallest);
    }
}

void heapify_up(int arr[], int i)
{
    int parent = (i - 1) / 2;
    if (arr[parent] > 0)
    {   // For Min-Heap, If current node is smaller than its parent, Swap both of them and call heapify again for the parent
        if (arr[i] < arr[parent])
        {
            swap(arr[i], arr[parent]);
            // Recursively heapify the parent node
            heapify_up(arr, parent);
        }
    }

}

*/
void Insert_Node(int arr[], int Key)
{
    // Increase the size of Heap by 1 and Insert the element at end of Heap
    arr[n++] = Key;
    /// Heapify the new node following a [Bottom =--> up] approach
    heapify_up(arr, n - 1);
}

// Function to delete the root from Heap
void Delete_Root(int arr[])
{
    // Get the last element and Replace root with first element
    arr[0] = arr[--n];
    /// heapify the root node following [Top =--> down] approach
    heapify_down(arr,n, 0);
}

void buildMinHeap(int a[], int size)
 {
    for(int i=size/2;i>=0;i--)
        heapify_down(a,size,i);

}
int kthLargest(int a[], int size, int k)
{
    int minHeap[k];
    int i;
    for(i=0;i<k;i++)
        minHeap[i] = a[i];
    buildMinHeap(minHeap,k);
    for(i=k;i<size;i++)
    {
        if(a[i]>minHeap[0])
        {
            minHeap[0]=a[i];
            heapify_down(minHeap,k,0);
        }
    }
    return minHeap[0];
}

int main()
{
 cout<<"Enter initial size: "; std::cin>>n; int A[n],ch,val,k; string type;
 cout<<"Enter "<<n<<" elements: "; for(int i=0;i<n;i++) cin>>A[i];
 //cout<<"Min_Heap or Max_Heap(DEFAULT: Max_Heap)? "; cin>>type;
 /*
 if((type=="min") || (type=="MIN"))
 {
    using namespace MIN;
    cout<<"\n_______________Current Format: MIN HEAP_______________\n";
 }
 else
 {
    using namespace MAX;
    cout<<"\n_______________Current Format: MAX HEAP_______________\n";
 }
 */
  for (int i = n / 2 - 1; i >= 0; i--) //Build Heap
        heapify_down(A,n, i);

 while(1)
 {
  std::cout<<"1. Insert\n2. Delete\n3. Display\n4. Increase/replace value at index\n5. Exit\n"<<"Enter Choice(1-5): "; std::cin>>ch;
  switch(ch)
  {
   case 1: std::cout<<"Enter value to insert: "; std::cin>>val;
           Insert_Node(A,val);
   break;
   case 2: Delete_Root(A);
   break;
   case 3: for(int i=0;i<n;i++)
            std::cout<<A[i]<<",";
           std::cout<<"\b \n";
   break;
   case 4: cout<<"Enter value and index "; cin>>val>>k; A[k]=val;
            cout<<"Array right now: ";
           for(int i=0;i<n;i++)
            std::cout<<A[i]<<",";
           std::cout<<"\b \n";
           cout<<"Array has been heapified now.......";
        for (int i = n / 2 - 1; i >= 0; i--) //Build Heap
        heapify_down(A,n, i);
   break;
   case 5: exit(0);
   break;
  }
    std::cout<<"________________________________________\n";
 }

 return 0;
}
