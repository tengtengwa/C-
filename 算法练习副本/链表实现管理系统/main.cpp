
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(struct product)

struct product{
	char num[50];
	char name[50];
	float price;
	struct product *next;
};

char filename[50];

int file_name()
{
	printf("输入你想打开的文件名:\n");
	scanf("%s",filename);
}

struct product *Creat(int n)
{
	void menu_print();
	struct product *head;
	struct product *p1,*p2;
	
	system("cls");
	int i;
	for(i=1;i<=n;i++)
	{
		p1=(struct product*)malloc(LEN);
		menu_print();
		scanf("%s%s%f",p1->name,p1->num,&p1->price);
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
	printf("\n\n输入你想添加的商品信息个数:\n");
	scanf("%d",&n);
	return n;
}

//信息表头 
void menu_print()
{
	printf("___________________________________\n");
	printf("商品名称  商品编号  商品价格\n");
	printf("___________________________________\n");
	
	
}


//二级菜单，添加信息 
int add_infor()
{
	void WriteData_wb();
	void WriteData_ab();
	int menu();
	
	system("cls");
	printf("\n\n        ********信息录入二级菜单********\n\n");
	printf("        ________________________________\n");
	printf("                1.新建文件\n");
	printf("        ________________________________\n");
	printf("                2.增添信息\n");	
	printf("        ________________________________\n");
	printf("                3.返回主菜单\n");	
	
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
		WriteData_ab(Creat(Creat_num()));
		printf("数据已成功保存\n");
		add_infor();
	}
	else if(a==2)
	{
		WriteData_ab(Creat(Creat_num()));
		printf("数据已成功保存\n");
		add_infor();
	}
	else if(a==3)
	{
		system("cls");
		menu();
	}
}

void WriteData_wb(struct product *head)
{
	FILE *fp;
	struct product *p;

	if((fp=fopen(filename,"wb"))==NULL) printf("文件打开出错\n");
	p=head;
	while(p!=NULL)
	{
		if(fwrite(p,LEN,1,fp)!=1)
		{
			printf("数据写入出错\n");
			fclose(fp);
			return;
		}
		p=p->next;
	}
	fclose(fp);
}

void WriteData_ab(struct product *head){
	FILE *fp;
	struct product *p;

	if((fp=fopen(filename,"ab"))==NULL) printf("文件打开出错\n");
	p=head;
	while(p!=NULL)
	{
		if(fwrite(p,LEN,1,fp)!=1)
		{
			printf("数据写入出错\n");
			fclose(fp);
			return;
		}
		p=p->next;
	}
	fclose(fp);
} 

int query_infor()
{
	
	
}

int change()
{
	
	
}


int menu()
{
	system("cls");
	printf("\n\n        ********商品信息管理系统********\n\n");
	printf("        ________________________________\n");
	printf("                1.信息录入\n");
	printf("        ________________________________\n");
	printf("                2.信息查询\n");	
	printf("        ________________________________\n");
	printf("                3.信息修改\n");	
	printf("        ________________________________\n");
	printf("                4.退出系统\n");	
	
	int n;
	printf("\n\n选择相应功能:\n");
	scanf("%d",&n);
	while(n<1 || n>4)
	{
		printf("错误，请重新选择\n");
		scanf("%d",&n);
	}
	
	
	if(n==1)
	{
		file_name();add_infor();
	}
	else if(n==2)
	{
		file_name();query_infor();
	}
	else if(n==3)
	{
			file_name();change();
	}
	else if(n==4) exit(0);	
}


int main()
{
	menu();
}

