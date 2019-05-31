#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"head.h"

int user_manage()
{
    system("cls");
    printf("\n\n\t\t      ********账户信息管理二级菜单********\n\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                1.管理学生账户\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                2.管理管理员账户\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                3.返回主菜单\n");

    char n;
    fflush(stdin);
    printf("请选择功能:\n");
    scanf("%c",&n);

    switch(n){
        case '1':stu_m(); user_manage(); break;
        case '2':m_m(); user_manage(); break;
        case '3':menu_manager(); break;
        default:printf("输入错误，请重新输入!\n\n"); system("pause"); user_manage(); break;
    }
}

int stu_m()
{
    system("cls");
    printf("\n\n\t\t    ********学生信息管理选择面板********\n\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                1.添加学生账户\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                2.删除学生账户\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                3.修改学生账户信息\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                4.返回上级菜单\n");

    char n;
    fflush(stdin);
    scanf("%c",&n);

    switch(n){
        case '1':user_add_stu(); stu_m(); break;
        case '2':del_stu(); stu_m(); break;
        case '3':printf("程序猿偷了个懒，请先删除再重新添加账户吧~\n"); system("pause"); stu_m(); break;
        case '4':user_manage(); break;
        default:printf("输入错误，请重新输入!\n\n"); system("pause"); stu_m(); break;
    }
}

int m_m()
{
    system("cls");
    printf("\n\n\t\t    ********管理员信息管理选择面板********\n\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                1.添加管理员账户\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                2.删除管理员账户\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                3.修改管理员账户信息\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                4.返回上级菜单\n");

    char n;
    fflush(stdin);
    printf("\n请选择功能:\n");
    scanf("%c",&n);

    switch(n){
        case '1':user_add_manager(); m_m(); break;
        case '2':del_manager(); m_m(); break;
        case '3':printf("程序猿偷了个懒，请先删除再重新添加账户吧~\n"); system("pause"); m_m(); break;
        case '4':user_manage(); break;
        default:printf("输入错误，请重新输入!\n\n"); system("pause"); m_m(); break;
    }
}
