#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

void insertionSortAscending(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

void insertionSortDescending(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        
        while (j >= 0 && arr[j] < key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

int main()
{
	clock_t start,end;
	long double total_time;
	int n;
	printf("Enter number of values in array");
	scanf("%d",&n);
	int arr[n];
	while (1)
	{
		int x;
		printf("INSERTION SORT MENU:\n");
		printf("0.Quit\n");
		printf("1. place n Random numbers into Array\n");
		printf("2.Display the Array\n");
		printf("3.Sort the Array in Ascending Order by using Insertion Sort Algorithm\n");
		printf("4.Sort the Array in Descending Order by using any sorting Algorithm\n");
		printf("5.Time Complexity to sort ascending of random data\n");
		printf("6.Time Complexity to sort ascending of data already sorted in ascending order\n");
		printf("7.Time Complexity to sort ascending of data already sorted in descending order\n");
		printf("8.Time Complexity to sort ascending of data for all Cases (Data Ascending, Data in descending & Random Data) in Tabular form for values n=5000 to 50000, step=5000\n");     
		printf("Enter a valid option:\n");
		scanf("%d",&x);
		
		switch (x)
		{
		
		case 0: exit(1);
				break;
		case 1:	for(int i=0;i<n;i++)
				arr[i]=rand();
				printf("\n");
				break;
		case 2: for(int i=0;i<n;i++)
				printf("%d | ",arr[i]);
				printf("\n");
				break;
		case 3: insertionSortAscending(arr,n);
		printf("\n");
				break;
		case 4: insertionSortDescending(arr,n);
		printf("\n");
				break;
		case 5: for(int i=0;i<n;i++)
				arr[i]=rand();
				start=clock();
				insertionSortAscending(arr,n);
				end=clock();
				total_time=((long double)(end-start))/CLOCKS_PER_SEC;
				printf("time taken: %Lf\n",total_time);
				printf("\n");
				break;
		case 6: for(int i=0;i<n;i++)
				arr[i]=rand();
				insertionSortAscending(arr,n);
				start=clock();
				insertionSortAscending(arr,n);
				end=clock();
				total_time=((long double)(end-start))/CLOCKS_PER_SEC;
				printf("time taken: %Lf\n",total_time);
				printf("\n");
				break;
		case 7: for(int i=0;i<n;i++)
				arr[i]=rand();
				insertionSortDescending(arr,n);
				start=clock();
				insertionSortAscending(arr,n);
				end=clock();
				total_time=((long double)(end-start))/CLOCKS_PER_SEC;
				printf("time taken: %Lf\n",total_time);
				printf("\n");
				break;
		case 8: printf("s.no\tValue of n\t time for ascending data\t time for descending data\ttime for random data \n");
				for(int k=5000;k<=50000;k+=5000)
				{
					long double t1,t2,t3;
					n=k;
					int arr2[n];
					for(int i=0;i<n;i++)
					arr2[i]=rand();
					start=clock();
					insertionSortAscending(arr2,n);
					end=clock();
					t3=((long double)(end-start))/CLOCKS_PER_SEC;
					start=clock();
					insertionSortAscending(arr2,n);
					end=clock();
					t1=((long double)(end-start))/CLOCKS_PER_SEC;
					insertionSortDescending(arr2,n);
					start=clock();
					insertionSortAscending(arr2,n);
					end=clock();
					t2=((long double)(end-start))/CLOCKS_PER_SEC;
					printf("%d\t%d\t\t\t%Lf\t\t\t%Lf\t\t\t%Lf\n",k/5000,n,t1,t2,t3);
		
				}
				printf("\n");
				break;
		default: printf("enter a valid option");
		printf("\n");
		}
	}
	
	return 0;
}
