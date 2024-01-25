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

int main()
{
LL linkedList1;
initLL(&linkedList1);
printf("Insertion nodes into LL\n");
for(int i =0;i<10;i++)
{
insertAtEnd(&linkedList1,i);
}
traverseLL(&linkedList1);
printf("deleting from start\n");
deleteNodeAtStart(&linkedList1);
traverseLL(&linkedList1);
printf("deleting from end\n");
deleteNodeAtEnd(&linkedList1);
traverseLL(&linkedList1);
printf("inserting in sorted order.\n");
insertInSortedOrder(&linkedList1,-1);
traverseLL(&linkedList1);
printf("inserting at nth place\n");
insertAtnthPlace(&linkedList1,10000,10);
traverseLL(&linkedList1);
return 0;
}
