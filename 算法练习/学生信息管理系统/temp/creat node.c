#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"head.h"


struct stu *Creat(int n)
{
	void chart_print();
    struct stu *p1,*p2;

    if(n<0)
    {
        printf("输入有误，请重新输入\n\n");
        return;
    }

	system("cls");
	int i;
	for(i=1;i<=n;i++)
	{
	    int flag=1;
		p1=(struct stu*)malloc(LEN);
		chart_print();
		scanf("%s %s %d %f %f %f %f",p1->name,p1->num,&p1->age,&p1->C,&p1->math,&p1->Eng,&p1->PE);
		//输入年龄，成绩合法性判断
		do
        {
            if(p1->age>120 || p1->age<0)
            {
                printf("年龄输入错误");
                flag=0;
            }
            if(p1->C<0 || p1->math<0 || p1->Eng<0 || p1->PE<0)
            {
                printf(" 成绩输入有误");
                flag=0;
            }
            if(p1->age<120 && p1->age>0 && p1->C>0 && p1->math>0 && p1->Eng>0 && p1->PE>0) flag=1;
            if(flag==0)
            {
                printf(" 请重新输入\n");
                scanf("%s %s %d %f %f %f %f",p1->name,p1->num,&p1->age,&p1->C,&p1->math,&p1->Eng,&p1->PE);
            }
        }while(flag==0);

		p1->next=NULL;
		if(i==1)
		{
			head=p2=p1;
		}
		else
		{
			p2->next=p1;
			p2=p1;
		}
	}
	return (head);
    printf("\n\n数据已成功保存\n\n");
}

int Creat_num()
{
	int n;
	printf("\n\n输入你想添加的学生信息个数,输入0返回主菜单\n");
	scanf("%d",&n);
	if(n==0) menu_manager();
	return n;
}
