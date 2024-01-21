#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void _printAllComb(char* seed, char* x, int sizeOfArr, int maxLength)
{
if(maxLength==0)
{
printf("%s\n",seed);
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
_printAllComb("",x,sizeOfArr,maxLength);
}

int main()
{
char charArr[4] = {'0','1','2','3'};
printAllComb(charArr,4,3);
return 0;
}
