#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int*x, int size)
{
int m = size - 2;
//printf("Size of x is %d\n",m);
while(m>=0)
{
int e =0;
int f =1;
int temp;
while(e<=m)
{
if(x[e]>x[f])
{
temp = x[e];
x[e] = x[f];
x[f] = temp;
}
e++;
f++;
}
m--;
}
}

int main()
{
//int x[5] = {13,-2,-3,15,16};
int size;
printf("Enter the size of the array: ");
scanf("%d",&size);
int* x = (int*)malloc(sizeof(int)*size);
if(x==NULL)
{
printf("Cannot allocate memory for %d integers",size);
return 0;
}
int j;
for(j=0;j<size;j++)
{
printf("Enter a number: ");
scanf("%d",&x[j]);
}

bubbleSort(x,size);

for(j=0;j<size;j++)
{
printf("%d\n",x[j]);
}
return 0;
}
