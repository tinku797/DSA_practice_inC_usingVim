#include<genericStackWithHeaderNode.h>
int main()
{
//remember that we cannot initialize the member variables of a structure, at the time of definition, as those variables don't exist yet.
stack s1;
init(&s1,sizeof(int));

int x = 241;
int y = 421;
push(&s1,&x,NULL,NULL);
push(&s1,&y,NULL,NULL);

/*
for(int i=0;i<899;i++)
{
printf("Popped data from stack: %d\n",*(pop(&s1)));
}
*/

while(!isEmpty(&s1))
{
void* data;
int success, errorno;
pop(&s1,&data,&success,&errorno);
printf("success: %d, errrorno: %d\n",success,errorno);
printf("popped data:%d\n",*(int*)data);
}

return 0;
}
