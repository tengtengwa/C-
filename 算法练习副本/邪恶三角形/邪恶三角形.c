#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
# define LEN sizeof(struct Student)
struct Student
{
	char num[100];     //ѧ��
	char name[200];    //����
	char sex[100];    //�Ա�
	int age;     //����
	char phone[120];   //�绰
	char address[120];  //��ַ
	char birthday[200];  //����
	char mail[200] ;  //�ʼ�
	struct Student *next;
};
void menu();
void start();
void welcome();
char filename[30];//ȫ�ֱ�������������Ҫ�򿪵��ļ�����
struct Student *Creat(int n);
//��������
struct Student *Creat(int n)
{
 void menu_print_in(void);
 struct Student *head;
 struct Student *p1, *p2;

 system("cls");

 int i;
 for(i=1;i<n+1;i++) {
  p1 = (struct Student*)malloc(LEN);
  menu_print_in();
  scanf("%s%s%s%d%s%s%s%s",p1->num,p1->name,p1->sex,
  &p1->age,p1->phone,p1->address,p1->birthday,p1->mail);
  p1->next = NULL;
  if(i==1)
  {
   head = p2 = p1;
  }
  else {
   p2->next = p1;
   p2 = p1;
  }
 }
 return(head);
}

//���ݴ���(wbֻд)
void WriteData_wb(struct Student *head) {
 FILE *fp;
 struct Student *p;
 if((fp = fopen(filename, "wb"))==NULL)
 printf("\a �ļ��򿪴���");
 p = head;
 while(p!=NULL) {
  if(fwrite(p,LEN,1,fp)!=1) {
   printf("д�����ݳ���\n");
   fclose(fp);
   return;
  }
  p=p->next;
 }
 fclose(fp);
}

//���ݴ���(ab׷��)
void WriteData_ab(struct Student *head)
{
 FILE *fp;
 struct Student *p;
 if((fp = fopen(filename, "ab"))==NULL)
 printf("\a �ļ��򿪴���!");
 p = head;
 while(p!=NULL) {
 if(fwrite(p,LEN,1,fp)!=1) {
   printf("д�����ݳ���\n");
   fclose(fp);
   return;
  }
  p=p->next;
 }
 fclose(fp);
}


//��ȡ�����ļ����浽������ ������ָ�������ͷָ��
struct Student *ReadData(void)
{
 struct Student *head = NULL;
 struct Student *p1, *p2;	//s = p1;p = p2;

 FILE *fp;
 if((fp=fopen(filename,"rb+"))==NULL)
 {
  printf("���ļ�����\n");
  exit(0);
 }
 while(!feof(fp)) {
  if((p1=(struct Student*)malloc(LEN))==NULL){
   printf("�ڴ��������\n");
   fclose(fp);
   exit(0);
  }
  if(fread(p1,LEN,1,fp)!=1){
   free(p1);
   break;
  }
  if(head==NULL)
  head=p2=p1;
  else{
   p2->next=p1;
   p2=p1;
  }
 }
 fclose(fp);
 return (head);
}

//ȫ����ѯ
void display()
{
 system("cls");
 void menu_print_out(void);
 struct Student *p;
 p = ReadData();
 menu_print_out();
 do
 {
  printf("%-10s%6s%8s%4d%13s%11s %4s %4s",p->num,p->name,p->sex,
  p->age,p->phone,p->address,p->birthday,p->mail);
  p = p->next;
  printf("\n\n");
 }while(p!=NULL);
 printf("\n\n");
}

//ѧ�Ų�ѯ
int query_num()
{
 system("cls");
 void menu_print_out();
 struct Student *p;
 char str_num[10];
 printf("��������Ҫ��ѯ��ѧ��:");
 scanf("%s", str_num);
 p = ReadData();
 menu_print_out();
 do {
  if(strcmp(p->num,str_num)==0) {
   printf("%-10s%6s%8s%4d%13s%11s %4s %4s",p->num,p->name,p->sex,
  p->age,p->phone,p->address,p->birthday,p->mail);
   printf("\n\n");
   return 0;
  }
  p = p->next;
 }while(p!=NULL);
 printf("���ݿ���û�д洢��Ҫ��ѯ�����ݣ�\n");
 printf("\n\n");
 return 0;
}

//������ѯ
int query_name()
{
 system("cls");
 void menu_print_out(void);
 struct Student *p;
 char str_name[20];
 printf("��������Ҫ��ѯ������:");
 scanf("%s", str_name);
 p = ReadData();
 menu_print_out();
 do {
  if(strcmp(p->name,str_name)==0)
  {
   printf("%-8s%6s%8s%4d%13s%11s %4s %4s",p->num,p->name,p->sex,
  p->age,p->phone,p->address,p->birthday,p->mail);
   printf("\n\n");
   return 0;
  }
  p = p->next;
 }while(p!=NULL);
 printf("���ݿ���û�д洢��Ҫ��ѯ�����ݣ�\n");
 printf("\n\n");
 return 0;
}

