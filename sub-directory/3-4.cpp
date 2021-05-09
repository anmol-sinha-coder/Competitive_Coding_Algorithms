#include<iostream>
#include<bits/stdc++.h>
using namespace std;

unsigned int floor_Sqrt(unsigned int x)
{
    if (x == 0 || x == 01)
     return x;

    int sqrt = 1;
    while (sqrt*sqrt <= x)
     sqrt++;

    if(x-(sqrt-1)*(sqrt-1) > 100+sqrt*sqrt-x)
     sqrt++;

    return sqrt-1 ;
}

int main()
{
 unsigned int num; clock_t s=0,e=0;
 printf("Enter Integer Number ( in range [0,429483] ): "); cin>>num;
 s=clock();
 cout<<"Square root (upto 2 decimals) = "<<(double)floor_Sqrt(num*10000)/100<<endl;
 e=clock();
 cout<<scientific<<setprecision(2)<<"Total CPU time taken (in seconds): "<<(double)(e-s)/CLOCKS_PER_SEC<<endl;
}

