/*
题目描述
在X星系的广袤空间中漂浮着n个X星人造“炸弹”，每个炸弹都可以设定多少天之后爆炸。例如：阿尔法炸弹2015年1月1日放置，定时为15天，则它在2015年1月16日，星期五爆炸。

输入
第一行为n值，以后连续n行为炸弹放置日期（格式为 年-月-日）和定时天数（整型）。

输出
输出n行，每行为爆炸的准确日期（格式为 yyyy年mm月dd日 星期几），日期和星期之间用一个空格隔开。请严格按照格式书写，不能出现其它文字或符号。

提示信息：星期的数据集合是【星期日、星期一、星期二、星期三、星期四、星期五、星期六】。1900年1月1日，是星期一。

样例输入
2
1999-9-9 800
2014-11-9 1000
样例输出
2001年11月17日 星期六
2017年08月05日 星期六
*/
#include<stdio.h>
#include<string.h> 
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char week[7][10]={"星期日","星期一","星期二","星期三","星期四","星期五","星期六"};
struct Date {
    int year;
    int month;
    int day;
};

struct Date whichDate(struct Date date, int days){
    //将起始日期转化为当前月份的第一天
    days += (date.day -1);
    date.day = 1;

    //计算当前月份天数
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
    //更新日期和总天数
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
        return whichDate(date,days-day);//递归

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
		
//		printf("测试 %d %d %d\n\n",date.year,date.month,date.day); 
		x=CaculateWeekDay(date.year,date.month,date.day);
		switch(x)
		{
		case 1:strcpy(xq,"星期一");break;
		case 2:strcpy(xq,"星期二");break;
		case 3:strcpy(xq,"星期三");break;
		case 4:strcpy(xq,"星期四");break;
		case 5:strcpy(xq,"星期五");break;
		case 6:strcpy(xq,"星期六");break;
		case 7:strcpy(xq,"星期日");break;
		}
		xq[7]='\0';
		printf("%d年%d月%d日 ",date.year,date.month,date.day);
		printf("%s",xq);
	}
	return 0;
}
