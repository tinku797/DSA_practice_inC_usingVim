#include<stdio.h>
#include<stdlib.h>

int merge(int* x, int* auxArr, int lb1, int ub1, int lb2, int ub2, int* invCount)
{
int i1 = lb1, i2 = lb2, i3 = lb1;
while(i1<=ub1 && i2<=ub2)
{
if(x[i1]<=x[i2])
{
auxArr[i3] = x[i1];
i1++;
i3++;
}
else
{
auxArr[i3] = x[i2];
i2++;
i3++;
*invCount = *invCount + ub1-i1+1;
}
}
while(i1<=ub1)
{
auxArr[i3] = x[i1];
i1++;
i3++;
}
while(i2<=ub2)
{
auxArr[i3] = x[i2];
i2++;
i3++;
}
i3 = lb1;
while(i3<=ub2)
{
x[i3] = auxArr[i3];
i3++;
}
}

int mergeSort(int* x, int* auxArr, int lb, int ub,int* invCount)
{
int mid = lb + ((ub-lb)/2);
if(mid-lb > 0) mergeSort(x, auxArr, lb, mid, invCount);
if(ub-mid+1 > 0) mergeSort(x, auxArr, mid+1, ub,invCount);
merge(x,auxArr,lb,mid,mid+1,ub,invCount);
return 0;
}

int inversionCount(int* x, int lb, int ub)
{
int ic = 0;
int sizeOfGivenArr = ub-lb+1;
int* auxArr = (int*)malloc(sizeof(int)*sizeOfGivenArr);
mergeSort(x,auxArr,lb,ub,&ic);
return ic;
}

int main()
{
int req;
int i;
int data;
int invCount;
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

invCount = inversionCount(ptr2arr,0,req-1);

printf("Inversion count: %d\n",invCount);
for(int i =0;i<req;i++)
{
printf("%d\n",ptr2arr[i]);
}
free(ptr2arr);
return 0;
}
