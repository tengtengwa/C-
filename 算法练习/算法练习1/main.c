







/*

//Dijkstra算法
#include<stdio.h>
int main()
{
    int i,j,e[10][10],book[10]={0},a,b,c,n,m,u,v,min,dis[10];
    int inf=999999999;

    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(i==j) e[i][j]=0;
            else e[i][j]=inf;
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        e[a][b]=c;
    }
    for(i=1;i<=n;i++) dis[i]=e[1][i];
    book[1]=1;
    //Dijkstra算法核心
    for(i=1;i<=n-1;i++)
    {
        min=inf;
        for(j=1;j<=n;j++)
        {
            if(book[j]==0 && dis[j]<min)
            {
                min=dis[j];
                u=j;
            }
        }
        book[u]=1;
        for(v=1;v<=n;v++)
        {
            if(e[u][v]<inf)
            {
                if(dis[v]>dis[u]+e[u][v]) dis[v]=dis[u]+e[u][v];
            }
        }
    }
    for(i=1;i<=n;i++) printf("%d ",dis[i]);
    printf("\n");
}

*/

/*

//变态最大值
#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,n,min,max,Max,a[10010],flag;

    while(scanf("%d",&n)!=EOF)
    {
        flag=1;
        for(i=1;i<=n;i++) scanf("%d",&a[i]);
        min=999999999;
        max=-666666;
        Max=-666666;
        for(j=1;j<=n;j+=3)
        {
            for(i=j;i<=j+2;i++)
            {
                if(flag%2==0)
                {
                    if(a[i]<min) min=a[i];
                }
                else if(flag%2!=0)
                {
                    if(a[i]>max) max=a[i];
                }
            }
            flag++;
        }
            if(n==3) Max=max;
            else
            {
                if(Max<max) Max=max;
                if(Max<min) Max=min;
            }
        printf("%d\n",Max);
    }

}

*/

/*

//1204 寻找子串位置
#include<stdio.h>
#include<string.h>
int main()
{
    char a[110],b[110];
    int lena,lenb,flag,t,i,j;

    scanf("%s %s",a,b);
    lena=strlen(a);
    lenb=strlen(b);
    flag=1;
    for(i=0;i<lena;i++)
    {
        if(b[0]==a[i])
        {
            t=i;
            for(j=0;j<lenb;j++)
            {
                if(b[j]!=a[i++]) flag=0;
            }
            if(flag==1) break;
        }
    }
    if(flag==1) printf("%d\n",t+1);
}

*/

/*

#include<stdio.h>
#include<string.h>
int arr[10];
int main()
{
	int n,x,y,i,j;
	int flag,temp,k;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&x,&y);
		for(i=x;i<=y;i++)
		{
			memset(arr,0,sizeof(arr));//要注意在每输入一个数都要将数组清零，不然当后面一个数为零时，输入不进去，所以一开始就将它初始化为零
			flag=k=0;
			temp=i;
			while(temp)//存数
			{
				arr[k++]=temp%10;
				if(temp%10>6)
				{
					flag=1;
					break;
				}
				temp/=10;
			}

			if(flag==0)
			{
				for(j=0;j<4;j++)
				{
					if(arr[j]==arr[j+1]&&arr[j+1]==arr[j+2])
					{
						flag=1;
						break;
					}
				}

				for(j=0;j<5;j++)
				{
					if((arr[j]-arr[j+1]<-4)||(arr[j]-arr[j+1]>4))
					{
						flag=1;
						break;
					}
				}
			}

			if(flag==0)
			{
				for(j=5;j>=0;j--)
					printf("%d",arr[j]);
				printf("\n");
			}


		}
		if(n!=0)
			printf("\n");
	}

	return 0;
}

*/

/*

//733-万圣节派对
#include<stdio.h>
#include<memory.h>
int main()
{
    int n,a,b,i,j,c[10],flag,t,sum;

    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&a,&b);
        for(i=a;i<=b;i++)
        {
            memset(c,0,sizeof(c));
            flag=1;
            t=i;
            j=0;
            sum=0;          //记录i的位数
            while(t>=1)
            {
                c[j++]=t%10;
                t/=10;
                sum++;
            }

            for(j=0;j<sum-2;j++) if(c[j]==c[j+1] && c[j]==c[j+2]) flag=0;
            for(j=0;j<sum-1;j++) if(abs(c[j]-c[j+1])>4) flag=0;
            if(flag==1)
            {
                for(j=0;j<6-sum;j++) printf("0");
                printf("%d\n",i);
            }
        }
        if(n) printf("\n");
    }
}

*/

