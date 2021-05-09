#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int n;
// MAX HEAP
void max_heapify_down(int arr[], int n, int i)
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
        max_heapify_down(arr,n, largest);
    }
}

void max_heapify_up(int arr[], int i)
{
    int parent = (i - 1) / 2;
    if (arr[parent] > 0)
    {   // For Max-Heap, If current node is greater than its parent, Swap both of them and call heapify again for the parent
        if (arr[i] > arr[parent])
        {
            swap(arr[i], arr[parent]);
            // Recursively heapify the parent node
            max_heapify_up(arr, parent);
        }
    }

}

// MIN_HEAP
void min_heapify_down(int arr[],int n, int i)
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
        min_heapify_down(arr,n, smallest);
    }
}

void min_heapify_up(int arr[], int i)
{
    int parent = (i - 1) / 2;
    if (arr[parent] > 0)
    {   // For Min-Heap, If current node is smaller than its parent, Swap both of them and call heapify again for the parent
        if (arr[i] < arr[parent])
        {
            swap(arr[i], arr[parent]);
            // Recursively heapify the parent node
            min_heapify_up(arr, parent);
        }
    }

}
/*
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
*/

int main()
{
 cout<<"Enter initial size: "; std::cin>>n;
 int A[n],B[n],ch,val,k;
 cout<<"Enter "<<n<<" elements: "; for(int i=0;i<n;i++) {cin>>A[i]; B[i]=A[i];} // A is max-heap, B is min-heap
 //cout<<"Min_Heap or Max_Heap(DEFAULT: Max_Heap)? "; cin>>type;

  for (int i = n / 2 - 1; i >= 0; i--) //Build Heap
        max_heapify_down(A,n, i);
 for (int i = n / 2 - 1; i >= 0; i--) //Build Heap
        min_heapify_down(B,n, i);
 while(1)
 {
  std::cout<<"1. Insert\n2. Delete\n3. Display\n4. Delete kth index values\n5. Exit\n"<<"Enter Choice(1-5): "; std::cin>>ch;
  switch(ch)
  {
   case 1: std::cout<<"Enter value to insert: "; std::cin>>val;
            A[n] = val;
            max_heapify_up(A, n);
            B[n] = val;
            min_heapify_up(B, n );
            n++;
   break;
   case 2: A[0] = A[n-1];
            max_heapify_down(A,n-1, 0);
            B[0] = B[n-1];
            min_heapify_down(B,n-1, 0);
            n--;

   break;
   case 3: cout<<"MAX: " ;
       for(int i=0;i<n;i++)
            std::cout<<A[i]<<",";
           std::cout<<"\b \n";
        cout<<"MIN: ";
           for(int i=0;i<n;i++)
            std::cout<<B[i]<<",";
           std::cout<<"\b \n";
   break;
   case 4: cout<<"Enter value of 'k': "; cin>>k;
           A[k] = A[n-1];
            max_heapify_down(A,n-1, k);
            B[k] = B[n-1];
            min_heapify_down(B,n-1, k);
            n--;
   break;
   case 5: exit(0);
   break;
  }
    std::cout<<"________________________________________\n";
 }

 return 0;
}
