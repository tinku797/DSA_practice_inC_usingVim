#include<stdio.h>
#include<stdlib.h>

typedef struct __LLNode
{
int data;
struct __LLNode* next;
struct __LLNode* prev;
}LLNode;

typedef struct __LL
{
LLNode* start;
LLNode* end;
int size;
}LL;

void initLL(LL* linkedList)
{
linkedList->start = NULL;
linkedList->end = NULL;
linkedList->size = 0;
}

void insertInCorrectPlace(LL* linkedList, int data)
{
LL* node = (LL*)malloc(sizeof(LL));
node->data = data;
if(linkedList->start == NULL)
{
linkedList->start = node;
linkedList->end = node;
}
else
{
LL* temp = linkedList->start;
while(temp!=NULL && temp->data < data)
{

}


}



}

int hashFunction(int data, int dcOfLargest)
{
int e = 1;
while(dcOfLargest-1>0)
{
e = e*10;
dcOfLargest--;
}
return data/e;
}

int addrCalcSort(int* x, int lb, int ub)
{
//code to find the largest element in the given array.
int largest = x[lb];
for(int i=lb;i<=ub;i++)
{
if(largest<x[i]) largest = x[i];
}
//code to find the no of digits in the found largest number.
int dc =1;
while(largest>9)
{
dc++;
largest /= 10;
}
//code to create an array of 10 linked lists
LL arrOfLL[10];



//code to find the key for every element through an order preserving hash function.
for(int i=lb;i<=ub;i++)
{
int key = hashFunction(x[i],dc);

}

return 0;
}

int main()
{
int req;
int i;
printf("Enter requirement: ");
scanf("%d",&req);
int* ptr2arr = (int*)malloc(sizeof(int)*req);
if(ptr2arr == NULL)
{
printf("Cannot allocated memory for array.\n");
return 0;
}
for(i=0;i<req;i++)
{
printf("Enter a number: ");
scanf("%d",&ptr2arr[i]);
}

addrCalcSort(ptr2arr,0,req-1);

for(i=0;i<req;i++)
{
printf("%d\n",ptr2arr[i]);
}
return 0;
}
