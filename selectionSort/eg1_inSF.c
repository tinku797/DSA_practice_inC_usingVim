#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int intComparator(void* a, void*b)
{
int* num1 = (int*)a;
int* num2 = (int*)b;
return *num1 - *num2;
}

int selectionSort(void* ptr2arr,int size, int elementSize,int (*func)(void*a, void*b))
{
void* temp = malloc(elementSize);
if(temp == NULL)
{
printf("Cannot allocate memory for an element of size %d bytes",elementSize);
return 0;
}

//code for selection sort
int e = 0;
while(e<=size-2)
{
int f = e+1;
int min = e;

void* ptrToE = ptr2arr + (elementSize*e);
void* ptrToMin = ptr2arr + (elementSize*min);
void* ptrToF = ptr2arr + (elementSize*f);

while(f<=size-1)
{
if(func(ptrToMin,ptrToF) > 0)
{
min = f;
ptrToMin = ptr2arr + (elementSize*min);
}
f++;
ptrToF = ptr2arr + (elementSize*f);
}
memcpy(temp,ptrToE, elementSize);
memcpy(ptrToE, ptrToMin, elementSize);
memcpy(ptrToMin, temp, elementSize);
e++;
}

free(temp);
return 1;
}

int main()
{
//data entry code
int size;
int i;
int resultOfSelectionSort;
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

resultOfSelectionSort = selectionSort(ptr2arr, size, sizeof(int), intComparator);
if(resultOfSelectionSort != 1)
{
printf("Unable to sort");
return 0;
}

//code to print sorted array
printf("Sorted array is-\n");
for(i=0;i<size;i++)
{
printf("%d\n",ptr2arr[i]);
}

free(ptr2arr);
return 0;
}
