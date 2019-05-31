











/*

//输出n的全排列
#include <stdio.h>
int n,a[30],book[10];

int dfs(int cur)
{
    int i,j;

    if(cur==n+1)    //到达边界，输出一种排列
    {
        for(i=1;i<=n;i++) printf("%d",a[i]);
        printf("\n");
    }
    else{
        for(i=1;i<=n;i++)
        if(book[i]==0)
        {
            book[i]=1;
            a[cur]=i;       //将第i个数放入当前数组位置（将第i个扑克牌放入当前盒子中）
            dfs(cur+1);
            book[i]=0;
        }
    }
}

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        dfs(1);
    }
}

*/

/*

#include <stdio.h>

int hasSelect[10];
int store[10], id, n, m;

void DFS(int k){
    int i;

	if(k == m){
		for(i = 0; i < m; ++i) printf("%d", store[i]);
		printf("\n");
		return;
	}
	for(i = 1; i <= n; ++i){
		if(!hasSelect[i]){
			store[k] = i;
			hasSelect[i] = 1;
			DFS(k + 1);
			hasSelect[i] = 0;
		}
	}
}

int main(){
	int t, i;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);

		for(i = 0; i < 10; ++i) hasSelect[i] = 0;
		id = 0;

		DFS(0);
	}
	return 0;
}

*/


/*

//19-擅长排列的小明
#include<stdio.h>
int m,n,a[15];

void dfs(int cur){
	int i,j;
	if(cur==m+1){
		for(i=1;i<=m;i++)
		printf("%d",a[i]);
		printf("\n");
	}
	else{
		for(i=1;i<=n;i++)
        {
			int flag=1;         //flag为0时，代表前面的数中已经有i，所以后面不能取i
            for(j=1;j<=cur-1;j++)
            {
                if(a[j]==i) flag=0;
            }
            if(flag)
            {
                a[cur]=i;
                dfs(cur+1);
            }
		}
	}
}
int main(){
	int cases,i,j,cur;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d %d",&n,&m);
		dfs(1);         //从a[1]开始
	}
	return 0;
}

*/

/*

//5-Binary String Matching
#include<stdio.h>
#include<string.h>
int main()
{
    int N,sum,i,j,t,lena,lenb;
    char a[20],b[1020];

    scanf("%d",&N);
    while(N--)
    {
        sum=0;
        scanf("%s %s",a,b);
        lena=strlen(a);
        lenb=strlen(b);
        for(i=0;i<lenb-lena+1;i++)
        {
            t=i;
            for(j=0;j<lena;j++)
            {
                if(a[j]-b[t++]==0) continue;
                else break;
            }
            if(j==lena) sum++;
        }
        printf("%d\n",sum);
    }
}

*/

/*

//599-奋斗的小蜗牛
#include<stdio.h>
int main()
{
    int N,n,i,h;

    scanf("%d",&N);
    while(N--)
    {
        n=0;
        scanf("%d",&h);
        if(h<=10) printf("1\n");
        else{
        while(h>10)
        {
            h-=5;
            n++;
        }
        n+=1;
        printf("%d\n",n);
        }
        if(N) printf("\n");
    }
}

*/

/*

//24-素数距离问题
#include<stdio.h>
#include<math.h>
int primeJudge(int pri);
int primePrint(int m);

int main()
{
    int k;
    scanf("%d",&k);
    int num[k],i;
    for(i=0;i<k;i++)
    {
        scanf("%d",&num[i]);    //输入测试数据
        primePrint(num[i]);     //输出符合条件的数
    }

    return 0;
}
int primePrint(int m)
{
    int count=0,j;
    if(primeJudge(m))
            printf("%d %d\n",m,count);
    else
        for(j=1;;j++)
        {
            if(primeJudge(m-j))
            {
                printf("%d %d\n",m-j,count+j);      //向左判断
                break;
            }
             if(primeJudge(m+j))
            {
                printf("%d %d\n",m+j,count+j);      //向右判断
                break;
            }
        }
}
int primeJudge(int pri)
{
    int i;
    for(i=2;i<=sqrt(pri);i++)
        if(pri%i==0)
            i=pri;
    if(i>pri)
        return 0;
    else
        return 1;
}

*/

/*

//2-括号配对问题(只有同类型括号相邻或消去后相邻时才能消去)
#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,n,len;
    char s[10010],t[10010];

    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        t[0]=s[0];
        j=1;
        len=strlen(s);

        for(i=1;i<len;i++)
        {
            if(s[i]=='(' || s[i]=='[')
            {
                t[j++]=s[i];        //相当于进栈
            }
            else if(s[i]==')')
            {
                if(t[j-1]=='(')
                {
                    j--;            //相当于出栈
                }
                else    t[j++]=s[i];    //不匹配栈顶括号，则进栈
            }
            else if(s[i]==']')      //同上
            {
                if(t[j-1]=='[')
                {
                    j--;
                }
                else    t[j++]=s[i];
            }
        }
        if(j==0) printf("Yes\n");
        else printf("No\n");

    }
}

*/

/*

//输出对应的数串
#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,len,j;
    char a[5000]="1";
    int *p1,*p2;
    len=1;

    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        len=len*2+1;
        a[len/2]=i+'0';     //将整型数i赋给字符中间
        p1=&a[len/2+1];
        p2=&a[0];
        strncpy(p1,p2,len/2);  //strncpy(*a,*b,n) 此函数将字符串b中n个字符复制给a,并返回指向a的指针
    }
    for(i=0;i<len;i++) printf("%c",a[i]);
    printf("\n");
}

*/

