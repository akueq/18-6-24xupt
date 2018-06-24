/*
��Ŀ����
��X��ϵ�Ĺ���ռ���Ư����n��X�����조ը������ÿ��ը���������趨������֮��ը�����磺������ը��2015��1��1�շ��ã���ʱΪ15�죬������2015��1��16�գ������屬ը��

����
��һ��Ϊnֵ���Ժ�����n��Ϊը���������ڣ���ʽΪ ��-��-�գ��Ͷ�ʱ���������ͣ���

���
���n�У�ÿ��Ϊ��ը��׼ȷ���ڣ���ʽΪ yyyy��mm��dd�� ���ڼ��������ں�����֮����һ���ո���������ϸ��ո�ʽ��д�����ܳ����������ֻ���š�

��ʾ��Ϣ�����ڵ����ݼ����ǡ������ա�����һ�����ڶ����������������ġ������塢����������1900��1��1�գ�������һ��

��������
2
1999-9-9 800
2014-11-9 1000
�������
2001��11��17�� ������
2017��08��05�� ������
*/
#include<stdio.h>
#include<string.h> 
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char week[7][10]={"������","����һ","���ڶ�","������","������","������","������"};
struct Date {
    int year;
    int month;
    int day;
};

struct Date whichDate(struct Date date, int days){
    //����ʼ����ת��Ϊ��ǰ�·ݵĵ�һ��
    days += (date.day -1);
    date.day = 1;

    //���㵱ǰ�·�����
    int day = 0;
    switch(date.month){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        day = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        day = 30;
        break;
    case 2:
        if((date.year % 4 == 0 && date.year % 100 !=0) || date.year % 400 == 0){
            day = 29;
        }
        else {
            day = 28;
        }
        break;
    }
    //�������ں�������
    if (days - day >= 0)
    {
        if (date.month == 12)
        {
            date.year += 1;
            date.month = 1;
        }
        else{
            date.month += 1;
        }
        return whichDate(date,days-day);//�ݹ�

    }
    else {
        date.day += days;
    }
    return date;
}

int CaculateWeekDay(int y,int m, int d)
{
	int iWeek;
	if(m==1||m==2) 
	{
		m+=12;
		y--;
	}
	iWeek=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
	iWeek++;
	return iWeek;
}
int main(void)
{
	int n;
	int days,x;
	struct Date date;
	char xq[8];
	scanf("%d",&n); 
	while(n--)
	{
		scanf("%d-%d-%d %d",&date.year,&date.month,&date.day,&days);
		
		date = whichDate(date,days);
		
//		printf("���� %d %d %d\n\n",date.year,date.month,date.day); 
		x=CaculateWeekDay(date.year,date.month,date.day);
		switch(x)
		{
		case 1:strcpy(xq,"����һ");break;
		case 2:strcpy(xq,"���ڶ�");break;
		case 3:strcpy(xq,"������");break;
		case 4:strcpy(xq,"������");break;
		case 5:strcpy(xq,"������");break;
		case 6:strcpy(xq,"������");break;
		case 7:strcpy(xq,"������");break;
		}
		xq[7]='\0';
		printf("%d��%d��%d�� ",date.year,date.month,date.day);
		printf("%s",xq);
	}
	return 0;
}
