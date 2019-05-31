#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"head.h"

void WriteData_a(struct stu *head){
	FILE *fp;
	struct stu *p;

	if((fp=fopen("E:\\stu_detail.txt","a"))==NULL) printf("文件打开出错\n");
	p=head;
	while(p!=NULL)
	{
		if(fprintf(fp,"\n%s %s %d %f %f %f %f",p->name,p->num,p->age,p->C,p->math,p->Eng,p->PE)<0)
		{
			printf("数据写入出错\n");
			fclose(fp);
		}
		p=p->next;
	}
	fclose(fp);
}

void WriteData_w(struct stu *head)
{
	FILE *fp;
	struct stu *p;

	if((fp=fopen("E:\\stu_detail.txt","w"))==NULL) printf("文件打开出错\n");
	p=head;
	while(p!=NULL)
	{
		if(fprintf(fp,"\n%s %s %d %f %f %f %f",p->name,p->num,p->age,p->C,p->math,p->Eng,p->PE)<0)
		{
			printf("数据写入出错\n");
			fclose(fp);
			return;
		}
		p=p->next;
	}
	fclose(fp);
}

struct stu *ReadData()
{
    FILE *fp;
    struct stu *head=NULL;
    struct stu *p1=NULL,*p2=NULL;
    if((fp=fopen("E:\\stu_detail.txt","a+"))==NULL)
    {
        printf("错误，文件打开失败\n");
        exit(0);
    }
    while(!feof(fp))
    {
        if((p1=(struct stu*)malloc(LEN))==NULL)
        {
            printf("内存申请出错\n");
            fclose(fp);
            exit(0);
        }
        if(fscanf(fp,"%s %s %d %f %f %f %f",p1->name,p1->num,&p1->age,&p1->C,&p1->math,&p1->Eng,&p1->PE)<0)
        {
            free(p1);
            break;
        }
        if(head==NULL)
        {
            head=p1;
            p2=p1;
        }
        else
        {
            p2->next=p1;
            p2=p1;
        }
    }
    p1->next=NULL;
    fclose(fp);
    return (head);
}
