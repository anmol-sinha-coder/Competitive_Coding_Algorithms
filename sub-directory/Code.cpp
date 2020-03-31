#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

int c;
int *A;
void compute( int arr[] , int n )
{
    int sum=0,d=1;
     for(int m = 1 ; m<= (n/2) ; m++)
     {
        for(int i = 0 ; i< n-1 ; )
         for(int j=i+d;j<n;j++)
          {sum+=func(arr[i],arr[j],c);i=j;}

     }
}

int find_minimum(int a[], int n) {
  int c, min, index;

  min = a[0];
  index = 0;

  for (c = 1; c < n; c++) {
    if (a[c] < min) {
       index = c;
       min = a[c];
    }
  }
  return index;
}

int func( int a , int b, int c)
{
    int s = pow((b-a),2)+c;
    return s;
}

int main()
{
    int a,n,sum=0;
    cout<<"Enter arr size & c\n";
    cin>>n;
    cin>>c;
    int *A=new int[n];

    for(int i=1;i<n+1;i++)
    {
        cin>>A[n];
    }


    return 0;
}
