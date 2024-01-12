#include<stdio.h>
#include<stdlib.h>

int shellSort(int* x, int lb, int ub)
{
int size = ub-lb+1;
int jump = size/2;
while(jump>=1)
{
//insertion sort code, acting as a skeleton
int e = lb + jump;
while(e<=ub)
{
int f = e-jump;
int temp = x[e];
while(x[f]>=temp && f>=lb)
{
x[f+jump] = x[f];
f = f - jump;
}
x[f+jump] = temp;
e = e + jump;
}
jump/=2;
}
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

shellSort(ptr2arr,0,req-1);

for(i=0;i<req;i++)
{
printf("%d\n",ptr2arr[i]);
}
return 0;
}
