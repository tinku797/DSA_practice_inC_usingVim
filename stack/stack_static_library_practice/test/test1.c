#include<genericStackWithHeaderNode.h>
int main()
{
//remember that we cannot initialize the member variables of a structure, at the time of definition, as those variables don't exist yet.
stack s1;
init(&s1,sizeof(int));

int x = 241;
int y = 421;
int success, errorno;
push(&s1,&x,&success,&errorno);
printf("success: %d, errorno: %d\n",success,errorno);
push(&s1,&y,&success,&errorno);
printf("success: %d, errorno: %d\n",success,errorno);

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
printf("success: %d, errorno: %d\n",success,errorno);
printf("popped data:%d\n",data);
}

return 0;
}
