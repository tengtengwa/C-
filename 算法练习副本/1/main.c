






/*

//(三)
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int N,x,a[100100],cha[100100],sum,i,j;

    while(scanf("%d",&N)!=EOF && N!=0)
    {
        sum=1;
        for(i=1;i<=N;i++) scanf("%d",&a[i]);
        for(i=1;i<N;i++)
        {
            for(j=i+1;j<=N;j++)
            {
                cha[sum++]=abs(a[j]-a[i]);
            }
        }
        sum-=1;
        for(i=1;i<sum;i++)
        {
            for(j=i+1;j<=sum;j++)
            {
                if(cha[i]>cha[j])
                {
                    cha[i]=cha[i]^cha[j];
                    cha[j]=cha[i]^cha[j];
                    cha[i]=cha[i]^cha[j];
                }
            }
        }
        if(sum%2==0) printf("%d\n",cha[sum/2]);
        else printf("%d\n",cha[(sum+1)/2]);
    }
}

*/











/*

//(二)I

//枚举法，把猜测的数字建立一个结构体，方便后续的比较，
//枚举每一个四位数，和猜测的数字进行比较，求出共有的数字个数
//和共有数字个数、位置都相等的数字个数，和题目中给出的这两个数值相比，
//如果都相等，则说明符合条件。

#include <stdio.h>
#include <string.h>
typedef struct
{
    char n[5];
    int num, pos;
}no;
no node[103];
int judge(int i, int j)
{
    int p, q, nr = 0, pr = 0, vis[4] = {0};     //nr==right num; pr==pos right
    char num[5];
    sprintf(num, "%d", i);//把i作为整数类型写入字符串num
    for(p = 0 ; p < 4 ; p++)
    {
        for(q = 0 ; q < 4 ; q++)
        {
            if(!vis[q] && num[q] == node[j].n[p])
            {
                nr++;
                vis[q] = 1; //也是防止重复的数出现。不过这里是为了防止外重循环里的数
                break;  //如果发现两个数中已经有共有的数了，直接break，防止重复的数出现，导致nr多加 （防止内重循环）
            }
        }
    }
    for(p = 0 ; p < 4 ; p++)
    {
        if(num[p] == node[j].n[p])
            pr++;
    }
    if(nr == node[j].num && pr == node[j].pos) return 1;
    return 0;

}
int main()
{
    int cou, ans, t, flag, i, j;
    while(scanf("%d", &t), t!=0)
    {
        cou = 0;
        for(i = 0 ; i < t ; i++)
            scanf("%s %d %d", node[i].n, &node[i].num, &node[i].pos);
        for(i = 1000 ; i < 10000 ; i++)//枚举每一个四位数
        {
            flag = 1;
            for(j = 0 ; j < t ; j++)//依次和第j个猜的数进行匹配
            {
                if(!judge(i, j))
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)//如果和每一个数匹配都符合条件，就把总符合条件数的个数+1
            {
                ans = i;
                cou++;
            }
        }
        if(cou == 1)        //仅有一个四位数满足条件
            printf("%d\n", ans);
        else
            printf("Not sure\n");
    }
    return 0;
}

*/

/*

#include <stdio.h>
int main()
{
    long long a,b,yellow,green,blue,y_need,g_need,b_need,min;

    while(scanf("%lld %lld",&a,&b)!=EOF)
    {
        scanf("%lld %lld %lld",&yellow,&green,&blue);
        y_need=yellow*2-a;   b_need=3*blue-b;   g_need=2*green;
        min=y_need+b_need+g_need;

        g_need=;
        a-=green;   b-=green;
        y_need=yellow*2-a;   b_need=3*blue-b;
        if(min>y_need+b_need+g_need) min=y_need+b_need+g_need;
        printf("%lld\n",);
    }
}

*/

/*

//J
#include <stdio.h>
int main()
{
    int N;
    long long x,y,l,r,max;

    scanf("%d",&N);
    while(N--)
    {
        max=0;
        scanf("%lld %lld",&l,&r);
        for(x=l;x<=r;x++)
        {
            for(y=x;y<=r;y++)
            {
                if((x|y)>max) max=x|y;
            }
        }
        printf("%lld\n",max);
    }
}

*/

/*

//H - 遇到百分之百的女孩/ HDU 七夕节

//普通做法（超时）
#include <stdio.h>
int main()
{
    int N,n,i,j,sum;

    scanf("%d",&N);
    while(N--)
    {
        sum=0;
        scanf("%d",&n);
        for(i=1;i<=n/2;i++)
        {
            if(n%i==0) sum+=i;
        }
        printf("%d\n",sum);
    }
}

*/

