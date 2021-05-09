#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int a[], int item, int low, int high)
{
    if (high <= low)
        return (item > a[low])?  (low + 1): low;

    int mid = (low + high)/2;

    if(item == a[mid])
        return mid+1;

    if(item > a[mid])
        return binarySearch(a, item, mid+1, high);
    return binarySearch(a, item, low, mid-1);
}

void Insertion_Sort(int a[], int n)
{
    int loc, j, key;
    for (int i = 1; i < n; ++i)
    {
        j = i - 1; key=a[i];
        loc = binarySearch(a, key, 0, j);

        while (j >= loc)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main()
{
    int n;
    cout<<"Enter number of elements required: "; cin>>n; int A[n];
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++) cin>>A[i];
    Insertion_Sort(A,n);
    cout<<"Sorted array: ";  for(int i=0;i<n;i++) cout<<A[i]<<" ";
    cout<<endl;

    cout<<scientific<<setprecision(3);
    printf("serial\tValue of n\t time for Insertion_Sort\n");
				for(int k=5000;k<=50000;k+=5000)
				{
					long double t1=0.0,t2=0.0,t3=0.0; time_t start=0,end=0;
					int m=k;
					int arr2[m]={0};
					srand(time(NULL));
					for(int i=0;i<m;i++)
					 arr2[i]=rand()%10000;

					start=clock();
                    //for(int i=0;i<2;i++)
                        Insertion_Sort(arr2,m);
					end=clock();
					t1=((long double)(end-start))/(CLOCKS_PER_SEC);

					cout<<k/5000<<"\t"<<m<<"\t\t\t"<<t1<<"\t\t\t"<<"\n";
                }
    return 0;
}
