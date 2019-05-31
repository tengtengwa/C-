#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
# define LEN sizeof(struct Student)
struct Student
{
	char num[100];     //学号
	char name[200];    //姓名
	char sex[100];    //性别
	int age;     //年龄
	char phone[120];   //电话
	char address[120];  //地址
	char birthday[200];  //生日
	char mail[200] ;  //邮件
	struct Student *next;
};
void menu();
void start();
void welcome();
char filename[30];//全局变量，用来保存要打开的文件名字
struct Student *Creat(int n);
//生成链表
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

//数据存盘(wb只写)
void WriteData_wb(struct Student *head) {
 FILE *fp;
 struct Student *p;
 if((fp = fopen(filename, "wb"))==NULL)
 printf("\a 文件打开错误");
 p = head;
 while(p!=NULL) {
  if(fwrite(p,LEN,1,fp)!=1) {
   printf("写入数据出错\n");
   fclose(fp);
   return;
  }
  p=p->next;
 }
 fclose(fp);
}

//数据存盘(ab追加)
void WriteData_ab(struct Student *head)
{
 FILE *fp;
 struct Student *p;
 if((fp = fopen(filename, "ab"))==NULL)
 printf("\a 文件打开错误!");
 p = head;
 while(p!=NULL) {
 if(fwrite(p,LEN,1,fp)!=1) {
   printf("写入数据出错\n");
   fclose(fp);
   return;
  }
  p=p->next;
 }
 fclose(fp);
}


//读取数据文件保存到链表中 ，返回指向此链表头指针
struct Student *ReadData(void)
{
 struct Student *head = NULL;
 struct Student *p1, *p2;	//s = p1;p = p2;