/*

//正解：打表

#include <stdio.h>
#define MAX 500010
static int table[MAX] = {0};

void Table()
{
    int i,j;
    for (i = 1; i < MAX / 2; i++)
    {
        for (j = i + i; j < MAX; j += i)
        {
            table[j] += i;
        }
    }
}

int main()
{
    Table();
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", table[x]);
    }
    return 0;
}

*/

/*

//G - 我怀疑这游戏里根本没有五星
#include <stdio.h>
#include<memory.h>
int main()
{
    int N,a,b,i,j,num[100100],head,end;

    while(scanf("%d",&N),N!=0)
    {
        memset(num,0,sizeof(num));
        scanf("%d %d",&a,&b);
        for(j=a;j<=b;j++) num[j]+=1;
        head=a;    end=b;
        for(i=1;i<N;i++)
        {
            scanf("%d %d",&a,&b);
            if(a<head) head=a;
            if(b>end) end=b;
            for(j=a;j<=b;j++) num[j]+=1;
        }
        for(i=head;i<=end;i++)
        {
            printf("%d ",num[i]);
        }
        printf("\n");
    }
}

*/

/*

//同上
#include <stdio.h>
#include <string.h>
#define maxn 100005
int main()
{
    int n,x,y,i,f[maxn];
    while(scanf("%d",&n)&&n)
    {
        memset(f,0,sizeof(f));
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            f[x]++;
            f[y+1]--;
        }
        printf("%d",f[1]);
        for(i=2;i<=n;i++)
        {
            f[i]+=f[i-1];
            printf(" %d",f[i]);
        }
        printf("\n");
    }
    return 0;
}

*/

/*

//F - Excalibur(圆桌会议)
#include <stdio.h>
int main()
{
	int n  ;
	while(~scanf("%d",&n))
	{
		int a = n/2 , b = n - a ;
		int sum = (a*(a-1))/2 + (b*(b-1))/2 ;
		printf("%d\n",sum) ;
	}
	return 0 ;
}

*/

/*

//E - 猜想滞销，帮帮小明
#include<stdio.h>
int main()
{
    int n,i,j,t,count,a[20],wei,hui,b[100];

    while(scanf("%d",&n)!=EOF)
    {
        count=0;    j=0;
        do
        {

            t=n;    i=0;    wei=0;
            while(t>0)
            {
                a[i++]=t%10;
                t/=10;
                wei++;          //记录位数
            }
            t=1;    hui=0;
            for(i=wei-1;i>=0;i--)
            {
                hui+=a[i]*t;
                t*=10;
            }
            if(n+hui==hui*2)        //变换前后都是回文数
            {
                printf("%d\n",count);
                b[j++]=n;
            }

            else
            {
                b[j++]=n;
                n+=hui;
                count++;
            }
        }while(n+hui!=hui*2);
        t=j;
        for(i=0;i<j;i++)
        {
            if(i<t-1) printf("%d--->",b[i]);
            else
            printf("%d\n",b[i]);
        }

    }
}

*/

/*

//C - 9102年啦
#include<stdio.h>
//1、将每个节目的开始时间排序；
//2、采用贪心算法：优先选择结束时间end最早的节目，且这个节目的开始时间要晚于上一个节目的结束时间
int main()
{
    int n, s[110]={0}, t[110]={0}, i, j, a, b;
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0)
            break;
        for(i=0; i<n; i++)
            scanf("%d%d",&s[i],&t[i]);
        for(i=0; i<n-1; i++)
        {
            for(j=0; j<n-i-1; j++)
            {
                if(t[j] > t[j+1])
                {
                    a = t[j];
                    t[j] = t[j+1];
                    t[j+1] = a;
                    b = s[j];
                    s[j] = s[j+1];
                    s[j+1] = b;
                }
            }
        }
        int sum=1, k=0;
        for(i=1; i<n; i++)  //依次找到第i个节目，要求第i个节目的开始时间start不早于第i-1个节目的结束时间end
        {
            if(s[i]>=t[k])
            {
                sum ++;
                k = i;
            }
        }
        printf("%d\n",sum);
    }
}

*/

