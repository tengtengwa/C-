#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"head.h"

int user_add_stu()
{
    FILE *fp;
    int i;
    i=read_stu_num();   //��ȡ�Ѿ������ѧ���˻�����
    i+=1;
    char account[20],passw[20],encode[20]={0};

    if((fp=fopen("E:\\user_stu.txt","a+"))==NULL)
    {
        printf("�ļ��򿪳���!\n");
        system("pause");
        fclose(fp);
        return;
    }
    printf("�������˺�(20λ����):\n");
    scanf("%s",user_stu[i].account);
    printf("\n����������(��֧��20λ������ĸ������):\n");
    scanf("%s",user_stu[i].passw);

    //�������
    int j;
    for(j=0;j<strlen(user_stu[i].passw);j++) encode[j]=user_stu[i].passw[j]^0x86;

    if(fprintf(fp,"\n%s %s",user_stu[i].account,encode)<0)
    {
        printf("�˻��������!\n");
        system("pause");
        fclose(fp);
    }
    else
    {
        printf("�˻��ɹ�����!\n");
        system("pause");
    }
    fclose(fp);
}

int user_add_manager()
{
    FILE *fp;
    int i;
    i=read_manager_num();   //��ȡ�Ѿ�����Ĺ���Ա�˻�����
    i+=1;
    char account[20],passw[20],encode[20]={0};

    if((fp=fopen("E:\\user_manager.txt","a+"))==NULL)
    {
        printf("�ļ��򿪳���!\n");
        system("pause");
        fclose(fp);
        return;
    }
    printf("�������˺�(20λ����):\n");
    scanf("%s",user_manager[i].account);
    printf("\n����������(��֧��20λ�������ֺ���ĸ):\n");
    scanf("%s",user_manager[i].passw);

    //�������
    int j;
    for(j=0;j<strlen(user_manager[i].passw);j++) encode[j]=user_manager[i].passw[j]^0x86;

    if(fprintf(fp,"\n%s %s",user_manager[i].account,encode)<0)
    {
        printf("�˻��������!\n");
        system("pause");
        fclose(fp);
    }
    else
    {
        printf("�˻��ɹ�����!\n");
        system("pause");
    }
    fclose(fp);
}
