#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int eqSumPivot(int A[], int n)
{
    int lb=0, ub=n-1, piv;
    long int sum_begin=A[lb], sum_end=A[ub];
    while(lb<ub)
        if(sum_begin > sum_end)
          sum_end += A[--ub];
        else if(sum_begin < sum_end)
          sum_begin += A[++lb];
        else // when both are ==
          sum_end += A[--ub], sum_begin += A[++lb];
    piv=lb;
    return piv;
}

int main()
{
    int n;   cout<<"Enter size: ";   cin>>n;
    int A[n];  cout<<"Enter array elements: ";
    for(int i=0;i<n;i++) cin>>A[i];

    cout<<"Pivot::\t index-  "<< eqSumPivot(A,n) <<"\t element-  "<< A[eqSumPivot(A,n)] ;

    return 0;
}
