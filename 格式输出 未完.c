/*
编写程序实现将一段文章格式化打印出来。打印时每行的长度为20个字符。

输入
该段文章长度<=500，单词的数量<=100。

以回车作为该段文章的输入结束。

输出
如果一行的最后一个单词超过了本行的20个字符的范围，则应把它移到下一行；
如果某行仅一个单词，则在该单词结束处直接换行；
否则在每行最后一个单词前增加一些空格，以便使每行的末尾准确地显示在第20个位置处。
样例输入
The relationship between XML functional dependencies and XML keys are also discussed.
样例输出
The     relationship
between          XML
functional
dependencies     and
XML keys are    also
discussed.
*/
#include<stdio.h>
#include<string.h>
int main(void)
{
	char word[128][21]={'\0'},ch;
	int words=0,i,j,k;//word是文本中单词的数量
	int startPos,spaces;//startPos表示 当前行从那个单词开始打印
	//spaces表示 单词中间隔几个空格
	int length=0,curwords=0;//length用于计算 输出时当前用于打印的长度
	//curwords用于计算 当前要打印的个数 
	ch=getchar();
	while(ch!='\n')
	{
		while(ch == ' ')
		{
			ch=getchar();
		}
		i=0;
		while(ch != ' ')
		{
			word[words][i++]=ch;
			ch=getchar();
		}
		word[words][i]='\0';
		words++;
	}
	///////////////////输入 
	startPos=0;
	for(i=0;i<words;i++)
	{
		length=0;curwords=0;
		while(length<20&&i<words)
		{
			length+=strlen(word[i]);
			if(length>20||length+curwords>20)
			{
				length-=strlen(word[i]);
			}
			i++;curwords++;
		}
		i=i-1;//i多走了一步
		//开始算空格这个事情 
		spaces=0;
		if(curwords>1)
		{
			spaces=20-length-curwords+1;//只在最后多加
		}
		j=startPos;
		do{
			printf("%s",word[j]);
			if()
		}
	}
	
	
	
}
