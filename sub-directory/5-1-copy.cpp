#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b)
{
 int t=a;
     a=b;
     b=t;
}

int partition(int A[],int lb,int ub)
{
    int pivot = A[ub];
    int i = lb ;

    for (int j = lb; j <= ub-1; j++) //traversal before pivot element
        if (A[j] < pivot)
          swap(A[i++], A[j]); // swap with smaller element(than pivot) and then increment index
    swap(A[i], A[ub]); //placing pivot in correct position
    return i;   // pi represents index of pivot element(placed at its correct position), not value of pivot element
}

void Quick_Sort(int A[], int lb, int ub)
{
    if (lb < ub)
    {
        int pi = partition(A, lb, ub);
        Quick_Sort(A, lb, pi - 1);
        Quick_Sort(A, pi + 1, ub);
    }
}

//-----------------------------------------------------------------------------------------------------------------------------
void Merge(int A[],int lb,int m,int ub)
{
 int i=lb,j=m+1,t[ub-lb+1],k=0;

 while(i<=m && j<=ub)   //assuming the two arrays are sorted, we fill array with whichever index's element is smaller
  if(A[i]<A[j])
   t[k++]=A[i++];
  else
    t[k++]=A[j++];

 while(i<=m)        //for putting the remaining elements in array
  t[k++]=A[i++];

 while(j<=ub)      //for putting the remaining elements in array, remember only either i or j is filled into array
  t[k++]=A[j++];

 for(i=lb;i<=ub;i++)
    A[i]=t[i-lb];
}

void Merge_Sort(int A[],int lb,int ub)
{
 int m=0;
  if(lb<ub)
  {
    m=(lb+ub)/2;
    Merge_Sort(A,lb,m);
    Merge_Sort(A,m+1,ub);
    Merge(A,lb,m,ub);
  }

}

int main()
{
 int n;
 cout<<"Enter number of values: "; cin>>n;
 int A[n];
 cout<<scientific;

 do
 {
  int ch; time_t s1,e1, s2,e2, s3,e3;
  cout<<"1. Generate random numbers\n2. Display Array\n3. Sort Array (merge sort)\n4. Sort Array (quick sort)\n5. Time complexity (Merge sort)\n6. Time complexity (Quick sort)\n7. Time complexity (Already sorted Array)\n8. Time Complexity (Data Ascending, Data Descending & Random Data)\n9. Quit/Exit";
  cout<<"\n Enter choice(1-9): "; cin>>ch;
  switch(ch)
  {
   case 1: srand (time(NULL)); for(int i=0;i<n;i++) A[i]=rand()%1000;
   break;
   case 2: cout<<"Generated Numbers: "; for(int i=0;i<n;i++) cout<<A[i]<<","; cout<<"\b \n";
   break;
   case 3: s1=clock()*1000;
           Merge_Sort(A,0,n-1);
           e1=clock()*1000;
   break;
   case 4: s2=clock();
           Quick_Sort(A,0,n-1);
           e2=clock();
   break;
   case 5: cout<<"The execution time for merge sort is : "<<(double)(e1-s1)/(1000*CLOCKS_PER_SEC);
   break;
   case 6: cout<<"The execution time for quick sort is : "<<(double)(e2-s2)/CLOCKS_PER_SEC;
   break;
   case 7: Merge_Sort(A,0,n-1);
           s3=clock();
           Merge_Sort(A,0,n-1);
           e3=clock();
           cout<<"The execution time for sorting, already sorted array : "<<(double)(e3-s3)/CLOCKS_PER_SEC;
   break;
   case 8:   printf("serial\tValue of n\t time for Quick_Sort\t time for Merge_Sort\n");
				for(int k=5000;k<=50000;k+=5000)
				{
					long double t1=0.0,t2=0.0,t3=0.0; time_t start=0,end=0;
					int m=k;
					int arr2[m]={0};
					srand(time(NULL));
					for(int i=0;i<m;i++)
					 arr2[i]=rand()%100000;

					start=clock();
					for(int i=0;i<2;i++)
                        Quick_Sort(arr2,0,m-1);
					end=clock();
					t1=((long double)(end-start))/(3*CLOCKS_PER_SEC);

					start=clock();
					for(int i=0;i<99;i++)
                        Merge_Sort(arr2,0,m-1);
					end=clock();
					t2=((long double)(end-start))/(100*CLOCKS_PER_SEC);

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
