#include<stdio.h>
#include<stdlib.h>

int pancakeSort(int* x, int lb, int ub)
{
int e = ub;
while(e>=lb)
{
//code to find the largest number and it's index, till index e.
int largest = x[lb];
int li = 0;
for(int i =0;i<=e;i++)
{
if(largest<x[i])
{
largest = x[i];
li = i;
}
}
//code to reverse from lb to index of largest number.
int start = lb;
int end = li;
while(start < end)
{
int temp = x[start];
x[start] = x[end];
x[end] = temp;
start++;
end--;
}
//code to reverse array till index e.
start = lb;
end = e;
while(start < end)
{
int temp = x[start];
x[start] = x[end];
x[end] = temp;
start++;
end--;
}
e--;
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

pancakeSort(ptr2arr,0,req-1);

for(i=0;i<req;i++)
{
printf("%d\n",ptr2arr[i]);
}
return 0;
}