/*

//大数加法
#include<stdio.h>
#include<string.h>
char s1[1000], s2[1000];
int n1[1000], n2[1000];//全局变量默认为所有元素初始值为0
int sum[1010];//同上

int fab()
{
    int i,j;
	while (scanf("%s %s", &s1, &s2) != EOF)//多组实例测试，让你加个够~
	{
		memset(n1, 0, sizeof(n1));
		memset(n2, 0, sizeof(n2));//每次计算要先把整形数组所有位归零，别忘啦
		for (i = 0; i < strlen(s1); i++)//第一个数字倒序存入整形数组n1
		{
			n1[i] = s1[strlen(s1) - 1 - i] - '0';
		}
		for (i = 0; i < strlen(s2); i++)//第二个倒序存入n2
		{
			n2[i] = s2[strlen(s2) - 1 - i] - '0';
		}
		for (i = 0; i < (strlen(s1) >= strlen(s2) ? strlen(s1) : strlen(s2)); i++)//开始愉快的加法环节~
		{
			sum[i] = n1[i] + n2[i];//一位一位加，不能一口吃个胖子
			if (sum[i] >= 10)//然后就是进位检查啦
			{
				sum[i + 1]++;
				sum[i] -= 10;
			}
		}
		for (i = (strlen(s1) >= strlen(s2) ? strlen(s1) : strlen(s2)); i >= 0; i--)//在这里我们从可能的最高位开始检查
		{
			if (sum[i] != 0)//直到某位不为0
			{
				for (j = i; j >= 0; j--)//然后一口气输出吧！
				{
					printf("%d", sum[j]);
				}
				break;//然后呢？跳出外层for啦~
			}
		}
		printf("\n");//换个行，回家吃饭~
	}
	return 0;
}

int main()
{
    int n;

    scanf("%d",&n);
    while(n--)
    {
        scanf("")

    }

}

*/

/*

//广搜
#include<stdio.h>
#include<string.h>

struct note
{
    int x;
    int y;
    int f;
    int s;
};

int main()
{
    struct note que[2501];
    int head,tail;
    int a[51][51],book[51][51];
    int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int i,j,k,m,n,startx,starty,p,q,tx,ty,flag;

    scanf("%d%d",&m,&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++) scanf("%d",&a[i][j]);
    scanf("%d %d %d %d",&startx,&starty,&p,&q);     //起点终点坐标

    head=1; tail=1;
    que[tail].x=startx;
    que[tail].y=starty;
    que[tail].f=0;
    que[tail].s=0;
    tail++;
    book[startx][starty]=1;
    flag=0;

    while(head<tail)
    {
        for(k=0;k<=3;k++)
        {
            tx=que[head].x+next[k][0];
            ty=que[head].x+next[k][1];
            if(tx<1 || tx>n || ty<1 || ty>n) continue;
            if(a[tx][ty]==0 && book[tx][ty]==0)
            {
                book[tx][ty]=1;
                que[tail].x=tx;
                que[tail].y=ty;
                que[tail].f=head;
                que[tail].s=que[head].s+1;
                tail++;
            }
            if(tx==p && ty==q)
            {
                flag=1;
                break;
            }
        }
        if(flag==1) break;
        head++;
    }
    printf("%d",que[tail-1].s);
    getchar();  getchar();

}

*/