/*

//517-最小公倍数
#include<stdio.h>
int a[105];
int s[100];
int main()
{
    int a[105];
    int i,j,n,x;
    for(i=1;i<105;i++)
        a[i]=i;
    for(i=1; i<105; i++)
        for(j=i+1; j<105; j++)
            if(a[j]%a[i]==0)
                a[j]=a[j]/a[i];     //将其因子筛去；
    while(~scanf("%d",&n))
    {
        x=0;
        memset(s,0,sizeof(s));
        s[0]=1;
       for(i=1;i<=n;i++)
       {
           for(j=0;j<100;j++)//大数；
           {
               int c=s[j]*a[i]+x;
               s[j]=c%10;
               x=c/10;
           }
       }
       for(i=99;i>=0;i--)
        if(s[i]) break;
       for(j=i;j>=0;j--)
        printf("%d",s[j]);
       printf("\n");
    }
   return 0;
}

*/


/*

//477-A+B Problem III

#include<stdio.h>
int main()
{
    int n;
    double a,b,c;

    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf %lf %lf",&a,&b,&c);

        if(a+b-c<=0.0001 && a+b-c>=-0.0001) //注意: 浮点数运算存在误差在（-0.0001—0.0001），浮点数不能直接等于
        printf("Yes\n");
        else printf("No\n");
    }
}

*/

/*

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

*/


/*

//463-九九乘法表
#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,N,n;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            for(j=i;j<=9;j++)
            {
                printf("%d*%d=%d ",i,j,i*j);
            }
            printf("\n");
        }
            if(N) printf("\n");
    }
}

*/

/*

//457-大小写互换
#include<stdio.h>
#include<string.h>
int main()
{
    int n,i;
    char s[200];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]>='a' && s[i]<='z') s[i]-=32;
            else
            s[i]+=32;
        }
        printf("%s\n",s);
    }
}

*/

/*

//大数阶乘


#include <stdio.h>
int main()
{
	int n,i,j;
	while (scanf("%d",&n)!=EOF)
	{
		int flag=1;
		int carry=0;        //设置进位
		int res=0;
		int str[40000];     //根据题目要求设置数组的大小
		str[0]=1;
		for (i=2;i<=n;i++)   //从2开始计算阶乘
		{
			for (j=1;j<=flag;j++)     //根据进位flag大小来判断当前阶乘结果的的位数
            {
                res=str[j-1]*i+carry;
                str[j-1]=res%10;
                carry=res/10;
            }
			while (carry)  //当进位大于一时将结果扩展到下一位
			{
				flag++;
				str[flag-1]=carry%10;
                carry/=10;
			}
		}
		for (i=flag-1;i>=0;i--)    //将结果数组倒序输出，注意最后一位是"i=flag-1",因为"flag=1" 对应str[0],以此类推
 		{
			 printf("%d",str[i]);
		}
		printf("\n");
	 }
 	return 0;
}

*/


/*

//快排
#include <stdio.h>
int quicksort(int left,int right,int a[])
{
    int i,j,tem;

    if(left>right) return a;    //大前提

    i=left;     j=right;    tem=a[left];    //赋初值
    while(i!=j)     //交换数
    {
        while(a[j]>=tem && i<j) j--;    //注意等号
        while(a[i]<=tem && i<j) i++;
        if(i<j)
        {
            a[i]=a[i]^a[j];
            a[j]=a[i]^a[j];
            a[i]=a[i]^a[j];
        }
    }
    a[left]=a[i];       //归为基准数
    a[i]=tem;

    quicksort(left,i-1,a);      //递归
    quicksort(i+1,right,a);
    return a;
}

int main()
{
    int i,a[20];

    for(i=1;i<=10;i++) scanf("%d",&a[i]);
    quicksort(1,10,a);
    for(i=1;i<=10;i++) printf("%d ",a[i]);
    printf("\n");

}

*/

/*

//升序快排
#include <stdio.h>
int quicksort(int left, int right, int a[])
{
    int i, j;
    int temp, t;
    if (left>right) return a;

    temp = a[left]; //temp中存的就是基准数
    i = left;
    j = right;
    while (i != j)
    {
        while (a[j] >= temp && i<j) j--;     //顺序很重要，要先从右边开始找;  注意等于号!!!
        while (a[i] <= temp && i<j) i++;      //再找zuo边的

        if (i<j)    //交换两个数在数组中的位置
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    //最终将基准数归位
    a[left] = a[i];
    a[i] = temp;

    quicksort(left, i - 1, a);//继续处理左边的，这里是一个递归的过程
    quicksort(i + 1, right, a);//继续处理右边的 ，这里是一个递归的过程
    return a;
}
int main()
{
    int i,j,t,n,a[20];

    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    quicksort(1,n,a); //快速排序调用

    for(i=1;i<=n;i++) printf("%d ",a[i]);
    return 0;
}

*/



