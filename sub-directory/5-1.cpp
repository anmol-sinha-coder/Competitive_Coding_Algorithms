#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b)
{
 int t=a;
     a=b;
     b=t;
}

void heapify_down(int A[],int n, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < n && A[left] > A[largest])
        largest = left;

    if (right < n && A[right] > A[largest])
        largest = right;

    if (largest != root)
    {
        swap(A[root], A[largest]);
        heapify_down(A, n, largest);
    }
}

void Heap_Sort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) //BUILD HEAP from arbitrary array
        heapify_down(arr, n, i);

    for (int i=n-1; i>0; i--)
    {
        swap(arr[0], arr[i]);
        heapify_down(arr, i, 0);
    }
}

int main()
{
    cout<<scientific<<setprecision(3);
    printf("serial\tValue of n\t time for Quick_Sort\t\n");
				for(int k=5000;k<=50000;k+=5000)
				{
					long double t1=0.0,t2=0.0,t3=0.0; time_t start=0,end=0;
					int m=k;
					int A2[m]={0};
					srand(time(NULL));
					for(int i=0;i<m;i++)
					 A2[i]=rand()%10000;

					start=clock();
                    for(int i=0;i<100;i++)
                        Heap_Sort(A2,m);
					end=clock();
					t1=((long double)(end-start))/(100*CLOCKS_PER_SEC);


					cout<<k/5000<<"\t"<<m<<"\t\t\t"<<t1<<"\t\t\t"<<"\n";
                }
    return 0;
}