/*

//2857 括号的匹配
#include<stdio.h>
#include<string.h>
int main()
{
    int top,i,j,n,len,flag;
    char a[1000],s[1000];

    scanf("%d",&n);
    while(n--)
    {
        flag=1;
        scanf("%s",a);
        top=0;
        len=strlen(a);
        if(len==0) printf("TRUE\n");
        else
        for(i=0;i<len;i++)
        {
            if(a[i]=='(' || a[i]=='[' || a[i]=='{' || a[i]=='<')
            {
                s[top++]=a[i];
            }
            else if(a[i]==')')
            {
                if(s[top-1]=='(') top--;
                else s[top++]=a[i];         //注意，如果当前元素不匹配栈顶元素，则进栈
                for(j=0;j<top;j++) if(s[j]=='<') flag=0;
            }
            else if(a[i]==']')
            {
                if(s[top-1]=='[') top--;
                else s[top++]=a[i];
                for(j=0;j<top;j++) if(s[j]=='(' || s[j]=='<') flag=0;
            }
            else if(a[i]=='>')
            {
                if(s[top-1]=='<') top--;
                else s[top++]=a[i];
            }
            else if(a[i]=='}')
            {
                if(s[top-1]=='{') top--;
                else s[top++]=a[i];
                for(j=0;j<=top;j++) if(s[j]=='(' || s[j]=='[' || s[j]=='<') flag=0;
            }
        }
        if(top==0 && flag==1) printf("YES\n");
        else printf("NO\n");
    }
}

*/

/*

//2058 括号序列
#include<stdio.h>
#include<string.h>
int main()
{
    int top,i,n,len;
    char a[1000],s[1000];

    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",a);
        top=0;
        len=strlen(a);
        if(len==0) printf("TRUE\n");
        else
        for(i=0;i<len;i++)
        {
            if(a[i]=='(' || a[i]=='[' || a[i]=='{' || a[i]=='<')
            {
                s[top++]=a[i];
            }
            else if(a[i]==')')
            {
                if(s[top-1]=='(') top--;
                else s[top++]=a[i];         //注意，如果当前元素不匹配栈顶元素，则进栈

            }
            else if(a[i]==']')
            {
                if(s[top-1]=='[') top--;
                else s[top++]=a[i];
            }
            else if(a[i]=='>')
            {
                if(s[top-1]=='<') top--;
                else s[top++]=a[i];
            }
            else if(a[i]=='}')
            {
                if(s[top-1]=='{') top--;
                else s[top++]=a[i];
            }
        }
        if(top==0) printf("TRUE\n");
        else printf("FALSE\n");
    }
}

*/

/*

#include<stdio.h>
int main()
{
    int i,j,a[110],n,max=0,min=0;

    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=1;i<n;i++)
    {
        if(a[i]<a[min]) min=i;
        if(a[i]>a[max]) max=i;
    }
    printf("%d %d\n",a[min],a[max]);
}

*/

/*

#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,min,max;
    char a[110][50];

    scanf("%d",&n);
    min=0;    max=0;
    for(i=0;i<n;i++) scanf("%s",a[i]);
    for(i=1;i<n;i++)
    {
        if(strcmp(a[max],a[i])>0) min=i;
    }
    for(i=1;i<n;i++)
    {
        if(strcmp(a[max],a[i])<0) max=i;
    }
    printf("%s %s\n",a[min],a[max]);
}

*/


/*

//217-a letter and a number
#include<stdio.h>
int main()
{   int N,y,sum;
    char x;

    scanf("%d",&N);
    while(N--)
    {
        sum=0;
        fflush(stdin);
        scanf("%c%d",&x,&y);
        if(x-'A'<26) sum=(x-'A'+1)+y;
        else sum=y-(x-'a'+1);
        printf("%d\n",sum);
    }
}

*/


/*

//216-A problem is easy
#include<stdio.h>
int main()
{
    int T,N,i,j,x;
    scanf("%d",&T);
    while(T--)
    {
        x=0;
        scanf("%d",&N);
        for(i=1;i*i<N;i++)      //循环条件???
        {
            j=(N-i)/(i+1);
            if(i*j+i+j==N && i<=j)
                x++;
        }
        printf("%d\n",x);
    }
}

*/

/*

//216-A problem is easy
#include<stdio.h>
int main()
{   int N,i,j,n,count;

    scanf("%d",&N);
    while(N--)
    {
        count=0;
        scanf("%d",&n);
        for(j=1;j<n;j++)
        {
            for(i=1;i<=j;i++) if((i*j+i+j)==n) count++;
        }
        printf("%d\n",count);
    }
}

*/

/*

//204-Coin Test
#include<stdio.h>
int main()
{   int n,m,i,count,max;
    double rate;
    char a[65536];

    scanf("%d",&n);
    scanf("%s",&a);
    count=0;
    for(i=0;i<n;i++)
    {
        if(a[i]=='U') count++;
        else if(a[i]=='S') break;
    }
    rate=count*1.0/n;
    if(i!=n) printf("Bingo");
    else
    {
        if(rate>=0.497 && rate<=0.503)
        {
            for(i=2;i<n;i++)
            {
                if(count%i==0 && n%i==0) max=i;
            }
            printf("%d/%d\n",count/max,n/max);
        }
        else printf("Fail\n");
    }
}

*/

