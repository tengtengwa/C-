






/*

//(��)
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

//(��)I

//ö�ٷ����Ѳ²�����ֽ���һ���ṹ�壬��������ıȽϣ�
//ö��ÿһ����λ�����Ͳ²�����ֽ��бȽϣ�������е����ָ���
//�͹������ָ�����λ�ö���ȵ����ָ���������Ŀ�и�������������ֵ��ȣ�
//�������ȣ���˵������������

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
    sprintf(num, "%d", i);//��i��Ϊ��������д���ַ���num
    for(p = 0 ; p < 4 ; p++)
    {
        for(q = 0 ; q < 4 ; q++)
        {
            if(!vis[q] && num[q] == node[j].n[p])
            {
                nr++;
                vis[q] = 1; //Ҳ�Ƿ�ֹ�ظ��������֡�����������Ϊ�˷�ֹ����ѭ�������
                break;  //����������������Ѿ��й��е����ˣ�ֱ��break����ֹ�ظ��������֣�����nr��� ����ֹ����ѭ����
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
        for(i = 1000 ; i < 10000 ; i++)//ö��ÿһ����λ��
        {
            flag = 1;
            for(j = 0 ; j < t ; j++)//���κ͵�j���µ�������ƥ��
            {
                if(!judge(i, j))
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)//�����ÿһ����ƥ�䶼�����������Ͱ��ܷ����������ĸ���+1
            {
                ans = i;
                cou++;
            }
        }
        if(cou == 1)        //����һ����λ����������
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

//H - �����ٷ�֮�ٵ�Ů��/ HDU ��Ϧ��

//��ͨ��������ʱ��
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

//���⣺���

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

//G - �һ�������Ϸ�����û������
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

//ͬ��
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

//F - Excalibur(Բ������)
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

//E - �������������С��
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
                wei++;          //��¼λ��
            }
            t=1;    hui=0;
            for(i=wei-1;i>=0;i--)
            {
                hui+=a[i]*t;
                t*=10;
            }
            if(n+hui==hui*2)        //�任ǰ���ǻ�����
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

//C - 9102����
#include<stdio.h>
//1����ÿ����Ŀ�Ŀ�ʼʱ������
//2������̰���㷨������ѡ�����ʱ��end����Ľ�Ŀ���������Ŀ�Ŀ�ʼʱ��Ҫ������һ����Ŀ�Ľ���ʱ��
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
        for(i=1; i<n; i++)  //�����ҵ���i����Ŀ��Ҫ���i����Ŀ�Ŀ�ʼʱ��start�����ڵ�i-1����Ŀ�Ľ���ʱ��end
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

//D - ��
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
    char t[100],nums;    //nums�ǵ���������

    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%s %s %d",fru[i].type,fru[i].place,&fru[i].num);
        for(i=1;i<n;i++)            //������������ĸ˳������ṹ��
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

        for(i=1;i<n;i++)            //��fruit type������ĸ˳������ṹ��
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

//C - 9102����
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

//A - TANG�������루�٣�
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
            if(a[head]>k && a[end]>k) break;        //��ͷ�ʹ�β�����Ѷ�����
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
            if(i!=len/2) printf("%d\n",len);        //���ǻ���
            else
            {
                a=s[0];
                for(i=1;i<len;i++)
                {
                    if(s[i]==a) continue;
                    else break;
                }
                if(i==len) printf("0\n");         //�������ĸȫ����ͬ
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
                if(i==len) printf("0\n");         //�������ĸȫ����ͬ
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
    int n,a,b,min,i,t,now;  //tΪĳһվ���˻���˵�����,nowΪ��ǰ���ϵ�����

    scanf("%d",&n);
    min=0; t=0; now=0;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        if(b-a>=0) now+=b-a;
        else now-=a-b;

        if(t+now>min) min=t+now;     //���˵�����

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

//S - ��������
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

//R - ����ĸ���д
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

//�����ˣ�����

//P - ̩̩ѧ������
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
//HDU Text Reverse ���
int main()
{
    int T=0,j;
    scanf("%d",&T);
    getchar();  //�ǵö�ȡ�س�
    char oneline[1000];
    while(T--)
    {
        gets(oneline);   //����ĳһ�У��������������λ��Ȼ���жϿո񣬽���ȡ��һ�����ʵ������
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

//O - ͳ��Ԫ��
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
//O - ͳ��Ԫ��
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
int f(int y)    //�ж��Ƿ�Ϊ����
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

//��д���򣬽�һ���ı��ļ�ÿһ���������ú����ԭ�ļ�������ʹ�������ļ���
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

//�Ӽ�����stu.dat�ļ�д��10��ѧ����¼������ѧ�š��������Ա𡢰༶����ͥסַ����Ϣ����
//Ȼ�������Щ��¼�������༶��ѧ�ŵ�˳���������Ļ
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
		printf("���������%dѧ����ѧ�š��������Ա𡢰༶����ͥסַ:\n",i+1);
		scanf("%s%s%s%d%s",stu[i].num,stu[i].name,stu[i].sex,&stu[i].class,stu[i].address);
		fwrite(&stu[i],sizeof(stu),1,fp);
	}
	printf("���밴ʲô˳�����?\n");
	printf("1.���༶\t2.��ѧ��\n");
	fflush(stdin);
	scanf("%d",&n);
	if(n==1)		//���༶�������
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
	else if(n==2)				//��ѧ���������
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

	printf("ѧ��     ����   �Ա� �༶    ��ͥסַ\n");
	printf("____________________________________________\n");

	for(i=0;i<N;i++)
	{
		printf("%s %s %s %d %s\n",stu[i].num,stu[i].name,stu[i].sex,stu[i].class,stu[i].address);
	}
}

*/

