#include<stdio.h>
#include<stdlib.h>

int binarySearch(int* x, int lb, int ub, int data)
{
if(lb == ub)
{
if(x[lb] != data) return -1;
else return lb;
}
int mid = lb + (ub-lb)/2;
if(x[mid] == data)
{
return mid;
}
else if(x[mid]>data)
{
return binarySearch(x,lb,mid-1,data);
}
else if(x[mid]<data)
{
return binarySearch(x,mid+1,ub,data);
}
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
