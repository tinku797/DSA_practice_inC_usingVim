#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
int data;
struct node* next;
};

int main()
{
struct node* top = NULL;
void push(int data)
{
struct node* temp = (struct node*)malloc(sizeof(struct node));
if(temp == NULL)
{
printf("Unable to allocate memory to push new data into the stack\n");
}
else
{
temp->data = data;
temp->next = top;
top = temp;
}
}

int pop()
{
int data = top->data;
struct node* temp = top;
top = top->next;
free(temp);
return data;
}

int isEmpty()
{
if(top == NULL)
{
return 1;
}
else return 0;
}

//pushing data into the stack now
for(int i =100;i<999;i++)
{
push(i);
}

for(int i=0;i<899;i++)
{
printf("Popped data from stack: %d\n",pop());
}

return 0;
}
