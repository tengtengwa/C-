
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"head.h"

int query_all()
{
    system("cls");
    void chart_print();
    struct stu *p;

    p=ReadData();
    chart_print();
    while(p!=NULL)
    {
        printf("%-5s %-9s %-5d %-5.1f %-5.1f %-5.1f %-5.1f\n",p->name,p->num,p->age,p->C,p->math,p->Eng,p->PE);
        p=p->next;
    }
    printf("\n\n");
}

int query_name()
{
    void chart_print();
    struct stu *p;
    char name[50];
    int flag=0;

    p=ReadData();
    printf("输入你想查询的学生姓名:\n");
    fflush(stdin);
    gets(name);

    system("cls");
    while(p!=NULL){
        if(strcmp(p->name,name)==0)
        {
            flag=1;
            chart_print();
            printf("%-5s %-9s %-5d %-5.1f %-5.1f %-5.1f %-5.1f\n",p->name,p->num,p->age,p->C,p->math,p->Eng,p->PE);
            break;
        }
        else
        p=p->next;
    }
    printf("\n\n");
    if(flag==0) printf("未查询到相关信息\n\n");
}

int query_num()
{
    void chart_print();
    struct stu *p;
    char num[50];
    int flag=0;

    p=ReadData();
    printf("输入你想查询的学生学号:\n");
    fflush(stdin);
    gets(num);

    system("cls");
    while(p!=NULL){
        if(strcmp(p->num,num)==0)
        {
            flag=1;
            chart_print();
            printf("%-5s %-9s %-5d %-5.1f %-5.1f %-5.1f %-5.1f\n",p->name,p->num,p->age,p->C,p->math,p->Eng,p->PE);
            break;
        }
        else
        p=p->next;
    }
    printf("\n\n");
    if(flag==0) printf("未查询到相关信息\n\n");


}

int query_name_num()
{
    void chart_print();
    struct stu *p;
    char name[50],num[50];
    int flag=0;

    p=ReadData();
    printf("输入你想查询的学生姓名和学号:\n");
    fflush(stdin);
    scanf("%s %s",name,num);

    system("cls");
    while(p!=NULL){
        if(strcmp(p->name,name)==0 && strcmp(p->num,num)==0)
        {
            flag=1;
            chart_print();
            printf("%-5s %-9s %-5d %-5.1f %-5.1f %-5.1f %-5.1f\n",p->name,p->num,p->age,p->C,p->math,p->Eng,p->PE);
            break;
        }
        else
        p=p->next;
    }
    printf("\n\n");
    if(flag==0) printf("未查询到相关信息或输入有误\n\n");
}

int query_stu()
{
    system("cls");
    char n;
    while(1)
    {
        printf("\n\n\t\t      ********学生信息查询二级菜单********\n\n");
        printf("\t\t        ________________________________\n");
        printf("\t\t                1.按姓名个人查询\n");
        printf("\t\t        ________________________________\n");
        printf("\t\t                2.按学号个人查询\n");
        printf("\t\t        ________________________________\n");
        printf("\t\t                3.查询全部学生信息\n");
        printf("\t\t        ________________________________\n");
        printf("\t\t                4.返回主菜单\n");

        printf("\n\n选择功能:\n");
        fflush(stdin);
        scanf("%c",&n);

        switch(n){
            case'1':
                    query_name();
                    system("pause");
                    query_stu();
                    break;
            case'2':
                    query_num();
                    system("pause");
                    query_stu();
                    break;
            case'3':
                    query_all();
                    system("pause");
                    query_stu();
                    break;
            case'4':
                    menu_stu();
                    break;
            default:printf("输入错误，请重新输入!\n");
                    query_stu();
                    break;
        }
    }
}

//二级查询信息菜单
int query_manager()
{
    system("cls");
    char n;
    while(1)
    {
        printf("\n\n\t\t      ********学生信息查询二级菜单********\n\n");
        printf("\t\t        ________________________________\n");
        printf("\t\t                1.查询全部信息\n");
        printf("\t\t        ________________________________\n");
        printf("\t\t                2.按姓名查询\n");
        printf("\t\t        ________________________________\n");
        printf("\t\t                3.按学号查询\n");
        printf("\t\t        ________________________________\n");
        printf("\t\t                4.返回主菜单\n");

        printf("\n\n选择功能:\n");
        fflush(stdin);
        scanf("%c",&n);

        switch(n){
            case'1':
                    query_all();
                    system("pause");
                    query_manager();
                    break;
            case'2':
                    query_name();
                    system("pause");
                    query_manager();
                    break;
            case'3':
                    query_num();
                    system("pause");
                    query_manager();
                    break;
            case'4':
                    menu_manager();
                    break;
            default:printf("输入错误，请重新输入!\n");
                    query_manager();
                    break;
        }
    }
}