/*

//快排

#include <stdio.h>
#include <stdlib.h>

#define n 10

//--------------------------------------------------
//函数名：display
//作用：打印数组元素
//参数：array - 打印的数组，maxlen - 数组元素个数
//返回值：无
//--------------------------------------------------
void display(int array[], int maxlen)
{
    int i;

    for(i = 0; i < maxlen; i++)
    {
        printf("%-3d", array[i]);
    }
    printf("\n");

    return ;
}

//--------------------------------------------------
//函数名：swap
//作用：交换两个数的值
//参数：交换的两个数
//返回值：无
//--------------------------------------------------
void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

    return ;
}

//--------------------------------------------------
//函数名：quicksort
//作用：快速排序算法
//参数：
//返回值：无
//--------------------------------------------------
void quicksort(int array[], int maxlen, int begin, int end)
{
    int i, j;

    if(begin < end)
    {
        i = begin + 1;  // 将array[begin]作为基准数，因此从array[begin+1]开始与基准数比较！
        j = end;        // array[end]是数组的最后一位

        while(i < j)
        {
            if(array[i] > array[begin])  // 如果比较的数组元素大于基准数，则交换位置。
            {
                swap(&array[i], &array[j]);  // 交换两个数
                j--;
            }
            else
            {
                i++;  // 将数组向后移一位，继续与基准数比较。
            }
        }

        // 跳出while循环后，i = j。
        // 此时数组被分割成两个部分  -->  array[begin+1] ~ array[i-1] < array[begin]
        //                          -->  array[i+1] ~ array[end] > array[begin]
        // 这个时候将数组array分成两个部分，再将array[i]与array[begin]进行比较，决定array[i]的位置。
        // 最后将array[i]与array[begin]交换，进行两个分割部分的排序！以此类推，直到最后i = j不满足条件就退出！

        if(array[i] >= array[begin])  // 这里必须要取等“>=”，否则数组元素由相同的值时，会出现错误！
        {
            i--;
        }

        swap(&array[begin], &array[i]);  // 交换array[i]与array[begin]

        quicksort(array, maxlen, begin, i);
        quicksort(array, maxlen, j, end);
    }
}

// 主函数
int main()
{
    int n;
    int array[n] = {12,85,25,16,34,23,49,95,17,61};
    int maxlen = n;

    printf("排序前的数组\n");
    display(array, maxlen);

    quicksort(array, maxlen, 0, maxlen-1);  // 快速排序

    printf("排序后的数组\n");
    display(array, maxlen);

    return 0;
}

*/






/*

#include <stdio.h>
int main(int argc,char*argv[])
{

	int d1,d2,d3;
	int min;
	while(scanf("%d%d%d",&d1,&d2,&d3)==3)
	{
		min=d1+d2+d3;
		if(d1+d2+d3>2*(d1+d2))
			min=2*(d1+d2);
		if(min>2*(d1+d3))
			min=2*(d1+d3);
		if(min>2*(d2+d3))
			min=2*(d2+d3);
		printf("%d\n",min);
	}
}

*/

/*

//324-猴子吃桃问题
#include<stdio.h>
int main()
{
    int N,m,i,sum;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&m);
        sum=1;
        for(i=0;i<m;i++)
        {
            sum=(sum+1)*2;

        }
        printf("%d\n",sum);
    }
}

*/

/*

//277-车牌号
#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
        int m;
        char a[6],c[6];
        scanf("%d",&m);
        getchar();
        while(--m)
        {
            gets(c);
            gets(a);
            if(strcmp(a,c)<0) strcpy(c,a);  //字符串复制(把后面的复制给前面的字符串)
        }                                   //字符串比较:
                                            //当s1<s2时，返回为负数;当s1=s2时，返回值= 0;当s1>s2时，返回正数.
                                            //两个字符串自左向右逐个字符相比（按ASCII值大小相比较），直到出现不同的字符或遇'\0'为止
        puts(c);
	}
	return 0;
}

*/

/*

//276-比较字母大小
#include<stdio.h>
int main()
{
    int N;
    char a,b,c;

    scanf("%d",&N);
    while(N--)
    {
        getchar();//清除输入缓冲区中的空格符
        scanf("%c %c",&a,&b);
        if(a>b) {c='<';}
        if(a==b) {c='=';}
        if(a<b) {c='>';}
        printf("%c%c%c\n",a,c,b);

    }
}

*/

/*

//275-队花的烦恼一(十进制转二进制)
#include<stdio.h>
int main()
{
    int i,n,a[100];

    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) printf("0\n");
        else
        {
            i=0;
            while(n>0)
            {
                a[i++]=n%2;
                n/=2;
            }
            i-=1;;
            for(;i>=0;i--) printf("%d",a[i]);
            printf("\n");
        }

    }
}

*/

/*

//274-正三角形的外接圆面积
#include<stdio.h>
#define pi 3.1415926
int main()
{
    int N;
    double s,r,l;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%lf",&l);
        s=1.0/3.0*pi*l*l;
        printf("%.2f\n",s);
    }
}

*/

/*

//273-字母小游戏
#include<stdio.h>
#include<string.h>
int main()
{
    int N,n,i;
    char s[200],a;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%s",&s);
        n=0;
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]>='a' && s[i]<='z') n++;
        }
        n%=26;
        a='a'-1;
        if(n==0) printf("z\n");
        else
        printf("%c\n",a+n);
    }
}

*/

/*

//268-荷兰国旗问题
#include<stdio.h>
#include<string.h>
int main()
{
    int N,r,b,w,i;
    char s[1000];
    scanf("%d",&N);
    while(N--)
    {
        scanf("%s",&s);
        for(i=0;i<strlen(s);i++) if(s[i]=='R') printf("R");
        for(i=0;i<strlen(s);i++) if(s[i]=='W') printf("W");
        for(i=0;i<strlen(s);i++) if(s[i]=='B') printf("B");
        printf("\n");
    }
}

*/

/*

//266-字符串逆序输出
#include<stdio.h>
#include<string.h>
int main()
{
    int N,i,len1,len2;
    char a[20],b[20];

    scanf("%d",&N);
    while(N--)
    {
        scanf("%s%s",&a,&b);
        len1=strlen(a);
        len2=strlen(b);
        for(i=len2-1;i>=0;i--)
        {
            if(b[i]>'9') printf("%c",b[i]);
        }
        for(i=len1-1;i>=0;i--)
        {
            if(a[i]>'9') printf("%c",a[i]);
        }
        printf("\n");
    }
}

*/

