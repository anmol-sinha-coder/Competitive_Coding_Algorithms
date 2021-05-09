#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

bool isPrime(int n)
{
	if (n <= 1)
        return false;
	for (int i=2; i<n; i++)
		if (n%i == 0)
			return false;
	return true;
}

int power(int a, unsigned int n, int p) 
{
	int res = 1;
	a = a % p;

	while (n > 0)
	{
		if (n & 1)
			res = (res*a) % p;
		n = n>>1;
		a = (a*a) % p;
	}
	return res;
}

int gcd(int a, int b)
{
	if(a < b)
		return gcd(b, a);
	else if(a%b == 0)
		return b;
	else return gcd(b, a%b);
}

bool isPrime2(unsigned int n, int k)
{
if (n <= 1 || n == 4) return false;
if (n <= 3) return true;

    while (k>0)
    {
        int a = 2 + rand()%(n-4);

        if (gcd(n, a) != 1)
            return false;

        if (power(a, n-1, n) != 1)
            return false;

        k--;
	}

	return true;
}

int power3(int x, unsigned int y, int p) //Method 3
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;

        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}


bool miillerTest(int d, int n)
{

    int a = 2 + rand() % (n - 4);

    int x = power3(a, d, n);

    if (x == 1  || x == n-1)
       return true;

    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false;
        if (x == n-1)    return true;
    }

    return false;
}
bool isPrime3(int n, int k)
{
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;

    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
         if (!miillerTest(d, n))
              return false;

    return true;
}

int main()
{
    time_t start,end;
    bool res;
    printf("Number\tResult\t\tMethod 1\tMethod 2\tMethod 3\n");
    for(int i=0;i<10;i++)
    {
        int x=rand();
        printf("%d\t",x);
        
        
        
        start=time(NULL);
        for(int k=0;k<100000;k++)
        res=isPrime(x);
        end=time(NULL);
        if(res==true)
            printf("Prime\t\t");
        else
            printf("Not Prime\t");
        printf("%f\t",((double)(end-start))/CLOCKS_PER_SEC);
        
        
        
        start=time(NULL);
         for(int k=0;k<100000;k++)
        res=isPrime2(x,3);
        end=time(NULL);
        printf("%f\t",((double)(end-start))/CLOCKS_PER_SEC);
        
        
        
        
        start=time(NULL);
         for(int k=0;k<1000;k++)
        res=isPrime3(x,4);
        end=time(NULL);
        printf("%f\t",((double)(end-start))/CLOCKS_PER_SEC);
        printf("\n");
    }
	return 0;
}
