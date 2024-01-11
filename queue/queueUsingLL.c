#include<stdio.h>
#include<stdlib.h>

typedef struct __queueNode
{
int data;
struct __queueNode* next;
}QueueNode;

typedef struct __queue
{
QueueNode* start;
QueueNode* end;
int size;
}Queue;

void initQueue(Queue* queue)
{
queue->start = NULL;
queue->end = NULL;
queue->size = 0;
}

int isQueueEmpty(Queue* queue)
{
if(queue->start == NULL) return 1;
else return 0;
}

void enqueue(Queue* queue, int data)
{
QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
node->data = data;
node->next = NULL;
if(queue->start != NULL)
{
queue->end->next = node;
queue->end = node;
}
else
{
queue->start = node;
queue->end = node;
}
}

void dequeue(Queue* queue, int* ptr2data)
{
if(!isQueueEmpty(queue))
{
*ptr2data = queue->start->data;
QueueNode* temp = queue->start;
queue->start = queue->start->next;
if(queue->start == NULL) queue->end = NULL;
free(temp);
}
else printf("Cannot dequeue, cause queue is empty.\n");
}

int main()
{
Queue q1;
initQueue(&q1);
for(int i=0;i<10;i++) enqueue(&q1,i);
for(int i=0;i<10;i++)
{
int data;
dequeue(&q1,&data);
printf("%d\n",data);
}
return 0;
}
