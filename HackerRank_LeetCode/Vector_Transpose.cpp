#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct transposed_ref {
    T& t;
    transposed_ref(T& t) : t(t) {}
    typename T::value_type& get(int x,int y) { return T[y][x]; }
};

int main()
{
  vector<vector<int>> M = {{0,1,2},{2,3,4},{4,5,6},{6,7,8}};
  transposed_ref<vector<vector<int>>> Trans(M);
  for(int i=0;i<M.size();i++)
    for(int j=0;j<M[i].size();j++)
    cout<<M[i][j]<<",";
  cout<<"\b \n";

 return 0;
}
