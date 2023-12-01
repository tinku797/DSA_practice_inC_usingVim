#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int bubbleSort(int*x, int size, int elementSize, int (*func)(void* a, void* b))
{
int m = size - 2;
void* v = malloc(elementSize);
if(v==NULL)
{
printf("Unable to allocate memory for an element of element size %d",elementSize);
return -1;
}
printf("Size of an element is %d\n",elementSize);
while(m>=0)
{
int e =0;
int f =1;
int temp;
while(e<=m)
{
int bool = func(&x[e], &x[f]);
if(bool > 0)
{
memcpy(v,&x[e],elementSize);
memcpy(&x[e],&x[f],elementSize);
memcpy(&x[f],v,elementSize);
}
e++;
f++;
}
m--;
}
return 1;
}

int intComparator(void* a, void* b)
{
int* ptr1 = (int*)a;
int* ptr2 = (int*)b;
return *ptr1-*ptr2;
}

int main()
{
//int x[5] = {13,-2,-3,15,16};
int size;
int resultForBubbleSort;
printf("Enter the size of the array: ");
scanf("%d",&size);
int* x = (int*)malloc(sizeof(int)*size);
if(x==NULL)
{
printf("Cannot allocate memory for %d integers",size);
return 0;
}
int j;
for(j=0;j<size;j++)
{
printf("Enter a number: ");
scanf("%d",&x[j]);
}

resultForBubbleSort = bubbleSort(x,size,sizeof(int), intComparator);
if(resultForBubbleSort !=1)
{
printf("Unable to sort");
return 0;
}

for(j=0;j<size;j++)
{
printf("%d\n",x[j]);
}
return 0;
}
