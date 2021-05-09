#include <bits/stdc++.h>
using namespace std;

void print_top_k_mostFrequentNumber(int A[], int n, int k)
{
 int large=INT_MIN,big=INT_MIN,pos=-1;
 for(int i=0;i<n;i++)
   if(A[i]>large)
      large=A[i];
  int freq[large+1]={0},sort[large+1]={0};
  for(int i=0;i<n;i++)
    freq[A[i]]++;
  int c=0;
  for(int i=1;i<=k;i++)
  {
  for(int j=large;j>=0;j--)
    if(freq[j]>big)
      {big=freq[j]; pos=j;}
  freq[pos]=0;
  sort[c++]=pos;
 }
  for(int i=0;i<k;i++)
    cout<<k<<" ";
  cout<<endl;
}
int main()
{
    int n,i,k;
    cin>>n>>k;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    print_top_k_mostFrequentNumber(arr, n, k);
    return 0;
}