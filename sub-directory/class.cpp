#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
 std::cout<<std::showpos;
 cout<<"Range: "<<INT_MIN<<" --> "<<INT_MAX<<"\n\nx = ";
 int x; cin>>x; int counter=0;

 for(int c=1;(c&=(x^=c)^c)<<=1;counter++); //specialized incremental Logic counter

 cout<<x<<"\tcount="<<counter;
 cout<<endl<<endl;
 return 0;
}