/*

//unsolved question

//264-国王的魔镜
#include<stdio.h>
#include<string.h>
int main()
{
    int N,i,j,len;
    char s[100];

    scanf("%d",&N);
    while(N--)
    {
        scanf("%s",&s);
        len=strlen(s);
        if(len==1) printf("1\n");
        else
        {
            while(len%2==0)
            {
                if(len==2 && s[0]!=s[1]) break;
                for(i=0,j=len-1;i<len/2;i++,j--)
                {
                    if(s[i]==s[j]) continue;
                    else break;
                }
                if(i==len/2) len/=2;
                else break;
            }
            printf("%d\n",len);
        }
    }
}

*/

/*

//263-精挑细选
#include<stdio.h>
int main()
{
    int n,m,i,a,b,c,x,y,z;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        a=0;    b=0;    c=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            if(x>a||x==a && y<b||x==a && y==b && z>c) { a=x;b=y;c=z; }
        }
        printf("%d\n",c);
    }
    return 0;
}

*/

/*

//260-数数小木块
#include<stdio.h>
int main()
{
    int N,n,i,j,sum;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&n);
        sum=0;
        while(n>0)
        {
            for(i=n;i>0;i--) sum+=i;      //第n层的正方体数
            n--;
        }
        printf("%d\n",sum);
    }
}

*/

/*

//259-茵茵的第一课
#include<stdio.h>
#include<string.h>
#include<memory.h>
int main()
{
    int N,i,len;
    char a[20];

    scanf("%d",&N);
    while(N--)
    {
        memset(a,0,sizeof(a));
        scanf("%s",&a);
        len=strlen(a);
        for(i=0;i<len;i++) printf("%c",a[i]);
        printf("\n");
    }
}

*/

/*

//255-C小加 之 随机数
#include<stdio.h>
int main()
{
    int N,n,i,j,a[100],b[100],t,nums;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=0;i<n-1;i++)
        {
            t=a[i];
            for(j=i+1;j<n;j++)
            {
                if(t==a[j]) a[j]=0;
            }
        }
        j=0;
        for(i=0;i<n;i++)
        {
            if(a[i]!=0)
            {
                b[j]=a[i];
                j++;
            }
        }
    //sort
        nums=j;
        for(i=0;i<nums-1;i++)
        {
            for(j=i+1;j<nums;j++)
            {
                if(b[i]>b[j])
                {
                    b[i]=b[i]^b[j];
                    b[j]=b[i]^b[j];
                    b[i]=b[i]^b[j];
                }
            }
        }
        printf("%d\n",nums);
        for(i=0;i<nums;i++) printf("%d ",b[i]);
        printf("\n");
    }
}

*/

/*

//103-A+B Problem II
#include<stdio.h>
#include<string.h>
int main()
{
    char a1[1100],b1[1100];
    int    T;
    while(scanf("%d",&T)!=EOF)
    {
        int i1,i,j,k,k1,La,Lb,t,L;

        for(i1=1;i1<=T;i1++)
        {
            int a[1100]={0},b[1100]={0},c[1100]={0};
            scanf("%s%s",&a1,&b1);
            La=strlen(a1);
            Lb=strlen(b1);
            printf("Case %d:\n",i1);
            for(i=0;i<La;i++)//输出第一个数
            {
                printf("%c",a1[i]);
            }
            printf(" + ");
            for(i=0;i<Lb;i++)//输出第二个数
            {
                printf("%c",b1[i]);
            }
            printf(" = ");
            for(j=La-1,t=0;j>=0;j--,t++)//反序
            {
                a[t]=a1[j]-'0';
            }
            for(k=Lb-1,t=0;k>=0;k--,t++)//反序
            {
                b[t]=b1[k]-'0';
            }
            L=(La>=Lb?La:Lb);
           for(i=0;i<=L-1;i++)//加法运算
           {
               c[i]+=(a[i]+b[i]);
               if(c[i]>=10)     //进位
               {
                   c[i]%=10;
                   c[i+1]++;
               }
           }
           if(c[L]!=0)
           {
               L++;
           }
           for(i=L-1;i>=0;i--)//输出运算结果
           {
               printf("%d",c[i]);
           }
           printf("\n");

        }
    }
    return 0;
}

*/

/*

//244-16进制的简单运算
#include<stdio.h>
#include<string.h>
int main()
{   int N,i,s1,s2,sum;
    char ch;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%x%c%x",&s1,&ch,&s2);
        switch (ch)
        {
        case '+':
            sum=s1+s2;
            printf("%o\n",sum);
            break;

        case '-':
            sum=s1-s2;
            printf("%o\n",sum);
            break;
        }
    }
}

*/

/*

//243-交换输出
#include<stdio.h>
int main()
{   int N,a[100],i,t,min;

    for(;;)
    {
        scanf("%d",&N);
        if(N==0) break;
        for(i=0;i<N;i++) scanf("%d",&a[i]);
        min=a[0];
        for(i=0;i<N;i++)
        {
            if(min>a[i])
            {
                min=a[i];
                t=i;        //记录下标
            }
        }
        if(min!=a[0])       //第一个数不是最小
        {
            a[0]=a[0]^a[t];
            a[t]=a[0]^a[t];
            a[0]=a[0]^a[t];
        }
        for(i=0;i<N;i++)
        printf("%d ",a[i]);
        printf("\n");
    }
}

*/

/*

//242-计算球体积
#include<stdio.h>
#define pi 3.1415926
int main()
{   double r,v;

    while(~scanf("%lf",&r))
    {
        v=4.0/3.0*pi*r*r*r;
        printf("%.0f\n",v);
    }
}

*/

