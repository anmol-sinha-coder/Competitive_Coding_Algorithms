#include<iostream>
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int c=0;
void Display(int A[9][9])
{
 cout<<"         ";
 for(int i=0;i<75;i++)
    cout<<"=";
 cout<<endl<<"         ";
 for(int i=0;i<9;i++)
 {
  if((i+1)%3)
  {
  for(int j=0;j<9;j++)
   if(j%3)cout<<"\b|       |"; else cout<<"\b||       |";
  cout<<"|"<<endl;
  cout<<"         ";
  for(int j=0;j<9;j++)
   if(A[i][j]|=0){if(j%3)cout<<"\b|   "<<A[i][j]<<"   |"; else cout<<"\b||   "<<A[i][j]<<"   |";}
   else{if(j%3)cout<<"\b|   -   |"; else cout<<"\b||   -   |";}
  cout<<"|"<<endl;
  cout<<"         ";
  for(int j=0;j<9;j++)
   if(j%3)cout<<"\b|_______|"; else cout<<"\b||_______|";
  cout<<"|"<<endl;
  cout<<"         ";
  }
  else
  {
  for(int j=0;j<9;j++)
   if(j%3)cout<<"\b|       |"; else cout<<"\b||       |";
  cout<<"|"<<endl;
  cout<<"         ";
  for(int j=0;j<9;j++)
   if(A[i][j]|=0){if(j%3)cout<<"\b|   "<<A[i][j]<<"   |"; else cout<<"\b||   "<<A[i][j]<<"   |";}
   else{if(j%3)cout<<"\b|   -   |"; else cout<<"\b||   -   |";}
  cout<<"|"<<endl;
  cout<<"         ";
  for(int j=0;j<9;j++)
   if(j%3)cout<<"\b|_______|"; else cout<<"\b||_______|";
  cout<<"|"<<endl;
  if(i<9-1)cout<<"        |"; else cout<<"         ";
  for(int j=0;j<75;j++)
    cout<<"-";
  if(i<9-1)cout<<"|";
  cout<<endl<<"         ";
  }
 }
 cout<<endl;c++;
system("PAUSE");
//Sleep(1000); //milliseconds
system("CLS");
}

bool check(int A[9][9],int r,int c)
{
 if(A[r-1][c-1])
 {
 for(int i=0;i<9;i++)   //column check
  if(i!=r-1 && A[i][c-1]==A[r-1][c-1])
   return 0;
 for(int j=0;j<9;j++)   //row check
  if(j!=c-1 && A[r-1][j]==A[r-1][c-1])
   return 0;
for(int m=0;m<3;m++)   //box check
 for(int n=0;n<3;n++)
  if((r-1)/3*3+m%3!=r-1 && (c-1)/3*3+n%3!=c-1 && A[(r-1)/3*3+m%3][(c-1)/3*3+n%3]==A[r-1][c-1])
   return 0;
}

return 1;
}


int main()
{
 int A[9][9] = {
//     COL
/*ROW*/// 1 2 3   4 5 6   7 8 9
/* 1 */  {9,0,6,  0,1,3,  0,0,8},
/* 2 */  {0,5,8,  0,0,0,  0,9,0},
/* 3 */  {0,3,0,  0,0,0,  0,1,0},

/* 4 */  {0,6,0,  8,0,0,  9,2,0},
/* 5 */  {0,0,3,  4,0,9,  1,0,0},
/* 6 */  {0,4,9,  0,0,6,  0,3,0},

/* 7 */  {0,9,0,  0,0,0,  0,8,0},
/* 8 */  {0,1,0,  0,0,0,  6,7,0},
/* 9 */  {4,0,0,  9,6,0,  3,0,1},

               };
cout<<"                         __________________SUDOKU__________________\n";
 Display(A); int flag;


flag=0;      //Loop until Sudoku cells are filled
for(int i=1;i<=9;i++)
{for(int j=1;j<=9;j++)
  if(check(A,i,j))
    cout<<"OK  ";
  else
    cout<<"Not ";
 cout<<endl;
}

//cout<<" Final Solution: \n";Display(A);
 return 0;
}
