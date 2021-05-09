#include<bits/stdc++.h>
using namespace std;

int main()
{
 string S[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"},temp="";
 int m,n;
 cin>>temp>>m>>n;
 cout<<S[m].size()*S[n].size()<<endl;
 temp="";
 for(int i=0;i<S[m].size();i++)
  for(int j=0;j<S[n].size();j++,temp="")
   temp+=S[m][i],temp+=S[n][j], cout<<temp<<",";
 cout<<"\b "<<endl;

 return 0;
}

/*
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int fact(int n)
{
    return (n <= 1) ? 1 : n * fact(n - 1);
}

int findSmallerInRight(char* str, int low, int high)
{
    int countRight = 0, i;

    for (i = low + 1; i <= high; ++i)
        if (str[i] < str[low])
            ++countRight;

    return countRight;
}

int findRank(char* str)
{
    int len = strlen(str);
    int mul = fact(len);
    int rank = 1;
    int countRight;

    int i;
    for (i = 0; i < len; ++i) {
        mul /= len - i;
        countRight = findSmallerInRight(str, i, len - 1);
        rank += countRight * mul;
    }

    return rank;
}

int main()
{
    char str[] = "string";
    cout << findRank(str);
    return 0;
}

*/
