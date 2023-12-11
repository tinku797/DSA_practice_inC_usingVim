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
struct student* ptr2arr = (struct student*)malloc(sizeof(struct student)*size);
if(ptr2arr == NULL)
{
printf("Cannot allocate memory for %d integers",size);
return 0;
}
for(i=0;i<size;i++)
{
printf("Enter a roll number of the student: ");
scanf("%d",&(ptr2arr[i].rollNumber));
printf("Enter the name of the student: ");
scanf("%s", &(ptr2arr[i].name));
}

resultOfSelectionSort = selectionSort(ptr2arr, size, sizeof(struct student), studCompByRoll);
if(resultOfSelectionSort != 1)
{
printf("Unable to sort");
return 0;
}

//code to print sorted array
printf("Sorted array is-\n");
for(i=0;i<size;i++)
{
printf("%d %s\n",ptr2arr[i].rollNumber, ptr2arr[i].name);
}

free(ptr2arr);
return 0;
}
