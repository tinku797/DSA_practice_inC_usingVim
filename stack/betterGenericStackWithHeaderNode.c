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

void init(stack*s,int elementSize) //int* success and int* errorno not needed in init() and isEmpth() since these are simple functions not involving any i/o operations
{
s->top = NULL;
s->size = 0;
s->elementSize = elementSize;
}

void push(stack*s,void* addrOfDataToCopy,int* success,int* errorno)
{
if(success != NULL) *success = 0; //assumed unsuccessful by default.
if(errorno != NULL) *errorno = 100; //errorno 100 for push(), can be set in doc to - function not fully executed.
if(s == NULL)
{
if(errorno != NULL) *errorno = 2; //errorno 2 for push(), can be set in doc to - cannot accept NULL as argument for the parameter stack*s.
return;
}
if(addrOfDataToCopy == NULL)
{
if(errorno != NULL) *errorno = 3; //errorno 3 for push(), can be set in doc to - cannot accept NULL as argument for the parameter void* addrOfDataToCopy. 
return;
}
node* temp = (node*)malloc(sizeof(node));
if(temp == NULL)
{
// printf("Unable to allocate memory to push new data into the stack\n"); -- no print statement should be written in a library function. Use success and errorno instead
// *success = 0; --not really needed as *success is already set to 0 by default.
if(errorno != NULL) *errorno = 1;    //errorno 1 for push(), can be set in doc to - cannot allocate memory.
return;
}
else
{
void* p2d = malloc(s->elementSize);
memcpy(p2d,addrOfDataToCopy,s->elementSize);
temp->ptr2data = p2d;
temp->next = s->top;
s->top = temp;
s->size++;
if(success != NULL) *success = 1;
if(errorno != NULL) *errorno = 0;   //errorno 0 for push(), can be set in doc to - no error, operation successful.
}
}

int isEmpty(stack*s)
{
if(s->top == NULL) return 1;
else return 0;
}

void pop(stack*s,void* addrOfVarToCopyDataTo,int* success,int* errorno)  //could even change int* success and int* errorno to unsigned int* success, and unsigned int* errorno
{
if(success != NULL) *success = 0;  //by default, assumed unsuccessful.
if(errorno != NULL) *errorno = 100;  //errorno 100 for pop(), could be set in documentation to - full function execution could not be completed.
if(s == NULL)
{
if(errorno != NULL) *errorno = 2; //errorno 2 for pop(), can be set in doc to - cannot accept NULL as argument for the parameter stack*s.
return;
}
if(addrOfVarToCopyDataTo == NULL)
{
if(errorno != NULL) *errorno = 3; //errorno 3 for pop(), can be set in doc to - cannot accept NULL as argument for the parameter void* addrOfDataToCopy. 
return;
}
if(!isEmpty(s))
{
void* p2d = s->top->ptr2data;
memcpy(addrOfVarToCopyDataTo,s->top->ptr2data,s->elementSize); //one of the reasons why elementSize is required as a data member for generic stack
node* temp = s->top;
s->top = s->top->next;
free(p2d);
free(temp);
s->size--;
if(success != NULL) *success = 1;
if(errorno != NULL) *errorno = 0;  //errorno 0 for pop(), could be set in doc to - no error, operation successful.
}
else
{
// *returnedPtr2data = NULL; -- not really required 
// *success = 0; --not really needed as *success is already set to 0 by default above.
if(errorno != NULL) *errorno = 1;  //errorno 1 for pop(), could be set to in documentation to - stack is empty, hence cannot pop.
}
}



int main()
{
//remember that we cannot initialize the member variables of a structure, at the time of definition, as those variables don't exist yet.
stack s1;
init(&s1,sizeof(int));

int x = 241;
int y = 421;
int success, errorno;
push(&s1,&x,&success,&errorno);
printf("success: %d, errrorno: %d\n",success,errorno);
push(&s1,&y,&success,&errorno);
printf("success: %d, errrorno: %d\n",success,errorno);

/*
for(int i=0;i<899;i++)
{
printf("Popped data from stack: %d\n",*(pop(&s1)));
}
*/

while(!isEmpty(&s1))
{
int data;
pop(&s1,&data,&success,&errorno);
printf("success: %d, errrorno: %d\n",success,errorno);
printf("popped data:%d\n",data);
}

return 0;
}
