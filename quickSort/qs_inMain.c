#include<stdio.h>
#include<stdlib.h>

int partition(int*x, int lb, int ub)
{
int e = lb;
int f = ub;

while(e<f)
{
while(x[e]<=x[lb] && e<ub) e++;
while(x[f]>x[lb]) f--;
if(e<f)
{
//swap(x[e],x[f]);
int temp = x[e];
x[e] = x[f];
x[f] = temp;
}
else if(e>=f)
{
//swap(x[lb],x[f]);
int temp = x[lb];
x[lb] = x[f];
x[f] = temp;
}
}

return f;
}

int quickSort(int* x,int lb, int ub)
{
int f = partition(x,lb,ub);
if(lb<f-1)
{
quickSort(x,lb,f-1);
}
if(f+1<ub)
{
quickSort(x,f+1,ub);
}
return 1;
}

int main()
{
int req;
int i;
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
quickSort(ptr2arr, 0, req-1);

for(i=0;i<req;i++)
{
printf("%d\n",ptr2arr[i]);
}
return 0;
}
