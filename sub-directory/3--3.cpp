#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
 int M[10][10]={1,1,1,1,1,1,1,0,0,0,
                1,1,1,1,1,0,0,0,0,0,
                1,1,1,1,0,0,0,0,0,0,
                1,1,1,1,1,1,1,1,0,0,
                1,1,1,1,1,1,1,0,0,0,
                1,1,1,1,1,1,1,1,0,0,
                1,1,1,1,1,0,0,0,0,0,
                1,1,1,0,0,0,0,0,0,0,
                1,1,1,1,1,0,0,0,0,0,
                1,1,1,1,1,1,0,0,0,0,
               };



	int cnt=0, max_row, i=0, j=0;
	while(i<10 && j<10)
		if(M[i][j])
			j++;
        else
            i++;

	printf("Rows with most number of 1's = ");
	for(int i=0;i<10;i++)
     if(M[i][j-1]==1)
      printf("%d,",max_row=i);
    printf("\b \n");
	printf("Count of 1's = %d\n",cnt=j);

 return 0;
}
