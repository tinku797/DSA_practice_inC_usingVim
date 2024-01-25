#include<stdio.h>
#include<stdlib.h>

typedef struct __LLNode
{
int data;
struct __LLNode* next;
}LLNode;

typedef struct __LL
{
LLNode* start;
int size;
}LL;

void initLL(LL* linkedList)
{
linkedList->start = NULL;
linkedList->size = 0;
}

void insertAtEnd(LL* linkedList, int data)
{
LLNode* llNode = (LLNode*)malloc(sizeof(LLNode));
llNode->data = data;
llNode->next = NULL;
if(linkedList->start == NULL)
{
linkedList->start = llNode;
}
else
{
LLNode* temp = linkedList->start;
while(temp->next != NULL)
{
temp = temp->next;
}
temp->next = llNode;
}
linkedList->size++;
}

void insertAtStart(LL* linkedList, int data)
{
LLNode* llNode = (LLNode*)malloc(sizeof(LLNode));
llNode->data = data;
llNode->next = linkedList->start;
linkedList->start = llNode;
linkedList->size++;
}

//code to insert at nth place.
void insertAtnthPlace(LL* linkedList, int data, int n)
{
if(n==1)
{
insertAtStart(linkedList, data);
return;
}
LLNode* temp = linkedList->start;
int count = 1;
while(count<=n-2 && temp != NULL)
{
temp = temp->next;
count++;
}
if(count != n-1 || temp == NULL) //means cannot insert at nth place, cause there are not n-1 nodes in the LL to begin with.
{
printf("Cannot insert at nth place, cause there are not n-1 nodes in the LL to begin with.\n");
return;
}
LLNode* llNode = (LLNode*)malloc(sizeof(LLNode));
llNode->data = data;
llNode->next = temp->next;
temp->next = llNode;
linkedList->size++;
}

//code to insert at correct place in sorted ascending order
void insertInSortedOrder(LL* linkedList, int data)
{
LLNode* temp = linkedList->start;
LLNode* beforeTemp = NULL;
LLNode* llNode = (LLNode*)malloc(sizeof(LLNode));
llNode->data = data;
while(temp != NULL && temp->data <= data)
{
beforeTemp = temp;
temp = temp->next;
}
//now, there can be no elements in the linkedList, or temp has reached NULL after the end of the linkedList
if(temp == NULL && beforeTemp == NULL) //it means the LL is empty, and we are inserting the first element.
{
linkedList->start = llNode;
llNode->next = NULL;
linkedList->size++;
}
else if(temp != NULL && beforeTemp == NULL) //it means we are inserting at he beginning of a non-empty list.
{
llNode->next = linkedList->start;
linkedList->start = llNode;
linkedList->size++;
}
else if(temp == NULL && beforeTemp != NULL) //it means we are inserting at the end of the list.
{
beforeTemp->next = llNode;
llNode->next = NULL;
linkedList->size++;
}
else if(temp != NULL && beforeTemp != NULL) //it means we are inserting somewhere in the middle of the list.
{
llNode->next = beforeTemp->next;
beforeTemp->next = llNode;
linkedList->size++;
}
return;
}


//code to delete node at the end.
void deleteNodeAtEnd(LL* linkedList)
{
if(linkedList->start != NULL)
{
LLNode* temp = linkedList->start;
LLNode* tempPrev = NULL;
while(temp->next != NULL)
{
tempPrev = temp;
temp = temp->next;
}
if(tempPrev == NULL) //it means that there is only one node in the linked list
{
linkedList->start = NULL;
free(temp);
}
else //it means there are atleast 2 node in the linked list
{
tempPrev->next = NULL;
free(temp);
}
linkedList->size--;
}
else
{
printf("cannot delete node, since linked list is already empty.\n");
}
}


//code to delete node at the start.
void deleteNodeAtStart(LL* linkedList)
{
if(linkedList->start != NULL)
{
LLNode* temp = linkedList->start;
linkedList->start = linkedList->start->next;
linkedList->size--;
free(temp);
}
else
{
printf("cannot delete node, since linked list is already empty.\n");
}
}

//code to delete node at nth place.


//code to delete all the elements of a linked list.
void deleteFullLL(LL* linkedList)
{
while(linkedList->start != NULL)
{
deleteNodeAtStart(linkedList);
}
}

//code to linear search in a linked list.


//code to reverse a singly linked list.


//code to sort a singly linked list.




void traverseLL(LL* linkedList)
{
LLNode* temp = linkedList->start;
while(temp != NULL)
{
printf("%d\n",temp->data);
temp = temp->next;
}
}


int pigeonHoleSort(int* x, int lb, int ub)
{
int min = lb;
int max = lb;
for(int i=0;i<=ub;i++)
{
if(min>x[i]) min = x[i];
if(max<x[i]) max = x[i];
}
int rangeOfAuxArr = max-min+1;
LL arrOfLL[rangeOfAuxArr];
for(int i=0;i<rangeOfAuxArr;i++)
{
initLL(&arrOfLL[i]);
}
for(int i=lb;i<=ub;i++)
{
insertAtEnd(&arrOfLL[x[i]-min],x[i]);
}
int index = 0;
for(int i=0;i<rangeOfAuxArr;i++)
{
LLNode* temp = arrOfLL[i].start;
while(temp != NULL)
{
x[index] = temp->data;
index++;
temp = temp->next;
}
}
for(int i=0;i<rangeOfAuxArr;i++)
{
deleteFullLL(&arrOfLL[i]);
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

pigeonHoleSort(ptr2arr,0,req-1);

for(i=0;i<req;i++)
{
printf("%d\n",ptr2arr[i]);
}
return 0;
}
