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

int kthLargestEle(int* x, int k, int lb, int ub)
{
int size = ub-lb+1;
int* auxArr = (int*)malloc(sizeof(int)*size);
for(int i=0;i<size;i++)
{
auxArr[i] = x[i];
}
shellSort(auxArr,0,size-1);
int kthLar = auxArr[ub-k+1];
free(auxArr);
return kthLar;
}

int main()
{
int req;
int i;
int k;
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
printf("Enter the value of k: ");
scanf("%d",&k);

int result = kthLargestEle(ptr2arr,k,0,req-1);
printf("When k = %d, The kth largest element is: %d",k,result);

return 0;
}
