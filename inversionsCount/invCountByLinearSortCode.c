#include<stdio.h>
#include<stdlib.h>

int inversionCount(int* x, int lb, int ub)
{
int invCount = 0;
for(int i = 0;i<=ub-1;i++)
{
for(int j = i+1;j<=ub;j++)
{
if(x[i]>x[j]) invCount++;
}
}
return invCount;
}

int main()
{
int req;
int i;
int data;
int invCount;
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

invCount = inversionCount(ptr2arr,0,req-1);

printf("Inversion count: %d",invCount);
return 0;
}