/*

//D - 梦
#include<stdio.h>
#include<string.h>

struct fruit
{
    char type[100];
    char place[100];
    int num;
}fru[110];

struct fruit tem;


int main()
{
    int N,n,i,j,len;
    char t[100],nums;    //nums是地名的数量

    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%s %s %d",fru[i].type,fru[i].place,&fru[i].num);
        for(i=1;i<n;i++)            //按地名的首字母顺序排序结构体
        {
            for(j=i+1;j<=n;j++)
            {
                if(fru[i].place[0]-fru[j].place[0]>0)
                {
                    tem=fru[i];
                    fru[i]=fru[j];
                    fru[j]=tem;
                }
            }
        }

        for(i=1;i<n;i++)            //按fruit type的首字母顺序排序结构体
        {
            for(j=i+1;j<=n;j++)
            {
                if(fru[i].type[0]-fru[j].type[0]>0)
                {
                    tem=fru[i];
                    fru[i]=fru[j];
                    fru[j]=tem;
                }
            }
        }

        t[0]=fru[1].place;
        for(i=1;i<=n;i++)
        {
            if(fru[i].place==t)
            {
                len=strlen(fru[i].place);
                for(j=0;j<len;j++)
                printf("%c",fru[i].place[j]);
                printf("\n");
                printf("\t|----%s",fru[i].type);
            }


        }


    }
}

*/

/*

//C - 9102年啦
#include<stdio.h>
int main()
{
    int N,i,a[110],b[110];

    while(scanf("%d",&N),N!=0)
    {
        for(i=0;i<N;i++)
        {




        }



    }
}

*/

/*

//A - TANG的新密码（假）
#include<stdio.h>
int main()
{
    int n,k,i,j,t,count;

    while(scanf("%d %d",&n,&k)!=EOF)
    {
        count=0;
        for(j=0;j<=n/k;j++)
        {
            t=0;
            for(i=1;i<=k;i++)
            {
                if(count<n)
                {
                    printf("%c",'a'+t);
                    count++;
                }
                t++;
            }
        }
        printf("\n");
    }
}

*/















/*

//Y - Mishka and Contest
#include<stdio.h>
int main()
{
    int n,k,count,i,a[100],head,end,t;

    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        head=0;    end=n-1;    count=0;    t=head;
        while(head<=end)
        {
            if(a[head]>k && a[end]>k) break;        //船头和船尾的盆友都超重
            else if(a[head]<=k && a[end]>k)
            {
                count++;
                head++;
            }
            else if(a[end]<=k && a[head]>k)
            {
                count++;
                end--;
            }
            else
            {
                if(t==head)
                {
                    count++;
                    head++;
                    t=end;
                }
                else if(t==end)
                {
                    count++;
                    end--;
                    t=head;
                }
            }

        }
        printf("%d\n",count);
    }
}

*/

/*

//W - Antipalindrome
#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,len;
    char s[50],a;

    while(scanf("%s",&s)!=EOF)
    {
        len=strlen(s);
        for(i=0,j=len-1;i<len/2;i++,j--)
        {
            if(s[i]==s[j]) continue;
            else break;
        }
        if(len%2==0)
        {
            if(i!=len/2) printf("%d\n",len);        //不是回文
            else
            {
                a=s[0];
                for(i=1;i<len;i++)
                {
                    if(s[i]==a) continue;
                    else break;
                }
                if(i==len) printf("0\n");         //输入的字母全部相同
                else printf("%d\n",len-1);
            }
        }
        else
        {
            if(i!=(len-1)/2) printf("%d\n",len);
            else
            {
                a=s[0];
                for(i=1;i<len;i++)
                {
                    if(s[i]==a) continue;
                    else break;
                }
                if(i==len) printf("0\n");         //输入的字母全部相同
                else printf("%d\n",len-1);
            }
        }
    }
}

*/

/*

//T - Adjacent Replacements
#include<stdio.h>
int main()
{
    int n,a[1000],i,j;

    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=0;i<n;i++)
        {
            if(a[i]%2==0) a[i]-=1;
            printf("%d",a[i]);
            if(i<n) printf(" ");
        }
        printf("\n");
    }
}

*/

/*

//Q - Pizza, Pizza, Pizza!!!
#include<stdio.h>
int main()
{
    long long int n,cut;

    while(scanf("%lld",&n)!=EOF)
    {
        n+=1;
        if(n==1) cut=0;
        else
        {
            if(n%2==0) cut=n/2;
            else
            cut=n;
        }
        printf("%lld\n",cut);
    }
}

*/