/*

//241-字母统计
#include<stdio.h>
#include<string.h>
#include<memory.h>
int main()
{   int N,len,n,a[26],i,max,tem;
    char s[1010],t;

    scanf("%d",&N);
    while(N--)
    {
        memset(a,0,sizeof(a));  //置零数组
        scanf("%s",&s);
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            n=s[i]-'a';
            a[n]++;             //记录每个字母出现次数
        }
        tem=a[0];   max=0;
        for(i=0;i<26;i++)
        {
            if(tem<a[i])
            {
                max=i;
                tem=a[i];
            }
        }
        t='a'+max;
        printf("%c\n",t);
    }
}

*/

/*

//113-字符串替换
#include<stdio.h>
#include<string.h>
int main()
{   int i;
    char s[1002];

    while(gets(s)!=0)
    {
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]=='y' && s[i+1]=='o' && s[i+2]=='u')
            {
                printf("we");
                i+=2;
            }
            else printf("%c",s[i]);
        }
        printf("\n");
    }
}

*/

/*

//111-分数加减法
#include<stdio.h>
#include<math.h>
int yjj(int n,int m)        //求最大公约数
{
	int t,x;
	if(m>n)
	{t=n;n=m;m=t;}
	while(m)
	{
		x=n%m;
		n=m;
		m=x;
	}
	return n;
}
int main()
{
	int a,b,c,d,e,f;//求和或求差后的e为分子，f为分母
	char ch;
	while(scanf("%d/%d%c%d/%d",&a,&b,&ch,&c,&d)!=EOF)
	{
		int k,temp=1;//tepm判断结果正负，1为正，0为负 ，k为最大公约数
		f=b*d;
		switch(ch)
		{
			case '+':
				e=a*d+b*c;
				break;
			case '-':
				e=a*d-b*c;
				if(e<0)
				{
					e=fabs(e);
					temp=0;
				}
				break;
		}
		if(temp==0) printf("-");
		if(e==0) printf("0\n");
		else if(e%f==0) printf("%d\n",e/f);         //如果结果是整数，直接输出一个整数
		else
		{
			k=yjj(e,f);
			e/=k;
			f/=k;
			printf("%d/%d\n",e,f);
		}
	}
	return 0;
}

*/

/*

//101-两点距离
#include<stdio.h>
#include<math.h>
int main()
{   double x1,y1,x2,y2,t;
    int N;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);      //输入的时候，输入单精度(float型)要用%f而输入双精度(double型)要用%lf
        t=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        printf("%.2f\n",t);
    }
}

*/

/*

//100-1的个数
#include<stdio.h>
int main()
{   int N,i,n,a[20],count;

    scanf("%d",&N);
    while(N--)
    {
        count=0;
        scanf("%d",&n);
        i=0;
        while(n>0)
        {
            a[i]=n%2;
            n/=2;
            i++;
        }
        i-=1;
    for(;i>=0;i--) if(a[i]==1) count++;
    printf("%d\n",count);
    }
}

*/

/*

//97-兄弟郊游问题
#include<stdio.h>
int main()
{   int N,x,y,z,m;
    float t,s;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%d%d%d%d",&m,&x,&y,&z);
        t=x*m*1.0/(y-x);                             //结果是以一样的但为啥要乘1.0?
        s=z*t;
        printf("%.2f\n",s);
    }
}

*/

/*

#include<stdio.h>
int main()
{
    int M,n,t;
    int i,j,k,c;
    scanf("%d",&M);
    for(i=1;i<=M;i++)
        {
            scanf("%d",&n);
            j=0;t=n;c=1;
            while(t)
            {
                t/=10;
                j++;            //j记录n的位数
            }
            for(k=0;k<j-1;k++)
            {
                c=c*10;         //c的大小为(n-1)*10
            }
            printf("%d\n",n%c);
        }

return 0;
}

*/

/*

//96-n-1位数
#include "stdio.h"
#include <string.h>
int main()
{	int N,n,a[20],i,count1,count2;

	scanf("%d",&N);
	while(N--)
	{
	    count2=0;
		scanf("%d",&n);
		i=0;
		while(n>10)
		{
			a[i]=n%10;
			n/=10;
			count2++;
			i++;
		}
		count1=0;
		for(i=count2-1;i>=0;i--)
		{
			if(a[i]==0) count1++;	//记录有多少位是0
			printf("%d",a[i]);
		}
		if(count1==count2) printf("0");		//后n-1位都是0
		printf("\n");
	}
}

*/

/*

//cigarettes
#include <stdio.h>
int main()
{   int N,a,b,i,sum;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%d%d",&a,&b);
        sum=a;
        while(a/b>=1)
        {
            if(a==1) break;
            sum=sum+a/b;
            a/=b;
        }
    printf("%d\n",sum);
    }
}

*/


/*

//找球号(一）
#include <stdio.h>
int main()
{   int n,m,a[1001],b[1101],i,j;

    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++) scanf("%d",&a[i]);

    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        for(j=0;j<m;j++)
        {
            if(b[i]==a[j])
            {
                printf("YES\n");
                break;
            }
        }
        if(j==m) printf("NO\n");
    }
}


*/


/*

//开灯问题
#include <stdio.h>
int main()
{   int n,k,i,j,a[1001];

    scanf("%d%d",&n,&k);
        for(i=1;i<=n;i++) a[i]=1;
        for(j=2;j<=k;j++)
        {
            for(i=j;i<=n;i+=j)
            {
                if(a[i]==0) a[i]=1;
                else a[i]=0;
            }
        }
    for(i=1;i<=n;i++) if(a[i]==1) printf("%d ",i);
}

*/


