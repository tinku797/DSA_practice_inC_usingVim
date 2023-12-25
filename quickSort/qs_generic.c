#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int intComp(void*a, void*b)
{
int*num1 = (int*)a;
int*num2 = (int*)b;
return (*num1)-(*num2);
}

int partition(void*x, int lb, int ub, int es, int (*func)(void*a, void*b))
{
int e = lb;
int f = ub;
void*temp = malloc(es);

while(e<f)
{
while(func(x+(e*es),x+(lb*es)) <= 0 && e<ub) e++;  //func(x+(e*es),x+(lb*es)) <= 0
while(func(x+(f*es),x+(lb*es)) >0) f--;           //func(x+(f*es),x+(lb*es)) >0
if(e<f)
{
//swap(x[e],x[f]);
memcpy(temp,x+(e*es),es);
memcpy(x+(e*es),x+(f*es),es);
memcpy(x+(f*es),temp,es);
}
else if(e>=f)
{
//swap(x[lb],x[f]);
memcpy(temp,x+(lb*es),es);
memcpy(x+(lb*es),x+(f*es),es);
memcpy(x+(f*es),temp,es);
}
}

return f;
}

int quickSort(void* x,int lb, int ub, int es, int (*func)(void*a, void*b))
{
int f = partition(x,lb,ub, es,func);
if(lb<f-1)
{
quickSort(x,lb,f-1,es,func);
}
if(f+1<ub)
{
quickSort(x,f+1,ub,es,func);
}
return 1;
}

int main()
{
int req;
int i;
int resultOfQS;
printf("Enter your requirement: ");
scanf("%d",&req);
int* ptr2arr = (int*)malloc(sizeof(int)*req);
if(ptr2arr == NULL)
{
printf("Cannot allocate memory for %d integers\n",req);
return 0;
}

for(i=0;i<req;i++)
{
printf("Enter a number: ");
scanf("%d",&ptr2arr[i]);
}

//quickSort((void)ptr2arr, req, sizeof(int), intComparator);
resultOfQS = quickSort(ptr2arr, 0, req-1, sizeof(int), intComp);
if(resultOfQS !=1)
{
printf("Cannot sort\n");
return 0;
}

for(i=0;i<req;i++)
{
printf("%d\n",ptr2arr[i]);
}
return 0;
}
