#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


typedef struct DUI
{
	char name[13] = {0};
	int sheng = 0;
	int cent = 0;
}dui;

int compare(const void *a,const void *b)
{
	DUI *s1 = (DUI*)a;
	DUI *s2 = (DUI *)b;
	if(s1->sheng != s2->sheng)
	{ 
		return s2->sheng - s1->sheng;
	}
	else if(s1->cent != s2->cent)
	{
		return s2->cent - s1->cent;
	}
	else
	{
		return strcmp(s1->name,s2->name);
	}
}


int main(){
	
	int n = 0;
	scanf("%d",&n);
	
	dui a[11];
	
	for(int i = 0;i<n;i++)
	{
		scanf("%s",&a[i].name);
	}
	
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			int ans = 0;
			scanf("%d",&ans);
			
			switch (ans)
			{
				case 5:
				a[i].sheng++;
				a[i].cent+=2;
				break;
				case 4:
				a[i].sheng++;
				a[i].cent+=3;
				break;
				case 3:
				a[i].sheng++;
				a[i].cent+=3;
				break;
				case -5:
				a[i].cent+=1;
				break;
				default:
				break;
			}
		}
	}
			 
			 
			 
	qsort(a,n,sizeof(DUI),compare);
	
	
	for(int i = 0;i<n;i++)
	{
		printf("%s %d %d\n",a[i].name,a[i].sheng,a[i].cent);
	}
	
	return 0;
}

