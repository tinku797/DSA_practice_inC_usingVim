#include<stdio.h>
#include<stdlib.h>

int calledCount;

int __dynamicProgPowerFunc(int base, int exp, int* results)
{
calledCount++;
if(exp == 0)
{
results[exp] = 1;
return results[exp];
}
if(results[exp] != 0)
{
return results[exp];
}
else
{
int temp = __dynamicProgPowerFunc(base,exp/2, results);
if(exp%2 == 0)
{
results[exp] = temp*temp;  
}
else if(exp%2 == 1)
{
results[exp] = base*temp*temp;
}
return results[exp];
}
}

int dynamicProgPowerFunc(int base, int exp)
{
int* results = (int*)malloc(sizeof(int)*(exp+1));
for(int i=0;i<exp+1;i++)
{
results[i] = 0;
}
calledCount = 0;
int temp = __dynamicProgPowerFunc(base,exp,results);
free(results);
printf("calledCount = %d\n",calledCount);
return temp;
}

int main()
{
int base, exp;
printf("Enter the base: ");
scanf("%d",&base);
printf("Enter the exponent: ");
scanf("%d",&exp);
int result = dynamicProgPowerFunc(base,exp);
printf("Result is: %d\n",result);
return 0;
}
