#include<stdio.h>
#include<string.h>
#include"head.h"
#include<windows.h>

int pre_login()
{
	system("cls");
	system("color 80");
	printf("\n\n\t\t           **********��¼ѡ��********\n\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                1.ѧ����¼\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                2.����Ա��½\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                3.�˳�ϵͳ\n");

    printf("\n��ѡ����Ӧ����:\n");
	char n;
	fflush(stdin);
	scanf("%c",&n);

	switch(n){
        case '1':user_stu_login(); break;
        case '2':user_manager_login(); break;
        case '3':WriteData_w(head); printf("\n��лʹ�ñ�ϵͳ\n"); exit(0); break;
        default:
            printf("�����������������!\n\n");
            system("pause");
            pre_login();
            break;
	}
}

int user_manager_login()
{
    FILE *fp;
    char ch,account[200],passw[200],encode[200]={0};
    int p;

    fp=fopen("E:\\user_manager.txt","r+");

    system("color 80");
    fflush(stdin);
    printf("\n���������Ա�˺�:\n");
    scanf("%s",account);
    printf("����������:\n");
    p=0;

    {
        while((ch=getch())!='\r')
        {
            if(ch==8)
            {
                if(p>0 && p<M)
                {
                    p--;
                    putchar('\b');
                    putchar(' ');
                    putchar('\b');
                }
                else continue;
            }
            if(!isalpha(ch) && !isdigit(ch)) continue;
            printf("*");
            passw[p++]=ch;
        }
        passw[p]=0;
    }



    if(strcmp(account,"666666")==0 && strcmp(passw,"666666")==0)    //����Ա��ʼ����
    {
        menu_manager();
    }
    else
    {
        int j;
        for(j=0;j<strlen(passw);j++) encode[j]=passw[j]^0x86;   //�������������ܣ����½��жԱ�
        int i=0;
        while(!feof(fp))
        {
            fscanf(fp,"%s %s",user_manager[i].account,user_manager[i].passw);
            i++;
        }

        i-=1;
        int flag=0;
        for(;i>=0;i--)
            if(strcmp(account,user_manager[i].account)==0 && strcmp(encode,user_manager[i].passw)==0) flag=1;

        if(flag==0)
        {
            printf("\n�˺Ż�������������򲻴��ڴ��˻�\n\n");
            system("pause");
            pre_login();
        }
        else
        {
            printf("\n\n��½�ɹ�!\n");
            Sleep(500);
            menu_manager();
        }
    }
}


int user_stu_login()
{
    char ch,account[200],passw[200],encode[200]={0};
    int p,i;
    FILE *fp;
    fp=fopen("E:\\user_stu.txt","r+");

    system("color 80");
    fflush(stdin);
    printf("\n������ѧ���˺�:\n");
    scanf("%s",account);
    printf("����������:\n");
    p=0;

    //����������ʾ�Ǻ�
    {
        while((ch=getch())!='\r')
        {
            if(ch==8)
            {
                if(p>0 && p<M)
                {
                    p--;
                    putchar('\b');
                    putchar(' ');
                    putchar('\b');
                }
                else continue;
            }
            if(!isalpha(ch) && !isdigit(ch)) continue;
            printf("*");
            passw[p++]=ch;
        }
        passw[p]=0;
    }

    int j;
    for(j=0;j<strlen(passw);j++) encode[j]=passw[j]^0x86;   //�������������ܣ����½��жԱ�

    i=0;
    while(!feof(fp))
    {
        fscanf(fp,"%s %s",user_stu[i].account,user_stu[i].passw);
        i++;
    }
    i-=1;

    int flag=0;
    for(;i>=0;i--)
        if(strcmp(account,user_stu[i].account)==0 && strcmp(encode,user_stu[i].passw)==0) flag=1;

    if(flag==0)
    {
        printf("\n�˺Ż�������������򲻴��ڴ��˻�\n\n");
        system("pause");
        pre_login();
    }
    else
    {
        printf("\n\n��½�ɹ�!\n");
        Sleep(500);
        menu_stu();
    }
}
