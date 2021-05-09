#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main()
{
    printf("serial\tValue of n\t time for Linear\t time for Binary\n");
				for(int k=5000;k<=50000;k+=5000)
				{
					long double t1=0.0,t2=0.0,t3=0.0; time_t start=0,end=0;
					int m=k;
					int arr2[m]={0};
					srand(time(NULL));
					for(int i=0;i<m;i++)
					 arr2[i]=rand()%1000000;

					start=clock();
					for(int i=0;i<99999;i++)Quick_Sort(arr2,0,m-1);
					end=clock();
					t1=((long double)(end-start))/(100000*CLOCKS_PER_SEC);

					start=clock();
					for(int i=0;i<99999;i++)Merge_Sort(arr2,0,m-1);
					end=clock();
					t2=((long double)(end-start))/(100000*CLOCKS_PER_SEC);

					cout<<k/5000<<"\t"<<m<<"\t\t\t"<<t1<<"\t\t\t"<<t2<<"\t\t\t"<<"\n";
                }
    return 0;
}
