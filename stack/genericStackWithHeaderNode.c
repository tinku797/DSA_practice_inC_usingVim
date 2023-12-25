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

void init(stack*s,int elementSize)
{
s->top = NULL;
s->size = 0;
s->elementSize = elementSize;
}

void push(void* ptr2data,stack*s)
{
node* temp = (node*)malloc(sizeof(node));
if(temp == NULL)
{
printf("Unable to allocate memory to push new data into the stack\n");
}
else
{
temp->ptr2data = ptr2data;
temp->next = s->top;
s->top = temp;
s->size++;
}
}

void* pop(stack*s)
{
void* ptr2data = s->top->ptr2data;
node* temp = s->top;
s->top = s->top->next;
free(temp);
s->size--;
return ptr2data;
}

int isEmpty(stack*s)
{
if(s->top == NULL) return 1;
else return 0;
}

int main()
{
//remember that we cannot initialize the member variables of a structure, at the time of definition, as those variables don't exist yet.
stack s1;
init(&s1,sizeof(int));

int x = 241;
int y = 421;
push(&x,&s1);
push(&y,&s1);

/*
for(int i=0;i<899;i++)
{
printf("Popped data from stack: %d\n",*(pop(&s1)));
}
*/

while(!isEmpty(&s1))
{
int data = *(int*)pop(&s1);
printf("Popped data from stack:%d\n",data);
}

return 0;
}
