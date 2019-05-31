
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(struct stu)

struct stu{
	char name[50];
	char num[50];
	int age;
	float C;
	struct stu *next;
};

    char filename[50];
	struct stu *head;

int file_name()
{
	printf("\n\n输入你想打开的文件名:\n");
	scanf("%s",filename);
}

struct stu *Creat(int n)
{
	void menu_print();
    struct stu *p1,*p2;

	system("cls");
	int i;
	for(i=1;i<=n;i++)
	{
		p1=(struct stu*)malloc(LEN);
		menu_print();
		scanf("%s %s %d %f",p1->name,p1->num,&p1->age,&p1->C);
		p1->next=NULL;
		if(i==1)
		{
			head=p2=p1;
		}
		else
		{
			p2->next=p1;
			p2=p1;
		}
	}
	return (head);
}

int Creat_num()
{
	int n;
	printf("\n\n输入你想添加的学生信息个数:\n");
	scanf("%d",&n);
	return n;
}

//信息表头
void menu_print()
{
	printf("___________________________________\n");
	printf("姓名    学号   年龄  C语言成绩\n");
	printf("___________________________________\n");
}

int add_infor()
{
    struct stu *p1,*p2;

    if(head==NULL)
    {
        menu_print();
        scanf("%s %s %d %f",head->name,head->num,&head->age,&head->C);
        head->next=NULL;
    }
    else
    {
        menu_print();
        scanf("%s %s %d %f",head->name,head->num,&head->age,&head->C);
    }


}

//二级菜单，添加信息
int add()
{
	void WriteData_w();
	void WriteData_a();
	int menu();

	system("cls");
	printf("\n\n\t\t    ********信息录入二级菜单********\n\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                1.新建文件\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                2.增添信息\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                3.返回主菜单\n");

	int a;

	printf("\n\n选择相应功能:\n");
	scanf("%d",&a);
	while(a<1 || a>4)
	{
		printf("错误，请重新选择\n");
		scanf("%d",&a);
	}

	if(a==1)
	{
		WriteData_w(Creat(Creat_num()));
		printf("\n\n数据已成功保存\n\n");
		system("pause");
		add();
	}
	else if(a==2)
	{
		WriteData_a(Creat(Creat_num()));
		printf("\n\n数据已成功保存\n\n");
		system("pause");
		add();
	}
	else if(a==3)
	{
		system("cls");
		menu();
	}
}

void WriteData_w(struct stu *head)
{
	FILE *fp;
	struct stu *p;

	if((fp=fopen(filename,"w"))==NULL) printf("文件打开出错\n");
	p=head;
	while(p!=NULL)
	{
		if(fprintf(fp,"%s %s %d %f\n",p->name,p->num,p->age,p->C)<0)
		{
			printf("数据写入出错\n");
			fclose(fp);
			return;
		}
		p=p->next;
	}
	fclose(fp);
}

void WriteData_a(struct stu *head){
	FILE *fp;
	struct stu *p;

	if((fp=fopen(filename,"a"))==NULL) printf("文件打开出错\n");
	p=head;
	while(p!=NULL)
	{
		if(fprintf(fp,"%s %s %d %f\n",p->name,p->num,p->age,p->C)<0)
		{
			printf("数据写入出错\n");
			fclose(fp);
		}
		p=p->next;
	}
	fclose(fp);
}

struct stu *ReadData()
{
    FILE *fp;
    struct stu *head=NULL;
    struct stu *p1,*p2;
    if((fp=fopen(filename,"r+"))==NULL)
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
        if(fscanf(fp,"%s %s %d %f",p1->name,p1->num,&p1->age,&p1->C)<0)
        {
            free(p1);
            break;
        }
        if(head==NULL) head=p2=p1;
        else
        {
            p2->next=p1;
            p2=p1;
        }
    }
    fclose(fp);
    return (head);
}

int query_all()
{
    system("cls");
    void menu_print();
    struct stu *p;

    p=head;
    menu_print();
    do
    {
        printf("%-6s%-10s%-7d%.1f\n",p->name,p->num,p->age,p->C);
        p=p->next;
    }while(p!=NULL);
    printf("\n\n");
}

