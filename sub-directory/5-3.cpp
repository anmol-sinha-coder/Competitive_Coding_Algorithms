#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Minimum(int A[], int lb, int ub)
{
    int min;

    if(lb >= ub-2)   // ub-2 is the 2nd last element
    {
        if(A[lb] < A[lb + 1])
            return A[lb];
        else
            return A[lb + 1];
    }

    min = Minimum(A, lb + 1, ub);

    if(A[lb] < min)
        return A[lb];
    else
        return min;
}

int Maximum(int A[], int lb, int ub)
{
    int max;
    if(lb >= ub-2)
    {
        if(A[lb] > A[lb + 1])
            return A[lb];
        else
            return A[lb + 1];
    }

    max = Maximum(A, lb + 1, ub);

    if(A[lb] > max)
        return A[lb];
    else
        return max;
}

int main()
{
 int n;
 cout<<"Number of elements required: "; cin>>n;
 int A[n];
 cout<<"Enter "<<n<<" elements: ";
 for(int i=0;i<n;i++) cin>>A[i];

 cout<<"The largest value is "<<Maximum(A,0,n)<<" and smallest value is "<<Minimum(A,0,n)<<endl;

 return 0;
}
