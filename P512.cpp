#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


typedef struct BOOK
{
	char name[30];
	float cnt = 0;
}book;

int compare(const void *a,const void *b)
{
	BOOK *s1 = (BOOK *)a;
	BOOK *s2 = (BOOK *)b;
	return s1->cnt-s2->cnt;
}

int main(){
	
	int n =0;
	scanf("%d",&n);
	
	book a[10];
	for(int i = 0;i<n;i++)
	{
		getchar();
		fgets(a[i].name,30,stdin);
		scanf("%f",&a[i].cnt);
		
	}
	
	qsort(a,n,sizeof(BOOK),compare);
	
	printf("%.2f,%s\n",a[n-1].cnt,a[n-1].name);
	printf("%.2f,%s\n",a[0].cnt,a[0].name);
	
	return 0;
}