int query_name()
{
    void menu_print();
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
            menu_print();
            printf("%-6s%-10s%-7d%.1f\n",p->name,p->num,p->age,p->C);
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
    void menu_print();
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
            menu_print();
            printf("%-6s%-10s%-7d%.1f\n",p->name,p->num,p->age,p->C);
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
    void menu_print();
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
            menu_print();
            printf("%-6s%-10s%-7d%.1f\n",p->name,p->num,p->age,p->C);
            break;
        }
        else
        p=p->next;
    }
    printf("\n\n");
    if(flag==0) printf("未查询到相关信息或输入有误\n\n");
}

int query_name_C()
{
    void menu_print();
    struct stu *p;
    char name[50];
    float C;
    int flag=0;

    p=ReadData();
    printf("输入你想查询的学生姓名和C语言成绩:\n");
    fflush(stdin);
    scanf("%s %f",name,&C);

    system("cls");
    while(p!=NULL){
        if(strcmp(p->name,name)==0 && p->C==C)
        {
            flag=1;
            menu_print();
            printf("%-6s%-10s%-7d%.1f\n",p->name,p->num,p->age,p->C);
            break;
        }
        else
        p=p->next;
    }
    printf("\n\n");
    if(flag==0) printf("未查询到相关信息或输入有误\n\n");

}

//二级查询信息菜单
int query()
{
    system("cls");
    int n=0;
    while(1)
    {
        printf("\n\n\t\t    ********学生信息查询二级菜单********\n\n");
        printf("\t\t        ________________________________\n");
        printf("\t\t                1.查询全部信息\n");
        printf("\t\t        ________________________________\n");
        printf("\t\t                2.按姓名查询\n");
        printf("\t\t        ________________________________\n");
        printf("\t\t                3.按学号查询\n");
        printf("\t\t        ________________________________\n");
        printf("\t\t                4.按姓名和学号查询\n");
        printf("\t\t        ________________________________\n");
        printf("\t\t                5.按姓名和C语言成绩查询\n");
        printf("\t\t        ________________________________\n");
        printf("\t\t                6.返回主菜单\n");

        printf("\n\n选择功能:\n");
        scanf("%d",&n);
        if(n<1 || n>6)
        {
            printf("错误，请重新选择\n");
            scanf("%d",&n);
        }
        if(n==1)
        {
            query_all();
            system("pause");
            query();

        }
        else if(n==2)
        {
            query_name();
            system("pause");
            query();
        }
        else if(n==3)
        {
            query_num();
            system("pause");
            query();
        }
        else if(n==4)
        {
            query_name_num();
            system("pause");
            query();
        }
        else if(n==5)
        {
            query_name_C();
            system("pause");
            query();
        }
        else if(n==6) menu();
    }
}

int del_infor()
{
    char num[50];
    int flag=0;
    struct stu *p1,*p2;
    p2=head;
    p1=NULL;

    printf("输入要删除的学生信息编号\n");
    fflush(stdin);
    gets(num);
    if(strcmp(head->num,num)==0)      //待删除的是头结点
    {
        head=p1->next;
        free(p1);
        flag=1;
    }
    else
    {
        while(p2!=NULL)
        {
            p1=p2;
            p2=p2->next;

            if(strcmp(p2->num,num)==0)      //待删除的是中间节点
            {
                p1->next=p2->next;
                free(p2);
                flag=1;
            }
            if(flag==1) break;
        }
    }

    if(flag==1) printf("数据已成功删除\n");
    else printf("未找到相关信息,请重新输入\n");

}

int change1()
{
    struct stu *p1,*p2;
    char num[50];

    printf("输入要修改的学生学号\n");
    fflush(stdin);
    gets(num);
    p1=head;  //p1保存已检查过的节点
    p2=p1->next;    //p2保存当前节点

    while(p2!=NULL)
    {
        if(strcmp(p1->num,num)==0)      //待删除的是头结点
        {
            menu_print();
            scanf("%s %s %d %f",p1->name,p1->num,&p1->age,&p1->C);
        }
        else if(strcmp(p2->num,num)==0)
        {
            menu_print();
            scanf("%s %s %d %f",p2->name,p2->num,&p2->age,&p2->C);
        }
        p2=p2->next;
        p1=p1->next;
    }
    if(p2!=NULL) printf("未找到相关信息,请重新输入\n");

}