/*

//日期计算
#include <stdio.h>
int is_runnian(int y)
{
    if(y%400==0) return 1;
    else
    {
        if(y%100 !=0 && y%4==0) return 1;
        else return 0;
    }
}

int main()
{   int N,i,a,b,c,sum;
    int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    scanf("%d",&N);
    while(N--)
    {
        sum=0;
        scanf("%d%d%d",&a,&b,&c);
        if(is_runnian(a))
        {
            for(i=0;i<b-1;i++) sum+=m[i];
            if(b>=2) sum+=(c+1);
            else sum+=c;
        }
        else
        {
            for(i=0;i<b-1;i++) sum+=m[i];
            sum+=c;
        }
    printf("%d\n",sum);
    }
}

*/

/*

//小学生算术
#include <stdio.h>
int main()
{   int i,j,m,n,ge1,shi1,bai1,ge2,shi2,bai2,count;

    while(scanf("%d%d",&m,&n) != EOF, m!=0 && n!=0)
    {
        count=0;
        ge1=m%10;
        ge2=n%10;
        shi1=m/10%10;
        shi2=n/10%10;
        bai1=m/100%10;
        bai2=n/100%10;
        if(ge1+ge2>9)
        {
            shi1+=1;
            count++;
        }
        if(shi1+shi2>9)
        {
            bai1++;
            count++;
        }
        if(bai1+bai2>9) count++;
    printf("%d\n",count);
    }
}

*/

/*

//大数比大小
#include <stdio.h>
#include <string.h>
#define max 1000+10
char s1[max],s2[max];

int main()
{   int i,l1,l2;
    while(scanf("%s%s",s1,s2) != EOF)
    {
        if(s1[0]=='0' && s2[0]=='0' ) break;
        l1=strlen(s1);
        l2=strlen(s2);
        if(s1[0] == '-' && s2[0] != '-') printf("a<b\n");              //s1负，s2正
        else if(s1[0] != '-' && s2[0] == '-') printf("a>b\n");       //s1正，s2负
        else if(s1[0] != '-' && s2[0] != '-')                               //都为正
        {
            if(l1>l2) printf("a>b\n");
            else if(l1<l2) printf("a<b\n");
            else
            {
                if(strcmp(s1,s2)>0) printf("a>b\n");    //两个字符串自左向右逐个字符相比（按ASCII值大小相比较），直到出现不同的字符或遇'\0'为止
                else if(strcmp(s1,s2)<0) printf("a<b\n");
                else printf("a==b\n");
            }
        }
        else                                                                    //都为负
        {
            if(l1>l2) printf("a<b\n");
            else if(l1<l2) printf("a>b\n");
            else
            {
                if(strcmp(s1,s2)>0) printf("a<b\n");
                else if(strcmp(s1,s2)<0) printf("a>b\n");
                else printf("a==b\n");
            }
        }
    }
}

*/

/*

//笨小熊
#include <stdio.h>
#include <memory.h>

#define MAX(x,y) (((x)>(y))?(x):(y))
#define MIN(x,y) (((x)<(y))?(x):(y))

void get_num(int a[], char str[])	            // 得到每个字母出现的个数
{
	int i = 0;
	while (str[i]) a[str[i++]-'a']++;               //循环到字符串结束位置停止循环
}

int is_prime(int x)	// 判断是不是质数
{   int i;
	if (x == 0 || x == 1) return 0;
	for (i=2; i<x; i++)
    {
        if (x%i == 0) return 0;
    }
       if(i==x) return 1;
}

int main()
{
	int T,i; char str[105];
	int a[26], minn, maxn;
	scanf("%d", &T);	                                        // 第一个输入的整数
	while (T--)
	{
		scanf("%s", str);	                                        // 每次输入的单词，注意这里的输入都是小写字母的，没有空格
		minn = 100;	                                            // 将minn设为最大值
		maxn = 0;	                                                // 讲maxn设为最小值
		memset(a, 0, sizeof(a));	                            // 将记录的数组清0，以便下次记录
		get_num(a, str);
		for(i=0;i<26;i++)
			if(a[i])	                                                // 我这个单词一定是要出现过，这样才能判断是不是出现最多的还是最少的,不然会改变最小值
			{
				maxn = MAX(maxn, a[i]);
				minn = MIN(minn, a[i]);
			}	                                                         // 这里不用排序，排序的复杂度至少是O(nlogn)，而得到极值的复杂度只要扫一遍
		if (is_prime(maxn-minn))	                          // 看看最大和最少的差是不是质数
            printf("Lucky Word\n%d\n", maxn-minn);
		else printf("No Answer\n0\n");
	}
}

*/

/*

//另一种阶乘问题
#include<stdio.h>
int main()
{   int N,n,i,j,sum,Sum;
    scanf("%d",&N);
    while(N--)
    {
  Sum=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            sum=1;                  //每次新阶乘前将sum置零
            for(j=1;j<=i;j+=2)
            {
                sum*=j;
            }
                Sum+=sum;
        }
        printf("%d\n",Sum);
    }
}

*/

/*

//鸡兔同笼
#include<stdio.h>
int main()
{   int N,n,m,i,a,b;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%d%d",&n,&m);
        a=n;    b=n-a;              //a为兔子数，b为鸡数
        for(i=1;i<100;i++)
        {
            if((a*4+b*2)==m) break;
            else
            {
                a--;
                b++;
            }
        }
        if(a>=0 && b>=0) printf("%d %d\n",b,a);
        else printf("No answer\n");
    }

}

*/

/*
//十进制转二进制
#include<stdio.h>
#include<string.h>
int a[35];
int main()
{
	int n, i, j;
	while (scanf("%d",&n)!=EOF)
	{
		if(n==0)
		{
			printf("0\n");
			continue;
		}
		i=0;
        while(n!=0)
		{
			a[i++]=n%2;
			n=n/2;
		}
		while (i--)
        printf("%d", a[i]);
		printf("\n");
	}
}

*/


