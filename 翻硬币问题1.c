#include<stdio.h>
int main(void)
{
	int count=0;
	int i;
	char a[1002];
	char b[1002];
	scanf("%s",a);
	scanf("%s",b);
	for(i=0;a[i]!=0&&b[i]!=0;i++)
	{
		if(a[i]!=b[i])
		{
			a[i]=(a[i]=='*')?'o':'*';
			a[i+1]=(a[i+1]=='*')?'o':'*';
			count++;
		}
	}
	printf("%d",count);
	return 0;
}