//信息修改及删除二级菜单
int change()
{
	system("cls");
	printf("\n\n\t\t    ********学生信息修改二级菜单********\n\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                1.按学号删除信息\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                2.修改学生信息\n");
    printf("\t\t        ________________________________\n");
	printf("\t\t                3.返回主菜单\n");

    int n;
    printf("选择相应功能\n");
    scanf("%d",&n);
    while(n<1 || n>3)
    {
        printf("错误，请重新输入\n");
        scanf("%d",&n);
    }
    if(n==1)
    {
        del_infor();
        system("pause");
        change();
    }
    else if(n==2)
    {
        change1();
        printf("\n\n数据已成功修改\n");
        system("pause");
        change();
    }
    else if(n==3)
    {
        menu();
    }
}

int tongji_aver()
{
    system("cls");
    struct stu *p;

    p=head;
    menu_print();
    do{
        printf("%-6s%-10s%-7d%.1f\n",p->name,p->num,p->age,p->C);
        p=p->next;
    }while(p!=NULL);
    printf("\n\n");

    struct stu *p1,*p2;
    int n=0;
    float sum=0.0;

    p1=head;  //p1保存已检查过的节点
    p2=p1->next;    //p2保存当前节点

    while(p1!=NULL)
    {
        n+=1;
        sum+=p1->C;
        p1=p1->next;
    }
    sum/=n*1.0;
    printf("\n\nC语言平均成绩为%.1f\n\n",sum);


}

int tongji_60()
{
    system("cls");
    void menu_print();
    struct stu *p;

    p=head;
    menu_print();
    do{
        printf("%-6s%-10s%-7d%.1f\n",p->name,p->num,p->age,p->C);
        p=p->next;
    }while(p!=NULL);
    printf("\n\n");

    struct stu *p1,*p2;
    int n=0,n_60=0;            //记录总人数,及格人数
    float rate=0.0;

    p1=ReadData();  //p1保存已检查过的节点
    p2=p1->next;    //p2保存当前节点
    head=p1;

    while(p1!=NULL)
    {
        n+=1;
        if(p1->C-60.0>=0) n_60+=1;
        p1=p1->next;
    }
    rate=(1.0*n_60)/(1.0*n);
    printf("\n\n及格率为%%%.2f\n\n",rate*100);
}

int tongji_C_each()
{
    system("cls");
    void menu_print();
    struct stu *p;

    int a=0,b=0,c=0,d=0,e=0;
    p=head;
    menu_print();
    do{
        printf("%-6s%-10s%-7d%.1f\n",p->name,p->num,p->age,p->C);
        if(p->C>=90) a++;
        else if(p->C>=80.0 && p->C<90.0) b++;
        else if(p->C>=70.0 && p->C<80.0) c++;
        else if(p->C>=60.0 && p->C<70.0) d++;
        else if(p->C<60.0) e++;
        p=p->next;
    }while(p!=NULL);
    printf("\n\n");
    printf("90分及以上的人数为:%d\n",a);
    printf("80~90分的人数为:%d\n",b);
    printf("70~80分的人数为:%d\n",c);
    printf("60~70分的人数为:%d\n",d);
    printf("60分以下的人数为:%d\n\n",e);
}

int tongji()
{
    system("cls");
    printf("\n\n\t\t    ********学生信息统计二级菜单********\n\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                1.统计C语言平均成绩\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                2.统计C语言成绩及格率\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                3.统计C语言各分数段成绩\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                4.返回主菜单\n");

	int n;
	printf("请选择所需功能\n");
	scanf("%d",&n);
	while(n>4 || n<1)
    {
        printf("错误，请重新输入\n");
        scanf("%d",&n);
    }
	if(n==1)
    {
        tongji_aver();
        system("pause");
        tongji();
    }
	else if(n==2)
    {
        tongji_60();
        system("pause");
        tongji();
    }
	else if(n==3)
    {
        tongji_C_each();
        system("pause");
        tongji();
    }

    else if(n==4) menu();
}

