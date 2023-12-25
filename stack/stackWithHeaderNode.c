#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct __node
{
int data;
struct node* next;
}node;

typedef struct __stack
{
node* top;
int size;
}stack; 

void push(int data,stack*s)
{
node* temp = (node*)malloc(sizeof(node));
if(temp == NULL)
{
printf("Unable to allocate memory to push new data into the stack\n");
}
else
{
temp->data = data;
temp->next = s->top;
s->top = temp;
s->size++;
}
}

int pop(stack*s)
{
int data = s->top->data;
node* temp = s->top;
s->top = s->top->next;
free(temp);
s->size--;
return data;
}

int isEmpty(stack*s)
{
if(s->top == NULL) return 1;
else return 0;
}

int main()
{
stack s1;
s1.top = NULL;
s1.size = 0;


//pushing data into the stack now
for(int i =100;i<999;i++)
{
push(i,&s1);
}

/*
for(int i=0;i<899;i++)
{
printf("Popped data from stack: %d\n",pop(&s1));
}
*/

while(!isEmpty(&s1))
{
printf("Popped data from stack:%d\n",pop(&s1));
}

return 0;
}
