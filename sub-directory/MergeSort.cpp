#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int n;
void Merge(int A[],int lb,int m,int ub)
{
 int i=lb,j=m+1,t[ub-lb+1],k=0;
 int inv_count=0;
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

void MergeSort(int A[],int lb,int ub)
{
 int m=0,inv_count=0;
 if(lb<ub)
 {
    m=(lb+ub)/2;
    //inv_count=
    MergeSort(A,lb,m);
    MergeSort(A,m+1,ub);

    Merge(A,lb,m,ub);
 }
        for (int i=0;i<n;i++)
      cout<<A[i]<<",";
    cout<<"\b \n";
}

int main()
{
    cout<<"Enter number of elements required: ";
    cin>>n;
     int A[n];
    cout<<"Enter "<<n<<" elements: ";
    for (int i=0;i<n;i++)
     cin>>A[i];
    MergeSort(A,0,n-1);
     cout<<endl<<endl;

 return 0;
}
