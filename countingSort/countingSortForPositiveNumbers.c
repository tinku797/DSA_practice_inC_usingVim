#include<stdio.h>
#include<stdlib.h>

int countingSort(int* x, int lb, int ub)
{
int largest = x[lb];
for(int i =lb;i<=ub;i++)
{
if(largest<x[i]) largest = x[i];
}
int* ptr2auxArr = (int*)malloc(sizeof(int)*(largest+1));
for(int i =0;i<=largest;i++)
{
ptr2auxArr[i] = 0;
}
for(int i = lb;i<=ub;i++)
{
ptr2auxArr[x[i]]++;
}
int e = 0;
for(int i =0;i<=largest;i++)
{
while(ptr2auxArr[i]!=0)
{
x[e] = i;
ptr2auxArr[i]--;
e++;
}
}
return 0;
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

countingSort(ptr2arr,0,req-1);

for(i=0;i<req;i++)
{
printf("%d\n",ptr2arr[i]);
}
return 0;
}
