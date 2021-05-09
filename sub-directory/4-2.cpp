#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int n;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void Bubble_Sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}

int Linear_Search(int A[],int s,int size=n)
{
 for(int i=0;i<=size;i++)
  if(A[i]==s)
   return i;
 return -1;
}

int Binary_Search(int arr[], int s, int l=0, int r=n-1)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == s)
            return mid;

        if (arr[mid] > s)
            return Binary_Search(arr, s, l, mid - 1);

        // arr[mid] < s
        return Binary_Search(arr, s, mid + 1, r);
    }

    return -1;
}

int main()
{
 int s;
 cout<<"Enter number of values: "; cin>>n;
 int A[n];
 cout<<scientific<<setprecision(2);

 do
 {
  int ch; time_t s1,e1, s2,e2, s3,e3;
  cout<<"1. Generate random numbers\n2. Display Array\n3. Perform Linear Search\n4. Perform Binary Search\n5. Time complexity (Linear Search)\n6. Time complexity (Binary Search)\n7. Time complexity (Unavailable elment in Array)\n8. Time Complexity (Linear Search, Binary Search & Random Data)\n9. Quit/Exit";
  cout<<"\n Enter choice(1-9): "; cin>>ch;
  switch(ch)
  {
   case 1: srand (time(NULL)); for(int i=0;i<n;i++) A[i]=rand()%1000;
   break;
   case 2: cout<<"Generated Numbers: "; for(int i=0;i<n;i++) cout<<A[i]<<","; cout<<"\b \n";
   break;
   case 3: cout<<"Enter search element: "; cin>>s;
           s1=clock()*1000;
           cout<<"Element at index-"<<Linear_Search(A,s);
           e1=clock()*1000;
   break;
   case 4: cout<<"Enter search element: "; cin>>s;
            Bubble_Sort(A,n);
           s2=clock();
           cout<<"Element at index-"<<Binary_Search(A,s);
           e2=clock();
   break;
   case 5: cout<<"The execution time is : "<<(double)(e1-s1)/(1000*CLOCKS_PER_SEC);
   break;
   case 6: cout<<"The execution time is : "<<(double)(e2-s2)/CLOCKS_PER_SEC;
   break;
   case 7: s=-34;
           s3=clock();
           Linear_Search(A,s);
           e3=clock();
           cout<<"The execution time for sequence is : "<<(double)(e3-s3)/CLOCKS_PER_SEC;
   break;
   case 8:  printf("serial\tValue of n\t time for Linear\t time for Binary\n");
				for(int k=5000;k<=50000;k+=5000)
				{
					long double t1=0.0,t2=0.0,t3=0.0; time_t start=0,end=0;
					int m=k;
					int arr2[m]={0};
					srand(time(NULL));
					for(int i=0;i<m;i++)
					 arr2[i]=rand()%1000000;

					start=clock();
					for(int i=0;i<99999;i++)Linear_Search(arr2,-200,m-1);
					end=clock();
					t1=((long double)(end-start))/(100000*CLOCKS_PER_SEC);

					Bubble_Sort(arr2,m);
					start=clock();
					for(int i=0;i<999999;i++)Binary_Search(arr2,-200,0,m-1);
					end=clock();
					t2=((long double)(end-start))/(1000000*CLOCKS_PER_SEC);

					cout<<k/5000<<"\t"<<m<<"\t\t\t"<<t1<<"\t\t\t"<<t2<<"\t\t\t"<<"\n";
                }
				cout<<endl;
   break;
   case 9: exit(0);
   break;
  }
  cout<<"\n_____________________________________\n";
 }while(1);

 return 0;
}
