#include<stdio.h>

typedef struct __queue
{
int arr[10];
int rear;
}Queue;

void initQueue(Queue* queue)
{
queue->rear = 0;
}

int isQueueEmpty(Queue* queue)
{
if(queue->rear == 0) return 1;
else return 0;
}

int isQueueFull(Queue* queue)
{
if(queue->rear == 10) return 1;
else return 0;
}

void enqueue(Queue* queue, int data)
{
if(!isQueueFull(queue))
{
queue->arr[queue->rear] = data;
queue->rear++;
}
else printf("Cannot enqueue, cause queue is already full.\n");
}

void dequeue(Queue* queue, int* data)
{
if(!isQueueEmpty(queue))
{
*data = queue->arr[0];
int y = 1;
while(y<=queue->rear-1)
{
queue->arr[y-1] = queue->arr[y];
y++;
}
queue->rear--;
}
else printf("Cannot dequeue, cause queue is empty.\n");
}

int main()
{
Queue q1;
initQueue(&q1);
enqueue(&q1, 10);
enqueue(&q1, 11);
enqueue(&q1, 12);
enqueue(&q1, 13);


int data;
dequeue(&q1,&data);
printf("%d\n",data);
dequeue(&q1,&data);
printf("%d\n",data);
dequeue(&q1,&data);
printf("%d\n",data);
dequeue(&q1,&data);
printf("%d\n",data);
return 0;
}
