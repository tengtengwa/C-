#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"head.h"

int sort_name()     //按姓名升序排序
{
    system("cls");
    struct stu *p1=NULL,*p2=NULL,*r=NULL,tem;


    for(p1=head;p1!=NULL;p1=p1->next)
    {
        for(p2=p1->next;p2!=NULL;p2=p2->next)
        {
            if(strcmp(p1->name,p2->name)>0)
            {
                tem=*p1; *p1=*p2; *p2=tem;
                r=p1->next; p1->next=p2->next; p2->next=r;
            }
        }
    }
    chart_print();
    p1=head;
    while(p1!=NULL)
    {
        printf("%-5s %-9s %-5d %-5.1f %-5.1f %-5.1f %-5.1f\n",p1->name,p1->num,p1->age,p1->C,p1->math,p1->Eng,p1->PE);
        p1=p1->next;
    }
    printf("\n\n");
}

int sort_num()      //按学号升序排序
{
    system("cls");
    struct stu *p1=NULL,*p2=NULL,*r=NULL,tem;
    char name[50],num[50];

    for(p1=head;p1!=NULL;p1=p1->next)
    {
        for(p2=p1->next;p2!=NULL;p2=p2->next)
        {
            if(strcmp(p1->num,p2->num)>0)
            {
                tem=*p1; *p1=*p2; *p2=tem;
                r=p1->next; p1->next=p2->next; p2->next=r;
            }
        }
    }
    chart_print();
    p1=head;
    while(p1!=NULL)
    {
        printf("%-5s %-9s %-5d %-5.1f %-5.1f %-5.1f %-5.1f\n",p1->name,p1->num,p1->age,p1->C,p1->math,p1->Eng,p1->PE);
        p1=p1->next;
    }
    printf("\n\n");

}


int sort()
{
    system("cls");
    printf("\n\n\t\t      ********学生信息排序二级菜单********\n\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                1.按姓名升序排序\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                2.按学号升序排序\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                3.返回主菜单\n");

	char n;
	fflush(stdin);
	printf("请选择相应功能\n");
	scanf("%c",&n);

    switch(n)
    {
        case'1': sort_name(); system("pause"); sort(); break;
        case'2': sort_num(); system("pause"); sort(); break;
        case'3': menu_manager(); break;
        default: printf("输入错误，请重新选择\n"); system("pause"); menu_manager(); break;
    }
}
