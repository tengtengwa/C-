#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"head.h"

int tongji_3()
{
    system("cls");

    printf("_________________________________________________________________\n");
	printf("姓名  学号     年龄  C语言  数学  英语  体育成绩 总成绩 平均成绩\n");
	printf("_________________________________________________________________\n");

    struct stu *p,*p1;
    head=ReadData();
    p1=head;    p=head;

    int n=0,num=0,i;
    float sum[50],aver[50];

    while(p1!=NULL)
    {
        sum[n]=p1->C+p1->Eng+p1->math+p1->PE;
        n+=1;
        p1=p1->next;
    }
    n+=1;    //总人数
    for(i=0;i<n;i++) aver[i]=sum[i]/4;
    i=0;
    while(p!=NULL)
    {
        printf("%-5s %-9s %-5d %-5.1f %-5.1f %-5.1f %-8.1f %-6.1f %-5.1f\n",p->name,p->num,p->age,p->C,p->math,p->Eng,p->PE,sum[i],aver[i]);
        p=p->next;
        i++;
    }


    printf("\n");
}

int tongji_each()
{
    system("cls");
    void chart_print();
    struct stu *p;

    int a1=0,b1=0,c1=0,d1=0,e1=0;
    int a2=0,b2=0,c2=0,d2=0,e2=0;
    int a3=0,b3=0,c3=0,d3=0,e3=0;
    int a4=0,b4=0,c4=0,d4=0,e4=0;
    float per_c,per_math,per_eng,per_pe;
    float n=0.0;

    p=ReadData();
    chart_print();
    do{
        printf("%-5s %-9s %-5d %-5.1f %-5.1f %-5.1f %-5.1f\n",p->name,p->num,p->age,p->C,p->math,p->Eng,p->PE);
        //C语言各分数段
        {
            if(p->C>=90) a1++;
            else if(p->C>=80.0 && p->C<90.0) b1++;
            else if(p->C>=70.0 && p->C<80.0) c1++;
            else if(p->C>=60.0 && p->C<70.0) d1++;
            else e1++;
        }
        //数学各分数段
        {
            if(p->math>=90) a2++;
            else if(p->math>=80.0 && p->math<90.0) b2++;
            else if(p->math>=70.0 && p->math<80.0) c2++;
            else if(p->math>=60.0 && p->math<70.0) d2++;
            else e2++;
        }
        //英语各分数段
        {
            if(p->Eng>=90) a3++;
            else if(p->Eng>=80.0 && p->Eng<90.0) b3++;
            else if(p->Eng>=70.0 && p->Eng<80.0) c3++;
            else if(p->Eng>=60.0 && p->Eng<70.0) d3++;
            else e3++;
        }
        //体育各分数段
        {
            if(p->PE>=90) a4++;
            else if(p->PE>=80.0 && p->PE<90.0) b4++;
            else if(p->PE>=70.0 && p->PE<80.0) c4++;
            else if(p->PE>=60.0 && p->PE<70.0) d4++;
            else e4++;
        }
        n+=1.0;
        p=p->next;
    }while(p!=NULL);

    per_c=(n-e1*1.0)/n;
    per_math=(n-e2*1.0)/n;
    per_eng=(n-e3*1.0)/n;
    per_pe=(n-e4*1.0)/n;

    printf("\n\n");
    printf("C语言各分数段人数:\n");
    printf("90分及以上:%d   80~90分:%d   70~80分:%d   60~70分:%d   60分以下:%d    及格率:%.2f%%\n\n",a1,b1,c1,d1,e1,per_c);
    printf("数学各分数段人数:\n");
    printf("90分及以上:%d   80~90分:%d   70~80分:%d   60~70分:%d   60分以下:%d    及格率:%.2f%%\n\n",a2,b2,c2,d2,e2,per_math);
    printf("英语各分数段人数:\n");
    printf("90分及以上:%d   80~90分:%d   70~80分:%d   60~70分:%d   60分以下:%d    及格率:%.2f%%\n\n",a3,b3,c3,d3,e3,per_eng);
    printf("体育各分数段人数:\n");
    printf("90分及以上:%d   80~90分:%d   70~80分:%d   60~70分:%d   60分以下:%d    及格率:%.2f%%\n\n",a4,b4,c4,d4,e4,per_pe);
}

int tongji()
{
    system("cls");
    printf("\n\n\t\t        ********学生信息统计二级菜单********\n\n");
	printf("\t\t        __________________________________________\n");
	printf("\t\t                1.统计每个人总的成绩，平均成绩\n");
	printf("\t\t        __________________________________________\n");
	printf("\t\t                2.统计每一课目各分数段成绩和及格率\n");
	printf("\t\t        __________________________________________\n");
	printf("\t\t                3.返回主菜单\n");

	int n;
	printf("请选择所需功能\n");
	scanf("%d",&n);
	while(n>3 || n<1)
    {
        printf("错误，请重新输入\n");
        scanf("%d",&n);
    }
	if(n==1)
    {
        tongji_3();
        system("pause");
        tongji();
    }
	else if(n==2)
    {
        tongji_each();
        system("pause");
        tongji();
    }
    else if(n==3) menu_manager();
}
