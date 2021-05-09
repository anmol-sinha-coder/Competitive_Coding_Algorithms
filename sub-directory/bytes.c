#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int binaryToDecimal(int n) 
{ 
    int num = n; 
    int dec_value = 0; 
    int base = 1; 
    int temp = num; 
    while (temp) 
    { 
        int last_digit = temp % 10; 
        temp = temp / 10; 
        dec_value += last_digit * base; 
        base = base * 2; 
    } 
    return dec_value; 
} 

void main()
{
 int n,i=0; char b[32]=""; int s[4];
  for(int i=0;i<32;i++)
   b[i]=48;
 printf("Enter number: "); scanf("%d",&n);
 while(n!=0)
 {
  b[32-1-(i++)]=48+(n%2);
  n/=2;
 }
 
 for(int i=0,j=31;i<4;i++,j-=8)
  for(int k=0;k<8;k++)
   s[i]+= (b[j-k]-48)*pow(10,k);
//  s[i]=(b[j-7]-48)*pow(10,7)+(b[j-6]-48)*pow(10,6)+(b[j-5]-48)*pow(10,5)+(b[j-4]-48)*pow(10,4)+(b[j-3]-48)*pow(10,3)+(b[j-2]-48)*pow(10,2)+(b[j-1]-48)*10+(b[j]-48);
 
 printf("Bit value: ");
 for(int i=0;i<32;i++)
  printf("%c",b[i]);
  
   printf("\n\nindividual bytes (decimal values): ");
 for(int i=0;i<4;i++)
  printf("%d\t",binaryToDecimal(s[i])); 
  
  printf("\n\nindividual bytes (decimal values): ");
 for(n;n!=0;n/=256)
  printf("%d\t",n%256);
  

  printf("\n\n");
}