 FILE *fp;
 if((fp=fopen(filename,"rb+"))==NULL)
 {
  printf("打开文件出错\n");
  exit(0);
 }
 while(!feof(fp)) {
  if((p1=(struct Student*)malloc(LEN))==NULL){
   printf("内存申请出错\n");
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

//全部查询
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

//学号查询
int query_num()
{
 system("cls");
 void menu_print_out();
 struct Student *p;
 char str_num[10];
 printf("请输入您要查询的学号:");
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
 printf("数据库中没有存储您要查询的数据！\n");
 printf("\n\n");
 return 0;
}

//姓名查询
int query_name()
{
 system("cls");
 void menu_print_out(void);
 struct Student *p;
 char str_name[20];
 printf("请输入您要查询的姓名:");
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
 printf("数据库中没有存储您要查询的数据！\n");
 printf("\n\n");
 return 0;
}

//【1】修改数据之删除记录
int delStudent()
{
 struct Student *p1, *p2, *head;
 char str_num[20];
 printf("\n请输入您要删除的学号信息:");
 scanf("%s", str_num);
 p1 = ReadData();	//p1保存已经检查过的节点 
 p2 = p1->next;		//p2保存当前节点 
 head = p1;
 while(p2!=NULL)
 {
  if(strcmp(p1->num,str_num)==0) {		//删除头结点并将p2所指向的节点作为新的头结点 
   WriteData_wb(p2);					//写入数据 
  }
  else if(strcmp(p2->num,str_num)==0) {		
   p1->next = p2->next;						//删除中间节点(p2所指的节点)
   WriteData_wb(head);						//保存数据 
  }
  p2 = p2->next;
  p1 = p1->next;
 }
 if(p2!=NULL)
 printf("数据库中没有存储您要删除的数据！\n");
 printf("\n\n");
 return 0;
}

//【2】修改数据之修改记录
int change1()
{
 void menu_print_in(void);
 struct Student *p1, *p2, *head;
 char str_num[20];
 printf("请输入您要修改的学号信息:");
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
 printf("数据库中没有存储您要删除的数据！\n");
 return 0;
}
void start() //欢迎界面
{
  system("color 1E");
  printf("\n\n\n\t\t\t欢迎使用学生信息管理系统\n");
  printf("\t\t____________________________________\n\n");
  printf("\n系统开始启动.........\n\n\n");
  int i;

  system("pause");
 menu();
}

//主菜单
void menu()
{
 void addStudent();
 void query();
 int File_name();
 void change();
 system("CLS");
 system("color D");
 printf("\n\n\t\t\t* * * * * *主菜单* * * * *\n");
 printf("\n\t\t\t* * * * * * * * * * * * *\n\n");
 printf("\t\t\t  1.录入学生信息  \n");
 printf("\t\t\t___________________________\n");
 printf("\t\t\t  2.查询学生信息  \n");
 printf("\t\t\t___________________________\n");
 printf("\t\t\t  3.修改学生信息  \n");
 printf("\t\t\t___________________________\n");
 printf("\t\t\t  4. 退出系统  \n");
 printf("\t\t\t___________________________\n");
 printf("\t\t\t* * * * * * * * * * * * * *\n");
 printf("\n\t\t请选择功能:");

 int a = 0;
 a = getch();

 while(a!='1'&&a!='2'&&a!='3'&&a!='4')
 {
  printf("错误，请输入正确的号码!\n");
  putchar('\a');
  getch();
  printf("请输入功能前的序号选择服务项目:\n");
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
 printf("\n\t\t请输入您要打开的文件:");
 if(scanf("%s", filename)!=1)
 printf("\a error!");
 return 0;
}
//二级菜单之添加数据
void addStudent()
{
 int Creat_num();
 system("cls");
 getch();
 system("CLS");
 system("color B");
 printf("\t\t\t★★★★★★添加数据※※※※※\n");
 printf("\n\n\n\n\n\t\t\t※※※※※※※※※※※※※\n");
 printf("\t\t\t※      ※\n");
 printf("\t\t\t※  1. 新建文件  ※\n");
 printf("\t\t\t※----------------------※\n");
 printf("\t\t\t※  2. 增添数据  ※\n");
 printf("\t\t\t※----------------------※\n");
 printf("\t\t\t※  3. 返回菜单  ※\n");
 printf("\t\t\t※----------------------※\n");
 printf("\t\t\t※※※※※※※※※※※※※\n");
 printf("\n\t\t请输入功能前的序号选择服务项目:");

 int a = 0;
 a = getch();

 while(a!='1'&&a!='2'&&a!='3')
 {
  printf("错误，请输入正确的号码!\n");
  putchar('\a');
  getch();
  printf("\n\t\t请输入功能前的序号选择服务项目:");
  a = getch();
 }
 switch(a) {
  case '1': WriteData_wb(Creat(Creat_num()));
   printf("\n新建文件成功且数据已成功保存\n");
   system("cls");
   addStudent();
  break;
  case '2': WriteData_ab(Creat(Creat_num()));
    printf("\n数据已成功添加\n");
   system("cls");
   addStudent();
  break;
  case '3': system("cls");
   getch();
   menu();
  break;
 }
}

//二级菜单之查询数据
void query()
{
 system("cls");
 while(1)
 {
 system("CLS");
 system("color C");
 printf("\t\t\t★★★★★查询数据※※※※※\n");
 printf("\n\n\n\n\n\t\t\t※※※※※※※※※※※※※※\n");
 printf("\t\t\t※      ※\n");
 printf("\t\t\t※  1.全部查询  ※\n");
 printf("\t\t\t※------------------------※\n");
 printf("\t\t\t※  2.学号查询  ※\n");
 printf("\t\t\t※------------------------※\n");
 printf("\t\t\t※  3.姓名查询  ※\n");
 printf("\t\t\t※------------------------※\n");
 printf("\t\t\t※  4.返回菜单  ※\n");
 printf("\t\t\t※------------------------※\n");
 printf("\t\t\t※※※※※※※※※※※※※※\n");
 printf("\n\t\t请输入功能前的序号选择服务项目:");
 int a = 0;
 a = getch();

 while(a!='1'&&a!='2'&&a!='3'&&a!='4')
  {
   printf("\n错误，请输入正确的号码!\n");
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
 printf("\n\t\t请输入您要添加的数据个数:");
 int n;
 if(scanf("%d", &n)!=1) {
  printf("\a error!");
 }
 return n;
}
//二级菜单之修改数据/
void change()
{
 system("cls");
 getch();
 while(1)
 {
 system("CLS");
 system("color A");
 printf("\t\t\t★★★★★★修改数据※※※※※\n");
 printf("\n\n\n\n\n\t\t\t※※※※※※※※※※※※※※\n");
 printf("\t\t\t※      ※\n");
 printf("\t\t\t※  1.删除记录  ※\n");
 printf("\t\t\t※------------------------※\n");
 printf("\t\t\t※  2.修改记录  ※\n");
 printf("\t\t\t※------------------------※\n");
 printf("\t\t\t※  3.返回菜单  ※\n");
 printf("\t\t\t※------------------------※\n");
 printf("\t\t\t※※※※※※※※※※※※※※\n");
 printf("\n\t\t请输入功能前的序号选择服务项目:");

 int a = 0;
 a = getch();

 while(a!='1'&&a!='2'&&a!='3')
 {
  printf("错误，请输入正确的号码!\n");
  a = getch();
  }
  switch(a) {
   case '1': delStudent();
    printf("\n\n已成功删除指定数据\n");
    system("pause");
    getch();
   break;
   case '2': change1();
     printf("\n\n已成功修改指定数据\n");
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

//输入输出提示栏
void menu_print_in() {
 printf("------------------------------------------------------------------------\n");
 printf("学号  姓名  性别 年龄 电话   地址  生日 邮件 \n");
 printf("------------------------------------------------------------------------\n");
}
void menu_print_out(void) {
 printf("--------------------------------------------------------------------------\n");
 printf("学号  姓名  性别 年龄 电话   地址  生日 邮件 \n");
 printf("--------------------------------------------------------------------------\n");
}

//主函数
int main()
{
 start();
 return 0;
}