int sort_name()     //按姓名升序排序
{
    system("cls");
    struct stu *p1=NULL,*p2=NULL,*r=NULL,tem;
    char name[50],num[50];

    for(p1=head;p1!=NULL;p1=p1->next)
    {
        for(p2=p1->next;p2!=NULL;p2=p2->next)
        {
            if(strcmp(p1->name,p2->name)>0)
            {
                tem=*p1; *p1=*p2; *p2=tem;
                r=p1->next; p1->next=p2->next; p2->next=r;
            }
        }
    }
    menu_print();
    p1=head;
    while(p1!=NULL)
    {
        printf("%-6s%-10s%-7d%.1f\n",p1->name,p1->num,p1->age,p1->C);
        p1=p1->next;
    }
    printf("\n\n");
}

int sort_num()      //按学号升序排序
{
    system("cls");
    struct stu *p1=NULL,*p2=NULL,*r=NULL,tem;
    char name[50],num[50];

    for(p1=head;p1!=NULL;p1=p1->next)
    {
        for(p2=p1->next;p2!=NULL;p2=p2->next)
        {
            if(strcmp(p1->num,p2->num)>0)
            {
                tem=*p1; *p1=*p2; *p2=tem;
                r=p1->next; p1->next=p2->next; p2->next=r;
            }
        }
    }
    menu_print();
    p1=head;
    while(p1!=NULL)
    {
        printf("%-6s%-10s%-7d%.1f\n",p1->name,p1->num,p1->age,p1->C);
        p1=p1->next;
    }
    printf("\n\n");

}

int sort_C()        //按C语言成绩降序排序
{
    system("cls");
    void menu_print();
    struct stu *p1=NULL,*p2=NULL,*r=NULL,tem;
    char name[50],num[50];

    for(p1=head;p1!=NULL;p1=p1->next)
    {
        for(p2=p1->next;p2!=NULL;p2=p2->next)
        {
            if(p1->C<p2->C)
            {
                tem=*p1; *p1=*p2; *p2=tem;
                r=p1->next; p1->next=p2->next; p2->next=r;
            }
        }
    }
    menu_print();
    p1=head;
    while(p1!=NULL)
    {
        printf("%-6s%-10s%-7d%.1f\n",p1->name,p1->num,p1->age,p1->C);
        p1=p1->next;
    }
    printf("\n\n");
}

int sort()
{
    system("cls");
    printf("\n\n\t\t    ********学生信息排序二级菜单********\n\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                1.按姓名升序排序\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                2.按学号升序排序\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                3.按C语言成绩降序排序\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                4.返回主菜单\n");

	int n;
	printf("请选择相应功能\n");
	scanf("%d",&n);
	while(n>4 || n<1)
    {
        printf("错误，请重新输入\n");
        scanf("%d",&n);
    }
	if(n==1)
    {
        sort_name();
        system("pause");
        sort();
    }
	else if(n==2)
    {
        sort_num();
        system("pause");
        sort();
    }
    else if(n==3)
    {
        sort_C();
        system("pause");
        sort();
    }
    else if(n==4) menu();

}

int menu(void)
{
	system("cls");
	system("color 1F");
    printf("\n\n\t\t    ********学生信息管理系统功能菜单********\n\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                1.信息录入及插入\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                2.信息查询\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                3.信息删除及修改\n");
	printf("\t\t        ________________________________\n");
	printf("\t\t                4.信息统计\n");
    printf("\t\t        ________________________________\n");
	printf("\t\t                5.信息排序\n");
    printf("\t\t        ________________________________\n");
	printf("\t\t                6.退出系统并保存数据\n");

	int n;
	printf("\n\n选择相应功能:\n");
	scanf("%d",&n);
	while(n<1 || n>6)
	{
		printf("错误，请重新选择\n");
		scanf("%d",&n);
	}

	if(n==1)
	{
		add();
	}
	else if(n==2)
	{
		query();
	}
	else if(n==3)
	{
        change();
	}
	else if(n==4)
    {
        tongji();
    }
	else if(n==5)
    {
        sort();
    }
	else if(n==6)
    {
        WriteData_w(head);
        exit(0);
    }

}

#include<windows.h>

int start()
{
    int i,j;
    system("color 9F");
    printf("\n\n\n\n\n\t\t\t\t欢迎使用本系统\n\n");
    printf("\t\t\t\t程序猿：腾腾儿娃\n\n");
    printf("\n\n\n\n");

    file_name();
    head=ReadData();
    menu();
}

int main()
{
    start();
}

