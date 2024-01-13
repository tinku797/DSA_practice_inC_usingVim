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
for(int i =0;i<100;i++)
{
insertAtEnd(&linkedList1,i);
}
traverseLL(&linkedList1);
return 0;
}