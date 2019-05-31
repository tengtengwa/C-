
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
	printf("��������򿪵��ļ���:\n");
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
	printf("\n\n����������ӵ���Ʒ��Ϣ����:\n");
	scanf("%d",&n);
	return n;
}

//��Ϣ��ͷ 
void menu_print()
{
	printf("___________________________________\n");
	printf("��Ʒ����  ��Ʒ���  ��Ʒ�۸�\n");
	printf("___________________________________\n");
	
	
}


//�����˵��������Ϣ 
int add_infor()
{
	void WriteData_wb();
	void WriteData_ab();
	int menu();
	
	system("cls");
	printf("\n\n        ********��Ϣ¼������˵�********\n\n");
	printf("        ________________________________\n");
	printf("                1.�½��ļ�\n");
	printf("        ________________________________\n");
	printf("                2.������Ϣ\n");	
	printf("        ________________________________\n");
	printf("                3.�������˵�\n");	
	
	int a;

	printf("\n\nѡ����Ӧ����:\n");
	scanf("%d",&a);
	while(a<1 || a>4)
	{
		printf("����������ѡ��\n");
		scanf("%d",&a);	
	}
	
	if(a==1)
	{
		WriteData_ab(Creat(Creat_num()));
		printf("�����ѳɹ�����\n");
		add_infor();
	}
	else if(a==2)
	{
		WriteData_ab(Creat(Creat_num()));
		printf("�����ѳɹ�����\n");
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

	if((fp=fopen(filename,"wb"))==NULL) printf("�ļ��򿪳���\n");
	p=head;
	while(p!=NULL)
	{
		if(fwrite(p,LEN,1,fp)!=1)
		{
			printf("����д�����\n");
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

	if((fp=fopen(filename,"ab"))==NULL) printf("�ļ��򿪳���\n");
	p=head;
	while(p!=NULL)
	{
		if(fwrite(p,LEN,1,fp)!=1)
		{
			printf("����д�����\n");
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
	printf("\n\n        ********��Ʒ��Ϣ����ϵͳ********\n\n");
	printf("        ________________________________\n");
	printf("                1.��Ϣ¼��\n");
	printf("        ________________________________\n");
	printf("                2.��Ϣ��ѯ\n");	
	printf("        ________________________________\n");
	printf("                3.��Ϣ�޸�\n");	
	printf("        ________________________________\n");
	printf("                4.�˳�ϵͳ\n");	
	
	int n;
	printf("\n\nѡ����Ӧ����:\n");
	scanf("%d",&n);
	while(n<1 || n>4)
	{
		printf("����������ѡ��\n");
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

