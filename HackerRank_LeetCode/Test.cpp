#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 int maxElement(int n, int maxSum, int k)
{
 int v=maxSum/n;
 vector<int> a(n,v);
 while(maxSum-v!=0)
   a[v++]++;
 return *max_element(a.begin(),a.end());
}

int sortedSum(vector<int> a)
{
 int vector <vector<int>> m;
 for(int i=1;i<a.size();i++)
 {
  m.push(a);
  partial_sort(a.begin(),a.begin()+i,a.end());
 }

 int sum=0;
 for(int i=0;i<a.size();i++)

 return sum % (int)pow(10,9);
}
int main()
{

 return 0;
}