/*

//198-数数
#include<stdio.h>
int main()
{   int N,i,a[20],len,n,j;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&n);
        i=0;
        while(n>0)
        {
            a[i++]=n%10;
            n/=10;
        }
        for(j=0;j<i;j++)
        {
            if(a[j]==1) printf("O");
            else if(a[j]==2) printf("T");
            else if(a[j]==3) printf("T");
            else if(a[j]==4) printf("F");
            else if(a[j]==5) printf("F");
            else if(a[j]==6) printf("S");
            else if(a[j]==7) printf("S");
            else if(a[j]==8) printf("E");
            else if(a[j]==9) printf("N");
            else if(a[j]==0) printf("O");
        }
            printf("\n");
    }
}

*/

/*

//169-素数（筛法求素数）
#include<stdio.h>
#define MAX 1000010
int a[MAX];
void yjj()
{
	int i,j;
	for(i=0;i<MAX;++i)
	    a[i]=1;
	a[0]=a[1]=0;
	for(i=2;i<MAX;++i) //筛素数法 1为素数，0为非素数
	{
		if(a[i]==1)                            //如果i是素数
		{
			for(j=i+i;j<MAX;j+=i)       //每次删去i的倍数
			    a[j]=0;
		}
	}
}

int main()
{
	int N;
	yjj();
	scanf("%d",&N);
	while(N--)
	{
		int m,i,j;
		scanf("%d",&m);
		if(a[m]==1)  //m为素数
		    printf("%d\n",m);
		else  //m 不为素数
		{
			i=j=m;  //i向左查找，j向右查找
			while(a[i]==0 && i>=0) i--;
			while(a[j]==0) j++;
			if(i<0)
			    printf("%d\n",j);
			else if(m-i<j-m)
			    printf("%d\n",i);
			else
			    printf("%d\n",j);
		}
	}
	return 0;
}

*/

/*

//168-房间安排
#include<stdio.h>
#include <memory.h>
int main()
{
 int T,N,a,b,c,num[200],i,max;
 scanf("%d",&T);
 while(T--)
 {
    max=0;
    memset(num,0,sizeof(num));
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d%d%d",&a,&b,&c);
        for(i=b;i<b+c;i++)
        {
            num[i]+=a;
            if(num[i]>max) max=num[i];
        }
    }
    printf("%d\n",max);
 }
 return 0;
}

*/

/*

#include<stdio.h>
#include<string.h>
#define n 99
int main()
{
	char a[100],b[100],c[100];
	int i,j,k,up,len1,len2,len3,str[100],str1[100],str2[100],str3[100];
	while(~scanf("%s %s %s",a,b,c))
	{
		memset(str,0,sizeof(str));      memset(str1,0,sizeof(str1));              //不清零就错
		memset(str2,0,sizeof(str2));        memset(str3,0,sizeof(str3));
		len1=strlen(a);     len2=strlen(b);     len3=strlen(c);                               //将数组长度表示出来
		for(k=0,i=len1-1;i>=0;i--)                      //倒过来相加，避免进位问题，然后就是简单相加问题了
		{
			str1[k++]=a[i]-'0';
		}
		for(k=0,i=len2-1;i>=0;i--)
		{
			str2[k++]=b[i]-'0';
		}
		for(k=0,i=len3-1;i>=0;i--)
		{
			str3[k++]=c[i]-'0';
		}
		for(i=0;i<=n-3;i++)                                 //因为输出第99个数，str1[],str2[],str3[]这里有三个数，相加后算为一个数
		{
			for(up=0,j=0;j<=n;j++)
			{
				str[j]=str1[j]+str2[j]+str3[j]+up;
				up=str[j]/10;
				str[j]=str[j]%10;
			}
			for(j=0;j<=n;j++)                   //类似于母牛生母牛的迭代，只是多加了一个数
			{
				str1[j]=str2[j];
				str2[j]=str3[j];
				str3[j]=str[j];
			}
		}
		for(i=n;i>=0;i--)                               //去掉前面多余的0
		{
			if(str[i]) break;
		}
		if(len1==1&&len2==1&&len3==1&&a[0]=='0'&&b[0]=='0'&&c[0]=='0')          //这里坑了，0+0+0=0，大意了
		{
			printf("0\n");
		}
		for(k=i;k>=0;k--)
		{
			printf("%d",str[k]);
		}
		printf("\n");
	}
	return 0;
}

*/

