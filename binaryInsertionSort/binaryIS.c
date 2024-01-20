#include <stdio.h>
#include <stdlib.h>

int binaryIS(int* x, int lb, int ub)
{
int e = 0;
while(e<=ub)
{
int f = e-1;
int temp = x[e];
//binary search code to find index to insert at
int si = lb;
int li = f;
while(si<=li)
{
int mid = si + (li-si)/2;
if(x[mid] == temp || x[mid]<temp) si = mid+1;
else if(x[mid]>temp) li = mid-1; 
}
int posToInsertAt = si;
//code to shift all the elements after from  the insertion index to e-1 to the right
while(f>=posToInsertAt)
{
x[f+1] = x[f];
f--;
}
x[f+1] = temp;
e++;
}
return 1;
}

int main()
{
//data entry code
int size;
int i;
int result_of_insertion_sort;
printf("Enter your requirement: ");
scanf("%d",&size);
if(size<=0)
{
printf("Invalid requirement");
return 0;
}
int* ptr2arr = (int*)malloc(sizeof(int)*size);
if(ptr2arr == NULL)
{
printf("Unable to allocate memory for %d elements",size);
return 0;
}
for(i=0;i<size;i++)
{
printf("Enter a number: ");
scanf("%d",&ptr2arr[i]); 
}

//insertion sort code
result_of_insertion_sort = binaryIS(ptr2arr,0,size-1);
if(result_of_insertion_sort != 1)
{
printf("Unable to sort\n");
return 0;
}

//result of sorting display code
for(i=0;i<size;i++)
{
printf("%d\n",ptr2arr[i]);
}

free(ptr2arr);
return 0;
}
