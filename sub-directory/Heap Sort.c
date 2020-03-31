/* Sort the array elements in ascending order using heap sort.   */
/* ------------------------------------------------------------- */

#include<stdio.h>
#define MAX 100

void build_Heap(int H[MAX],int);
void HeapSort(int H[MAX],int);

int main()
{
    int arr[MAX],n,i;
    printf("Enter the total number of array elements: ");
    scanf("%d",&n);

    printf("Enter the array elements: ");
    for(i=1;i<=n;i++)
        scanf("%d",&arr[i]);

    HeapSort(arr,n);
    printf("The sorted array is: ");
    for(i=1;i<=n;i++)
    {
        printf("\t%d",arr[i]);
    }

    return 0;
}

void Min_Heap(int H[MAX],int n)
{
    int i,j,k,v,heap;
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=H[k];
        heap=0;
        while(heap==0 && (2*k)<=n)
        {
            j=2*k;
            if(j<n)
            {
                if(H[j]<H[j+1])
                    j++;
            }
            if(v>=H[j])
                heap=1;
            else
            {
                H[k]=H[j];
                k=j;
            }
        }
        H[k]=v;
    }
}

void Max_Heap(int H[MAX],int n)
{
    int i,j,k,v,heap;
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=H[k];
        heap=0;
        while(heap==0 && (2*k)<=n)
        {
            j=2*k;
            if(j<n)
            {
                if(H[j]>H[j+1])
                    j++;
            }
            if(v<=H[j])
                heap=1;
            else
            {
                H[k]=H[j];
                k=j;
            }
        }
        H[k]=v;
    }
}

void HeapSort(int H[MAX],int n)
{
    int t,i;
    for(i=n;i>=1;i--)
    {
        Max_Heap(H,i);
        t=H[1];   //H[1] and H[i] swap
        H[1]=H[i];
        H[i]=t;
    }
}
