#include<genericStackWithHeaderNode.h>
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
