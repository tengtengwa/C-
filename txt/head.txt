#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#define LEN sizeof(struct stu)
#define M 150

char account[M],passw[M];

struct stu{
	char name[M];
	char num[M];
	int age;
	float C;
	float math;
	float Eng;
	float PE;
	struct stu *next;
};

struct         //Ñ§ÉúÕËºÅÃÜÂë
{
    char account[M];
    char passw[M];
}user_stu[M];

struct        //¹ÜÀíÔ±ÕËºÅÃÜÂë
{
    char account[M];
    char passw[M];
}user_manager[M];

struct stu *head;



int add();

int change1();
int del_infor();
int change();

void chart_print();

struct stu *Creat(int n);
int Creat_num();

int del_stu();
int del_manager();

int pre_login();

int user_manager_login();
int user_stu_login();

int main();

int user_manage();
int stu_m();
int m_m();

int menu_manager();
int menu_stu();

int query_all();
int query_name();
int query_num();
int query_name_num();
int query_stu();
int query_manager();

int read_stu_num();
int read_manager_num();

void WriteData_a(struct stu *head);
void WriteData_w(struct stu *head);

struct stu *ReadData();

int sort_name();
int sort_num();
int sort();

int tongji_3();
int tongji_each();
int tongji();

int user_add_stu();
int user_add_manager();



#endif // HEAD_H_INCLUDED
