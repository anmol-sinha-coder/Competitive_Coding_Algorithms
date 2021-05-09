/*que2.

2.Write a program to find out GCD (greatest common divisor) using the following three algorithms.
a)Euclid’s algorithm
b)Consecutive integer checking algorithm.
Write a program to find out which algorithm is faster for the following data. Estimate the time complexity in each case.
I.Find GCD of two numbers when both are very large i.e. GCD (31415, 14142) by applying each of the above algorithms.
II.Find GCD of two numbers when one of them can be very large i.e. GCD (56, 32566) or GCD (34218, 56) by applying each of the above algorithms.
III.Find GCD of two numbers when both are very small i.e. GCD (12, 15) by applying each of the above algorithms.
IV.Find GCD of two numbers when both are same i.e. GCD (31415, 31415) or GCD (12, 12) by applying each of the above algorithms.
*/

#include <stdio.h> 
#include<time.h>
#include<stdlib.h>

int gcdByEuclid(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcdByEuclid(b % a, a); 
} 

int gcdByConsecutiveInteger(int a, int b)
{
	int i, c;
	c= a>=b? b : a; 
	for(i=c;i>=1;i--)
	{
		if(a%i==0 && b%i==0)
			return i;
	}
}
  
int main() 
{ 
	clock_t start,end;
	double total1,total2;
    int a = 10, b = 15; 
    printf("Enter Numbers");
    scanf("%d%d",&a,&b);
   	start=clock();
   	for(int i=0;i<100000;i++)
    gcdByEuclid(a,b);
    end=clock();
	total1=((double)(end-start))/CLOCKS_PER_SEC;
	printf("time by euclid method %f\n",total1);
	
	start=clock();
	for(int i=0;i<100000;i++)
    gcdByConsecutiveInteger(a,b);
    end=clock();
	total2=((double)(end-start))/CLOCKS_PER_SEC;
	printf("time by consecutive method %f \n",total2);
   
   int x=gcdByEuclid(a,b);
   int y=gcdByConsecutiveInteger(a,b);
   
   printf("Gcd by euclid : %d \nGcd by consecutive : %d",x,y);
		 
	return 0;
}


