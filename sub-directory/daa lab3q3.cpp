#include<stdio.h>
#include<stdlib.h>

int count(int **arr,int r,int lb,int ub)
{
	int mid = (lb+ub)/2;
	if(mid==0)
		return -1;
	else if(arr[r][mid]==1&&arr[r][mid+1]==0||arr[r][mid]==1&&mid==9)
		return mid;
	else if(arr[r][mid]==1&&arr[r][mid+1]==1)
		return (count(arr,r,mid+1,ub));
	else if(arr[r][mid]==0)
		return (count(arr,r,lb,mid-1));
}

int main()
{
	FILE *fp;
	int **arr=(int* *)malloc(10*sizeof(int *));
	for(int i=0;i<10;i++)
		arr[i]=(int *)malloc(10*sizeof(int));
	fp=fopen("abc.txt","r");
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			char ch=fgetc(fp);
			arr[i][j]=atoi(&ch);
		}
	}
	
	int res=0,max=-1,i=0,j;
	for(j=0;j<10;)
	{
		if(arr[i][j]==0)
			i++;
		else if(arr[i][j]==1)
		{
			max=i;
			j++;
		}
		if(i==10)
			break;
	}
	res=j;
	printf("Row with maximum 1's = %d\nCount = %d\n",max,res);
	
	return 0;
}
