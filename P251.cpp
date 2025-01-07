#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//#define scanf scanf_s

typedef struct DATE
{
	int year;
	int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int day;
}date;


int main()
{
	int cnt = 0;
	int a1, a2, a3;
	scanf("%d,%d,%d", &a1, &a2, &a3);
	date yi;
	yi.year = a1;
	yi.day = a3;
	if ((a1 % 4 == 0 && a1 % 100 != 0) || a1 % 400)
	{
		yi.year = 29;
	}
	for (int i = 1; i < a2; i++)
	{
		cnt += yi.mon[i];
	}
	cnt += a3;
	printf("%d", cnt);
	return 0;
}
