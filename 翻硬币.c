/*题目描述
小明正在玩一个“翻硬币”的游戏，桌上放着排成一排的若干硬币。我们用 * 表示正面， 用 o 表示反面（是小写字母，不是零）。例如，可能情形是：**oo***oooo，如果同时翻转左边的两个硬币，则变为：oooo***oooo。

现在小明的问题是：如果已知了初始状态和要达到的目标状态，每次只能同时翻转相邻的两个硬币,那么对特定的局面，最少要翻动多少次呢？

我们约定：把翻动相邻的两个硬币叫做一步操作。

输入
两行等长的字符串，分别表示初始状态和要达到的目标状态，每行的长度<1000。

输出
一个整数，表示最小操作步数。
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int solve(char *a,char *b)
{
	int count=0;
	while(*a)
	{
		while(*a&&*a==*b)
		{
			a++;b++;
		}
		if(*a)
		{
			*a=(*a=='*')?'o':'*';
			*(a+1)=(*(a+1)=='*')?'o':'*';
			count++;
		}
	}
	return count;
}
int main(void)
{
	char a[1002];
	char b[1002];
	scanf("%s",a);
	scanf("%s",b);
	printf("%d",solve(a,b));
	return 0;
}
