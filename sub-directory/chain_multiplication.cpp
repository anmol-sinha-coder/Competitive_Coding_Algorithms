#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int matrixOrder(int array[], int n)
{
   int minMul[n][n];          //holds the number of scalar multiplication needed
   for (int i=1; i<n; i++)
      minMul[i][i] = 0;           //for multiplication with 1 matrix, cost is 0

   for (int length=2; length<n; length++)       //find the chain length starting from 2
      for (int i=1; i<n-length+1; i++)
      {
         int j = i+length-1;
         minMul[i][j] = INT_MAX;     //set to infinity
         for (int k=i; k<=j-1; k++)
         {  //store cost per multiplications
            int mult_cost = minMul[i][k] + minMul[k+1][j] + array[i- 1]*array[k]*array[j];
            if (mult_cost < minMul[i][j]) // Minimizing the value of cost
               minMul[i][j] = mult_cost;
         }
      }

   for(int i=1;i<n;i++)
   {
    for(int j=1;j<n;j++)
     if(j<i)
      cout<<"\t";
     else
      cout<<minMul[i][j]<<"\t";
    cout<<endl;
   }
   cout<<endl;

   return minMul[1][n-1];
}

int main()
{
    int n;
    cout<<"Enter number of Matrices in chain: "; cin>>n;   n++;
   int dimensions[n];
   cout<<"Enter matrix dimensions in continuum: ";
   for(int i=0;i<n; i++) cin>>dimensions[i];
   cout<<"________________________________________________________"<<endl;
   cout << "Minimum number of matrix multiplications: " << matrixOrder(dimensions, n)<<endl;

 return 0;
}
