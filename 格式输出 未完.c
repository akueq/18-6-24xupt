/*
��д����ʵ�ֽ�һ�����¸�ʽ����ӡ��������ӡʱÿ�еĳ���Ϊ20���ַ���

����
�ö����³���<=500�����ʵ�����<=100��

�Իس���Ϊ�ö����µ����������

���
���һ�е����һ�����ʳ����˱��е�20���ַ��ķ�Χ����Ӧ�����Ƶ���һ�У�
���ĳ�н�һ�����ʣ����ڸõ��ʽ�����ֱ�ӻ��У�
������ÿ�����һ������ǰ����һЩ�ո��Ա�ʹÿ�е�ĩβ׼ȷ����ʾ�ڵ�20��λ�ô���
��������
The relationship between XML functional dependencies and XML keys are also discussed.
�������
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
	int words=0,i,j,k;//word���ı��е��ʵ�����
	int startPos,spaces;//startPos��ʾ ��ǰ�д��Ǹ����ʿ�ʼ��ӡ
	//spaces��ʾ �����м�������ո�
	int length=0,curwords=0;//length���ڼ��� ���ʱ��ǰ���ڴ�ӡ�ĳ���
	//curwords���ڼ��� ��ǰҪ��ӡ�ĸ��� 
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
	///////////////////���� 
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
		i=i-1;//i������һ��
		//��ʼ��ո�������� 
		spaces=0;
		if(curwords>1)
		{
			spaces=20-length-curwords+1;//ֻ�������
		}
		j=startPos;
		do{
			printf("%s",word[j]);
			if()
		}
	}
	
	
	
}