/*

#include<stdio.h>
void move(int n,char x,char y,char z)
{
    if(n==1) printf("%c -> %c\n",x,z);
    else
    {
        move(n-1,x,z,y);
        printf("%c -> %c\n",x,z);
        move(n-1,y,x,z);
    }
}
int main()
{   int n;

    while(1)
    {
        printf("输入层数:\n");
        scanf("%d",&n);
        printf("移动步骤:\n");
        move(n,'1','2','3');
    }
}


*/



/*

#include<stdio.h>

void f ();

int main ()
{
    int n;
    scanf("%d", &n);

    while (n)
    {
        f();
        n--;
    }
    return 0;
}

void f ()
{
    int a[99], i, j, k, m, n, b;
    scanf("%d", &m);

    for ( i = 0; i < m; i++ ) {
        scanf("%d", &a[i]);
    }

    for ( i = 0; i < m; i++ ) {
        n = 0;
        for ( j = 0; j < m; j++ ) {
            if ( a[i] == a[j] ) {
                n++;
            }
        }
        if ( n > b ) {
            k = a[i];
            b = n;
        }
    }

    printf("%d %d\n", k, b);
}

*/



/*

//最多125位,小数点最多75位
//将浮点数化成整数,并计算出扩大了多少倍
//整数部分高精度快速幂, 扩大倍数n*log10()直接计算出小数点位置

#include<stdio.h>
#include<memory.h>
#include<string.h>

void mul(int *a,int *b)
{   int i,j;
	int temp,c[250];
	memset(c,0,sizeof(c));
	for(i=0;i<125;i++)
    {
		int nC=0;
		for(j=0;j<125;j++)
		{
			temp=c[i+j]+a[j]*b[i]+nC;
			nC=temp/10;
			c[i+j]=temp%10;
		}
	}
	memcpy(a,c,sizeof(c));
}

int main()
{
	char str[8];
	char astr[150];
	int n,len,dot,i,k;
	int ans[250];
	int base[250];
	while(scanf("%s",str)!=EOF)
    {
		memset(ans,0,sizeof(ans));
		memset(base,0,sizeof(base));
		memset(astr,'0',sizeof(astr));
//
		scanf("%d",&n);
		len=strlen(str);
		ans[0]=1;
		int j=0;
		dot=0;
		for(i=len-1;i>=0;i--)
        {
			//找到小数点的位置
			if(str[i]=='.')
				dot=len-i-1;
			//整数放入base
			if(str[i]!='.')
				base[j++]=(str[i]-'0');
        }

		dot *=n;

		//大幂幂
		while(n>0)
		{
			if(n&1) mul(ans,base);
			mul(base,base);
			n>>=1;
		}

		//处理结果
		//数和点都放到字符串数组
		j=0;

		int count=0;//记录小数点后第一个不为0的位置 ,无小数点则为0

		if(dot!=0)              //有小数点
		{
			for(i=0;i<150;i++)
			{
				if(dot!=i)
				{
					astr[j] = ans[i]+'0';
					j++;
				}
				else if(dot==i)
				{
					astr[j]= '.';
					j++;
					astr[j]= ans[i]+'0';
					j++;
				}
			}
			//找 小数点后的零
			for(k=0;k<124;k++)
			{
				if(astr[k]!='0')
				{
					count=k;
					break;
				}
			}
			//小数点位置等于count,就是小数点后面没有有效数字,+1不输出小数点
			if(count==dot)
				count++;
		}
		else                            //无小数点
		{
			for(i=0;i<150;i++)
			{
				astr[j++] = ans[i]+'0';
			}
		}



		//输出
		int flag=0;
		for(i=124;i>=count;i--)
		{
			if(flag!=0)
				printf("%c",astr[i]);
			else if(astr[i]!='0')
			{
					printf("%c",astr[i]);
					flag=1;
			}
		}
		printf("\n");
    }
}

*/
