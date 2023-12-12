#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
int rollNumber;
char name[20];
};

int studCompByRoll(void* a, void* b)
{
struct student* stud1 = (struct student*)a;
struct student* stud2 = (struct student*)b;
return (stud1->rollNumber) - (stud2->rollNumber);
}

int studCompByName(void* a, void* b)
{
struct student* stud1 = (struct student*)a;
struct student* stud2 = (struct student*)b;
return strcmp(stud1->name,stud2->name);
}

int intComparator(void* a, void* b)
{
int* num1 = (int*)a;
int* num2 = (int*)b;
return (*num1)-(*num2);
}

int insertionSort(void* ptr2arr, int size, int elementSize, int (*func)(void*a, void*b))
{

void* tempElement = malloc(elementSize);
if(tempElement == NULL)
{
printf("Unable to allocate memory for the temporary swapping element for size %d bytes\n",elementSize);
return 0;
}

int e = 0;
while(e<=size-1)
{
int f = e-1;
memcpy(tempElement,ptr2arr + (elementSize*e),elementSize);   
while(f>=0 && func(ptr2arr + (elementSize*f),tempElement) >= 0)    
{
memcpy(ptr2arr + (elementSize*(f+1)), ptr2arr + (elementSize*f), elementSize);
f--;
}
memcpy(ptr2arr + (elementSize*(f+1)), tempElement, elementSize);
e++;
}

free(tempElement);
return 1;
}

int main()
{
//data entry code
int size;
int i;
int result_of_insertion_sort;
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
result_of_insertion_sort = insertionSort(ptr2arr,size, sizeof(int), intComparator);
if(result_of_insertion_sort != 1)
{
printf("Unable to sort\n");
return 0;
}

//result of sorting display code
for(i=0;i<size;i++)
{
printf("%d\n",ptr2arr[i]);
}

free(ptr2arr);
return 0;
}
