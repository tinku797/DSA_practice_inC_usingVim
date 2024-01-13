#include<stdio.h>
#include<stdlib.h>

int oddEvenSort(int* x, int lb, int ub)
{
int swapFlag = 1;
while(swapFlag == 1)
{
swapFlag = 0;
int odd = 1;
int even = 0;
while(odd+1 <=ub)
{
if(x[odd+1]<x[odd])
{
int temp = x[odd];
x[odd] = x[odd+1];
x[odd+1] = temp;
swapFlag = 1;
}
odd += 2;
}
while(even+1<=ub)
{
if(x[even+1]<x[even])
{
int temp = x[even];
x[even] = x[even+1];
x[even+1] = temp;
swapFlag = 1;
} 
even += 2;
}
}
}

int main()
{
int req;
int i;
printf("Enter requirement: ");
scanf("%d",&req);
int* ptr2arr = (int*)malloc(sizeof(int)*req);
if(ptr2arr == NULL)
{
printf("Cannot allocated memory for array.\n");
return 0;
}
for(i=0;i<req;i++)
{
printf("Enter a number: ");
scanf("%d",&ptr2arr[i]);
}

oddEvenSort(ptr2arr,0,req-1);

for(i=0;i<req;i++)
{
printf("%d\n",ptr2arr[i]);
}
return 0;
}
