#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int intComp(void*a, void*b)
{
int* num1 = (int*)a;
int* num2 = (int*)b;
return (*num1)-(*num2);
}

int merge(void*x,void*y,int lb1, int ub1, int lb2, int ub2,int es, int (*func)(void*a,void*b))
{
int i1 = lb1;
int i2 = lb2;
int i3 = lb1;
while(i1<=ub1 && i2<=ub2)
{
if(func(x+(i1*es),x+(i2*es)) <= 0) //change to if(func(x+(i1*es),x+(i2*es)) <= 0)
{
memcpy(y+(i3*es),x+(i1*es),es);  //change to memcpy(y+(i3*es),x+(i1*es),es);
i1++;
i3++;
}
else
{
memcpy(y+(i3*es),x+(i2*es),es);  //change to memcpy(y+(i3*es),x+(i2*es));
i2++;
i3++;
}
}
while(i1<=ub1)
{
memcpy(y+(i3*es),x+(i1*es),es);  //change to memcpy(y+(i3*es),x+(i1*es),es);
i1++;
i3++;
}
while(i2<=ub2)
{
memcpy(y+(i3*es),x+(i2*es),es);  //change to memcpy(y+(i3*es),x+(i2*es));
i2++;
i3++;
}
i3 = lb1;
while(i3<=ub2)
{
memcpy(x+(i3*es),y+(i3*es),es);   //change to memcpy(x+(i3*es),y+(i3*es),es);
i3++;
}
//printf("Done %d %d %d %d\n",lb1,ub1,lb2,ub2);
return 1;
}

int mergeSort(void*x,void*y,int lb,int ub,int es, int (*func)(void*a,void*b))
{
int mid = (lb+ub)/2;
if(lb<mid)
{
//printf("Calling mergeSort for %d,%d\n",lb,mid);
mergeSort(x,y,lb,mid,es,func);
}
if(mid+1<ub)
{
//printf("Calling mergeSort for %d,%d\n",mid+1,ub);
mergeSort(x,y,mid+1,ub,es,func);
}
return merge(x,y,lb,mid,mid+1,ub,es,func);
}

int main()
{
int req;
int i;
int resultOfMergeSort;
printf("Enter your requirement: ");
scanf("%d",&req);
int* ptr2arr = (int*)malloc(sizeof(int)*req);
int* auxArr = (int*)malloc(sizeof(int)*req);
if(ptr2arr == NULL || auxArr == NULL)
{
printf("Cannot allocate memory.\n");
return 0;
}

for(i=0;i<req;i++)
{
printf("Enter a number: ");
scanf("%d",&ptr2arr[i]);
}

resultOfMergeSort = mergeSort(ptr2arr,auxArr,0,req-1,sizeof(int),intComp);
if(resultOfMergeSort != 1)
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
