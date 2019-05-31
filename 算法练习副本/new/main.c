






//114-某种序列

#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,len1,len2,len3,q,h,d[100],e[100],f[100],g[100];
	char a[100],b[100],c[100];
	while(scanf("%s %s %s",a,b,c)!=EOF)
	{
	    memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		memset(f,0,sizeof(f));
		len1=strlen(a);
		len2=strlen(b);
		len3=strlen(c);
		if(len1==1&&len2==1&&len3==1&&a[0]=='0'&&b[0]=='0'&&c[0]=='0')
			printf("0\n");
		else
		{   //此处开始是字符串转化为数字
			for( i=0,j=len1-1;j>=0;i++,j--)
				d[i]=a[j]-'0';
			for(i=0,j=len2-1;j>=0;i++,j--)
				e[i]=b[j]-'0';
			for(i=0,j=len3-1;j>=0;i++,j--)
				f[i]=c[j]-'0';
			for(i=0;i<=96;i++)
			{    int k=0;
				for(j=0;j<=99;j++)//此处为大数相加的模版
				{
                    g[j]=d[j]+e[j]+f[j]+k;      //k为进位数
				    k=g[j]/10;
				    g[j]=g[j]%10;
				}
				for(j=0;j<=99;j++)//此处是进行迭代交换····很有技巧·······
				{
					d[j]=e[j];
					e[j]=f[j];
					f[j]=g[j];
				}
			}
			for(i=99;i>=0;i--)
		        if(g[i])break;
			for(j=i;j>=0;j--)
				printf("%d",g[j]);
			printf("\n");
		}
	}return 0;
}







/*

#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,len1,len2,len3,q,h,d[100],e[100],f[100],g[100];
	char a[100],b[100],c[100];
	while(scanf("%s %s %s",a,b,c)!=EOF)
	{
	    memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		memset(f,0,sizeof(f));
		len1=strlen(a);
		len2=strlen(b);
		len3=strlen(c);
		if(len1==1&&len2==1&&len3==1&&a[0]=='0'&&b[0]=='0'&&c[0]=='0')
			printf("0\n");
		else
		{   //此处开始是字符串转化为数字
			for( i=0,j=len1-1;j>=0;i++,j--)
				d[i]=a[j]-'0';
			for(i=0,j=len2-1;j>=0;i++,j--)
				e[i]=b[j]-'0';
			for(i=0,j=len3-1;j>=0;i++,j--)
				f[i]=c[j]-'0';
			for(i=0;i<=96;i++)
			{    int k=0;
				for(j=0;j<=99;j++)//此处为大数相加的模版
				{
                    g[j]=d[j]+e[j]+f[j]+k;      //k为进位数
				    k=g[j]/10;
				    g[j]=g[j]%10;
				}
				for(j=0;j<=99;j++)//此处是进行迭代交换····很有技巧·······
				{
					d[j]=e[j];
					e[j]=f[j];
					f[j]=g[j];
				}
			}
			for(i=99;i>=0;i--)
		        if(g[i])break;
			for(j=i;j>=0;j--)
				printf("%d",g[j]);
			printf("\n");
		}
	}return 0;
}


*/




/*

//数字和标点
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int a[255]={0},i,min,t,sum=0;
    char s[50];

    while(scanf("%s",s))
    {
        for(i=0;i<strlen(s);i++)
        {
            t=s[i]-'a';
            a[t]++;
        }


        for(i=0;i<26;i++)
        {
            if(a[i]!=0) sum++;  //字母总数
        }
        while(sum!=0)
        {
            for(i=0;i<26;i++) if(a[i]!=0) min=i;
            for(i=0;i<26;i++)
            {
                if(a[i]!=0) if(a[i]<a[min]) min=i;
            }
            printf("%c",'a'+min);
            a[min]=0;
            sum--;
        }
        printf("\n");

    }

}

*/

/*

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,i;

    while(scanf("%d",&n))
    {
        if(n==1) printf("false\n");
        else
        {
            while(n%2==0) n/=2;
            while(n%3==0) n/=3;
            while(n%5==0) n/=5;
            if(n!=2 && n!=3 && n!=5 && n!=1) printf("false\n");
            else printf("true\n");
        }

    }

}

*/


/*

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int n,i,t=2;
    char s[500];
    s[0]='1';

    while(scanf("%d",&n))
    {
        if(n==1) printf("1\n");
        else
        {
            for(i=2;i<=n;i++)
            {
                s[i+1]='i';
                s[i+2]=s;

            }
        printf("%s\n",s);
        }

    }


}

*/

/*

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int i,t1,t2,sum=0;
    char s[100];

    while(scanf("%s",s))
    {
        for(i=0;i<strlen(s);i++) if(s[i]=='m') sum++;
        while(sum--)
        {
            for(i=0;i<strlen(s);i++)
            {
                if(s[i]=='m' && s[i+1]=='e') //me相邻
                {
                    s[i]=' '; s[i+1]=' ';
                }
                if(s[i]=='m' && s[i+1]==' ')        //me不相邻
                {
                    t1=i;
                    i++;
                    while(s[i]==' ') i++;
                    if(s[i]=='e')
                    {
                        s[t1]=' ';
                        s[i]=' ';
                    }
                }
            }
        }
            for(i=0;i<strlen(s);i++)
            if(s[i]==' ') continue;
            else printf("%c",s[i]);
            printf("\n");
    }


}

*/










