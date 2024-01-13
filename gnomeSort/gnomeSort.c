#include<stdio.h>
#include<stdlib.h>

int gnomeSort(int* x, int lb, int ub)
{
int j =1;
while(j<ub+1)
{
while(x[j] < x[j-1])
{
int temp = x[j];
x[j] = x[j-1];
x[j-1] = temp;
j--;
}
j++;
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

gnomeSort(ptr2arr,0,req-1);

for(i=0;i<req;i++)
{
printf("%d\n",ptr2arr[i]);
}
return 0;
}
