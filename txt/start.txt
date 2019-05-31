#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include"head.h"

int start()
{
    int i,j;
    system("color 80");
    printf("\n\n\t\t\t\t欢迎使用学生管理系统\n\n");
    printf("\t\t\t\t程序猿：腾腾儿娃\n\n");
    printf("\n\t\t");
    printf("\t\t系统正在启动，请稍等...\n\n\t\t");
    for(i=0;i<=50;i++)
    {
        Sleep(30);
        printf(">");
    }
    printf("\n");


    printf("\n");
    pre_login();
}
