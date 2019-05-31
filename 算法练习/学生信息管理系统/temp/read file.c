#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"head.h"


int read_stu_num()
{
    FILE *fp;
    if((fp=fopen("E:\\user_stu.txt","r"))==NULL)
    return 0;
    fseek(fp,0,SEEK_END);
    return (ftell(fp)/40);
    fclose(fp);
}

int read_manager_num()
{
    FILE *fp;
    if((fp=fopen("E:\\user_manager.txt","r"))==NULL)
    return 0;
    fseek(fp,0,SEEK_END);
    return (ftell(fp)/40);
    fclose(fp);
}
