/*
已知X可以写成从1开始连续若干个整数的和， 现在要求把其中两个不相邻的加号变成乘号，使得结果为Y。找出所有满足条件的可能答案并输出（把两个乘号左边的数字用小括号括起来，中间用英文逗号间隔，两个括号之间不空格）；若找不到满足的条件，则输出“NONE”字样。编写程序，完成n组数据的判定。

例如：当X为1225，Y为2015时

因为：1+2+3+ ... + 49 = 1225

           1+2+3+...+10*11+12+...+27*28+29+...+49 = 2015

所以：一个解为(10,27)。
输入
第一行为n值，接下来依次n行的第一个数据是加法结果X，第二个数据是变乘法后的结果Y，以空格间隔。

输出
输出n行，每一行的格式为“(***,***)(***,***)”（或者“NONE”）。请严格按照格式书写，不能出现其它文字或符号。
*/
#include<stdio.h>
int main(void)
{
	int n,x,y,max,a,b,num,choo;
	scanf("%d",&n);
	while(n--)
	{
		num=0;
		choo=1;
		scanf("%d %d",&x,&y);
		for(max=1;num<x;max++)
		{
			num+=max;
		}
		//此时max是那个49的角色
		if(num==x)
		{
			for(a=1;a<=max-2;a++)	//因为a,b不能相邻
			{
				for(b=a+2;b<=max;b++)
				{
					if((a*(a+1)+(b*(b+1))-(2*a+2*b+2))==(y-x))
					{
						choo=0;
						printf("(%d,%d)",a,b);
					}
				}
			}
			if(choo==1)
			{
				printf("NONE");
			}
		}
		else
		printf("NONE");
		if(n!=0)
		{
			printf("\n");
		}
	}
} 