/*

//6174问题
#include <stdio.h>
int sort(int num)
{   int a[4],b[4],i,j,max,min,tem;

        a[0]=num%10;
        a[1]=num/10%10;
        a[2]=num/100%10;
        a[3]=num/1000;
        for(i=0;i<3;i++)
        {
            for(j=i+1;j<4;j++)
            {
                if(a[i]<a[j])
                {
                    a[i]=a[i]^a[j];
                    a[j]=a[i]^a[j];
                    a[i]=a[i]^a[j];
                }
            }
        }
        min=a[3]*1000+a[2]*100+a[1]*10+a[0];
        max=a[0]*1000+a[1]*100+a[2]*10+a[3];
        tem=max-min;
        return tem;
}

int main()
{   int N,num,count,t;

    scanf("%d",&N);
    while(N--)
    {
        count=0;
        scanf("%d",&num);
        t=sort(num);
        while(t !=6174)
        {
            t=sort(t);
            count++;
            if(t==sort(t)) break;
        }
        printf("%d\n",count+2);
    }
}

*/

/*

//阶乘因式分解(一)
#include <stdio.h>
int main()
{   int t;

    scanf("%d",&t);
    while(t--)
    {
        int n,m,sum=0;      //每次更新sum的值

        scanf("%d%d",&n,&m);
        while(n>=m)
        {
        n/=m;
        sum+=n;
        }
        printf("%d\n",sum);
    }
}

*/

/*

//字符数组逆序排列如：<ABCDE-EDCBA>
#include<string.h>
int main()
{   char str[80];
    int i,j;

    printf("Enter a string:");
    scanf("%s",str);                            // 也可以gets(str);puts(str);
    for(i=0,j=strlen(str)-1;i<j;i++,j--)
    {
        str[i]=str[i]+str[j];
        str[j]=str[i]-str[j];
        str[i]=str[i]-str[j];
    }
    printf("Reversed string:%s",str);
}

*/

/*

//大数阶乘
#include <stdio.h>
int main()
{   int a[100001];                                     //储存每一位所得到的数
	int temp,digit,n,i,j=0;                           //temp每次的得数   digit每次得数的位数

	scanf("%d",&n);
	a[0]=1;                                                //从1开始乘
	digit=1;                                               //位数从第一位开始
	for(i=2;i<=n;i++)                                  //乘到n，包括n
	{
		int num=0;                                      //最高位置零
		for(j=0;j<digit;j++)
		{
			temp=a[j]*i+num;                        //将一个数的每一位数都分别乘以i，
			a[j]=temp%10;                            //将一个数的每一位数利用数组进行储存
			num=temp/10;                           //num储存当前最高位
		}
		while(num)                                    //判断退出循环后，num的值是否为0
		{
			a[digit]=num%10;                       //继续储存
			num/=10;
			digit++;
		}
	}
	for(i=digit-1;i>=0;i--)                            //倒序输出每一位
    printf("%d",a[i]);
	printf("\n");
}

*/



/*

//阶乘因式分解（一）

#include <stdio.h>
int main()
{
	int n,m,sum,s;
	scanf("%d",&s);
	while(s--)
	{
		sum=0;
		scanf("%d%d",&n,&m);
		while(n)
		{
			sum+=n/m;
			n=n/m;
		}
		printf("%d\n",sum);
	}
}

*/


/*

//不高兴的小明
#include<stdio.h>
int main()
{   int N,a[7],b[7],c[7],i,j,max,u;
    scanf("%d",&N);
    while(N--)
    {
        max=0;
        for(i=0;i<7;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            c[i]=a[i]+b[i];                 //总时间
        }
        max=c[0];
        u=1;
        for(i=0;i<7;i++)    //判断最长的时间
        {
                if(max<c[i])
                {
                    max=c[i];
                    u=i+1;
                }
        }
        if(max<=8) printf("0\n");
        else printf("%d\n",u);
    }
}

*/

/*

//奇偶数分离
#include<stdio.h>
int main()
{   int N,n,i;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&n);
        for(i=1;i<=n-1;i+=2) printf("%d ",i);
        printf("\n");
        for(i=2;i<=n;i+=2) printf("%d ",i);
        printf("\n\n");
    }
}

*/

/*

//最大公约数和最小公倍数
#include<stdio.h>
int main()
{   int N,m,n,k,a,b;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%d%d",&m,&n);
        if (m<n)
		{
			m=m^n;
			n=m^n;
			m=m^n;
		}

		if (m%n==0)         //m是n的倍数的情况
		{
			printf("%d %d\n",n,m);
		}

		else
		{	//求m，n的最大公约数
			for (k=1;k<n;k++)
			{
				if (m%k==0 && n%k==0)
				{
					a=k;                            // 持续更新公约数，直至最大
				}
			}
			b=m*n/a;//求最小公倍数
			printf("%d %d\n",a,b);
		}
    }
}

*/



/*

//水仙花数
#include<stdio.h>
int main()
{   int i,n,bai,shi,ge;

    while(scanf("%d",&n), n!=0)
    {
        bai=n/100;
        shi=(n/10)%10;
        ge=n%10;
        if((bai*bai*bai+shi*shi*shi+ge*ge*ge)==n) printf("Yes\n");
        else printf("No\n");
    }
}

*/

