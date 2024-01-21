#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int combCount;

void _printAllComb(char* seed, char* x, int sizeOfArr, int maxLength)
{
if(maxLength==0)
{
printf("%s\n",seed);
combCount++;
return;
}
int seedLength = strlen(seed);
char* arr = (char*)malloc(sizeof(char)*(seedLength+2));
strcpy(arr,seed);
for(int i =0;i<sizeOfArr;i++)
{
arr[seedLength] = x[i];
arr[seedLength+1] = '\0';
_printAllComb(arr,x,sizeOfArr,maxLength-1);
}
free(arr);
}

void printAllComb(char* x,int sizeOfArr, int maxLength)
{
combCount = 0;
_printAllComb("",x,sizeOfArr,maxLength);
printf("Total combinations are: %d\n",combCount);
}

int main()
{
/*
char charArr[4] = {'0','1','2','3'};
*/
int req;
printf("Enter the size of the string: ");
scanf("%d",&req);
char* str = (char*)malloc(sizeof(char)*(req+1));
printf("Enter a string: ");
scanf("%s",str);
printAllComb(str,req,req);
return 0;
}
