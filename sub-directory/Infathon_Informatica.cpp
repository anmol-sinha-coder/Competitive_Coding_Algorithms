#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
 int N; cin>>N;
 int A[N];
 try{
 int pos=-1,min=INT_MAX;
 for(int i=0;i<N;i++)
  cin>>A[i];
 for (int i = 0; i < N; i++)
   if(A[i]==int("null"))
    throw A[i];

 for(int i=0;i<N;i++)
  {
   if(abs(A[i])<min)
    min=abs(A[i]), pos=i;
   if(abs(A[i]) == min && A[i]>0)
    min=abs(A[i]), pos=i;
  }
  cout<<A[pos];
 }
 catch(int x)
 {cout<<"exception\n"; return 1;}


 return 0;
}
/*
"Word Transformations"

Your solution will be scored against some number of hidden test cases. A sample is provided below.

Time limit: 30 minutes

Given two words of equal length that are in a dictionary , write a method to transform one word into another word by changing only one letter at a time. The new word you get in each step must be in the dictionary.

Assume, the dictionary words to be used in the program will be provided as part of the input.

Input

Input contains one test case.
First line contains the starting word to be transformed.
Second line contains the final word, the transformed state.
Third line contains a number N, denoting the number of words in the dictionary.
The next N lines contain the words in the dictionary, one word per line.

Output

Print each word from starting word to final word during the transformation, one word per line.
If it is not possible to transform the word, print “Transformation is not possible” (without quotes).

Code evaluation is based on your output, please follow the sample format and do NOT print anything else.
in
DAMP
LIKE
6
DUMP
LUMP
LAMP
LIMP
LIME
LIGHT

out
DAMP
LAMP
LIMP
LIME
LIKE
*/
