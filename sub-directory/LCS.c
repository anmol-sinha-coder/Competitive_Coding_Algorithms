#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include<limits.h>

int max(int a,int b)
{
 return a>b?a:b;
}

void longestCommonSubsequence( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */

      // Memoization
   for (int i=0; i<=m; i++)
     for (int j=0; j<=n; j++)
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else //when (X[i-1] != Y[j-1])
         L[i][j] = max(L[i-1][j], L[i][j-1]);

   int index = L[m][n]; //Last value
   char lcs[index+1];
   lcs[index] = '\0';

   // Start from the right-most-bottom-most corner and
   // one by one store characters in lcs[]
   int i = m, j = n;
   while (i > 0 && j > 0)
      // If current character in X[] and Y are same, then
      // current character is part of LCS
      if (X[i-1] == Y[j-1])
      {
          lcs[index-1] = X[i-1]; // Put current character in result
          i--; j--; index--;     // reduce values of i, j and index
      }
      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (L[i-1][j] > L[i][j-1]) /* Whichever is maximum */
         i--;
      else
         j--;


   printf("\n    "); for(int j=0;j<n;j++) printf(" %c",Y[j]); printf("\n");
   printf("    "); for(int j=0;j<n;j++) printf(" -"); printf("\n");
printf("   ");
   for(int j=0;j<=n;j++)
     printf("%d ",L[0][j]);
  printf("\n");

   for(int i=1;i<=m;i++)
   {printf("%c |",X[i-1]);
   for(int j=0;j<=n;j++)
     printf("%d ",L[i][j]);
  printf("\n");
   }
printf("\n");

   printf( "\nLongest Common Subsequence is '%s'\n",lcs);
   printf( "Length of Longest Common Subsequence is %d\n",strlen(lcs));
}

int main()
{
  char X[100]="", Y[100]="";
  printf("Enter 2 strings: \n");
  scanf("%s%s",X,Y);
  int m = strlen(X);
  int n = strlen(Y);
  longestCommonSubsequence(X, Y, m, n);

  return 0;
}
