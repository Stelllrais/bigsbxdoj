#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a,const void *b)
{
	return (*(char *)a) - (*(char *)b);
}

int main(){
	
	char str1[100];
	
	scanf("%s",&str1);
	
	char x = str1[0];
	
	int len = strlen(str1);
	if (str1[len - 1] == '\n') {
        str1[len - 1] = '\0';
        len--;
    }
	char str2[100];
	int ji1= 0;
	char str3[100];
	int ji2 = 0;
	for(int i = 1;i<len;i++)
	{
		if(str1[i] > x)
		{
			str2[ji1] = str1[i];
			ji1++;
		}
		if(str1[i] <= x)
		{
			str3[ji2] = str1[i];
			ji2++;
		}
	}
	
	qsort(str3,ji2,sizeof(char),compare);
	
	
	for(int i = 0;i<ji1;i++)
	{
		putchar(str2[i]);
	}
	putchar(x);
	
	for(int i = 0;i<ji2;i++)
	{
		putchar(str3[i]);
	}
	return 0;
}

