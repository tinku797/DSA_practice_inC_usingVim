#include<stdio.h>
#include<stdlib.h>

int binarySearch(int* x, int lb, int ub, int data)
{
int si = lb;
int li = ub;
while(si<=li)
{
int mid = si + (li-si)/2;
if(x[mid] == data) return mid;
else if(x[mid]>data)
{
li = mid-1;
}
else if(x[mid]<data)
{
si = mid+1;
}
}
return -1;
}

int main()
{
int req;
int i;
int data;
int resultOfBS;
printf("Enter requirement: ");
scanf("%d",&req);
int* ptr2arr = (int*)malloc(sizeof(int)*req);
if(ptr2arr == NULL)
{
printf("Cannot allocated memory for array.\n");
return 0;
}
printf("Enter a sorted sequence.\n");
for(i=0;i<req;i++)
{
printf("Enter a number: ");
scanf("%d",&ptr2arr[i]);
}

printf("Enter a number to search for: ");
scanf("%d",&data);

resultOfBS = binarySearch(ptr2arr,0,req-1,data);

if(resultOfBS != -1)
{
printf("Number found at index %d\n",resultOfBS);
}
else printf("Number not found\n");
return 0;
}
