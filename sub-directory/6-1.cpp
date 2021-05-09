#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    /*

10.9 2.5 1.3 9.3
3.8  9.2 2.2 11.8
7.9  5.2 7.3 0.6
3.4  13.1 1.2 6.3

    */
    int n;
   cout<<"Enter dimension value: "; cin>>n;
   float M[n][n],T[n][n];
   for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
     cin>>M[i][j];


   for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
     if(M[i][j]-(int)M[i][j]>=0.5)
      M[i][j]=(int)M[i][j]+1;
     else
      M[i][j]=(int)M[i][j];
      cout<<endl<<endl;
 for(int x=0;x<n;x++)
 {
  for(int y=0;y<n;y++)
   printf("%d\t",(int)M[x][y]);
 printf("\n");
 }

    return 0;
}