/*

//X - Fingerprints
#include<stdio.h>
int main()
{
    int a,b,a1[100],a2[100],i,j;

    while(scanf("%d%d",&a,&b)!=EOF)
    {
        for(i=0;i<a;i++) scanf("%d",&a1[i]);
        for(i=0;i<b;i++) scanf("%d",&a2[i]);
        for(i=0;i<a;i++)
        {
            for(j=0;j<b;j++)
            {
                if(a1[i]==a2[j]) printf("%d ",a2[j]);
            }
        }
        printf("\n");
    }
}

*/

/*

//V - Tram
#include<stdio.h>
int main()
{
    int n,a,b,min,i,t,now;  //t为某一站少了或多了的人数,now为当前车上的人数

    scanf("%d",&n);
    min=0; t=0; now=0;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        if(b-a>=0) now+=b-a;
        else now-=a-b;

        if(t+now>min) min=t+now;     //多了的人数

    }
        printf("%d\n",min);
}

*/

/*

//U - Team
#include<stdio.h>
int main()
{
    int N,a,b,c,count,i;

    scanf("%d",&N);
    count=0;
    for(i=0;i<N;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a+b+c>=2) count++;
    }
    printf("%d\n",count);
}

*/

/*

//S - 懒惰的杨队
#include<stdio.h>
#include<string.h>
int main()
{
    int N,i;
    char s[100],start,end;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%s",&s);
        if(strlen(s)<=10) for(i=0;i<strlen(s);i++) printf("%c",s[i]);
        else
        {
            start=s[0];
            end=s[strlen(s)-1];
            printf("%c%d%c",start,strlen(s)-2,end);
        }
        printf("\n");
    }
}

*/

/*

//R - 首字母变大写
#include<stdio.h>
#include<string.h>
int main()
{
    int i;
    char s[100];

    while(gets(s))
    {

        for(i=0;i<strlen(s);i++)
        {
            if(i==0) s[0]-=32;
            if(s[i]==' ') s[i+1]-=32;
            printf("%c",s[i]);
        }
        printf("\n");
    }
}

*/

/*

#include<stdio.h>
int main()
{
    int N,i,n,sum,a;

    scanf("%d",&N);
    while(N--)
    {
        sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            sum+=a;
        }
        printf("%d\n",sum);
        if(N>0)
        printf("\n");
    }
}

*/

/*

//错哪了？？？

//P - 泰泰学长的信
#include<stdio.h>
#include<string.h>
int main()
{
    int N,i,j,t,start,end;
    char s[10000];

    scanf("%d",&N);
    while(N--)
    {
        fflush(stdin);
        gets(s);
        t=0;
        start=0;
        for(i=start;i<strlen(s);i++)
        {
            if(s[i]==' ')
            {
                for(j=t-1;j>=start;j--)
                printf("%c",s[j]);
                printf(" ");
                start=t+1;
                while(s[i+1]==' ')
                {
                    printf(" ");
                    i++;
                    start++;
                    t++;
                }
            }
            t++;

            if(i==strlen(s)-1)
            {
                for(j=t-1;j>=start;j--)
                printf("%c",s[j]);
                start=t;
            }
        }
        printf("\n");
    }
}

*/

/*

#include<stdio.h>
#include<string.h>
//HDU Text Reverse 题解
int main()
{
    int T=0,j;
    scanf("%d",&T);
    getchar();  //记得读取回车
    char oneline[1000];
    while(T--)
    {
        gets(oneline);   //处理某一行，规则是设立标记位，然后判断空格，将读取的一个单词倒序输出
        int begin=0,end=0;
        int i=0;
        int len=strlen(oneline);
        while(i<=len)
        {
            while(oneline[i]!=' ' && oneline[i]!='\0')
            {
                i++;
            };
            end=i-1;
            for(j=end;j>=begin;j--)
                printf("%c",oneline[j]);
            if(oneline[i]==' ')
                printf("%c",' ');
            begin=i+1;
            i++;
        }
        printf("\n");
    }
    return 0;
}

*/

/*

//O - 统计元音
#include <stdio.h>
int main()
{
 int n,m=0,j,a=0,e=0,i=0,o=0,u=0,p;
 scanf("%d",&n);
 char str[100],k;
 k=getchar();
 for(p=1;p<=n;p++)
 {
  while(scanf("%c",&str[m])&&str[m]!='\n')
   m++;
  for(j=0;j<m;j++)
  {
   switch(str[j])
   {
   case 'a':a++;break;
   case 'e':e++;break;
      case 'i':i++;break;
   case 'o':o++;break;
   case 'u':u++;break;
   }
  }
  printf("a:%d\n",a);
  printf("e:%d\n",e);
  printf("i:%d\n",i);
  printf("o:%d\n",o);
  printf("u:%d\n",u);
  if(p!=n)
   printf("\n");
  m=0;
  a=0,e=0,i=0,o=0,u=0;
 }
 return 0;
}

*/