//��1���޸�����֮ɾ����¼
int delStudent()
{
 struct Student *p1, *p2, *head;
 char str_num[20];
 printf("\n��������Ҫɾ����ѧ����Ϣ:");
 scanf("%s", str_num);
 p1 = ReadData();	//p1�����Ѿ������Ľڵ� 
 p2 = p1->next;		//p2���浱ǰ�ڵ� 
 head = p1;
 while(p2!=NULL)
 {
  if(strcmp(p1->num,str_num)==0) {		//ɾ��ͷ��㲢��p2��ָ��Ľڵ���Ϊ�µ�ͷ��� 
   WriteData_wb(p2);					//д������ 
  }
  else if(strcmp(p2->num,str_num)==0) {		
   p1->next = p2->next;						//ɾ���м�ڵ�(p2��ָ�Ľڵ�)
   WriteData_wb(head);						//�������� 
  }
  p2 = p2->next;
  p1 = p1->next;
 }
 if(p2!=NULL)
 printf("���ݿ���û�д洢��Ҫɾ�������ݣ�\n");
 printf("\n\n");
 return 0;
}

//��2���޸�����֮�޸ļ�¼
int change1()
{
 void menu_print_in(void);
 struct Student *p1, *p2, *head;
 char str_num[20];
 printf("��������Ҫ�޸ĵ�ѧ����Ϣ:");
 scanf("%s", str_num);
 p1 = ReadData();
 p2 = p1->next;
 head = p1;
 while(p2!=NULL)
  {
  if(strcmp(p1->num,str_num)==0) {
   menu_print_in();
   scanf("%s%s%s%d%s%s%s%s",p1->num,p1->name,p1->sex,
  &p1->age,p1->phone,p1->address,p1->birthday,p1->mail);
   WriteData_wb(head);
  }
  else if(strcmp(p2->num,str_num)==0)
  {
   menu_print_in();
   scanf("%s%s%s%d%s%s%s%s",p2->num,p2->name,p2->sex,
  &p2->age,p2->phone,p2->address,p2->birthday,p2->mail);
   WriteData_wb(head);
  }
  p2 = p2->next;
  p1 = p1->next;
 }
 if(p2!=NULL)
 printf("���ݿ���û�д洢��Ҫɾ�������ݣ�\n");
 return 0;
}
void start() //��ӭ����
{
  system("color 1E");
  printf("\n\n\n\t\t\t��ӭʹ��ѧ����Ϣ����ϵͳ\n");
  printf("\t\t____________________________________\n\n");
  printf("\nϵͳ��ʼ����.........\n\n\n");
  int i;

  system("pause");
 menu();
}

//���˵�
void menu()
{
 void addStudent();
 void query();
 int File_name();
 void change();
 system("CLS");
 system("color D");
 printf("\n\n\t\t\t* * * * * *���˵�* * * * *\n");
 printf("\n\t\t\t* * * * * * * * * * * * *\n\n");
 printf("\t\t\t  1.¼��ѧ����Ϣ  \n");
 printf("\t\t\t___________________________\n");
 printf("\t\t\t  2.��ѯѧ����Ϣ  \n");
 printf("\t\t\t___________________________\n");
 printf("\t\t\t  3.�޸�ѧ����Ϣ  \n");
 printf("\t\t\t___________________________\n");
 printf("\t\t\t  4. �˳�ϵͳ  \n");
 printf("\t\t\t___________________________\n");
 printf("\t\t\t* * * * * * * * * * * * * *\n");
 printf("\n\t\t��ѡ����:");

 int a = 0;
 a = getch();

 while(a!='1'&&a!='2'&&a!='3'&&a!='4')
 {
  printf("������������ȷ�ĺ���!\n");
  putchar('\a');
  getch();
  printf("�����빦��ǰ�����ѡ�������Ŀ:\n");
  a = getch();
 }
 switch(a) {
  case '1': File_name();addStudent();
  break;
  case '2': File_name();query();
  break;
  case '3': File_name();change();
  break;
  case '4': exit(0);
  break;
 }
 getch();
}

