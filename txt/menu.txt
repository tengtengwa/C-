#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"head.h"

int menu_manager()
{
	system("cls");
	system("color 80");
    printf("\n\n\t\t        **********管理员功能菜单********\n\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                1.信息录入\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                2.信息查询\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                3.信息删除及修改\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                4.信息统计\n");
    printf("\t\t        ________________________________\n");
	printf("\t\t                5.信息排序\n");
    printf("\t\t        ________________________________\n");
	printf("\t\t                6.管理账户信息\n");
    printf("\t\t        ________________________________\n");
	printf("\t\t                7.退出登录\n");

    head=ReadData();//从文件读取数据

	char n;
	printf("\n\n选择相应功能:\n");
	fflush(stdin);
	scanf("%c",&n);

    switch(n)
    {
        case'1': add(); system("pause"); menu_manager(); break;
        case'2': query_manager(); system("pause"); menu_manager(); break;
        case'3': change(); system("pause"); menu_manager(); break;
        case'4': tongji(); system("pause"); menu_manager(); break;
        case'5': sort(); system("pause"); menu_manager(); break;
        case'6': user_manage(); system("pause"); menu_manager(); break;
        case'7': pre_login();
        default: printf("输入错误，请重新选择\n"); system("pause"); menu_manager(); break;
    }
}

int menu_stu()
{
	system("cls");
	system("color 80");
    printf("\n\n\t\t        *********学生功能菜单********\n\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                1.信息查询\n");
    printf("\t\t        ________________________________\n");
	printf("\t\t                2.退出登陆\n");

	int n;
	printf("\n\n选择相应功能:\n");
	scanf("%d",&n);
	while(n<1 || n>3)
	{
		printf("错误，请重新选择\n");
		scanf("%d",&n);
	}

	if(n==1) query_stu();
	else if(n==2) pre_login();

}
