#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define scanf scanf_s
typedef struct student
{
	int xuehao;
	char name[12] = { 0 };
	int fener[3] = { 0 };
	float fen = 0;
	int fen1 = 0;
} ren;

int compare(const void* a, const void* b)
{
	ren* s1 = (ren*)a;
	ren* s2 = (ren*)b;

	if (s1->fen1 != (s2->fen1))
	{
		return (s2->fen1) - (s1->fen1);
	}
	else
	{
		return (s1->xuehao) - (s2->xuehao);
	}
}




int main()
{
	 ren a[101];

	int n = 0;
	scanf("%d", &n);
	char x = getchar();
	for (int i = 0; i < n; i++)
	{
		scanf("%d ", &a[i].xuehao);
		for (int j = 0;; j++)
		{
			char x = 'a';
			x = getchar();
			if (x != ' ')
			{
				a[i].name[j] = x;
			}
			else
			{
				a[i].name[j + 1] = '\0';
				break;
			}
		}
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &a[i].fener[j]);
		}
		a[i].fen = (a[i].fener[0] + a[i].fener[1] + a[i].fener[2]) * 1.0 / 3.0;
		a[i].fen1 = a[i].fen * 10;//主要用来解决compare函数中浮点类型之间的比较问题
	}

	qsort(a, n, sizeof(ren), compare);

	for (int i = 0; i < n; i++)
	{
		printf("%d %s %.1f\n", a[i].xuehao, a[i].name, a[i].fen);
	}

	return 0;
}



