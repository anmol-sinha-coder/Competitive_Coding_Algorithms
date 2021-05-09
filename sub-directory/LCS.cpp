#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;


void longestCommonSubsequence( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];

   /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (int i=0; i<=m; i++)
     for (int j=0; j<=n; j++)
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;0l
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);

   int index = L[m][n];

   char lcs[index+1];
   lcs[index] = '\0';

   // Start from the right-most-bottom-most corner and
   // one by one store characters in lcs[]
   int i = m, j = n;
   while (i > 0 && j > 0)
   {
      // If current character in X[] and Y are same, then
      // current character is part of LCS
      if (X[i-1] == Y[j-1])
      {
          lcs[index-1] = X[i-1]; // Put current character in result
          i--; j--; index--;     // reduce values of i, j and index
      }
      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }
   cout << "LCSubsequence is " << lcs;
}

void LCSubStr(char* X, char* Y, int m, int n)
{
    // Create a table to store lengths of longest common
    // suffixes of substrings.   Note that LCSuff[i][j]
    // contains length of longest common suffix of X[0..i-1]
    // and Y[0..j-1]. The first row and first column entries
    // have no logical meaning, they are used only for
    // simplicity of program
    int LCSuff[m + 1][n + 1];

    // To store length of the longest common substring
    int len = 0;

    // To store the index of the cell which contains the
    // maximum value. This cell's index helps in building
    // up the longest common substring from right to left.
    int row, col;

    /* Following steps build LCSuff[m+1][n+1] in bottom
       up fashion. */
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
            {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                if (len < LCSuff[i][j])
                {
                    len = LCSuff[i][j];
                    row = i;
                    col = j;
                }
            }
            else
                LCSuff[i][j] = 0;

    // if true, then no common substring exists
    if (len == 0) {
        cout << "No Common Substring";
        return;
    }

    // allocate space for the longest common substring
    char resultStr[len+1] = "";
    resultStr[len]='\0';
    // traverse up diagonally form the (row, col) cell
    // until LCSuff[row][col] != 0
    while (LCSuff[row][col] != 0)
    {
        resultStr[--len] = X[row - 1]; // or Y[col-1]
        // move diagonally up to previous cell
        row--;
        col--;
    }

    // required longest common substring
    cout << "\nLCSubstring is "<<resultStr<<endl;
}


int main()
{
  char X[] = "babad";
  char Y[] = "dabab";
  int m = strlen(X);
  int n = strlen(Y);
  longestCommonSubsequence(X, Y, m, n);
  LCSubStr(X, Y, m, n);

  return 0;
}