/*
    ???
//O - 统计元音
#include<stdio.h>
#include<string.h>
int main()
{
    int N,a,e,i,o,u,j;
    char s[101];

    scanf("%d",&N);
    while(N--)
    {
        fflush(stdin);
        gets(s);
        a=0; e=0; i=0; o=0; u=0;
        for(j=0;j<strlen(s);j++)
        {
            if(s[j]=='a') a++;
            if(s[j]=='e') e++;
            if(s[j]=='i') i++;
            if(s[j]=='o') o++;
            if(s[j]=='u') u++;
        }
        printf("a:%d\n",a);
        printf("e:%d\n",e);
        printf("i:%d\n",i);
        printf("o:%d\n",o);
        printf("u:%d\n",u);
        if(N) printf("\n");
    }
}

*/

/*

#include<stdio.h>
int main()
{
    int n,a,b,c,i;
    float t;

    while(scanf("%d",&n),n!=0)
    {
        a=0; b=0; c=0;
        for(i=0;i<n;i++)
        {
            scanf("%f",&t);
            if(t<0) a++;
            else if(t==0) b++;
            else if(t>0) c++;
        }
        printf("%d %d %d\n",a,b,c);
    }
}

*/

/*

#include<stdio.h>
#include<memory.h>
#include<string.h>
int main()
{
    int N,i,count;
    char s[1000];

    scanf("%d",&N);
    while(N--)
    {
        count=0;
        memset(s,0,sizeof(s));
        scanf("%s",&s);
        for(i=0;i<strlen(s);i++) if(s[i]>='0' && s[i]<='9') count++;
        printf("%d\n",count);
    }
}

*/

/*

#include<stdio.h>
int main()
{
    int n,a,i,sum;

    while(scanf("%d",&n)!=EOF)
    {
        sum=1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            if(a%2!=0) sum*=a;
        }
        printf("%d\n",sum);
    }
}

*/

/*

#include<stdio.h>
int f(int y)    //判断是否为闰年
{
    if(y%400==0) return 1;
    {
        if(y%100!=0 && y%4==0) return 1;
        else return 0;
    }
}

int main()
{
    int y,m,d,sum,i;
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    while(scanf("%d/%d/%d",&y,&m,&d)!=EOF)
    {
        sum=0;
        if(f(y)==1)
        {
            for(i=0;i<m-1;i++)
            {
                sum+=month[i];
            }
            if(m>2) sum+=1;     //caution
        }
        else
        {
            for(i=0;i<m-1;i++)
            {
                sum+=month[i];
            }
        }
        sum+=d;
        printf("%d\n",sum);
    }

}

*/

/*

#include<stdio.h>
#include<math.h>
int main()
{
    double x1,y1,x2,y2,l;

    while(scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2)!=EOF)
    {
        l=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        printf("%.2f\n",l);


    }

}

*/

/*

#include<stdio.h>
int main()
{
    int N,n,a,sum,i;

    scanf("%d",&N);
    while(N--)
    {
        sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            sum+=a;
        }
        printf("%d\n\n",sum);
    }
}

*/

/*

//Let the Balloon Rise
#include <stdio.h>
#include <string.h>
int main()
{
    int n,i,j,num[1000];
    int max=0,t=0;
    char color[1000][16];
    while(scanf("%d",&n)!=EOF)
    {
        if(n)
        {
            num[0]=0;
            scanf("%s",color[0]);
            for(i=1;i<n;i++)
            {
                num[i]=0;
                scanf("%s",color[i]);
                for(j=0;j<i-1;j++)
                    if(strcmp(color[i],color[j])==0) num[i]+=1;
            }
            max=0;
            t=0;
            for(i=1;i<n;i++)
               if(max<num[i])
               {
                   max=num[i];
                   t=i;}
            printf("%s\n",color[t]);
        }
    }
}

*/

