#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void election_result(char votes[],int n)
{
 int indexA=-1,indexB=-1;
	bool foundA=false,foundB=false;
	int nullCount=0,Acount=0,Bcount=0,neutral_count=0;


	for(int i=0;i<n;i++)
	{
        if(votes[i]=='-')
		    nullCount++;

		if(votes[i]=='A' && foundB==false)
		{
			indexA=i;
			foundA=true;
			Acount+=nullCount+1;
			nullCount=0;
		}

		if(votes[i]=='B' && foundA==false)
		{
			indexB=i;
			foundB=true;
			neutral_count+=nullCount;
			Bcount++;
			nullCount=0;
		}

		if(votes[i]=='A' && foundB==true)
		{
			indexA=i;
			foundA=true;
			foundB=false;

			Acount+=1+(indexA-indexB-1)/2;
			Bcount+=(indexA-indexB-1)/2;
			neutral_count+= (indexA-indexB-1)%2;
			nullCount=0;
		}

		if(votes[i]=='B' && foundA==true)
		{
			indexB=i;
			foundB=true;
			foundA=false;
			Bcount++;
			neutral_count+= (indexB-indexA-1);
			nullCount=0;
		}
	}

	if(foundA==true)
	 neutral_count+=(n-(Acount+Bcount+neutral_count));
	else
	 Bcount+=(n-(Acount+Bcount+neutral_count));

	printf("%d | %d | %d \n",Acount,Bcount,neutral_count); // to check counts

	if(Acount>Bcount)
	printf("A\n");
	else if(Acount<Bcount)
	printf("B\n");
	else
	printf("Coalition government\n");
}
/* 13
--A-B--AB--B-
Coalition government

Process returned 0 (0x0)   execution time : 84.927 s
Press any key to continue.
*/

int main()
{
	int n;
	scanf("%d",&n);
	char votes[n];
	fflush(stdin);
	scanf("%s",votes);
    election_result(votes,n);

	return 0;
}
