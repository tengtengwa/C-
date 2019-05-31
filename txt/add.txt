#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"head.h"


//二级菜单，添加信息
int add()
{
	void WriteData_w();
	void WriteData_a();
    struct stu *p1;
    int i;
    system("cls");

    WriteData_a(Creat(Creat_num()));
    printf("\n数据保存成功~\n");
    system("pause");
    menu_manager();
}
