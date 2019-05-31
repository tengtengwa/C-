
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"head.h"


int del_stu()
{
    char account[20];
    int i,n;

    printf("输入你想删除的学生账号:\n");
    scanf("%s",account);
    for(i=0;i<=20;i++)
    {
        if(strcmp(account,user_stu[i].account)==0)
        {
            user_stu[i].account[0]='\0';
            user_stu[i].passw[0]='\0';
        }
    }

    FILE *fp;
    n=read_manager_num();   //获取已经保存的管理员账户个数
    n+=1;

    if((fp=fopen("E:\\user_stu.txt","w"))==NULL)
    {
        printf("文件打开出错!\n");
        system("pause");
        fclose(fp);
        return;
    }
    for(i=0;i<n;i++)
    if(fprintf(fp,"%s %s\n",user_stu[i].account,user_stu[i].passw)<0)
    {
        printf("账户保存出错!\n");
        system("pause");
        fclose(fp);
    }
    if(i==n)
    {
        printf("成功删除该账户!\n");
        system("pause");
    }
    fclose(fp);
}

int del_manager()
{
    char account[20];
    int i,n;

    printf("输入你想删除的管理员账号:\n");
    scanf("%s",account);
    for(i=0;i<=20;i++)
    {
        if(strcmp(account,user_manager[i].account)==0)
        {
            user_manager[i].account[0]='\0';
            user_manager[i].passw[0]='\0';
        }
    }

    FILE *fp;
    n=read_manager_num();   //获取已经保存的管理员账户个数
    n+=1;

    if((fp=fopen("E:\\user_manager.txt","w"))==NULL)
    {
        printf("文件打开出错!\n");
        system("pause");
        fclose(fp);
        return;
    }
    for(i=0;i<n;i++)
    if(fprintf(fp,"%s %s\n",user_manager[i].account,user_manager[i].passw)<0)
    {
        printf("账户保存出错!\n");
        system("pause");
        fclose(fp);
    }
    if(i==n)
    {
        printf("成功删除该账户!\n");
        system("pause");
    }
    fclose(fp);
}
