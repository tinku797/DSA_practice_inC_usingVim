#include <stdio.h>
#include <stdlib.h>
int linearSort(int* x, int size)
{

// linear sort code
int e = 0;
while(e<=size-2)
{
int f = e+1;
while(f<=size-1)
{
if(x[e] > x[f])
{
int temp = x[e];
x[e] = x[f];
x[f] = temp;
}
f++;
}
e++;
}

return 1;
}
int main()
{
// data entry code
//int ptr2arr[5] = {4,-2,1,3,0};
int size;
int j;
int resultOfLinearSort;
printf("Enter the size of array: ");
scanf("%d",&size);
int* ptr2arr = (int*)malloc(sizeof(int)*size);
if(ptr2arr == NULL)
{
printf("Unable to allocate an integer array of size %d\n",size);
return 0;
}

for(j=0;j<size;j++)
{
printf("Enter a number: ");
scanf("%d",&ptr2arr[j]);
}

resultOfLinearSort = linearSort(ptr2arr,size);
if(resultOfLinearSort != 1)
{
printf("Unable to sort");
return 0;
}

for(j=0;j<size;j++)
{
printf("%d\n",ptr2arr[j]);
}
free(ptr2arr);
return 0;
}
