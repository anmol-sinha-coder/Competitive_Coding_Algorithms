#include<iostream>
#include<bits/stdc++.h>
using namespace std;

unsigned int power1(int a,unsigned int n) // a**n
{
 if(n==0)
    return 1;
 else if(n==1)
    return a;
 else
    return a*power1(a,n-1);
}

unsigned int power2(int a,unsigned int n) // a**n
{
 if(n==0)
    return 1;
 else if(n==1)
    return a;
 else if(n%2) // odd exponent value
    return power2(a,int(n/2))*power2(a,int(n/2)+1);
 else if(!(n%2)) //even exponential_distribution
    return power2(a,int(n/2))*power2(a,int(n/2));
}

int main()
{
    int p,q;
    cout<<"Enter base and exponent: "; cin>>p>>q;
    cout<<"Function-1, "<<p<<"^"<<q<<" = "<<power1(p,abs(q))<<endl<<"Function-2, "<<p<<"^"<<q<<" = "<<power2(p,abs(q))<<endl;
    cout<<scientific<<setprecision(3);
    printf("serial\tValue of n\t time for Brute force\t time for Divide_Conqueor\n");
				for(int k=5;k<=50;k+=5)
				{
					long double t1=0.0,t2=0.0,t3=0.0; time_t start=0,end=0;
					int m=k;

					start=clock();
                    for(int i=0;i<1000;i++)

                    power1(2,m);
					end=clock();
					t1=((long double)(end-start))/(1000*CLOCKS_PER_SEC);

					start=clock();
					for(int i=0;i<999;i++)
                     power2(2,m);
					end=clock();
					t2=((long double)(end-start))/(1000*CLOCKS_PER_SEC);

					cout<<k/5000<<"\t"<<m<<"\t\t\t"<<t1<<"\t\t\t"<<t2<<"\t\t\t"<<"\n";
                }
    return 0;
}