/*

//编写程序，将一个文本文件每一行内容逆置后存入原文件（不能使用其他文件）
#include<stdio.h>
#include<string.h>
int main()
{   int i,j,count=0,len;
	char ch[1000],ch1[1000];
    FILE *fp;

    if((fp=fopen("C:\\Users\\111\\Desktop\\zuonie.txt","r+"))==NULL) printf("cannot open the file\n");
    i=0;
	while(!feof(fp))
	{
		ch[i++]=fgetc(fp);
		count++;
	}
	i--;
	j=0;
	while(i>=0)
	{
		ch1[j++]=ch[i--];
	}
    fclose(fp);

    if((fp=fopen("C:\\Users\\111\\Desktop\\zuonie.txt","r+"))==NULL) printf("cannot open the file\n");
    for(i=0;i<count;i++)
    {
    	fwrite(&ch1[i],sizeof(char),1,fp);
	}
    fclose(fp);
    printf("order changed suceessfully\n");
}

*/


/*

//从键盘向stu.dat文件写入10条学生记录（包括学号、姓名、性别、班级、家庭住址等信息）。
//然后读出这些记录，并按班级、学号的顺序输出到屏幕
#include<stdio.h>
#include<string.h>
#define N 10
struct student
{
	char num[20];
	char name[20];
	char sex[10];
	int class;
	char address[50];
}stu[N];

int main()
{	int i,j,n;
	FILE *fp;
	struct student tem;

	if((fp=fopen("C:\\Users\\111\\Desktop\\stu.dat.txt","w"))==NULL) printf("cannot open this file\n");
	for(i=0;i<N;i++)
	{
		printf("依次输入第%d学生的学号、姓名、性别、班级、家庭住址:\n",i+1);
		scanf("%s%s%s%d%s",stu[i].num,stu[i].name,stu[i].sex,&stu[i].class,stu[i].address);
		fwrite(&stu[i],sizeof(stu),1,fp);
	}
	printf("你想按什么顺序输出?\n");
	printf("1.按班级\t2.按学号\n");
	fflush(stdin);
	scanf("%d",&n);
	if(n==1)		//按班级升序输出
	{
		for(i=0;i<N-1;i++)
		{
			for(j=i+1;j<N;j++)
			{
				if(stu[i].class>stu[j].class)
				{
					tem=stu[i];
					stu[i]=stu[j];
					stu[j]=tem;
				}
			}
		}
	}
	else if(n==2)				//按学号升序输出
	{
		for(i=0;i<N-1;i++)
		{
			for(j=i+1;j<N;j++)
			{
				if(strcmp(stu[i].num,stu[j].num)<0)
				{
					tem=stu[i];
					stu[i]=stu[j];
					stu[j]=tem;
				}
			}
		}
	}

	printf("学号     姓名   性别 班级    家庭住址\n");
	printf("____________________________________________\n");

	for(i=0;i<N;i++)
	{
		printf("%s %s %s %d %s\n",stu[i].num,stu[i].name,stu[i].sex,stu[i].class,stu[i].address);
	}
}

*/

/*

//编写函数，实现两个文本文件的比较。若相等，则返回0；否则返回第一次不相等的两个字符的ASCII码的差值
#include<stdio.h>
#include<string.h>
int main()
{	int sum;
	char ch1,ch2;
	FILE *p1,*p2;

	if((p1=fopen("C:\\Users\\111\\Desktop\\zuonie.txt","r"))==NULL) printf("cannot open this file\n");
	if((p2=fopen("C:\\Users\\111\\Desktop\\lll.txt","r"))==NULL) printf("cannot open this file\n");
	sum=0;
	while(!feof(p1) && !feof(p2))
	{
		ch1=getc(p1);
		ch2=getc(p2);
		if(ch1!=ch2)
			break;
	}
	fclose(p1);
	fclose(p2);
	printf("%d\n",abs(ch1-ch2));
}

*/

/*

//将一个文件的内容追加（复制）到另一个文件中
#include<stdio.h>
int main()
{   char ch;
    FILE *p1,*p2;

    if((p1=fopen("C:\\Users\\111\\Desktop\\zuonie.txt","a"))==NULL) printf("cannot open the file\n");
    if((p2=fopen("C:\\Users\\111\\Desktop\\lll.txt","r"))==NULL) printf("cannot open the file\n");
	ch=getc(p2);
	while(!feof(p2))
	{
		putc(ch,p1);
		ch=getc(p2);
	}
    fclose(p1);
    fclose(p2);
    printf("file append sucessfully\n");
}

*/

