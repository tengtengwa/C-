#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"head.h"

int user_add_stu()
{
    FILE *fp;
    int i;
    i=read_stu_num();   //获取已经保存的学生账户个数
    i+=1;
    char account[20],passw[20],encode[20]={0};

    if((fp=fopen("E:\\user_stu.txt","a+"))==NULL)
    {
        printf("文件打开出错!\n");
        system("pause");
        fclose(fp);
        return;
    }
    printf("请输入账号(20位以内):\n");
    scanf("%s",user_stu[i].account);
    printf("\n请输入密码(仅支持20位以内字母和数字):\n");
    scanf("%s",user_stu[i].passw);

    //密码加密
    int j;
    for(j=0;j<strlen(user_stu[i].passw);j++) encode[j]=user_stu[i].passw[j]^0x86;

    if(fprintf(fp,"\n%s %s",user_stu[i].account,encode)<0)
    {
        printf("账户保存出错!\n");
        system("pause");
        fclose(fp);
    }
    else
    {
        printf("账户成功保存!\n");
        system("pause");
    }
    fclose(fp);
}

int user_add_manager()
{
    FILE *fp;
    int i;
    i=read_manager_num();   //获取已经保存的管理员账户个数
    i+=1;
    char account[20],passw[20],encode[20]={0};

    if((fp=fopen("E:\\user_manager.txt","a+"))==NULL)
    {
        printf("文件打开出错!\n");
        system("pause");
        fclose(fp);
        return;
    }
    printf("请输入账号(20位以内):\n");
    scanf("%s",user_manager[i].account);
    printf("\n请输入密码(仅支持20位以内数字和字母):\n");
    scanf("%s",user_manager[i].passw);

    //密码加密
    int j;
    for(j=0;j<strlen(user_manager[i].passw);j++) encode[j]=user_manager[i].passw[j]^0x86;

    if(fprintf(fp,"\n%s %s",user_manager[i].account,encode)<0)
    {
        printf("账户保存出错!\n");
        system("pause");
        fclose(fp);
    }
    else
    {
        printf("账户成功保存!\n");
        system("pause");
    }
    fclose(fp);
}
