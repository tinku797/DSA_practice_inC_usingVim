#include <stdio.h>
int main()
{
// data entry code
int arr[5] = {4,-2,1,3,0};
int j;

// bubble sort code
int e = 0;
while(e<=3)
{
int f = e+1;
while(f<=4)
{
if(arr[e] > arr[f])
{
int temp = arr[e];
arr[e] = arr[f];
arr[f] = temp;
}
f++;
}
e++;
}

for(j=0;j<5;j++)
{
printf("%d\n",arr[j]);
}

return 0;
}
