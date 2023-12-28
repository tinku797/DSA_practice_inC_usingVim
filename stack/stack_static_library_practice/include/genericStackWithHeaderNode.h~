#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct __node
{
void* ptr2data;
struct __node* next;
}node;

typedef struct __stack
{
node* top;
int size;
int elementSize;
}stack; 

void init(stack*s,int elementSize);

void push(stack*s,void* addrOfDataToCopy,int* success,int* errorno);

int isEmpty(stack*s);

void pop(stack*s,void** returnedPtr2data,int* success,int* errorno);
