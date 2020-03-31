#include<iostream>
#include<bits/stdc++.h>
#define size 7
using namespace std;

int n;
int Merge(int A[],int lb,int m,int ub)
{
 int i=lb,j=m+1,t[ub-lb+1],k=0;
 int inv_count=0;
 while(i<=m && j<=ub)   //assuming the two arrays are sorted, we fill array with whichever index's element is smaller
 {
  if(A[i]<A[j])
   t[k++]=A[i++];
  else
   {
    //cout<<"\t("<<A[i]<<","<<A[j]<<")";
    t[k++]=A[j++];
    inv_count+=m+1-i;
   }
 }

 while(i<=m)        //for putting the remaining elements in array
  {t[k++]=A[i++];}

 while(j<=ub)      //for putting the remaining elements in array, remember only either i or j is filled into array
  {t[k++]=A[j++];}

 for(i=lb;i<=ub;i++)
    A[i]=t[i-lb];

 return inv_count;
}

int MergeSort(int A[],int lb,int ub)
{
 int m=0,inv_count=0;
 if(lb<ub)
 {
    m=(lb+ub)/2;
    inv_count=
    MergeSort(A,lb,m)+
    MergeSort(A,m+1,ub)+
    Merge(A,lb,m,ub);
 }
 return inv_count;
}

void swap(int &a,int &b)
{
 int t=a;
     a=b;
     b=t;
}

int partition(unsigned long int A[],int lb,int ub)
{
    int pivot = A[ub]; // pivot
    int i = lb ; // Index of smaller element

    for (int j = lb; j <= ub-1; j++) //traversal before pivot element
        if (A[j] < pivot)
          swap(A[i++], A[j]); // swap with smaller element(than pivot) and then increment index
    swap(A[i], A[ub]); //placing pivot in correct position
    return i;   // pi represents index of pivot element(placed at its correct position), not value of pivot element
}

void quickSort(unsigned long int A[], int lb, int ub)
{
    if (lb < ub)
    {
        int pi = partition(A, lb, ub);
        quickSort(A, lb, pi - 1);
        quickSort(A, pi + 1, ub);
    }
    else
    {
     cout<<endl;
     for (int i=0;i<n;i++)
     cout<<A[i]<<",";
     cout<<"\b ";cout;
    }
}

void transpose(int **A,int r,int c)
{

}

int main()
{
    int ic;
        cout<<"Enter number of elements required: ";
    cin>>n;
    int A[n];
    cout<<"Enter "<<n<<" elements: ";
    for (int i=0;i<n;i++)
     cin>>A[i];
 //   quickSort(A,0,n-1);
    ic = MergeSort(A,0,n-1);
    cout<<endl<<"_________________________"<<endl<<"FINAL SORTED ARRAY\n ";
    for (int i=0;i<n;i++)
     cout<<A[i]<<",";
    cout<<"\b \n";
    cout<<"Inversion count = "<<ic;
    int num=A[0],c=1,t=1;
    for(int i=0,j=1;i<n,j<n;i++,j++)
     if(A[i]==A[j])
     {
      t++;
      if(t>c)
      {
       c=t;
       num=A[i];
      }
     }
     else
     {
      t=1;
     }

    cout<<"\nFrequency = "<<c<<endl<<"Mode = "<<num;
cout<<endl<<endl;
 return 0;
}
