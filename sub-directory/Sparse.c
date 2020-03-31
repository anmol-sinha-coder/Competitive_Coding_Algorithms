#include<stdio.h>
#include<stdlib.h>

void addSparseMatrix(int sa[][3], int sb[][3], int sc[][3])
{
    int i, j, tr1, tr2,k=1;
    //if number of rows or columns of the sparse matrix are not matching, return
    if (sa[0][0] != sb[0][0] || sa[0][1] != sb[0][1])
    {
        printf("\nInvalid matrix size for Addition");
        return;
    }

    tr1 = sa[0][2]; //Total number of rows of sparse matrix-1
    tr2 = sb[0][2]; //Total number of rows of sparse matrix-2

    /*i, j and k are the row counters for sparse matrix-1, 2 and 3 respectively*/
    i = j = k = 1;

    //loop through untill all rows of sparse matrix-1 and sparse matrix-2 are covered.
    while ( i <= tr1 && j <= tr2)
    {
        if (sa[i][0] < sb[j][0])  // row index comparison of the 2 sparse matrices
        {
            sc[k][0] = sa[i][0];
            sc[k][1] = sa[i][1];  // smaller value goes to the addition matrix
            sc[k][2] = sa[i][2];
            k++;
            i++;
        }
        else if (sa[i][0] > sb[j][0])
        {
            sc[k][0] = sb[j][0];
            sc[k][1] = sb[j][1];
            sc[k][2] = sb[j][2];
            k++;
            j++;
        }
        else if (sa[i][0] == sb[j][0] )
        {
            if (sa[i][1] < sb[j][1])
            {
                sc[k][0] = sa[i][0];
                sc[k][1] = sa[i][1];
                sc[k][2] = sa[i][2];
                k++;
                i++;
            }
            else if (sa[i][1] > sb[j][1])
            {
                sc[k][0] = sb[j][0];
                sc[k][1] = sb[j][1];
                sc[k][2] = sb[j][2];
                k++;
                j++;
            }
            else
            {
                sc[k][0] = sb[j][0]; //does not matter which you fill among i or j
                sc[k][1] = sb[j][1]; //does not matter
                sc[k][2] = sa[i][2] + sb[j][2];
                k++;
                j++;
                i++;
            }
        } // end of else if for matching
    } // end of while

    /*Transfering the rest rows (if any) of sparse matrix-1 to sparse matrix-3*/
    while (i <=tr1)
    {
        sc[k][0] = sa[i][0];
        sc[k][1] = sa[i][1];
        sc[k][2] = sa[i][2];
        k++;
        i++;
    }

    /*Transfering the rest rows (if any) of sparse matrix-2 to sparse matrix-3*/
    while ( j <= tr2 )
    {
        sc[k][0] = sb[j][0];
        sc[k][1] = sb[j][1];
        sc[k][2] = sb[j][2];
        k++;
        j++;
    }
    sc[0][0] = sa[0][0]; //does not matter if you put sa[] or sb[]
    sc[0][1] = sa[0][1];
    sc[0][2] = k-1;

        for(int i=0; i<k; i++)
        if(i==0)
            printf("\t%d\t%d\t%d\n\t------------------\n",sc[i][0],sc[i][1],sc[i][2]);
        else
            printf("\t%d\t%d\t%d\n",sc[i][0],sc[i][1],sc[i][2]);
}

void multSparseMatrix(sa[][3],sb[][3],sc[][3])
{

}

void transposeSparseMatrix(int sp[][3], int ts[][3])
{
    int i, j, k, n;
    ts[0][0]=sp[0][1];
    ts[0][1]=sp[0][0];
    ts[0][2]=sp[0][2];
    k=1;

    for(i=0;i<sp[0][1];i++)  //number of columns is sp[0][1]
    {
        for(j=1;j<=sp[0][2];j++)   //for 1st column, check that index which matches its tuple(of 3) and according fill values
            if(i==sp[j][1])        //for 2nd column, check the same as above and add values accordingly to transpose matrix
            {                      //for 3rd column, check the same as above and add values accordingly to transpose matrix
                ts[k][0]=i;
                ts[k][1]=sp[j][0];
                ts[k][2]=sp[j][2];
                k++;
            }
    }
}

int main()
{
    int v;
    printf("Enter no. of non-zero values: ");
    scanf("%d",&v);
    int A[1+v][3],B[1+v][3],Sum[2*(1+v)][3];
    for(int i=0; i<=v; i++)
        scanf("%d%d%d",&A[i][0],&A[i][1],&A[i][2]);
    printf("\n");

    for(int i=0; i<=v; i++)
        if(i==0)
            printf("\t%d\t%d\t%d\n\t------------------\n",A[i][0],A[i][1],A[i][2]);
        else
            printf("\t%d\t%d\t%d\n",A[i][0],A[i][1],A[i][2]);

    printf("\nTranspose:-\n");
    transposeSparseMatrix(A,B);
    for(int i=0; i<=v; i++)
        if(i==0)
            printf("\t%d\t%d\t%d\n\t------------------\n",B[i][0],B[i][1],B[i][2]);
        else
            printf("\t%d\t%d\t%d\n",B[i][0],B[i][1],B[i][2]);

    printf("\n\nSUM:-\n");
    addSparseMatrix(A,B,Sum);

    printf("\n\nPRODUCT:-\n");
    int Prod[A[0][1]*B[0][0]][3];
    multSparseMatrix(A,B,Prod);
}