/*

//��д������ʵ�������ı��ļ��ıȽϡ�����ȣ��򷵻�0�����򷵻ص�һ�β���ȵ������ַ���ASCII��Ĳ�ֵ
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

//��һ���ļ�������׷�ӣ����ƣ�����һ���ļ���
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
    printf("��������༭���ļ�:\n");
    scanf("%s",&filename);
}


void login()
{
	system("cls");
	printf("\n\n\n\t\t\tѧ����Ϣ����ϵͳ1.0\n\n");
	printf("\t\t\t����Գ:���ڶ���\n\n\n\n");
	system("pause");
}

int menu()
{	int c;

	do
	{
		system("cls");
		printf("\n\n\n\t\t\t�����б�\n");
		printf("  ____________________________________________________\n");
		printf("\t1.¼��ѧ����Ϣ\t\t2.��ѯ���޸�ѧ����Ϣ\n");
		printf("\t3.��Ϣ����\t\t4.ɾ����Ϣ\n");
		printf("\t5.�˳�ϵͳ\n");
		printf("\n����ѡ��:\n");
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
		printf("\n\n~~~~~~~~~~~ѧ����Ϣ¼��~~~~~~~~~\n\n");
		printf("����ѧ����ѧ��:\n");
		scanf("%s",stu[i].num);
		printf("����ѧ��������:\n");
		scanf("%s",stu[i].name);
		printf("�ֱ�����ѧ������ѧ��C���ԣ����ĺ�Ӣ��ɼ�:\n");
		scanf("%d%d%d%d",&stu[i].math,&stu[i].clanguage,&stu[i].chinese,&stu[i].english);
		printf("\n��Ϣ¼��ɹ�,�Ƿ����¼��(y/n)?\n");
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
	printf("\tѧ�� ���� ��ѧ ���� Ӣ�� C����\n");
	printf("___________________________________________________\n");
	for(i=0;i<n-1;i++);
	printf("\t%s  %s  %d  %d  %d  %d\n",stu[i].num,stu[i].name,stu[i].math,stu[i].clanguage,stu[i].chinese,stu[i].english);
	printf("\n\n�Ƿ���Ҫ�޸���Ϣ?(y/n)\n");
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
				printf("����Գ͵�˸�������û�����������~\n");
				system("pause");
				break;
			case 4:
				printf("����Գ͵�˸�������û�����������~\n");
				system("pause");
				break;
			case 5:
				printf("����Գ͵�˸�������û�����������~\n");
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
 struct Student *p1, *p2;//s = p1;p = p2;

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



/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
# define LEN sizeof(struct Student)
struct Student {
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
 struct Student *p1, *p2;//s = p1;p = p2;

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
  printf("\n\n\n\n\n\n\n\n\n\t\t\t�ѡѡѡѡѡѡѡѡѡѡѡѡѡѡѡѡѡ�\n");
  printf("\t\t\t��        ��\n");
  printf("\t\t\t�� ��ӭʹ��ѧ����Ϣ����ϵͳ ��\n");
  printf("\t\t\t��        ��\n");
  printf("\t\t\t�ѡѡѡѡѡѡѡѡѡѡѡѡѡѡѡѡѡ�\n");
  printf("\n\t\t\t\tϵͳ��ʼ����.........\n");
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
void welcome()//��¼����
{
 system("CLS");
 system("color 2");
 printf("\n\n\n\n\n\n\t\t\t�����������������\n");
 printf("\t\t\t��       ��\n");
 printf("\t\t\t�� ��ӭʹ��ѧ����Ϣ����ϵͳ ��\n");
 printf("\t\t\t��       ��\n");
 printf("\t\t\t��  ����ߣ��⾴��  ��\n");
 printf("\t\t\t��       ��\n");
 printf("\t\t\t��  ���ڣ�2016.7.1  ��\n");
 printf("\t\t\t��       ��\n");
 printf("\t\t\t�����������������\n");

 printf("\n\t\t\t�����������...");
 getchar();
 system("CLS");
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
 printf("\t\t\t����������˵�����������\n");
 printf("\n\n\n\n\n\t\t\t����������������������������\n");
 printf("\t\t\t��      ��\n");
 printf("\t\t\t��  1.¼��ѧ����Ϣ  ��\n");
 printf("\t\t\t��------------------------��\n");
 printf("\t\t\t��  2.��ѯѧ����Ϣ  ��\n");
 printf("\t\t\t��------------------------��\n");
 printf("\t\t\t��  3.�޸�ѧ����Ϣ  ��\n");
 printf("\t\t\t��------------------------��\n");
 printf("\t\t\t��  4. �˳�ϵͳ  ��\n");
 printf("\t\t\t��------------------------��\n");
 printf("\t\t\t����������������������������\n");
 printf("\n\t\t�����빦��ǰ�����ѡ�������Ŀ:");

 int a = 0;
 a = getchar();

 while(a!='1'&&a!='2'&&a!='3'&&a!='4') {
  printf("������������ȷ�ĺ���!\n");
  putchar('\a');
  getchar();
  printf("\n\t\t�����빦��ǰ�����ѡ�������Ŀ:");
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
 getchar();
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
 a = getchar();

 while(a!='1'&&a!='2'&&a!='3')
 {
  printf("������������ȷ�ĺ���!\n");
  putchar('\a');
  getchar();
  printf("\n\t\t�����빦��ǰ�����ѡ�������Ŀ:");
  a = getchar();
 }
 switch(a) {
  case '1': WriteData_wb(Creat(Creat_num()));
   printf("\n�½��ļ��ɹ��������ѳɹ�����\n");
    system("pause");
   system("cls");
   addStudent();
  break;
  case '2': WriteData_ab(Creat(Creat_num()));
    printf("\n�����ѳɹ����\n");
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

//�����˵�֮��ѯ����
void query()
{
 system("cls");
 getchar();
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
 a = getchar();

 while(a!='1'&&a!='2'&&a!='3'&&a!='4')
  {
   printf("������������ȷ�ĺ���!\n");
   putchar('\a');
   getchar();
   printf("\n\t\t�����빦��ǰ�����ѡ�������Ŀ:");
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
 getchar();
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
 a = getchar();

 while(a!='1'&&a!='2'&&a!='3')
 {
  printf("������������ȷ�ĺ���!\n");
  putchar('\a');
  getchar();
  printf("\n\t\t�����빦��ǰ�����ѡ�������Ŀ:");
  a = getchar();
  }
  switch(a) {
   case '1': delStudent();
    printf("\n\n�ѳɹ�ɾ��ָ������\n");
    system("pause");
    getchar();
   break;
   case '2': change1();
     printf("\n\n�ѳɹ��޸�ָ������\n");
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

*/





