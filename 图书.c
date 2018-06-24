/*
题目描述
一本图书的信息有: 编号、书名、作者、出版社、出版日期、价格。设计一个结构体类型描述图书信息，并实现输入多本（不超过20本）图书信息，存储在该结构体的数组变量中，按价格从低到高排序并输出图书信息。
输入
第一行输入图书的本数，以后每行输入一本图书的信息；每本图书信息的输入说明如下：输入时，各个信息之间空格间隔；编号为整数；书名、作者、出版社均为长度不超过20的字符串；出版日期的输入格式为yyyy-mm-dd,例如（2017-5-2）；价格为实数。

输出
以列表方式输出：（注意，输出中除了汉字外，其他符号均为英文符号）


第一行输出标题行，分别输出：“编号”、“书名”、“作者”、“出版社”、“出版日期”、“价格”；相邻两项之间以一个空格间隔。（参见样例）


以后每行输出一本书，依次输出<编号>，<书名>，<作者>，<出版社>，<出版日期>，<价格（小数点后保留2位)>，相邻两项之间以一个空格间隔。（参见样例）


样例输入
4
2 数据结构 耿国华 高等教育出版社 2005-7-1 28.00
4 大学英语 LEE 清华出版社 1990-4-1 34.6
6 草莓点心 噼里啪啦 二十一世纪出版社 2008-8-8 18.00
7 车来了 噼里啪啦 二十一世纪出版社 2008-9-9 18.50
样例输出
编号 书名 作者 出版社 出版日期 价格
6 草莓点心 噼里啪啦 二十一世纪出版社 2008年8月8日 18.00
7 车来了 噼里啪啦 二十一世纪出版社 2008年9月9日 18.50
2 数据结构 耿国华 高等教育出版社 2005年7月1日 28.00
4 大学英语 LEE 清华出版社 1990年4月1日 34.60

6 草莓点心 噼里啪啦 二十一世纪出版社 2008年8月8日 18.00
7 车来了 噼里啪啦 二十一世纪出版社 2008年9月9日 18.50
2 数据结构 耿国华 高等教育出版社 2005年7月1日 28.00
4 大学英语 LEE 清华出版社 1990年4月1日 34.60

*/
#include<stdio.h>
typedef struct book{
	int number;
	char title[21];
	char auther[21];
	char push[31];
	int year;
	int month;
	int data;
	float price;
}Book;
int main(void)
{
	int n,a,i,j;
	Book books[21],t;
	scanf("%d",&n);
	for(a=0;a<n;a++)
	{
		scanf("%d",&books[a].number);
		scanf("%s",&books[a].title);
		scanf("%s",&books[a].auther);
		scanf("%s",&books[a].push);
		scanf("%d-",&books[a].year);
		scanf("%d-",&books[a].month);
		scanf("%d",&books[a].data);
		scanf("%f",&books[a].price);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(books[j].price > books[j+1].price)
			{
				t=books[j];
				books[j]=books[j+1];
				books[j+1]=t;
			}
		}
	}
	printf("编号 书名 作者 出版社 出版日期 价格\n");
	for(a=0;a<n;a++)
	{
		printf("%d ",books[a].number);
		printf("%s ",books[a].title);
		printf("%s ",books[a].auther);
		printf("%s ",books[a].push);
		printf("%d年",books[a].year);
		printf("%d月",books[a].month);
		printf("%d日 ",books[a].data);
		printf("%.2f\n",books[a].price);
	}
}
