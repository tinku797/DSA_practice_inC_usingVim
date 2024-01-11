#include<stdio.h>
#include<stdlib.h>

int heapSort(int* x, int lb, int ub)
{
//creating a max heap from scratch code
int y = lb+1;
while(y<=ub)
{
int ci = y;
int ri = (ci-1)/2;
while(ri>=lb)       //this could be a bug
{
if(x[ci]>x[ri])
{
int temp = x[ci];
x[ci] = x[ri];
x[ri] = temp;
ci = ri;
ri = (ci-1)/2;
}
else break;
}
y++;
}
return 1;
}

int main()
{
int req;
int i;
printf("Enter requirement: ");
scanf("%d",&req);
int* ptr2arr = (int*)malloc(sizeof(int)*req);
if(ptr2arr == NULL)
{
printf("Cannot allocated memory for array.\n");
return 0;
}
for(i=0;i<req;i++)
{
printf("Enter a number: ");
scanf("%d",&ptr2arr[i]);
}

heapSort(ptr2arr,0,req-1);

for(i=0;i<req;i++)
{
printf("%d\n",ptr2arr[i]);
}

return 0;
}