/*

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
	char num[15];
	char name[20];
	int math;
	int clanguage;
	int english;
	int chinese;
}stu[60];

char filename[20];

void Filename()
{
    printf("输入你想编辑的文件:\n");
    scanf("%s",&filename);
}


void login()
{
	system("cls");
	printf("\n\n\n\t\t\t学生信息管理系统1.0\n\n");
	printf("\t\t\t制作猿:腾腾儿娃\n\n\n\n");
	system("pause");
}

int menu()
{	int c;

	do
	{
		system("cls");
		printf("\n\n\n\t\t\t功能列表\n");
		printf("  ____________________________________________________\n");
		printf("\t1.录入学生信息\t\t2.查询和修改学生信息\n");
		printf("\t3.信息排序\t\t4.删除信息\n");
		printf("\t5.退出系统\n");
		printf("\n功能选择:\n");
		scanf("%d",&c);

	}while(c>5 || c<1);
	return c;
}

int add()
{	int i=0,n=0;
	FILE *fp;
	char sign='y';

	system("cls");
	while(sign!='n' && sign!='N')
	{
		printf("\n\n~~~~~~~~~~~学生信息录入~~~~~~~~~\n\n");
		printf("输入学生的学号:\n");
		scanf("%s",stu[i].num);
		printf("输入学生的姓名:\n");
		scanf("%s",stu[i].name);
		printf("分别输入学生的数学，C语言，语文和英语成绩:\n");
		scanf("%d%d%d%d",&stu[i].math,&stu[i].clanguage,&stu[i].chinese,&stu[i].english);
		printf("\n信息录入成功,是否继续录入(y/n)?\n");
		fflush(stdin);
		scanf("%c",&sign);
		i++;	n++;
		system("cls");
	}

	if((fp=fopen("filename","a"))==NULL)
	{
		printf("Error! Can not open the file\n");
		return;
	}
	for(i=0;i<n;i++)
	{
		if((fwrite(&stu[i],sizeof(stu),1,fp)) !=1)
		printf("file write error\n");
		fclose(fp);
		system("pause");
	}
}

int scan()
{	int i=0,n;
	char sign='y';
	FILE *fp;

	void amend();
	system("pause");
	if(fopen("filename","r")==NULL)
	{
		printf("cannot read the file!\n");
		system("pause");
		return;
	}
	while(!feof(fp))
	{
		fread(&stu[i],sizeof(stu),1,fp);
		n++;
	}
	system("cls");
	printf("___________________________________________________\n");
	printf("\t学号 姓名 数学 语文 英语 C语言\n");
	printf("___________________________________________________\n");
	for(i=0;i<n-1;i++);
	printf("\t%s  %s  %d  %d  %d  %d\n",stu[i].num,stu[i].name,stu[i].math,stu[i].clanguage,stu[i].chinese,stu[i].english);
	printf("\n\n是否需要修改信息?(y/n)\n");
	fflush(stdin);
	scanf("%c",&sign);
	if(sign=='y') amend();
	system("cls");

}

void amend()
{
	return 0;
}


int main()
{
	login();
	Filename();
	for(;;)
	{
		switch(menu())
		{
			case 1:
				add();
				break;
			case 2:
				scan();
				break;
			case 3:
				printf("程序猿偷了个懒，还没开放这个功能~\n");
				system("pause");
				break;
			case 4:
				printf("程序猿偷了个懒，还没开放这个功能~\n");
				system("pause");
				break;
			case 5:
				printf("程序猿偷了个懒，还没开放这个功能~\n");
				exit(0);


		}
	}

}

*/



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
 for(i=1;i<=n;i++) {
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
 struct Student *p1, *p2;//s = p1;p = p2;

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
 p1 = ReadData();
 p2 = p1->next;
 head = p1;
 while(p2!=NULL)
 {
  if(strcmp(p1->num,str_num)==0) {
   WriteData_wb(p2);
  }
  else if(strcmp(p2->num,str_num)==0) {
   p1->next = p2->next;
   WriteData_wb(head);
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



/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
# define LEN sizeof(struct Student)
struct Student {
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
 struct Student *p1, *p2;//s = p1;p = p2;

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
 p1 = ReadData();
 p2 = p1->next;
 head = p1;
 while(p2!=NULL)
 {
  if(strcmp(p1->num,str_num)==0) {
   WriteData_wb(p2);
  }
  else if(strcmp(p2->num,str_num)==0) {
   p1->next = p2->next;
   WriteData_wb(head);
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
  printf("\n\n\n\n\n\n\n\n\n\t\t\t⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙\n");
  printf("\t\t\t⊙        ⊙\n");
  printf("\t\t\t⊙ 欢迎使用学生信息管理系统 ⊙\n");
  printf("\t\t\t⊙        ⊙\n");
  printf("\t\t\t⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙⊙\n");
  printf("\n\t\t\t\t系统开始启动.........\n");
  printf("===============================================================================\r");
  int i;
  for(i=1;i<80;i++)
  {
   Sleep(40);
   printf(">");
  }
  system("CLS");
 welcome();
}
void welcome()//登录界面
{
 system("CLS");
 system("color 2");
 printf("\n\n\n\n\n\n\t\t\t★★★★★★★★★★★★★★★★\n");
 printf("\t\t\t★       ★\n");
 printf("\t\t\t★ 欢迎使用学生信息管理系统 ★\n");
 printf("\t\t\t★       ★\n");
 printf("\t\t\t★  设计者：吴敬超  ★\n");
 printf("\t\t\t★       ★\n");
 printf("\t\t\t★  日期：2016.7.1  ★\n");
 printf("\t\t\t★       ★\n");
 printf("\t\t\t★★★★★★★★★★★★★★★★\n");

 printf("\n\t\t\t按任意键继续...");
 getchar();
 system("CLS");
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
 printf("\t\t\t★★★★★★主菜单※※※※※\n");
 printf("\n\n\n\n\n\t\t\t※※※※※※※※※※※※※※\n");
 printf("\t\t\t※      ※\n");
 printf("\t\t\t※  1.录入学生信息  ※\n");
 printf("\t\t\t※------------------------※\n");
 printf("\t\t\t※  2.查询学生信息  ※\n");
 printf("\t\t\t※------------------------※\n");
 printf("\t\t\t※  3.修改学生信息  ※\n");
 printf("\t\t\t※------------------------※\n");
 printf("\t\t\t※  4. 退出系统  ※\n");
 printf("\t\t\t※------------------------※\n");
 printf("\t\t\t※※※※※※※※※※※※※※\n");
 printf("\n\t\t请输入功能前的序号选择服务项目:");

 int a = 0;
 a = getchar();

 while(a!='1'&&a!='2'&&a!='3'&&a!='4') {
  printf("错误，请输入正确的号码!\n");
  putchar('\a');
  getchar();
  printf("\n\t\t请输入功能前的序号选择服务项目:");
  a = getchar();
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
 getchar();
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
 getchar();
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
 a = getchar();

 while(a!='1'&&a!='2'&&a!='3')
 {
  printf("错误，请输入正确的号码!\n");
  putchar('\a');
  getchar();
  printf("\n\t\t请输入功能前的序号选择服务项目:");
  a = getchar();
 }
 switch(a) {
  case '1': WriteData_wb(Creat(Creat_num()));
   printf("\n新建文件成功且数据已成功保存\n");
    system("pause");
   system("cls");
   addStudent();
  break;
  case '2': WriteData_ab(Creat(Creat_num()));
    printf("\n数据已成功添加\n");
    system("pause");
   system("cls");
   addStudent();
  break;
  case '3': system("cls");
   getchar();
   menu();
  break;
 }
}

//二级菜单之查询数据
void query()
{
 system("cls");
 getchar();
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
 a = getchar();

 while(a!='1'&&a!='2'&&a!='3'&&a!='4')
  {
   printf("错误，请输入正确的号码!\n");
   putchar('\a');
   getchar();
   printf("\n\t\t请输入功能前的序号选择服务项目:");
   a = getchar();
  }
  switch(a) {
   case '1': display();system("pause");getchar();
   break;
   case '2': query_num();system("pause");getchar();
   break;
   case '3': query_name();system("pause");getchar();
   break;
   case '4': system("cls");getchar();menu();
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
 getchar();
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
 a = getchar();

 while(a!='1'&&a!='2'&&a!='3')
 {
  printf("错误，请输入正确的号码!\n");
  putchar('\a');
  getchar();
  printf("\n\t\t请输入功能前的序号选择服务项目:");
  a = getchar();
  }
  switch(a) {
   case '1': delStudent();
    printf("\n\n已成功删除指定数据\n");
    system("pause");
    getchar();
   break;
   case '2': change1();
     printf("\n\n已成功修改指定数据\n");
    system("pause");
     getchar();
   break;
   case '3': system("cls");
    getchar();
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

*/





