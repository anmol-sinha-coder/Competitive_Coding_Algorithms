#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int r=4,c=3;
int** Rotate_Clockwise(int M[r][c])
{
 int A[c][r]={0};
 for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            A[i][j]=M[j][n-i];
 return A;
}

int main()
{
        int M[r][c]={
                        1,2,3,
                        1,2,3,
                        1,2,3,
                        1,2,3
                    };
    for(int i=0;i<r;i++, cout<<endl)
        for(int j=0;j<c;j++, cout<<" ")
            cout<<" "<<M[i][j];
    cout<<endl;
    int A[c][r]=Rotate_Clockwise(M,r,c);
    cout<<endl;
    for(int i=0;i<c;i++, cout<<endl)
        for(int j=0;j<r;j++, cout<<" ")
            cout<<" "<<A[i][j];

 return 0;
}
