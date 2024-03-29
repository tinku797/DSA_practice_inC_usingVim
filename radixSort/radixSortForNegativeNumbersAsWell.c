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

int radixSort(int* x, int lb, int ub)
{
//code to segregate negative numbers to the left, and positive numbers to the right of the array.
int left = lb;
while(x[left]<0) left++;
int right = ub;
while(x[right]>=0) right--;
while(left<right)
{
int temp = x[left];
x[left] = x[right];
x[right] = temp;
while(x[left]<0) left++;
while(x[right]>=0) right--;
}

//if(left==lb) //then there are no negative numbers
//else if(right==ub) //then there are no positive numbers
int lastNegNoIndex = left-1;
int firstPosNoIndex = right+1; 

if(left!=lb)
{
//code to find the smallestNegNo number in the array
int smallestNegNo = x[lb];
for(int i = lb;i<=lastNegNoIndex;i++)
{
if(smallestNegNo > x[i]) smallestNegNo = x[i];
}

//code to find the number of digits in the smallestNegNo number
int dc = 1;
while((smallestNegNo * -1)>9)
{
dc++;
smallestNegNo = smallestNegNo/10;
}


//code to create and initialize 10 queues
Queue queue[10];
for(int i=0;i<10;i++)
{
initQueue(&queue[i]);
}

//code to enqueue the values into the queues,based on the place values increasing by a factor of 10, then dequeue into the original array, and repeating this process dc no of times.
int e = 10;
int f = 1;
for(int i=0;i<dc;i++)
{
for(int j=lb;j<=lastNegNoIndex;j++)
{
int placeValue = -1*((x[j]%e)/f);
enqueue(&queue[placeValue],x[j]);
}
int temp = lb;
for(int k=0;k<10;k++)
{
while(!isQueueEmpty(&queue[k]))
{
int data;
dequeue(&queue[k],&data);
x[temp] = data;
temp++;
}
}
e*=10;
f*=10;
}

//code to reverse the negative part of the array, to get it in ascending order.
int start = lb;
int end = lastNegNoIndex;
while(start<end)
{
int temp = x[start];
x[start] = x[end];
x[end] = temp;
start++;
end--;
}

}

if(right!=ub)
{

//code to find the largest number in the array
int largest = x[firstPosNoIndex];
for(int i = firstPosNoIndex;i<=ub;i++)
{
if(largest < x[i]) largest = x[i];
}


//code to find the number of digits in the largest number
int dc = 1;
while(largest>9)
{
dc++;
largest = largest/10;
}

//code to create and initialize 10 queues
Queue queue[10];
for(int i=0;i<10;i++)
{
initQueue(&queue[i]);
}

//code to enqueue the values into the queues,based on the place values increasing by a factor of 10, then dequeue into the original array, and repeating this process dc no of times.
int e = 10;
int f = 1;
for(int i=0;i<dc;i++)
{
for(int j=firstPosNoIndex;j<=ub;j++)
{
int placeValue = (x[j]%e)/f;
enqueue(&queue[placeValue],x[j]);
}
int temp = firstPosNoIndex;
for(int k=0;k<10;k++)
{
while(!isQueueEmpty(&queue[k]))
{
int data;
dequeue(&queue[k],&data);
x[temp] = data;
temp++;
}
}
e*=10;
f*=10;
}
}

return 1;
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

radixSort(ptr2arr,0,req-1);

for(i=0;i<req;i++)
{
printf("%d\n",ptr2arr[i]);
}
return 0;
}
