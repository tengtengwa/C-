#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"head.h"

int change1()
{
    struct stu *p1;
    char num[50];

    printf("输入要修改的学生学号\n");
    fflush(stdin);
    scanf("%s",num);
    head=ReadData();
    p1=head;              //p1保存已检查过的节点

    while(p1!=NULL)
    {
        if(strcmp(p1->num,num)==0)      //待修改的是头结点
        {
            chart_print();
            scanf("%s %s %d %f %f %f %f",p1->name,p1->num,&p1->age,&p1->C,&p1->math,&p1->Eng,&p1->PE);
            int flag=1;
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

        }
        p1=p1->next;
    }
    if(p1!=NULL) printf("未找到相关信息,请重新输入\n");
    else
    {
        WriteData_w(head);
        printf("\n\n数据已成功修改\n");
    }
}

int del_infor()
{
    char num[50];
    int flag=0;
    struct stu *p1,*p2,*head;
    head=ReadData();
    p2=head;
    p1=NULL;

    printf("输入要删除的学生信息编号\n");
    fflush(stdin);
    scanf("%s",num);
    if(strcmp(head->num,num)==0)      //待删除的是头结点
    {
        head=head->next;
        free(p2);
        flag=1;
    }
    else
    {
        while(p2!=NULL)
        {
            p1=p2;
            p2=p2->next;

            if(strcmp(p2->num,num)==0)      //待删除的是中间节点,及删除p2指向的节点
            {
                p1->next=p2->next;
                free(p2);
                flag=1;
            }
            if(flag==1) break;
        }
    }

    if(flag==1)
    {
        WriteData_w(head);
        printf("\n数据已成功删除\n");
    }

    else printf("未找到相关信息,请重新输入\n");

}

//信息修改及删除二级菜单
int change()
{
	system("cls");
	printf("\n\n\t\t      ********学生信息修改二级菜单********\n\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                1.按学号删除信息\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                2.修改学生信息\n");
    printf("\t\t        ________________________________\n");
	printf("\t\t                3.返回主菜单\n");

    int n;
    printf("选择相应功能\n");
    scanf("%d",&n);
    while(n<1 || n>3)
    {
        printf("错误，请重新输入\n");
        scanf("%d",&n);
    }
    if(n==1)
    {
        del_infor();
        system("pause");
        change();
    }
    else if(n==2)
    {
        change1();
        system("pause");
        change();
    }
    else if(n==3)
    {
        menu_manager();
    }
}