/*

//韩信点兵
#include<stdio.h>
int main()
{   int a,b,c,min;
    scanf("%d %d %d",&a,&b,&c);
    min=a*70+b*21+c*15;
    while(min>105) min-=105;
    if(min>100 ||min<10 || a>=3 || b>=5 || c>=7) printf("No answer\n");
    else printf("%d\n",min);
}



//韩信点兵法二
#include <stdio.h>
int main()
{
    int a=0,b=0,c=0,x;
    scanf("%d%d%d",&a,&b,&c);
    for (x=10;x<=100;x++)
        if (x%3==a&&x%5==b&&x%7==c)
            {
                printf("%d",x);
                break;
            }
        else if(x==100)
                printf("no answer\n");
}

*/

/*

//设计一个从5个整数中取最小数和最大数的程序
#include<stdio.h>
int main()
{   int i,j,t,a[5],max=0,min=0;

    for(i=0;i<5;i++) scanf("%d",&a[i]);
    for(i=0;i<5;i++)            //先排序
    {
        for(j=i+1;j<5;j++)
        {
            if(a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    max=a[4]; min=a[0]; //
    printf("%d %d",min,max);
}

*/



/*

//求一个三行三列的转置矩阵
#include<stdio.h>
int main()
{   int N,i,a[9];

    scanf("%d",&N);
    while(N--)
    {
        for(i=0;i<9;i++)
        {
            scanf("%d",&a[i]);
        }
        printf("%d %d %d\n",a[0],a[3],a[6]);
        printf("%d %d %d\n",a[1],a[4],a[7]);
        printf("%d %d %d\n\n",a[2],a[5],a[8]);
    }
}

*/




/*

//现在给出你一些数，要求你写出一个程序，输出这些整数相邻最近的素数，并输出其相距长度。
//如果左右有等距离长度素数，则输出左侧的值及相应距离。如果输入的整数本身就是素数，则输出该素数本身，距离输出0

#include<stdio.h>
int main()
{   int N,i,m,l,r,zss,yss;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&m);
        for(i=2;i<m;i++)
        {
            if(m%i==0) break;
        }
        if(m==i) printf("%d 0\n",m);      //m是素数，直接打印
        else                                        //m不是素数
        {
                l=m;    r=m;
                zss=0;
                while( l>=2 && zss==0 )    //寻找左边最近素数
                      {
                            l--;
                            for(i=2;i<l;i++)
                            {
                                if(l%i==0) break;
                            }
                            if(l==i) zss=1;      //找到最近的左素数
                      }
                yss=0;
                while(yss==0)    //寻找右边最近素数
                      {
                            r++;
                            for(i=2;i<r;i++)
                            {
                                if(r%i==0) break;
                            }
                            if(r==i) yss=1;      //找到最近的右素数
                      }
        if(m-l>r-m) printf("%d %d\n",r,r-m);
        else if(m-l<=r-m) printf("%d %d\n",l,m-l);
        }
    }
}

*/

/*

//现在给你N个数（0<N<1000），现在要求你写出一个程序，找出这N个数中的所有素数，并求和
#include<stdio.h>
void main()
{   int n,N,i,j,a[1001],sum;

    scanf("%d",&N);
    while(N--)              //输入轮数
    {
        sum=0;
        scanf("%d",&n);
        for(j=1;j<=n;j++)   //每轮输入的数字数
        {
            scanf("%d",&a[j] );
            for(i=2;i<a[j];i++)
            {
                if(a[j]%i==0) break;            //有别的约数就非素数，跳出循环
            }
            if(i==a[j]) sum+=a[j];
        }
    printf("%d\n",sum);
    }
}

*/


/*

//A number sequence is defined as follows:
//f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.
//Given A, B, and n, you are to calculate the value of f(n).

#include<stdio.h>
void main()
{   int p,n,a,b,i;
    int array[48];

    while( scanf("%d%d%d",&a,&b,&n),a || b || n )       //有逗号运算符的式子的值是最后一个逗号后的式子的值
    {
        array[1]=1; array[2]=1;
            for(i=3;i<48;i++) array[i]=(a*array[i-1]+b*array[i-2]) %7;
                printf("%d\n",array[n%48]);
    }
}

*/



/*

//Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence.
//For example, given (6,-1,5,4,-7), the max sum in this sequence is 6 + (-1) + 5 + 4 = 14

#include<stdio.h>
void main()
{   int N,n,i,j;
    int a[100001];

    scanf("%d",&N);     //输入轮数

    for(j=1;j<=N;j++)
    {
        scanf("%d",&n);             //输入数字的个数
        for(i=1;i<=n;i++) scanf("%d",&a[i]);

        int maxsum=a[i],sum=0,l=1,r=1,teml=1;

        for(i=1;i<=n;i++)
        {
            sum+=a[i];
            if(sum>maxsum)              //sum加了一个正数
            {
                maxsum=sum;
                l=teml;
                r=i;
            }
            if(sum<0)                       //sum加了一个更小的负数
            {
                sum=0;
                teml=i+1;
            }
        }
            printf("Case %d:\n",j);
            printf("%d %d %d\n",maxsum,l,r);
            if(j< N) printf("\n");
    }

}

*/


/*

#include<stdio.h>
int main()
{
    int N;
    int count=1;
    scanf("%d",&N);
    while(N--)
    {
        int n,i;
        int a[100002];

        scanf("%d",&n);

        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);

        int max=a[1];
        int sum=0;
        int l=1,left=1,right=1;

        for(i=1;i<=n;i++)
        {
            sum=sum+a[i];
            if(sum>max)
            {
                max=sum;
                left=l;
                right=i;
            }
            if(sum<0)
            {
                sum=0;
                l=i+1;
            }
        }
        printf("Case %d:\n",count);
        printf("%d %d %d\n",max,left,right);
        if(N)printf("\n");
        count++;
    }
    return 0;
}


*/
