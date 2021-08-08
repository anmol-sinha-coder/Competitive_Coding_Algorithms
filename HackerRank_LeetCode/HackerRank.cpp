// https://leetcode.com/discuss/general-discussion/987729/hackerrank-problem-solving-intermediate-certification
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int BitAndPair(vector<int> A)
{
 vector<int> non; int exp[13]={0}, count=0;
 for(int i=0;i<A.size();i++)
    if(A[i]&&!(A[i]&(A[i]-1)))
        exp[(int)log2(A[i])]++;
    else
        non.push_back(A[i]);

 for(int i=0;i<=12;i++)
    for(int j=0;j<non.size();j++)
    {
     int x=(int)pow(2,i)&non[j];
     if(x&&!(x&(x-1)))
      count += exp[i];
    }
 return count;
}

/*
int SortedSum(vector<int> A)
{
 map<int,int> diff_dict;
 int temp[A.size()]={0}, sum=0;
 for(int i=0;i<A.size();i++)
    temp[i]=A[i];
 sort(temp, temp+A.size());

 for(int i=1;i<A.size();i++)
   if(!diff_dict[A[i]])
     diff_dict.insert(A[i],1);
   else
     diff_dict[A[i]]+=1;
  for(int i=1;i<A.size();i++)
    sum += A[i];

 return sum;
}
*/


int main()
{
 vector<int> A;
 int n,a; cin>>n;
 for(int i=0;i<n;i++)
    cin>>a, A.push_back(a);
 //cout<<SortedSum(A);
 cout<<BitAndPair(A);

 return 0;
}