int File_name()
{
 printf("\n\t\t��������Ҫ�򿪵��ļ�:");
 if(scanf("%s", filename)!=1)
 printf("\a error!");
 return 0;
}
//�����˵�֮�������
void addStudent()
{
 int Creat_num();
 system("cls");
 getch();
 system("CLS");
 system("color B");
 printf("\t\t\t�������������ݡ���������\n");
 printf("\n\n\n\n\n\t\t\t��������������������������\n");
 printf("\t\t\t��      ��\n");
 printf("\t\t\t��  1. �½��ļ�  ��\n");
 printf("\t\t\t��----------------------��\n");
 printf("\t\t\t��  2. ��������  ��\n");
 printf("\t\t\t��----------------------��\n");
 printf("\t\t\t��  3. ���ز˵�  ��\n");
 printf("\t\t\t��----------------------��\n");
 printf("\t\t\t��������������������������\n");
 printf("\n\t\t�����빦��ǰ�����ѡ�������Ŀ:");

 int a = 0;
 a = getch();

 while(a!='1'&&a!='2'&&a!='3')
 {
  printf("������������ȷ�ĺ���!\n");
  putchar('\a');
  getch();
  printf("\n\t\t�����빦��ǰ�����ѡ�������Ŀ:");
  a = getch();
 }
 switch(a) {
  case '1': WriteData_wb(Creat(Creat_num()));
   printf("\n�½��ļ��ɹ��������ѳɹ�����\n");
   system("cls");
   addStudent();
  break;
  case '2': WriteData_ab(Creat(Creat_num()));
    printf("\n�����ѳɹ����\n");
   system("cls");
   addStudent();
  break;
  case '3': system("cls");
   getch();
   menu();
  break;
 }
}

//�����˵�֮��ѯ����
void query()
{
 system("cls");
 while(1)
 {
 system("CLS");
 system("color C");
 printf("\t\t\t�������ѯ���ݡ���������\n");
 printf("\n\n\n\n\n\t\t\t����������������������������\n");
 printf("\t\t\t��      ��\n");
 printf("\t\t\t��  1.ȫ����ѯ  ��\n");
 printf("\t\t\t��------------------------��\n");
 printf("\t\t\t��  2.ѧ�Ų�ѯ  ��\n");
 printf("\t\t\t��------------------------��\n");
 printf("\t\t\t��  3.������ѯ  ��\n");
 printf("\t\t\t��------------------------��\n");
 printf("\t\t\t��  4.���ز˵�  ��\n");
 printf("\t\t\t��------------------------��\n");
 printf("\t\t\t����������������������������\n");
 printf("\n\t\t�����빦��ǰ�����ѡ�������Ŀ:");
 int a = 0;
 a = getch();

 while(a!='1'&&a!='2'&&a!='3'&&a!='4')
  {
   printf("\n������������ȷ�ĺ���!\n");
   a = getch();
  }
  switch(a) {
   case '1': display();system("pause");getchar();
   break;
   case '2': query_num();system("pause");getchar();
   break;
   case '3': query_name();system("pause");getchar();
   break;
   case '4': system("cls");system("pause");getchar();menu();
   break;
  }
 }
}
int Creat_num() {
 printf("\n\t\t��������Ҫ��ӵ����ݸ���:");
 int n;
 if(scanf("%d", &n)!=1) {
  printf("\a error!");
 }
 return n;
}
//�����˵�֮�޸�����/
void change()
{
 system("cls");
 getch();
 while(1)
 {
 system("CLS");
 system("color A");
 printf("\t\t\t��������޸����ݡ���������\n");
 printf("\n\n\n\n\n\t\t\t����������������������������\n");
 printf("\t\t\t��      ��\n");
 printf("\t\t\t��  1.ɾ����¼  ��\n");
 printf("\t\t\t��------------------------��\n");
 printf("\t\t\t��  2.�޸ļ�¼  ��\n");
 printf("\t\t\t��------------------------��\n");
 printf("\t\t\t��  3.���ز˵�  ��\n");
 printf("\t\t\t��------------------------��\n");
 printf("\t\t\t����������������������������\n");
 printf("\n\t\t�����빦��ǰ�����ѡ�������Ŀ:");

 int a = 0;
 a = getch();

 while(a!='1'&&a!='2'&&a!='3')
 {
  printf("������������ȷ�ĺ���!\n");
  a = getch();
  }
  switch(a) {
   case '1': delStudent();
    printf("\n\n�ѳɹ�ɾ��ָ������\n");
    system("pause");
    getch();
   break;
   case '2': change1();
     printf("\n\n�ѳɹ��޸�ָ������\n");
    system("pause");
     getch();
   break;
   case '3': system("cls");
    getch();
    menu();
   break;
  }
 }
}

//���������ʾ��
void menu_print_in() {
 printf("------------------------------------------------------------------------\n");
 printf("ѧ��  ����  �Ա� ���� �绰   ��ַ  ���� �ʼ� \n");
 printf("------------------------------------------------------------------------\n");
}
void menu_print_out(void) {
 printf("--------------------------------------------------------------------------\n");
 printf("ѧ��  ����  �Ա� ���� �绰   ��ַ  ���� �ʼ� \n");
 printf("--------------------------------------------------------------------------\n");
}

//������
int main()
{
 start();
 return 0;
}
