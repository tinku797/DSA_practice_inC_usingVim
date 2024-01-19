#include<stdio.h>
#include<stdlib.h>

int stoogeSort(int* x, int lb, int ub)
{
printf("Called stoogeSort(%d,%d)\n",lb,ub);
if(x[lb]>x[ub])
{
int temp = x[lb];
x[lb] = x[ub];
x[ub] = temp;
}
int size = ub-lb+1;
if(size > 2)
{
/*
int twoThird = (size) - ((size)/3); //kelkar sir's trick to get 2/3 ceiling of a number.
stoogeSort(x, lb, twoThird -1);
stoogeSort(x, ub-(twoThird-1), ub);
stoogeSort(x, lb, twoThird -1);
*/
int oneThird = (size)/3; //kelkar sir's trick to get 2/3 ceiling of a number.
stoogeSort(x, lb,  ub-oneThird);
stoogeSort(x, lb+oneThird, ub);
stoogeSort(x, lb,  ub-oneThird);

}
return 0;
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

stoogeSort(ptr2arr,0,req-1);

for(i=0;i<req;i++)
{
printf("%d\n",ptr2arr[i]);
}
return 0;
}
