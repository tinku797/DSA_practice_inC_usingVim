#include <stdio.h>
#include <stdlib.h>
int main()
{
//data entry code
int size;
int i;
printf("Please enter your requiremenet/size of the array: ");
scanf("%d",&size);
if(size<=0)
{
printf("Entered requirement is invalid");
return 0;
}
int* ptr2arr = (int*)malloc(sizeof(int)*size);
if(ptr2arr == NULL)
{
printf("Cannot allocate memory for %d integers",size);
return 0;
}
for(i=0;i<size;i++)
{
printf("Enter a number: ");
scanf("%d",&ptr2arr[i]);
}

//code for selection sort
int e = 0;
while(e<=size-2)
{
int f = e+1;
int min = e;
while(f<=size-1)
{
if(ptr2arr[f] < ptr2arr[min])
{
min = f;
}
f++;
}
int temp = ptr2arr[e];
ptr2arr[e] = ptr2arr[min];
ptr2arr[min] = temp;
e++;
}
//code to print sorted array
printf("Sorted array is-\n");
for(i=0;i<size;i++)
{
printf("%d\n",ptr2arr[i]);
}
return 0;
}
