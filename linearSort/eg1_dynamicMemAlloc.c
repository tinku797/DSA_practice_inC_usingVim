#include <stdio.h>
#include <stdlib.h>
int main()
{
// data entry code
//int ptr2arr[5] = {4,-2,1,3,0};
int size;
int j;

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

// linear sort code
int e = 0;
while(e<=size-2)
{
int f = e+1;
while(f<=size-1)
{
if(ptr2arr[e] > ptr2arr[f])
{
int temp = ptr2arr[e];
ptr2arr[e] = ptr2arr[f];
ptr2arr[f] = temp;
}
f++;
}
e++;
}

for(j=0;j<size;j++)
{
printf("%d\n",ptr2arr[j]);
}

return 0;
}
