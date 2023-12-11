#include <stdio.h>
#include <stdlib.h>
int main()
{
//data entry code
int size;
int i;
printf("Enter your requirement: ");
scanf("%d",&size);
if(size<=0)
{
printf("Invalid requirement");
return 0;
}
int* ptr2arr = (int*)malloc(sizeof(int)*size);
if(ptr2arr == NULL)
{
printf("Unable to allocate memory for %d elements",size);
return 0;
}
for(i=0;i<size;i++)
{
printf("Enter a number: ");
scanf("%d",&ptr2arr[i]); 
}

//insertion sort code
int e = 0;
while(e<=size-1)
{
int f = e-1;
int temp = ptr2arr[e];
while(f>=0 && ptr2arr[f] >= temp)
{
ptr2arr[f+1] = ptr2arr[f];
f--;
}
ptr2arr[f+1] = temp;
e++;
}

//result of sorting display code
for(i=0;i<size;i++)
{
printf("%d\n",ptr2arr[i]);
}

free(ptr2arr);
return 0;
}
